//
//  SimplePieChart.h
//  CorePlotGallery
//
//  Created by Jeff Buck on 8/2/10.
//  Copyright 2010 Jeff Buck. All rights reserved.
//

#import "PlotItem.h"
#import "Test1ViewController.h"


@interface SimplePieChart : PlotItem<CPTPlotSpaceDelegate,
									 CPTPlotDataSource,UIGestureRecognizerDelegate>
{
	NSArray *plotData;
}
@property (nonatomic, retain) NSArray *plotData;
@property (nonatomic, retain) NSArray *plotLegend;
@property (nonatomic, retain) NSArray *plotColor;
@property (nonatomic, retain) NSArray *plotStatus;
@property (nonatomic, retain) Test1ViewController *aGraphView;
@property (nonatomic, retain) CPTGraphHostingView *layerView;

@property (nonatomic) NSUInteger selectedIndex;
@property (nonatomic,retain) CPTPieChart *pie;

@property (nonatomic, retain) NSMutableArray *executionList;
@property (nonatomic, retain) NSMutableArray *launchList;
@property (nonatomic, retain) NSString *nodeName;


@end
