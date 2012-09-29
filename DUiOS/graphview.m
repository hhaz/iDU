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
#import "PlotItem.h"
#import "jobruns.h"
#import "SimplePieChart.h"
#import "Test1ViewController.h"

@interface graphview()
@property (nonatomic,retain) Test1ViewController *pageOne;

-(CPTTheme *)currentTheme;

@end

@implementation graphview
@synthesize executionList;
@synthesize nodeName;
@synthesize filterStatus;
@synthesize launchList;
@dynamic detailItem;



- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerBeforeViewController:(UIViewController *)viewController
{
    return _pageOne;
}

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerAfterViewController:(UIViewController *)viewController
{
    return _pageOne;
    
}

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

// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.pageViewController = [[UIPageViewController alloc] initWithTransitionStyle:UIPageViewControllerTransitionStyleScroll navigationOrientation:UIPageViewControllerNavigationOrientationHorizontal options:nil];
    
    [self.pageViewController didMoveToParentViewController:self];
    _pageOne = [self.storyboard instantiateViewControllerWithIdentifier:@"Test1"];
    
    self.pageViewController.dataSource = self;
    self.pageViewController.delegate = self;
    
    [self.pageViewController setViewControllers:[NSArray arrayWithObjects:_pageOne, nil] direction:UIPageViewControllerNavigationDirectionForward animated:NO completion:nil];
    
    [self addChildViewController:self.pageViewController];
    [self.view addSubview:self.pageViewController.view];
    
    // Set the page view controller's bounds using an inset rect so that self's view is visible around the edges of the pages.
    CGRect pageViewRect = self.view.bounds;
    if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad) {
        pageViewRect = CGRectInset(pageViewRect, 40.0, 40.0);
    }
    self.pageViewController.view.frame = pageViewRect;
    
    [self.pageViewController didMoveToParentViewController:self];
    
    self.pageViewController.dataSource = self;
    self.pageViewController.delegate   = self;
    
    self.view.gestureRecognizers = self.pageViewController.gestureRecognizers;
    
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
                
                
                if([item.status isEqualToString:@"LAUNCH_WAIT"])
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
        
        
        if([item.status isEqualToString:@"LAUNCH_WAIT"])
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
                          @"LAUNCH_WAIT",
                          nil];
    
    //plotItem.aGraphView = self;
    detailItem = plotItem;
    [detailItem renderInView:hostingView withTheme:[CPTTheme themeNamed:@"None"]];
    [scrollView addSubview:hostingView];
    scrollView.contentSize = CGSizeMake(hostingView.frame.size.width, hostingView.frame.size.height);
    

}

-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender

{
    if ([[segue identifier] isEqualToString:@"seguejoblist"])
    {
        jobruns *jobRunsController = [segue destinationViewController];
        
        jobRunsController.executionList = executionList;
        jobRunsController.launchList    = launchList;
        jobRunsController.filterStatus  = filterStatus;
        jobRunsController.theNode       = nodeName;
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
