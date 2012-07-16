//
//  duiosAppDelegate.h
//  DUiOS
//
//  Created by Hervé Azoulay on 28/01/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DuWebServiceSvc.h"

@interface duiosAppDelegate : UIResponder <UIApplicationDelegate>
{
    UINavigationController	*navigationController;
    UIWindow				*window;
}

@property (strong, nonatomic) UIWindow *window;
@property (nonatomic, retain) IBOutlet UINavigationController *navigationController;
@property (nonatomic, retain) DuWebServiceSoapBinding *binding;

@property (nonatomic, retain) NSString *uvmsHost;
@property (nonatomic, retain) NSString *uvmsUser;
@property (nonatomic, retain) NSString *uvmsPort;
@property (nonatomic, retain) NSString *company;
@property (nonatomic, retain) NSString *area;
@property (nonatomic, retain) NSString *url;
@property (nonatomic, retain) NSString *suffix;
@property (nonatomic, retain) NSString *period;
@property (nonatomic, retain) NSString *nbPeriods;
@property (nonatomic, retain) NSString *nbJobs;
@property (nonatomic) Boolean isConnected;
@property (nonatomic, retain) DuWebServiceSvc_contextHolder *theContext;
@property (nonatomic, retain) NSMutableArray *periodArray;

@property (nonatomic, retain) NSArray *nodeList;

@property (nonatomic, retain) NSMutableDictionary *contentStatus;
@property (nonatomic, retain) NSMutableArray *statusKeys;
@property (nonatomic, retain) UITabBarController *tbController;

@end
