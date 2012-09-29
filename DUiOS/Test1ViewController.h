//
//  Test1ViewController.h
//  iDU
//
//  Created by Hervé AZOULAY on 29/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "graphview.h"
#import "DuWebServiceSvc.h"
#import "iDUAppDelegate.h"
#import "PlotItem.h"
#import "jobruns.h"

@interface Test1ViewController : UIViewController
{
    IBOutlet UIScrollView *scrollView;
    IBOutlet UIView *hostingView;

}

@property (nonatomic,retain) UIScrollView *scrollView;;
@property (nonatomic,retain) UIView *hostingView;
@property (strong, nonatomic) id dataObject;

@property (nonatomic, retain) PlotItem *detailItem;
@property (nonatomic, retain) NSMutableArray *plotData;
@property (nonatomic, retain) NSMutableArray *plotLegend;
@property (nonatomic, retain) NSMutableArray *plotColor;
@property (nonatomic, retain) NSMutableArray *plotStatus;

@property (nonatomic, retain) NSMutableArray *executionList;
@property (nonatomic, retain) NSMutableArray *launchList;
@property (nonatomic, retain) NSString *nodeName;
@property (nonatomic, retain) NSString *filterStatus;

@end
