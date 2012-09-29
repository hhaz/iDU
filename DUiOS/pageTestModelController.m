//
//  pageTestModelController.m
//  PageTest
//
//  Created by Hervé AZOULAY on 28/09/12.
//  Copyright (c) 2012 Hervé AZOULAY. All rights reserved.
//

#import "pageTestModelController.h"

#import "Test1ViewController.h"
#import "SimplePieChart.h"
#import "ColoredBarChart.h"
#import "DuWebServiceSvc.h"


@interface pageTestModelController()
@property (readonly, strong, nonatomic) NSArray *pageData;
@end

@implementation pageTestModelController
@synthesize plotColor,plotData,plotLegend,plotStatus,executionList,nodeName,launchList;

- (id)init
{
    self = [super init];
    if (self) {
        
        // Create the data model.
        
        SimplePieChart *plotItem1 = (SimplePieChart *)[[PlotGallery sharedPlotGallery] objectAtIndex:0];
        ColoredBarChart *plotItem2 = (ColoredBarChart *)[[PlotGallery sharedPlotGallery] objectAtIndex:1];
        _pageData = @[plotItem1,plotItem2];
    }
    return self;
}

- (Test1ViewController *)viewControllerAtIndex:(NSUInteger)index storyboard:(UIStoryboard *)storyboard
{   
    // Return the data view controller for the given index.
    if (([self.pageData count] == 0) || (index >= [self.pageData count])) {
        return nil;
    }
    
    NSInteger nbOK          = 0;
    NSInteger nbOverrun     = 0;
    NSInteger nbEventWait   = 0;
    NSInteger nbAborted     = 0;
    NSInteger nbRefused     = 0;
    NSInteger nbPending     = 0;
    NSInteger nbRunning     = 0;
    NSInteger nbLaunchWait  = 0;
    
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
    
    plotData = [[NSMutableArray alloc] initWithObjects:
                [NSNumber numberWithDouble:nbOK],
                [NSNumber numberWithDouble:nbOverrun],
                [NSNumber numberWithDouble:nbEventWait],
                [NSNumber numberWithDouble:nbAborted],
                [NSNumber numberWithDouble:nbRefused],
                [NSNumber numberWithDouble:nbPending],
                [NSNumber numberWithDouble:nbRunning],
                [NSNumber numberWithDouble:nbLaunchWait],
                nil];
    
    plotLegend= [[NSMutableArray alloc] initWithObjects:
                 @"Success",
                 @"Time Overrun",
                 @"Event Wait",
                 @"Aborted",
                 @"Refused",
                 @"Pending",
                 @"Running",
                 @"Launch Wait",
                 nil];
    
    plotColor = [[NSMutableArray alloc] initWithObjects:
                 [CPTColor greenColor],
                 [CPTColor orangeColor],
                 [CPTColor blueColor],
                 [CPTColor redColor],
                 [CPTColor brownColor],
                 [CPTColor yellowColor],
                 [CPTColor cyanColor],
                 [CPTColor purpleColor],
                 nil];
    plotStatus= [[NSMutableArray alloc] initWithObjects:
                 @"COMPLETED",
                 @"TIME_OVERRUN",
                 @"EVENT_WAIT",
                 @"ABORTED",
                 @"REFUSED",
                 @"PENDING",
                 @"RUNNING",
                 @"LAUNCH_WAIT",
                 nil];
    
    // Create a new view controller and pass suitable data.
    Test1ViewController *dataViewController = [storyboard instantiateViewControllerWithIdentifier:@"Test1"];
    
    dataViewController.dataObject   = self.pageData[index];
    
    dataViewController.plotColor    = plotColor;
    dataViewController.plotData     = plotData;
    dataViewController.plotLegend   = plotLegend;
    dataViewController.plotStatus   = plotStatus;
    
    dataViewController.executionList = executionList;
    dataViewController.launchList = launchList;
    dataViewController.nodeName = nodeName;
    return dataViewController;
}



- (NSUInteger)indexOfViewController:(Test1ViewController *)viewController
{
     // Return the index of the given data view controller.
     // For simplicity, this implementation uses a static array of model objects and the view controller stores the model object; you can therefore use the model object to identify the index.
    return [self.pageData indexOfObject:viewController.dataObject];
}

#pragma mark - Page View Controller Data Source

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerBeforeViewController:(UIViewController *)viewController
{
    NSUInteger index = [self indexOfViewController:(Test1ViewController *)viewController];
    if ((index == 0) || (index == NSNotFound)) {
        return nil;
    }
    
    index--;
    return [self viewControllerAtIndex:index storyboard:viewController.storyboard];
}

- (UIViewController *)pageViewController:(UIPageViewController *)pageViewController viewControllerAfterViewController:(UIViewController *)viewController
{
    NSUInteger index = [self indexOfViewController:(Test1ViewController *)viewController];
    if (index == NSNotFound) {
        return nil;
    }
    
    index++;
    if (index == [self.pageData count]) {
        return nil;
    }
    return [self viewControllerAtIndex:index storyboard:viewController.storyboard];
}

@end
