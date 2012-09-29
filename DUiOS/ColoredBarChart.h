#import "PlotItem.h"

@interface ColoredBarChart : PlotItem<CPTPlotSpaceDelegate,
									  CPTPlotDataSource,
									  CPTBarPlotDelegate>
{
	NSArray *plotData;
}

@property (nonatomic, retain) NSArray *plotData;
@property (nonatomic, retain) NSArray *plotLegend;
@property (nonatomic, retain) NSArray *plotColor;
@property (nonatomic, retain) NSArray *plotStatus;

@end
