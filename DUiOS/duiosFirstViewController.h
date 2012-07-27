//
//  duiosFirstViewController.h
//  DUiOS
//
//  Created by Hervé Azoulay on 28/01/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "settings.h"
#import "duiosAppDelegate.h"

@protocol duiosFirstViewController;


@interface duiosFirstViewController : UIViewController <UINavigationBarDelegate, UITableViewDelegate, UITableViewDataSource> {
    
    id<duiosFirstViewController> delegate;
    IBOutlet UITableView *theNodes;
    
    
}
@property (nonatomic, retain) NSArray *nodeList;
@property (nonatomic, retain) NSMutableArray *launchList;
@property (nonatomic, retain) IBOutlet UITableView *myTableView;
@property (retain) IBOutlet settings *aSecondController;
@property (nonatomic, retain) NSMutableArray *executionList;
@property (nonatomic, retain) NSString *theNode;
@property (nonatomic, retain) NSString *theLog;
@property (nonatomic, retain) duiosAppDelegate *appDelegate;

@property (nonatomic, retain) DuWebServiceSvc_executionItem *job;

@end
