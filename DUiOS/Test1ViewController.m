//
//  Test1ViewController.m
//  iDU
//
//  Created by Hervé AZOULAY on 29/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import "Test1ViewController.h"
#import "SimplePieChart.h"
#import "ColoredBarChart.h"
#import "jobruns.h"

@interface Test1ViewController ()

@end

@implementation Test1ViewController
@synthesize hostingView,scrollView,detailItem,plotColor,plotData,plotLegend,plotStatus,executionList,launchList,nodeName,filterStatus;


- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    if([self.dataObject isKindOfClass:[SimplePieChart class]])
    {
    
        SimplePieChart *plotItem = (SimplePieChart *)self.dataObject;
    
        plotItem.plotLegend = plotLegend;
        plotItem.plotStatus = plotStatus;
        plotItem.plotData   = plotData;
        plotItem.plotColor  = plotColor;
        plotItem.aGraphView = self;
        [plotItem renderInView:hostingView withTheme:[CPTTheme themeNamed:@"None"]];
    }
    else
    {
        ColoredBarChart *plotItem = (ColoredBarChart *)self.dataObject;
        plotItem.plotLegend = plotLegend;
        plotItem.plotStatus = plotStatus;
        plotItem.plotData   = plotData;
        plotItem.plotColor  = plotColor;
        [plotItem renderInView:hostingView withTheme:[CPTTheme themeNamed:@"None"]];
    }
    

    [scrollView addSubview:hostingView];
    scrollView.contentSize = CGSizeMake(hostingView.frame.size.width, hostingView.frame.size.height);
   
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender

{
    if ([[segue identifier] isEqualToString:@"segueJob2"])
    {
        jobruns *jobRunsController = [segue destinationViewController];
        
        jobRunsController.executionList = executionList;
        jobRunsController.launchList    = launchList;
        jobRunsController.filterStatus  = filterStatus;
        jobRunsController.theNode       = nodeName;
    }
    
}

@end
