//
//  duiosFirstViewController.h
//  DUiOS
//
//  Created by Hervé Azoulay on 28/01/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "settings.h"
#import "iDUAppDelegate.h"
#import "getJobs.h"

@protocol iDUFirstViewController;


@interface iDUFirstViewController : UIViewController <UINavigationBarDelegate, UITableViewDelegate, UITableViewDataSource> {
    
    id<iDUFirstViewController> delegate;
    IBOutlet UITableView *theNodes;
    IBOutlet UISwitch *switchControl;
    UIRefreshControl *refresh;

}
@property (nonatomic, retain) NSArray *nodeList;
@property (nonatomic, retain) NSMutableArray *launchList;
@property (nonatomic, retain) IBOutlet UITableView *myTableView;
@property (nonatomic, retain) NSMutableArray *executionList;
@property (nonatomic, retain) NSString *theNode;
@property (nonatomic, retain) NSString *theLog;
@property (nonatomic, retain) iDUAppDelegate *appDelegate;
@property (nonatomic, retain) getJobs *retrieveJobs;

@property (nonatomic, retain) DuWebServiceSvc_executionItem *job;

@end
