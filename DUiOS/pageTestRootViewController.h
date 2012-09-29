//
//  pageTestRootViewController.h
//  PageTest
//
//  Created by Hervé AZOULAY on 28/09/12.
//  Copyright (c) 2012 Hervé AZOULAY. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "pageTestModelController.h"

@interface pageTestRootViewController : UIViewController <UIPageViewControllerDelegate>

@property (strong, nonatomic) UIPageViewController *pageViewController;

@property (readonly, strong, nonatomic) pageTestModelController *modelController;


@end
