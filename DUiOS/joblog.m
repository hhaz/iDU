//
//  joblog.m
//  DUiOS
//
//  Created by Hervé Azoulay on 18/02/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import "joblog.h"
#import "joblogdetails.h"

@implementation joblog
@synthesize theLog;
@synthesize myTableView;
@synthesize contentsList;
@synthesize sectionKeys;
@synthesize currentJob;
@synthesize currentLaunch;
@synthesize uprocNum,uprocName,uprocVersion,session,sessionVersion,numLaunc,endDate,beginDate,uprocStatus,beginHour,endHour;



- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    NSString *key = [[self sectionKeys] objectAtIndex:[indexPath section]];
    NSArray *contents = [[self contentsList] objectForKey:key];
    NSString *contentForThisRow = [contents objectAtIndex:[indexPath row]];
    NSString *CellIdentifier = [contents objectAtIndex:[indexPath row]];  

    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier] autorelease];
       
        if ([indexPath section] == 0) {
            UITextField *uproc = [[UITextField alloc] initWithFrame:CGRectMake(130, 15, 185, 30)];
            [uproc setFont:[UIFont fontWithName:@"Arial" size:12]];
            uproc.textColor = [UIColor blackColor];
            uproc.enabled = false;
            
            switch ([indexPath row]) {
                case 0:
                    uproc.text = uprocName;
                    break;
                    
                case 1:
                    uproc.text = uprocNum;
                    break;
                
                case 2:
                    uproc.text = uprocVersion;
                    break;
                    
                case 3:
                    uproc.text = session;
                    break;
                    
                case 4:
                    uproc.text = sessionVersion;
                    break;
                    
                default:
                    break;
            }
   
            [cell addSubview:uproc];
        }
        
        if ([indexPath section] == 1) {
            UITextField *dates = [[UITextField alloc] initWithFrame:CGRectMake(130, 15, 185, 30)];
            [dates setFont:[UIFont fontWithName:@"Arial" size:12]];
            dates.textColor = [UIColor blackColor];
            dates.enabled = false;
            
            NSDateFormatter *dateFormat = [[NSDateFormatter alloc] init];
            [dateFormat setDateFormat:@"yyyyMMdd HHmmss"];
            NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
            [dateFormatter setDateFormat:@"dd MMMM yyyy HH:mm"];
            [dateFormatter setTimeZone:[NSTimeZone localTimeZone]];
            
            switch ([indexPath row]) {
                case 0:
                {
                    NSString *temp = [NSString stringWithFormat:@"%@%@%@", beginDate , @" " , beginHour];
                    NSDate *date = [dateFormat dateFromString:temp]; 
                    dates.text = [dateFormatter stringFromDate:date];
                    break;
                }
                    
                case 1:
                {
                    NSString *temp = [NSString stringWithFormat:@"%@%@%@", endDate , @" " , endHour];
                    NSDate *date = [dateFormat dateFromString:temp]; 
                    dates.text = [dateFormatter stringFromDate:date];
                    break;
                }
                
                default:
                    break;
            }
            
            [cell addSubview:dates];
        }

        if ([indexPath section] == 2) {
            UITextField *status = [[UITextField alloc] initWithFrame:CGRectMake(130, 15, 185, 30)];
            [status setFont:[UIFont fontWithName:@"Arial" size:12]];
            status.textColor = [UIColor blackColor];
            status.enabled = false;
            
            switch ([indexPath row]) {
                case 0:
                    status.text = uprocStatus;
                    break;
                    
                case 1:
                    status.text = numLaunc;
                    
                    break;
                    
                default:
                    break;
            }
            
            [cell addSubview:status];
        }


    }
        
    [[cell textLabel] setText:contentForThisRow];
    return cell;
}


- (void)tableView:(UITableView *)tableView
didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
    //UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    
       
    // Customize the number of rows in the table view.
}

- (NSString *)tableView:(UITableView *)tableView
titleForHeaderInSection:(NSInteger)section
{
    NSString *key = [[self sectionKeys] objectAtIndex:section];
    
    return key;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
   	NSInteger sections = [[self contentsList] count];
    
    return sections;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    NSString *key = [[self sectionKeys] objectAtIndex:section];
    NSArray *contents = [[self contentsList] objectForKey:key];
    NSInteger rows = [contents count];
    
    return rows;
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


// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad
{
    [super viewDidLoad];

    beginDate = [[NSString alloc] init];
    endDate = [[NSString alloc] init];
    
    if (currentJob.ident.uproc.length != 0) {
        uprocName = currentJob.ident.uproc;
        uprocNum = currentJob.ident.numProc;
        uprocStatus = currentJob.status;
        uprocVersion = currentJob.ident.uprocVersion;
        session = currentJob.ident.session;
        sessionVersion = currentJob.ident.sessionVersion;
        numLaunc = currentJob.ident.numLanc;

        beginDate = currentJob.beginDate;
        beginHour = currentJob.beginHour;
        
        endDate = currentJob.endDate;
        endHour = currentJob.endHour;
    }
    else {
        uprocName = currentLaunch.ident.uproc;
        uprocNum = currentLaunch.ident.numProc;
        uprocStatus = currentLaunch.status;
        uprocVersion = currentLaunch.ident.uprocVersion;
        session = currentLaunch.ident.session;
        sessionVersion = currentLaunch.ident.sessionVersion;
        numLaunc = currentLaunch.ident.numLanc;
        
        beginDate = currentLaunch.beginDate;
        beginHour = currentLaunch.beginHour;
        
        endDate = currentLaunch.endDate;
        endHour = currentLaunch.endHour;    }
    
    NSMutableArray *keys = [[NSMutableArray alloc] init];
    NSMutableDictionary *contents = [[NSMutableDictionary alloc] init];
	
    NSString *uproc = @"UPROC Information";
    NSString *dates = @"Dates";
    NSString *run = @"Run Information";
   	
    [contents setObject:[NSArray arrayWithObjects:@"Name",@"Number", @"Version", @"Session",@"Version",nil] forKey:uproc];
    [contents setObject:[NSArray arrayWithObjects:@"Start Date", @"End Date" , nil] forKey:dates];
    [contents setObject:[NSArray arrayWithObjects:@"Status", @"Num Launch", nil] forKey:run];
  
    [keys addObject:uproc];
    [keys addObject:dates];
    [keys addObject:run];
 	
    [self setSectionKeys:keys];
    [self setContentsList:contents];
	
    [keys release], keys = nil;
    [contents release], contents = nil;
}


-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender

{
    joblogdetails *jobLogDetailsController = [segue destinationViewController];
    
    jobLogDetailsController.currentJob  = currentJob;
    jobLogDetailsController.theLog      = theLog;        
    
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
