//
//  joblog.h
//  DUiOS
//
//  Created by Hervé Azoulay on 18/02/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "jobruns.h"
#import "DuWebServiceSvc.h"

@interface joblog : UIViewController <UINavigationBarDelegate,UITableViewDelegate,UITableViewDataSource> {
    
}
@property (nonatomic, retain) NSString *theLog;
@property (nonatomic, retain) IBOutlet UITableView *myTableView;
@property (nonatomic, retain) NSMutableDictionary *contentsList;
@property (nonatomic, retain) NSMutableArray *sectionKeys;
@property (nonatomic, retain) DuWebServiceSvc_executionItem *currentJob;
@property (nonatomic, retain) DuWebServiceSvc_launchItem *currentLaunch;


@property (nonatomic, retain) NSString *uprocName;
@property (nonatomic, retain) NSString *uprocNum;
@property (nonatomic, retain) NSString *uprocVersion;
@property (nonatomic, retain) NSString *session;
@property (nonatomic, retain) NSString *sessionVersion;
@property (nonatomic, retain) NSString *beginDate;
@property (nonatomic, retain) NSString *endDate;
@property (nonatomic, retain) NSString *uprocStatus;
@property (nonatomic, retain) NSString *numLaunc;
@property (nonatomic, retain) NSString *beginHour;
@property (nonatomic, retain) NSString *endHour;

@end
