//
//  pageTestModelController.h
//  PageTest
//
//  Created by Hervé AZOULAY on 28/09/12.
//  Copyright (c) 2012 Hervé AZOULAY. All rights reserved.
//

#import <UIKit/UIKit.h>

@class Test1ViewController;

@interface pageTestModelController : UIViewController <UIPageViewControllerDataSource>

@property (nonatomic, retain) NSMutableArray *plotData;
@property (nonatomic, retain) NSMutableArray *plotLegend;
@property (nonatomic, retain) NSMutableArray *plotColor;
@property (nonatomic, retain) NSMutableArray *plotStatus;

@property (nonatomic, retain) NSMutableArray *executionList;
@property (nonatomic, retain) NSMutableArray *launchList;
@property (nonatomic, retain) NSString *nodeName;

- (Test1ViewController *)viewControllerAtIndex:(NSUInteger)index storyboard:(UIStoryboard *)storyboard;
- (NSUInteger)indexOfViewController:(Test1ViewController *)viewController;

@end
