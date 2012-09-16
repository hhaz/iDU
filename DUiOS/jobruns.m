//
//  jobruns.m
//  DUiOS
//
//  Created by Hervé Azoulay on 30/01/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "jobruns.h"
#import "joblog.h"
#import "iDUAppDelegate.h"
#import "DuWebServiceSvc.h"
#import "ActivityAlertView.h"
#import "computePeriod.h"
#import "SectionInfo.h"
#import "SectionHeaderView.h"

@implementation jobruns
@synthesize nodeList;
@synthesize myTableView;
@synthesize launchList;
@synthesize executionList;
@synthesize theLog;
@synthesize currentJob;
@synthesize filteredLaunchList;
@synthesize filteredExecutionList;
@synthesize filterStatus;
@synthesize appDelegate;
@synthesize sectionKeys;
@synthesize contentsList;
@synthesize currentLaunch;
@synthesize sectionInfoArray;
@synthesize openSectionIndex=openSectionIndex_;
@synthesize uniformRowHeight=rowHeight_;

#define ROW_HEIGHT 40
#define HEADER_HEIGHT 45


#pragma mark Section header delegate

-(void)sectionHeaderView:(SectionHeaderView*)sectionHeaderView sectionOpened:(NSInteger)sectionOpened {
	
	SectionInfo *sectionInfo = [self.sectionInfoArray objectAtIndex:sectionOpened];
	
	sectionInfo.open = YES;
    
    /*
     Create an array containing the index paths of the rows to insert: These correspond to the rows for each quotation in the current section.
     */
    NSInteger countOfRowsToInsert = [sectionInfo.jobs count];
    NSMutableArray *indexPathsToInsert = [[NSMutableArray alloc] init];
    for (NSInteger i = 0; i < countOfRowsToInsert; i++) {
        [indexPathsToInsert addObject:[NSIndexPath indexPathForRow:i inSection:sectionOpened]];
    }
    
    /*
     Create an array containing the index paths of the rows to delete: These correspond to the rows for each quotation in the previously-open section, if there was one.
     */
    NSMutableArray *indexPathsToDelete = [[NSMutableArray alloc] init];
    
    NSInteger previousOpenSectionIndex = self.openSectionIndex;
    if (previousOpenSectionIndex != NSNotFound) {
		
		SectionInfo *previousOpenSection = [self.sectionInfoArray objectAtIndex:previousOpenSectionIndex];
        previousOpenSection.open = NO;
        [previousOpenSection.headerView toggleOpenWithUserAction:NO];
        NSInteger countOfRowsToDelete = [previousOpenSection.jobs count];
        for (NSInteger i = 0; i < countOfRowsToDelete; i++) {
            [indexPathsToDelete addObject:[NSIndexPath indexPathForRow:i inSection:previousOpenSectionIndex]];
        }
    }
    
    // Style the animation so that there's a smooth flow in either direction.
    UITableViewRowAnimation insertAnimation;
    UITableViewRowAnimation deleteAnimation;
    if (previousOpenSectionIndex == NSNotFound || sectionOpened < previousOpenSectionIndex) {
        insertAnimation = UITableViewRowAnimationTop;
        deleteAnimation = UITableViewRowAnimationBottom;
    }
    else {
        insertAnimation = UITableViewRowAnimationBottom;
        deleteAnimation = UITableViewRowAnimationTop;
    }
    
    // Apply the updates.
    [self.tableView beginUpdates];
    [self.tableView deleteRowsAtIndexPaths:indexPathsToDelete withRowAnimation:deleteAnimation];
    [self.tableView insertRowsAtIndexPaths:indexPathsToInsert withRowAnimation:insertAnimation];
    [self.tableView endUpdates];
    self.openSectionIndex = sectionOpened;
    
}


-(void)sectionHeaderView:(SectionHeaderView*)sectionHeaderView sectionClosed:(NSInteger)sectionClosed {
    
    /*
     Create an array of the index paths of the rows in the section that was closed, then delete those rows from the table view.
     */
	SectionInfo *sectionInfo = [self.sectionInfoArray objectAtIndex:sectionClosed];
	
    sectionInfo.open = NO;
    NSInteger countOfRowsToDelete = [self.tableView numberOfRowsInSection:sectionClosed];
    
    if (countOfRowsToDelete > 0) {
        NSMutableArray *indexPathsToDelete = [[NSMutableArray alloc] init];
        for (NSInteger i = 0; i < countOfRowsToDelete; i++) {
            [indexPathsToDelete addObject:[NSIndexPath indexPathForRow:i inSection:sectionClosed]];
        }
        [self.tableView deleteRowsAtIndexPaths:indexPathsToDelete withRowAnimation:UITableViewRowAnimationTop];
    }
    self.openSectionIndex = NSNotFound;
}

// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
     
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithFrame:CGRectZero];
        
        UIPinchGestureRecognizer *twoFingerPinch = 
        [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(handlePinchGesture:)];
        [cell addGestureRecognizer:twoFingerPinch];
        
		[cell addSubview:[[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(cell.frame)+50, CGRectGetMinY(cell.frame), CGRectGetWidth(cell.frame)-200 , ROW_HEIGHT)]];
        [cell addSubview:[[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(cell.frame)+ CGRectGetWidth(cell.frame)-200, CGRectGetMinY(cell.frame), CGRectGetWidth(cell.frame)-200, ROW_HEIGHT)]];
    }
    
    cell.accessoryType = UITableViewCellAccessoryDetailDisclosureButton;
    
    NSString *key = [[self sectionKeys] objectAtIndex:[indexPath section]];
    NSArray *contents = [[self contentsList] objectForKey:key];    
    
    NSString *statusString;
    NSString *uprocLabel;
    
    
    if( [[contents objectAtIndex: [indexPath row]] isKindOfClass:[DuWebServiceSvc_executionItem class]])
    {
        DuWebServiceSvc_executionItem *executionItem = [contents objectAtIndex: [indexPath row]];
        statusString = executionItem.status; 
        uprocLabel = executionItem.ident.uproc;
    }
    else {
        DuWebServiceSvc_launchItem *launchItem = [contents objectAtIndex: [indexPath row]];
        statusString = launchItem.status; 
        uprocLabel = launchItem.ident.uproc;
    }
    
       UILabel *labelText = [[cell subviews] objectAtIndex:1];
       labelText.backgroundColor = [UIColor clearColor];
       
       labelText.text = uprocLabel;
       labelText.font = [UIFont boldSystemFontOfSize:14];
       labelText.lineBreakMode = NSLineBreakByWordWrapping;
       labelText.numberOfLines = 2;	
       
       UILabel *labelText2 = [[cell subviews] objectAtIndex:2];
       labelText2.backgroundColor = [UIColor clearColor];
       labelText2.textColor = [UIColor blackColor];
       labelText2.text = @"OK";
       labelText2.textAlignment = NSTextAlignmentRight;
       
       labelText2.textColor = [UIColor blackColor];
       labelText2.text = @"OK";
    
    
       labelText2.text      = [[appDelegate.contentStatus objectForKey:statusString] objectAtIndex:0];
       labelText2.textColor = [[appDelegate.contentStatus objectForKey:statusString] objectAtIndex:1];
       NSString *imageFlag  = [[appDelegate.contentStatus objectForKey:statusString] objectAtIndex:2];

       labelText2.font = [UIFont systemFontOfSize:12];
       labelText2.lineBreakMode = NSLineBreakByClipping;
       labelText2.numberOfLines = 2;

        UIImage *tableImage = [UIImage imageNamed:imageFlag]; 
        [cell.imageView setImage:tableImage]; 
        CGSize imageSize = CGSizeMake(20,20);	
        UIGraphicsBeginImageContext(imageSize); 
        CGRect imageRect = CGRectMake(0.0, 0.5, imageSize.width, imageSize.height); 
        [tableImage drawInRect:imageRect]; 
        cell.imageView.image = UIGraphicsGetImageFromCurrentImageContext(); 
        UIGraphicsEndImageContext();
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeDetailDisclosure];
	[button setBackgroundColor:[UIColor whiteColor]];
    [button setImage:[UIImage imageNamed:@"rerun.png"] forState:UIControlStateNormal];
     [button setImage:[UIImage imageNamed:@"rerunblue.png"] forState:UIControlStateHighlighted];
    [button setFrame:CGRectMake(CGRectGetMinX(cell.frame)+ CGRectGetWidth(cell.frame)-70, CGRectGetMinY(cell.frame) + 8 , 22, 22)];
	[button addTarget:self action:@selector(ckCheckButtonTapped:event:) forControlEvents:UIControlEventTouchUpInside];
	[cell.contentView addSubview:button];
    return cell;
}


- (void)ckCheckButtonTapped:(id)sender event:(id)event
{
    
    UITableViewCell *cell = (UITableViewCell *)[[sender superview] superview];
    NSIndexPath *indexPath = [[self tableView] indexPathForCell:cell];
    
    NSString *key = [[self sectionKeys] objectAtIndex:[indexPath section]];
    NSArray *contents = [[self contentsList] objectForKey:key];
    
    if( [[contents objectAtIndex: [indexPath row]] isKindOfClass:[DuWebServiceSvc_executionItem class]])
    {
        DuWebServiceSvc_executionItem *executionItem    = [contents objectAtIndex: [indexPath row]];
        DuWebServiceSvc_rerunExecution *reRun           = [[DuWebServiceSvc_rerunExecution alloc]init];
        
        DuWebServiceSvc_executionId *job = [[DuWebServiceSvc_executionId alloc] init];
        
        job.mu              = executionItem.ident.mu;
        job.numLanc         = executionItem.ident.numLanc;
        job.numProc         = executionItem.ident.numProc;
        job.numSess         = executionItem.ident.numSess;
        job.session         = executionItem.ident.session;
        job.sessionVersion  = executionItem.ident.sessionVersion;
        job.uprocVersion    = executionItem.ident.uprocVersion;
        job.uproc           = executionItem.ident.uproc;
        job.session         = executionItem.ident.session;
        job.task            = executionItem.ident.task;

        reRun.executionId   = job;
        reRun.context       = appDelegate.theContext;
                
        [appDelegate.binding rerunExecutionAsyncUsingParameters:reRun delegate:self];
        
        @try {
            [appDelegate.binding rerunExecutionAsyncUsingParameters:reRun delegate:self];
        }
        @catch (NSException *excep) {
            appDelegate.isConnected = FALSE;
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error - No Log" message:@"Error" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
            return;
        }
        @finally {
            NSLog(@"Finally");

        }
    }          
}

- (void) operation:(DuWebServiceSoapBindingOperation *)operation completedWithResponse:(DuWebServiceSoapBindingResponse *)response
{
    @try {
        DuWebServiceSvc_rerunExecutionResponse *reRunresponse = (DuWebServiceSvc_rerunExecutionResponse *)([response.bodyParts objectAtIndex:0]);
        
        NSLog(@"%@",reRunresponse.description); // just to avoid compilation warning
    }
    @catch (NSException *excep) {
        appDelegate.isConnected = FALSE;
        SOAPFault *result = (SOAPFault *)[response.bodyParts objectAtIndex:0];
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error - No Log" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        return;
    }
}

int currentRowSelection = -1;
int currentSectionSelection = -1;
bool isExtended = false;

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    /*if ([indexPath row] == currentRowSelection && [indexPath section] == currentSectionSelection && !isExtended) {
        isExtended = true;
        return  ROW_HEIGHT*2;
    }
    else { 
        isExtended = false;
        return ROW_HEIGHT;
    }*/
    
    return ROW_HEIGHT;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    computePeriod *computeDate = [[computePeriod alloc] init];
    [computeDate compute];
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"dd MMMM YYYY HH:mm"];
    [dateFormatter setTimeZone:[NSTimeZone localTimeZone]];
    
    NSString *tempDate = [dateFormatter stringFromDate:[appDelegate.periodArray objectAtIndex:section]];
    
    return tempDate;
    
}

- (void)tableView:(UITableView *)tableView
didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    // Customize the number of rows in the table view.
    int row = [indexPath row];
    currentRowSelection = row;
    currentSectionSelection = [indexPath section];
    
     UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    
    NSString *key = [[self sectionKeys] objectAtIndex:[indexPath section]];
    NSArray *contents = [[self contentsList] objectForKey:key];    
    
    if( [[contents objectAtIndex: [indexPath row]] isKindOfClass:[DuWebServiceSvc_executionItem class]])
    {
        DuWebServiceSvc_executionItem *executionItem = [contents objectAtIndex: [indexPath row]];
        DuWebServiceSvc_getExecutionLog *joblog = [[DuWebServiceSvc_getExecutionLog alloc] init];
        
        DuWebServiceSvc_getExecutionLogResponse *joblogResponse = [[DuWebServiceSvc_getExecutionLogResponse alloc] init];
        
        DuWebServiceSvc_executionId *job = [[DuWebServiceSvc_executionId alloc] init];
        
        joblog.context = appDelegate.theContext;
        
        job.mu              = executionItem.ident.mu;
        job.numLanc         = executionItem.ident.numLanc;
        job.numProc         = executionItem.ident.numProc;
        job.numSess         = executionItem.ident.numSess;
        job.session         = executionItem.ident.session;
        job.sessionVersion  = executionItem.ident.sessionVersion;
        job.uprocVersion    = executionItem.ident.uprocVersion;
        job.uproc           = executionItem.ident.uproc;
        joblog.executionId  = job;
        
        
        DuWebServiceSoapBindingResponse *Response = [appDelegate.binding getExecutionLogUsingParameters:joblog];
        
        theLog = @"";
        
        if (Response.error == 0)
        {
            @try { 
                
                joblogResponse = (DuWebServiceSvc_getExecutionLogResponse *)([Response.bodyParts objectAtIndex:0]);
                
                for (NSString *logligne in joblogResponse.executionLog.log)
                {
                    theLog = [theLog stringByAppendingString:logligne];
                }
            }           
            @catch (NSException *excep) {
                appDelegate.isConnected = FALSE;
                SOAPFault *result = (SOAPFault *)[Response.bodyParts objectAtIndex:0];
                UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error - No Log" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
                [alert show];
                return;
            }
            @finally {
                NSLog(@"Finally");
                currentJob = executionItem;
                [self performSegueWithIdentifier:@"DisplayJobLog" sender:cell]; 
            }
        }

    }
    else {
        DuWebServiceSvc_launchItem *launchItem = [contents objectAtIndex: [indexPath row]];
        
        DuWebServiceSvc_launchId *jobLaunch = [[DuWebServiceSvc_launchId alloc] init];
                
        jobLaunch.mu                = launchItem.ident.mu;
        jobLaunch.numLanc           = launchItem.ident.numLanc;
        jobLaunch.numProc           = launchItem.ident.numProc;
        jobLaunch.numSess           = launchItem.ident.numSess;
        jobLaunch.session           = launchItem.ident.session;
        jobLaunch.sessionVersion    = launchItem.ident.sessionVersion;
        jobLaunch.uprocVersion      = launchItem.ident.uprocVersion;
        jobLaunch.uproc             = launchItem.ident.uproc;
        
        currentLaunch = launchItem;
        [self performSegueWithIdentifier:@"DisplayJobLog" sender:cell]; 

    }
    
}


-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender

{
    if ([[segue identifier] isEqualToString:@"DisplayJobLog"])

    {
        joblog *jobLogController = [segue destinationViewController];
        
        jobLogController.currentJob     = currentJob;
        jobLogController.currentLaunch  = currentLaunch;
        jobLogController.theLog         = theLog;
    }

}


- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {

    SectionInfo *sectionInfo = [self.sectionInfoArray objectAtIndex:section];
	NSInteger numJobsInSection = [sectionInfo.jobs count];
	
    return sectionInfo.open ? numJobsInSection : 0;

   
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
    return [appDelegate.nbPeriods intValue];
}


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView
{
}
*/
- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    if(refresh.refreshing)
    {
        executionList   = _retrieveJobs.executionList;
        launchList      = _retrieveJobs.launchList;
    }
    
    theLaunches.rowHeight   = 20;
    
    [filteredExecutionList removeAllObjects];
    [filteredLaunchList removeAllObjects];
    [sectionInfoArray removeAllObjects];
    
    self.openSectionIndex = NSNotFound;
    
    sectionInfoArray = [[NSMutableArray alloc] init];
    
    for (DuWebServiceSvc_executionItem *item in executionList ) 
    {  
        if ([item.status isEqualToString:filterStatus]) {
            [filteredExecutionList addObject:item];
        }
    }
    
    for (DuWebServiceSvc_launchItem *item in launchList ) 
    {
        if ([item.status isEqualToString:filterStatus]) {
            [filteredLaunchList addObject:item];
        }
    }
    
    // filter status
    
    NSCalendar *cal = [[NSCalendar alloc] initWithCalendarIdentifier:NSGregorianCalendar];
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyyMMdd"];
    [dateFormatter setCalendar:cal];
    
    NSDateFormatter *dateFormatter2 = [[NSDateFormatter alloc] init];
    [dateFormatter2 setDateFormat:@"yyyyMMdd HHmmss"];
    [dateFormatter2 setTimeZone:[NSTimeZone localTimeZone]];
    [dateFormatter2 setCalendar:cal];

    
    NSMutableArray *keys            = [[NSMutableArray alloc] init];
    NSMutableDictionary *contents   = [[NSMutableDictionary alloc] init];
	
    for(integer_t i = 0 ; i < appDelegate.periodArray.count ; i++)
    {
        NSDate *date = [appDelegate.periodArray objectAtIndex:i];
   
        NSMutableArray *temp = [[NSMutableArray alloc] init];
        NSDate *nextDate; 
        
        if([date isEqualToDate:[appDelegate.periodArray lastObject]])
        {
            nextDate = date;    
        }
        else
        {
            nextDate = [appDelegate.periodArray objectAtIndex:i+1];
        }
        
        for (DuWebServiceSvc_executionItem *item in filteredExecutionList ) 
        {
         
            integer_t offset = [[NSTimeZone localTimeZone] secondsFromGMT] / 3600;
            
            NSTimeInterval delay = offset * 60 * 60;
            
            NSString *dateItemString = [NSString stringWithFormat:@"%@%@%@", item.beginDate, @" " , item.beginHour];
            
            NSDate *dateItem = [dateFormatter2 dateFromString:dateItemString];
            
            // Manage timezone differences
            dateItem = [dateItem dateByAddingTimeInterval:delay];
            
            NSComparisonResult result1 = [dateItem compare:date];
            NSComparisonResult result2 = [dateItem compare:nextDate];
            
            if((result1 == NSOrderedAscending) && (result2 == NSOrderedDescending))
            {
                [temp addObject:item];
            }            
        }
        
        for (DuWebServiceSvc_launchItem *item in filteredLaunchList) 
        {
            
            integer_t offset = [[NSTimeZone localTimeZone] secondsFromGMT] / 3600;
            
            NSTimeInterval delay = offset * 60 * 60;
            
            NSString *dateItemString = [NSString stringWithFormat:@"%@%@%@", item.beginDate, @" " , item.beginHour];
            
            NSDate *dateItem = [dateFormatter2 dateFromString:dateItemString];
            
            // Manage timezone differences
            dateItem = [dateItem dateByAddingTimeInterval:delay];
            
            NSComparisonResult result1 = [dateItem compare:date];
            NSComparisonResult result2 = [dateItem compare:nextDate];
            
            if((result1 == NSOrderedAscending) && (result2 == NSOrderedDescending))
            {
                [temp addObject:item];
            }            
        }
        
        [contents setObject:temp forKey:date];
        [keys addObject:date];
    }    
    
    [self setSectionKeys:keys];
    [self setContentsList:contents];

    for(NSString *temp in appDelegate.periodArray)
    {
        SectionInfo *sectionTemp = [[SectionInfo alloc]init];
        
        sectionTemp.jobs = [[NSMutableArray alloc]initWithArray:[[self contentsList] objectForKey:temp]];
        sectionTemp.open = NO;
              
        NSNumber *defaultRowHeight = [NSNumber numberWithInteger:ROW_HEIGHT];
        NSInteger countOfJobs = [sectionTemp.jobs count];
        for (NSInteger i = 0; i < countOfJobs; i++) {
            [sectionTemp insertObject:defaultRowHeight inRowHeightsAtIndex:i];
        }
        
        [sectionInfoArray addObject:sectionTemp];
    }
    
    [theLaunches reloadData];
}

- (UIView*)tableView:(UITableView*)tableView viewForHeaderInSection:(NSInteger)section {

/*
 Create the section header views lazily.
 */
SectionInfo *sectionInfo = [self.sectionInfoArray objectAtIndex:section];
if (!sectionInfo.headerView) {
    computePeriod *computeDate = [[computePeriod alloc] init];
    [computeDate compute];
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"dd MMMM YYYY HH:mm"];
    [dateFormatter setTimeZone:[NSTimeZone localTimeZone]];
    
    NSString *tempDate = [dateFormatter stringFromDate:[appDelegate.periodArray objectAtIndex:section]];
    
    //SectionInfo *sectionInfo = [self.sectionInfoArray objectAtIndex:section];
    
    NSString *sectionTitle = [NSString stringWithFormat:@"%@%@%d%@", tempDate , @"  -  " , [sectionInfo.jobs count] , @" Jobs"];
    
    sectionInfo.headerView = [[SectionHeaderView alloc] initWithFrame:CGRectMake(0.0, 0.0, self.tableView.bounds.size.width, HEADER_HEIGHT) title:sectionTitle section:section delegate:self];
}

return sectionInfo.headerView;
}

- (void)refreshJobList
{
    NSLog(@"refresh");
    [_retrieveJobs getJobs:self :_theNode :@""];
    [refresh endRefreshing];
}

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad
{
    [super viewDidLoad];
    if (_retrieveJobs == nil) {
        _retrieveJobs = [[getJobs alloc]init];
    }
    
    if(refresh == nil)
    {
        refresh = [[UIRefreshControl alloc]initWithFrame:CGRectMake(0, 0 , 220, 22)];
        NSAttributedString *title = [[NSAttributedString alloc]initWithString:@"Refreshing Job List"];
        refresh.attributedTitle = title;
        [refresh addTarget:self action:@selector(refreshJobList) forControlEvents:UIControlEventValueChanged];
    }

    [theLaunches addSubview:refresh];
    
    filteredLaunchList = [[NSMutableArray alloc] init];
    filteredExecutionList = [[NSMutableArray alloc] init];
    
    appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];   
    
    currentLaunch = [[DuWebServiceSvc_launchItem alloc]init];
    currentJob = [[DuWebServiceSvc_executionItem alloc]init];
    theLog = [[NSString alloc]init];
    
    // Set up default values.
    self.tableView.sectionHeaderHeight = HEADER_HEIGHT;
	/*
     The section info array is thrown away in viewWillUnload, so it's OK to set the default values here. If you keep the section information etc. then set the default values in the designated initializer.
     */
    rowHeight_ = ROW_HEIGHT;
    openSectionIndex_ = NSNotFound;
}


- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

@end
