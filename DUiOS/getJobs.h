//
//  getJobs.h
//  iDU
//
//  Created by Hervé AZOULAY on 16/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "iDUAppDelegate.h"
#import "DuWebServiceSvc.h"

@interface getJobs : UIView

@property (nonatomic, retain) iDUAppDelegate *appDelegate;

@property (nonatomic, retain) NSMutableArray *launchList;
@property (nonatomic, retain) NSMutableArray *executionList;


- (void) getJobs:(id)sender:(NSString *)node:(NSString *)segue:(Boolean)alert:(NSDate *)fromDate:(NSDate *)toDate;

@end
