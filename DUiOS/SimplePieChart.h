//
//  SimplePieChart.h
//  CorePlotGallery
//
//  Created by Jeff Buck on 8/2/10.
//  Copyright 2010 Jeff Buck. All rights reserved.
//

#import "PlotItem.h"
#import "graphview.h"


@interface SimplePieChart : PlotItem<CPTPlotSpaceDelegate,
									 CPTPlotDataSource,UIGestureRecognizerDelegate>
{
	NSArray *plotData;
}
@property (nonatomic, retain) NSArray *plotData;
@property (nonatomic, retain) NSArray *plotLegend;
@property (nonatomic, retain) NSArray *plotColor;
@property (nonatomic, retain) NSArray *plotStatus;
@property (nonatomic, retain) graphview *aGraphView;
@property (nonatomic, retain) CPTGraphHostingView *layerView;

@property (nonatomic) NSUInteger selectedIndex;

@end
