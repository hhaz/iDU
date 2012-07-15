//
//  graphview.h
//  DUiOS
//
//  Created by Hervé Azoulay on 25/02/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "settings.h"
#import "CorePlot-CocoaTouch.h"
#import "PlotGallery.h"
#import "PlotItem.h"
#import "duiosFirstViewController.h"


@interface graphview : UIViewController {
    
    	PlotItem *detailItem;
    	UIScrollView *hostingView;
    
}

@property (nonatomic, retain) PlotItem *detailItem;
@property (nonatomic, retain) NSString *bindingAddress;
@property (nonatomic, retain) DuWebServiceSvc_contextHolder *theContext;
@property (nonatomic, retain) IBOutlet UIScrollView *hostingView;
@property (nonatomic, retain) NSArray *data;
@property (nonatomic, retain) NSString *nodeName;
@property (retain) IBOutlet duiosFirstViewController *aFirstController;
@property (nonatomic, retain) NSString *filterStatus;
@end