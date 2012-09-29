//
//  graphview.h
//  DUiOS
//
//  Created by Hervé Azoulay on 25/02/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "settings.h"
#import "CorePlot-CocoaTouch.h"
#import "PlotGallery.h"
#import "PlotItem.h"
//#import "SimplePieChart.h"


@interface graphview : UIViewController<UIPageViewControllerDelegate,UIPageViewControllerDataSource> {
        
    	PlotItem *detailItem;
    	IBOutlet UIScrollView *scrollView;
        IBOutlet UIView *hostingView;
    
}

@property (nonatomic, retain) PlotItem *detailItem;
@property (nonatomic, retain) NSString *nodeName;
@property (nonatomic, retain) NSString *filterStatus;
@property (nonatomic, retain) NSMutableArray *executionList;
@property (nonatomic, retain) NSMutableArray *launchList;

@property (strong, nonatomic) UIPageViewController *pageViewController;

@end