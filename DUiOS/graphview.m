//
//  graphview.m
//  DUiOS
//
//  Created by Hervé Azoulay on 25/02/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "graphview.h"
#import "DuWebServiceSvc.h"
#import "iDUAppDelegate.h"
#import "SimplePieChart.h"
#import "PlotItem.h"
#import "jobruns.h"

@interface graphview()

-(CPTTheme *)currentTheme;

@end

@implementation graphview
@synthesize executionList;
@synthesize bindingAddress;
@synthesize theContext;
@synthesize hostingView;
@synthesize data;
@synthesize nodeName;
@synthesize filterStatus;
@synthesize launchList;
@dynamic detailItem;

#pragma mark -
#pragma mark Managing the detail item

-(PlotItem *)detailItem
{
	return detailItem;
}

#pragma mark -
#pragma mark Theme Selection

-(CPTTheme *)currentTheme
{
	CPTTheme *theme;
    theme = [CPTTheme themeNamed:@"None"];
	return theme;
}

-(void)setDetailItem:(id)newDetailItem
{
	if ( detailItem != newDetailItem ) {
		[detailItem killGraph];
		[detailItem release];
        
		detailItem = [newDetailItem retain];
        [detailItem renderInView:hostingView withTheme:[self currentTheme]];
	}
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
        
    NSInteger nbOK          = 0;
    NSInteger nbOverrun     = 0;
    NSInteger nbEventWait   = 0;
    NSInteger nbAborted     = 0;
    NSInteger nbRefused     = 0;
    NSInteger nbPending     = 0;
    NSInteger nbRunning     = 0;
    NSInteger nbLaunchWait  = 0;

    SimplePieChart *plotItem = (SimplePieChart *)[[PlotGallery sharedPlotGallery] objectAtIndex:0];
    
    for (DuWebServiceSvc_executionItem *item in executionList ) 
            {
                
                if([item.status isEqualToString:@"TIME_OVERRUN"])
                {
                    nbOverrun = nbOverrun + 1;
                }
                
                if([item.status isEqualToString:@"EVENT_WAIT"])
                {
                    nbEventWait = nbEventWait + 1;
                }
                
                
                if([item.status isEqualToString:@"ABORTED"])
                {
                    nbAborted = nbAborted + 1;
                }
                
                
                if([item.status isEqualToString:@"REFUSED"])
                {
                    nbRefused = nbRefused + 1;
                }
                
                
                if([item.status isEqualToString:@"PENDING"])
                {
                    nbPending = nbPending + 1;
                }
                
                
                if([item.status isEqualToString:@"RUNNING"])
                {
                    nbRunning = nbRunning + 1;
                }
                
                
                if([item.status isEqualToString:@"COMPLETED"])
                {
                    nbOK = nbOK + 1;
                }
                
                
                if([item.status isEqualToString:@"LAUNCHING"])
                {
                    nbLaunchWait = nbLaunchWait + 1;
                }                
            }
    
    for (DuWebServiceSvc_launchItem *item in launchList ) 
    {
        
        if([item.status isEqualToString:@"TIME_OVERRUN"])
        {
            nbOverrun = nbOverrun + 1;
        }
        
        if([item.status isEqualToString:@"EVENT_WAIT"])
        {
            nbEventWait = nbEventWait + 1;
        }
        
        
        if([item.status isEqualToString:@"ABORTED"])
        {
            nbAborted = nbAborted + 1;
        }
        
        
        if([item.status isEqualToString:@"REFUSED"])
        {
            nbRefused = nbRefused + 1;
        }
        
        
        if([item.status isEqualToString:@"PENDING"])
        {
            nbPending = nbPending + 1;
        }
        
        
        if([item.status isEqualToString:@"RUNNING"])
        {
            nbRunning = nbRunning + 1;
        }
        
        
        if([item.status isEqualToString:@"COMPLETED"])
        {
            nbOK = nbOK + 1;
        }
        
        
        if([item.status isEqualToString:@"LAUNCHING"])
        {
            nbLaunchWait = nbLaunchWait + 1;
        }                
    }
    
    plotItem.plotData = [[NSMutableArray alloc] initWithObjects:
                [NSNumber numberWithDouble:nbOK],
                [NSNumber numberWithDouble:nbOverrun],
                [NSNumber numberWithDouble:nbEventWait],
                [NSNumber numberWithDouble:nbAborted],
                [NSNumber numberWithDouble:nbRefused],
                [NSNumber numberWithDouble:nbPending],
                [NSNumber numberWithDouble:nbRunning],
                [NSNumber numberWithDouble:nbLaunchWait],
                nil];
    
    plotItem.plotLegend= [[NSMutableArray alloc] initWithObjects:
                          @"Success",
                          @"Time Overrun",
                          @"Event Wait",
                          @"Aborted",
                          @"Refused",
                          @"Pending",
                          @"Running",
                          @"Launch Wait",
                          nil];
    
    plotItem.plotColor = [[NSMutableArray alloc] initWithObjects:
                          [CPTColor greenColor],
                          [CPTColor orangeColor],
                          [CPTColor blueColor],
                          [CPTColor redColor],
                          [CPTColor brownColor],
                          [CPTColor yellowColor],
                          [CPTColor cyanColor],
                          [CPTColor purpleColor],
                          nil];
    plotItem.plotStatus= [[NSMutableArray alloc] initWithObjects:
                          @"COMPLETED",
                          @"TIME_OVERRUN",
                          @"EVENT_WAIT",
                          @"ABORTED",
                          @"REFUSED",
                          @"PENDING",
                          @"RUNNING",
                          @"LAUNCHING",
                          nil];
    
    plotItem.aGraphView = self;
    detailItem = plotItem;
    [detailItem renderInView:hostingView withTheme:[CPTTheme themeNamed:@"None"]];

}

-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender

{
    if ([[segue identifier] isEqualToString:@"seguejoblist"])
    {
        jobruns *jobRunsController = [segue destinationViewController];
        
        jobRunsController.executionList = executionList;
        jobRunsController.launchList    = launchList;
        jobRunsController.filterStatus  = filterStatus;
    }
    
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
