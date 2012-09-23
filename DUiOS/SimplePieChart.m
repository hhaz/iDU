//
//  SimplePieChart.m
//  CorePlotGallery
//
//  Created by Jeff Buck on 8/2/10.
//  Copyright 2010 Jeff Buck. All rights reserved.
//

#import "SimplePieChart.h"
#import "jobruns.h"

@implementation SimplePieChart
@synthesize plotData;
@synthesize plotLegend;
@synthesize plotColor;
@synthesize aGraphView;
@synthesize plotStatus;
@synthesize selectedIndex;
@synthesize layerView;
@synthesize pie;


+(void)load
{
	[super registerPlotItem:self];
}

-(id)init
{
	if ( (self = [super init]) ) {
		//title = @"Simple Pie Chart";
	}

	return self;
}

-(void)killGraph
{
	[super killGraph];
}

-(void)dealloc
{

}

-(void)generateData
{
}

-(void)renderInLayer:(CPTGraphHostingView *)layerHostingView withTheme:(CPTTheme *)theme
{
#if TARGET_IPHONE_SIMULATOR || TARGET_OS_IPHONE
	CGRect bounds = layerHostingView.bounds;
#else
	CGRect bounds = NSRectToCGRect(layerHostingView.bounds);
#endif

    layerView = layerHostingView;
    
	CPTGraph *graph = [[CPTXYGraph alloc] initWithFrame:bounds];
	[self addGraph:graph toHostingView:layerHostingView];
	[self applyTheme:theme toGraph:graph withDefault:[CPTTheme themeNamed:kCPTPlainWhiteTheme]];
    
    UIPinchGestureRecognizer *pinch = [[UIPinchGestureRecognizer alloc]initWithTarget:self action:@selector(pinch:)];
    
    [layerHostingView addGestureRecognizer:pinch];
    
    UITapGestureRecognizer *tap = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(handleTap:)];
    
    [layerHostingView addGestureRecognizer:tap];
    
    UISwipeGestureRecognizer *swipeDown =[[UISwipeGestureRecognizer alloc]initWithTarget:self action:@selector(handleSwipe:)];
    swipeDown.direction =UISwipeGestureRecognizerDirectionDown;    
    [layerHostingView addGestureRecognizer:swipeDown];
    
    UISwipeGestureRecognizer *swipeLeft =[[UISwipeGestureRecognizer alloc]initWithTarget:self action:@selector(handleSwipe:)];
    swipeLeft.direction =UISwipeGestureRecognizerDirectionLeft;    
    [layerHostingView addGestureRecognizer:swipeLeft];
    
	graph.title = title;
	CPTMutableTextStyle *textStyle = [CPTMutableTextStyle textStyle];
	textStyle.color				   = [CPTColor grayColor];
	textStyle.fontName			   = @"Helvetica-Bold";
	textStyle.fontSize			   = bounds.size.height / 40.0f;
	graph.titleTextStyle		   = textStyle;
	graph.titleDisplacement		   = CGPointMake(0.0f, bounds.size.height / 18.0f);
	graph.titlePlotAreaFrameAnchor = CPTRectAnchorTop;

	graph.plotAreaFrame.masksToBorder = YES;

	// Graph padding
	CGFloat boundsPadding = bounds.size.width / 20.0f;
	graph.paddingLeft	= boundsPadding;
    graph.paddingTop	= 5;
	graph.paddingRight	= boundsPadding;
    graph.paddingBottom = 50;

	graph.axisSet = nil;

	// Overlay gradient for pie chart
	CPTGradient *overlayGradient = [[CPTGradient alloc] init];
	overlayGradient.gradientType = CPTGradientTypeRadial;
	overlayGradient				 = [overlayGradient addColorStop:[[CPTColor blackColor] colorWithAlphaComponent:0.0] atPosition:0.0];
	overlayGradient				 = [overlayGradient addColorStop:[[CPTColor blackColor] colorWithAlphaComponent:0.3] atPosition:0.9];
	overlayGradient				 = [overlayGradient addColorStop:[[CPTColor blackColor] colorWithAlphaComponent:0.7] atPosition:1.0];

	// Add pie chart
	CPTPieChart *piePlot = [[CPTPieChart alloc] init];
	piePlot.dataSource = self;
	piePlot.pieRadius  = MIN(0.8 * (layerHostingView.frame.size.height - 2 * graph.paddingLeft) / 2.0,
							 0.8 * (layerHostingView.frame.size.width - 2 * graph.paddingTop) / 2.0);
	piePlot.identifier	   = title;
	piePlot.startAngle	   = M_PI_4;
	piePlot.sliceDirection = CPTPieDirectionCounterClockwise;
	piePlot.overlayFill	   = [CPTFill fillWithGradient:overlayGradient];

	piePlot.delegate = self;
	[graph addPlot:piePlot];
    
    pie = piePlot;

	// Add legend
	CPTLegend *theLegend = [CPTLegend legendWithGraph:graph];
	theLegend.numberOfColumns = 4;
	theLegend.fill			  = [CPTFill fillWithColor:[CPTColor whiteColor]];
	theLegend.borderLineStyle = [CPTLineStyle lineStyle];
	theLegend.cornerRadius	  = 5.0;

    CPTMutableTextStyle *textStyleLegend    = [CPTMutableTextStyle textStyle];
	textStyleLegend.color                   = [CPTColor blackColor];
	textStyleLegend.fontName                = @"Helvetica";
	textStyleLegend.fontSize                = bounds.size.height / 50.0f;
    theLegend.textStyle                     = textStyleLegend;

	graph.legend = theLegend;

	graph.legendAnchor		 = CPTRectAnchorCenter;
    graph.legendDisplacement = CGPointMake(0, bounds.size.height / 2.5 + 20);
    
}

- (void)pinch:(UIPinchGestureRecognizer *)pinchRecognizer {
    
    pie.pieRadius = pie.pieRadius * pinchRecognizer.scale;
    
    if (pinchRecognizer.state == UIGestureRecognizerStateBegan) {
        
          pie.pieRadius = pie.pieRadius * pinchRecognizer.scale;
    }
    else {
        if (pinchRecognizer.state == UIGestureRecognizerStateChanged) {
              pie.pieRadius = pie.pieRadius * pinchRecognizer.scale;
        }
        else if ((pinchRecognizer.state == UIGestureRecognizerStateCancelled) || (pinchRecognizer.state == UIGestureRecognizerStateEnded)) {
           
        }
    }
    
}


- (void)handleTap:(UITapGestureRecognizer *)gesture {
    if (gesture.state == UIGestureRecognizerStateEnded) {
        
        aGraphView.filterStatus = [plotStatus objectAtIndex:selectedIndex];
        [aGraphView performSegueWithIdentifier:@"seguejoblist" sender:self];
    }
}

- (void)handleSwipe:(UISwipeGestureRecognizer *)recognizer 
{ 
    if(recognizer.direction == UISwipeGestureRecognizerDirectionDown)
    {
        NSLog(@"Swipe Down");
        NSMutableArray *newPlot = [[NSMutableArray alloc]initWithCapacity:plotData.count];
        
        for(int i = 0 ; i < plotData.count ; i++)
        {
            if (i != selectedIndex)
            {
                [newPlot addObject:[plotData objectAtIndex:i]];
            }
            else {
                [newPlot addObject:[NSNumber numberWithInt:0]];
            }
        }
        
        plotData = newPlot;
        
        CPTGraph *graph = [graphs objectAtIndex:0];
        
        [graph reloadData];
    }
    else {
        NSLog(@"Swipe Right");
        aGraphView.filterStatus = [plotStatus objectAtIndex:selectedIndex];
        [aGraphView performSegueWithIdentifier:@"seguejoblist" sender:self];
    }
}


-(CPTLayer *)dataLabelForPlot:(CPTPlot *)plot recordIndex:(NSUInteger)index
{
	static CPTMutableTextStyle *whiteText = nil;

	if ( !whiteText ) {
		whiteText		= [[CPTMutableTextStyle alloc] init];
		whiteText.color = [CPTColor blackColor];
	}

	CPTTextLayer *newLayer = [[CPTTextLayer alloc] initWithText:[NSString stringWithFormat:@"%3.0f", [[plotData objectAtIndex:index] floatValue]] style:whiteText];
	return newLayer;
}

-(void)pieChart:(CPTPieChart *)plot sliceWasSelectedAtRecordIndex:(NSUInteger)index
{
	NSLog(@"Slice was selected at index %d. Value = %f", (int)index, [[plotData objectAtIndex:index] floatValue]);
    selectedIndex = index;
}

-(CPTFill *)sliceFillForPieChart:(CPTPieChart *)pieChart recordIndex:(NSUInteger)index
{
    CPTFill *color = [[CPTFill alloc] initWithColor:[plotColor objectAtIndex:index]];
    
    return color;
  
}

#pragma mark -
#pragma mark Plot Data Source Methods

-(NSUInteger)numberOfRecordsForPlot:(CPTPlot *)plot
{
	return [plotData count];
}

-(NSNumber *)numberForPlot:(CPTPlot *)plot field:(NSUInteger)fieldEnum recordIndex:(NSUInteger)index
{
	NSNumber *num;

	if ( fieldEnum == CPTPieChartFieldSliceWidth ) {
		num = [plotData objectAtIndex:index];
	}
	else {
		return [NSNumber numberWithInt:index];
	}

	return num;
}

-(NSString *)legendTitleForPieChart:(CPTPieChart *)pieChart recordIndex:(NSUInteger)index
{
	return [plotLegend objectAtIndex:index];
}

@end
