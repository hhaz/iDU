//
//  jobruns.h
//  DUiOS
//
//  Created by Hervé Azoulay on 30/01/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "iDUFirstViewController.h"
#import "graphview.h"
#import "SectionHeaderView.h"

@protocol jobruns;

@interface jobruns : UITableViewController <UINavigationBarDelegate, UITableViewDelegate, UITableViewDataSource,SectionHeaderViewDelegate,DuWebServiceSoapBindingResponseDelegate> {
    
    id<jobruns> delegate;
    IBOutlet UITableView *theLaunches;    
}

@property (nonatomic, retain) NSArray *nodeList;
@property (nonatomic, retain) IBOutlet UITableView *myTableView;
@property (nonatomic, retain) NSMutableArray *launchList;
@property (nonatomic, retain) NSMutableArray *executionList;
@property (nonatomic, retain) NSString *theLog;
@property (nonatomic, retain) DuWebServiceSvc_executionItem *currentJob;
@property (nonatomic, retain) DuWebServiceSvc_launchItem *currentLaunch;
@property (nonatomic, retain) NSMutableArray *filteredExecutionList;
@property (nonatomic, retain) NSMutableArray *filteredLaunchList;
@property (nonatomic, retain) NSString *filterStatus;
@property (nonatomic, retain) NSMutableDictionary *contentsList;
@property (nonatomic, retain) NSMutableArray *sectionKeys;
@property (nonatomic, retain) iDUAppDelegate *appDelegate;
@property (nonatomic, strong) NSMutableArray* sectionInfoArray;
@property (nonatomic, assign) NSInteger openSectionIndex;
@property (nonatomic, assign) NSInteger uniformRowHeight;

@end
