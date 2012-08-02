//
//  duiosFirstViewController.m
//  DUiOS
//
//  Created by Hervé Azoulay on 28/01/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "duiosFirstViewController.h"
#import "DuWebServiceSvc.h"
#import "duiosAppDelegate.h"
#import "computePeriod.h"
#import "ActivityAlertView.h"
#import "joblog.h"


@implementation duiosFirstViewController
@synthesize nodeList;
@synthesize myTableView;
@synthesize aSecondController;
@synthesize launchList;
@synthesize executionList;
@synthesize theNode;
@synthesize appDelegate;
@synthesize job;
@synthesize theLog;

// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    static NSString *CellIdentifier = @"Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    }
    
    // Configure the cell.
    DuWebServiceSvc_envir *node = [appDelegate.nodeList objectAtIndex: [indexPath row]];
    DuWebServiceSvc_envirStatus status = node.status;
    NSString *imageFile = [[NSString alloc]init];
    NSString *nodeItem  = node.node_;
    cell.textLabel.text = nodeItem;
    
    if(status == DuWebServiceSvc_envirStatus_CONNECTED)
    {
        imageFile = @"DU.png";
        cell.accessoryType = UITableViewCellAccessoryDetailDisclosureButton;
    }
    else
    {
        imageFile = @"DUInactive.png";
        cell.accessoryType = UITableViewCellAccessoryNone;
        cell.userInteractionEnabled = NO;
        cell.textLabel.textColor = [UIColor darkGrayColor];
    }
    
    UIImage *tableImage = [UIImage imageNamed:imageFile];
    [cell.imageView setImage:tableImage];
    CGSize imageSize = CGSizeMake(25,25);	
    UIGraphicsBeginImageContext(imageSize); 
    CGRect imageRect = CGRectMake(1.0, 0.5, imageSize.width, imageSize.height); 
    [tableImage drawInRect:imageRect]; 
    cell.imageView.image = UIGraphicsGetImageFromCurrentImageContext(); 
    UIGraphicsEndImageContext(); 
    
    return cell;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    
        return @"Nodes";
}

- (void)tableView:(UITableView *)tableView
didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    
   Boolean goNext = TRUE;
    computePeriod *computeDate = [[computePeriod alloc] init];
    
    // Show the alert
    ActivityAlertView *activityAlert = [[ActivityAlertView alloc]
                                         initWithTitle:@"Retrieving Information"
                                         message:@"Please wait..."
                                         delegate:self cancelButtonTitle:nil 
                                         otherButtonTitles:nil];                                    
    [activityAlert show];
    
    [computeDate compute];
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyyMMdd"];
    [dateFormatter setTimeZone:[NSTimeZone localTimeZone]];
    NSDateFormatter *hourFormatter = [[NSDateFormatter alloc] init];
    [hourFormatter setDateFormat:@"HHmmss"];
    [hourFormatter setTimeZone:[NSTimeZone localTimeZone]];
    
    NSString *endDateMin = [dateFormatter stringFromDate:[appDelegate.periodArray lastObject]];
    NSString *endDateMax = [dateFormatter stringFromDate:[appDelegate.periodArray objectAtIndex:0]]; 
    
   UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
        
   DuWebServiceSvc_launchFilter *filter = [[DuWebServiceSvc_launchFilter alloc] init];
    
   DuWebServiceSvc_getListLaunch *listLaunch = [[DuWebServiceSvc_getListLaunch alloc] init];
    
   DuWebServiceSvc_getListLaunchResponse *listLaunchResponse = [[DuWebServiceSvc_getListLaunchResponse alloc] init];
    
    filter.mu = @"*";
    filter.beginDateMax = endDateMax;
    filter.beginDateMin = endDateMin;
    filter.maximumResults = appDelegate.nbJobs;
    filter.order = @"ASC";

   appDelegate.theContext.context.envir.node_ = cell.textLabel.text;
    
    listLaunch.context = appDelegate.theContext;
    listLaunch.filter = filter;

    // GetLaunchList
    
   DuWebServiceSoapBindingResponse *response = [appDelegate.binding getListLaunchUsingParameters:listLaunch];
  
    if (response.error == 0 && goNext ) {
        
        @try {      
            listLaunchResponse = (DuWebServiceSvc_getListLaunchResponse *)([response.bodyParts objectAtIndex:0]);        

            launchList = [[NSMutableArray alloc] initWithCapacity:listLaunchResponse.launchList.count];
        
            for (DuWebServiceSvc_launchItem *s in listLaunchResponse.launchList ) 
            {
                [launchList addObject:s];            
            }
        }
        @catch (NSException *excep) {
            goNext  = FALSE;
            SOAPFault *result = (SOAPFault *)[response.bodyParts objectAtIndex:0];
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        @finally {
            NSLog(@"Finally");
        }
    }
    
    // GetExecutionList
  
   DuWebServiceSvc_executionFilter *executionFilter = [[DuWebServiceSvc_executionFilter alloc] init];
    
   DuWebServiceSvc_getListExecution *listExecution = [[DuWebServiceSvc_getListExecution alloc] init];
    
   DuWebServiceSvc_getListExecutionResponse *listExecutionResponse = [[DuWebServiceSvc_getListExecutionResponse alloc] init];
    
    executionFilter.mu = @"*";
    executionFilter.beginDateMax = endDateMax;
    executionFilter.beginDateMin = endDateMin;
    executionFilter.maximumResults = appDelegate.nbJobs;
    executionFilter.order = @"ASC";
    
    appDelegate.theContext.context.envir.node_ = cell.textLabel.text;
    
    listExecution.context = appDelegate.theContext;
    listExecution.filter = executionFilter;

   DuWebServiceSoapBindingResponse *responseExecution = [appDelegate.binding getListExecutionUsingParameters:listExecution];
    
    if (responseExecution.error == 0 && goNext) {
        @try {
            listExecutionResponse = (DuWebServiceSvc_getListExecutionResponse *)([responseExecution.bodyParts objectAtIndex:0]);

            executionList = [[NSMutableArray alloc] initWithCapacity:listExecutionResponse.executionList.count];
            
            for (DuWebServiceSvc_executionItem *s in listExecutionResponse.executionList ) 
            {
                [executionList addObject:s];
            }
        }
        @catch (NSException *excep) {
            SOAPFault *result = (SOAPFault *)[responseExecution.bodyParts objectAtIndex:0];
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        @finally {
            NSLog(@"Finally");
        }
    }
    theNode = appDelegate.theContext.context.envir.node_;

    if (goNext) {
     [self performSegueWithIdentifier:@"seguegraph" sender:cell];
    }
    
        [activityAlert close];
}
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [appDelegate.nodeList count];
}

- (NSInteger)tableView:(UITableView *)tableView numberOfSections:(NSInteger)section {
    return 1;
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    appDelegate = (duiosAppDelegate *)[[UIApplication sharedApplication] delegate];
    appDelegate.tbController = self.tabBarController;
    
   UINavigationController *controller = [self.tabBarController.viewControllers  objectAtIndex:1];
    
    aSecondController = [controller.childViewControllers objectAtIndex:0];
    
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
  
    nodeList = appDelegate.nodeList;
    [theNodes reloadData];
    
    if (appDelegate.isRemoteNotif && appDelegate.isConnected) {                     
         appDelegate.isRemoteNotif = FALSE;
        
        NSString *area      = [appDelegate.args objectAtIndex:2];
        NSString *company   = [appDelegate.args objectAtIndex:1];
        
        if(![appDelegate.company isEqualToString:company])
        {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Job Detail Display Error" message:@"You are not connected to the same company" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
            
            return;
        }
        
        if(![appDelegate.area isEqualToString:area])
        {
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Job Detail Display Error" message:@"You are not connected to the same area" delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
            
            return;
        }

        // Get the job

        DuWebServiceSvc_executionId *execId = [[DuWebServiceSvc_executionId alloc]init];
        
        DuWebServiceSvc_getExecution *Execution = [[DuWebServiceSvc_getExecution alloc] init];
        
        DuWebServiceSvc_getExecutionResponse *ExecutionResponse = [[DuWebServiceSvc_getExecutionResponse alloc] init];
        
        execId.numLanc          = [appDelegate.args objectAtIndex:6];
        execId.numProc          = [appDelegate.args objectAtIndex:7];
        execId.uproc            = [appDelegate.args objectAtIndex:4];
        execId.mu               = [appDelegate.args objectAtIndex:5];
        execId.session          = [appDelegate.args objectAtIndex:10];
        execId.sessionVersion   = [appDelegate.args objectAtIndex:11];   
        execId.numSess          = [appDelegate.args objectAtIndex:12];
        execId.task             = [appDelegate.args objectAtIndex:8];
        // à gérer : pas de numéro de version quand on est en X
        //execId.uprocVersion = @"000";
        
        appDelegate.theContext.context.envir.node_ = [appDelegate.args objectAtIndex:3];
        
        Execution.context       = appDelegate.theContext;       
        Execution.executionId   = execId;
        
        DuWebServiceSoapBindingResponse *response = [appDelegate.binding getExecutionUsingParameters:Execution];
        
        if (response.error == 0 ) {
            @try {
                ExecutionResponse = (DuWebServiceSvc_getExecutionResponse *)([response.bodyParts objectAtIndex:0]);
                
                DuWebServiceSvc_execution *exec = ExecutionResponse.execution;
    
                job = exec.data;
            }
            @catch (NSException *excep) {
                SOAPFault *result = (SOAPFault *)[response.bodyParts objectAtIndex:0];
                UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
                [alert show];
            }
            @finally {
                NSLog(@"Finally");
            }
        }
        
        // Get the job Log
        
        DuWebServiceSvc_getExecutionLog *joblog = [[DuWebServiceSvc_getExecutionLog alloc] init];
        
        DuWebServiceSvc_getExecutionLogResponse *joblogResponse = [[DuWebServiceSvc_getExecutionLogResponse alloc] init];

        joblog.context = appDelegate.theContext;
        
        joblog.executionId  = execId;
        
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
            }
        }
        [self performSegueWithIdentifier:@"showjob" sender:self];   
    }
}

-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender

{
    if ([[segue identifier] isEqualToString:@"showjob"])
    {
        joblog *jobLogController = [segue destinationViewController];
        
        jobLogController.currentJob     = job;
        jobLogController.theLog         = theLog;
    }
    
    if ([[segue identifier] isEqualToString:@"seguegraph"])
    {
        graphview *graphviewController = [segue destinationViewController];
        
        graphviewController.nodeName        = theNode;
        graphviewController.launchList      = launchList;
        graphviewController.executionList   = executionList;
    }
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
   
}

- (void)viewWillDisappear:(BOOL)animated
{
	[super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
	[super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

@end
