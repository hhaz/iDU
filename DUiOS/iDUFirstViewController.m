//
//  duiosFirstViewController.m
//  DUiOS
//
//  Created by Hervé Azoulay on 28/01/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "iDUFirstViewController.h"
#import "DuWebServiceSvc.h"
#import "iDUAppDelegate.h"
#import "computePeriod.h"
#import "ActivityAlertView.h"
#import "joblog.h"
#import "getJobs.h"


@implementation iDUFirstViewController
@synthesize nodeList;
@synthesize myTableView;
@synthesize launchList;
@synthesize executionList;
@synthesize theNode;
@synthesize appDelegate;
@synthesize job;
@synthesize theLog;

#define REFRESH_HEADER_HEIGHT 52.0f

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
        cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
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
    
    UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
    theNode = cell.textLabel.text;
    
    [_retrieveJobs getJobs:self :theNode :@"seguegraph" :TRUE];
    
    NSLog(@"Cell Selected");
    
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
    _retrieveJobs = [[getJobs alloc]init];
    appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    appDelegate.tbController = self.tabBarController;
     
    if(refresh == nil)
    {
        refresh = [[UIRefreshControl alloc]initWithFrame:CGRectMake(0, 0 , 220, 22)];
        NSAttributedString *title = [[NSAttributedString alloc]initWithString:@"Refreshing Node List"];
        refresh.attributedTitle = title;
        [refresh addTarget:self action:@selector(refreshNodeList) forControlEvents:UIControlEventValueChanged];
    }
    
    [theNodes addSubview:refresh];
    
     UIImage *tableImage = [UIImage imageNamed:@"du.png"];
    switchControl.onImage = tableImage;
}


- (void)refreshNodeList
{
    NSLog(@"refresh");
    [self retrieveNodeList];
    [refresh endRefreshing];
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}


- (void)retrieveNodeList
{
    
    DuWebServiceSvc_uvmsNodeFilter *nodeFilter = [[DuWebServiceSvc_uvmsNodeFilter alloc] init];
    nodeFilter.node_ = @"*";
    nodeFilter.company = appDelegate.company;
    
    DuWebServiceSvc_getDUEnvironmentList *EnvirList = [[DuWebServiceSvc_getDUEnvironmentList alloc]init];
    EnvirList.token                                 = appDelegate.theContext.token;
    EnvirList.nodeFilter                            = nodeFilter;
    
    DuWebServiceSvc_getDUEnvironmentListResponse *EnvirListResponse = [[DuWebServiceSvc_getDUEnvironmentListResponse alloc]init];
    
    DuWebServiceSoapBindingResponse *responseEnvir = [appDelegate.binding getDUEnvironmentListUsingParameters:EnvirList];
    
    if (responseEnvir.error == 0) {
        @try {
            EnvirListResponse = (DuWebServiceSvc_getDUEnvironmentListResponse *)([responseEnvir.bodyParts objectAtIndex:0]);
            NSMutableArray *returnArray = [[NSMutableArray alloc] initWithCapacity:EnvirListResponse.envList.count];
            
            for (DuWebServiceSvc_envir *s in EnvirListResponse.envList )
            {
                if( [s.area isEqualToString:appDelegate.area])
                {
                    [returnArray addObject:s];
                }
            }
            
            appDelegate.nodeList = returnArray;
        }
        @catch (NSException *excep) {
            NSLog(@"Exception during node list retrieval");
            appDelegate.isConnected = FALSE;
            SOAPFault *result = (SOAPFault *)[responseEnvir.bodyParts objectAtIndex:0];
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
            return;
        }
        @finally {
            NSLog(@"Finally");
        }
        
    }
    nodeList = appDelegate.nodeList;
    [theNodes reloadData];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
  
    [self retrieveNodeList];
//    nodeList = appDelegate.nodeList;
//    [theNodes reloadData];
    
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
        if(![[appDelegate.args objectAtIndex:10] isEqualToString:@"n/a"])
        {
            execId.session = [appDelegate.args objectAtIndex:10];
        }
        execId.sessionVersion   = [appDelegate.args objectAtIndex:11];
        execId.numSess          = [appDelegate.args objectAtIndex:12];
        if(![[appDelegate.args objectAtIndex:8] isEqualToString:@"n/a"])
        {
            execId.task = [appDelegate.args objectAtIndex:8];
        }
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
        graphviewController.launchList      = _retrieveJobs.launchList;
        graphviewController.executionList   = _retrieveJobs.executionList;
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

-(IBAction)Test
{
    
    [self performSegueWithIdentifier:@"collectionTest" sender:self];
}


- (IBAction)changePage {
    [self performSegueWithIdentifier:@"collectionTest" sender:self];
}

@end
