//
//  SettingsViewController.h
//  iDU
//
//  Created by Hervé AZOULAY on 19/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DuWebServiceSvc.h"
#import "WebServiceConnection.h"
#import "iDUAppDelegate.h"

@protocol SettingsViewController;

@interface SettingsViewController : UITableViewController<UINavigationBarDelegate, UITableViewDelegate, UITableViewDataSource,UIPickerViewDelegate,UIPickerViewDataSource> {
    
    id<SettingsViewController> delegate;
    IBOutlet UITableView *theSettings;
    
    IBOutlet UITextField *theUserName;
    IBOutlet UITextField *theURL;
    IBOutlet UITextField *theToken;
    IBOutlet UITextField *theUVMS;
    IBOutlet UITextField *thePort;
    IBOutlet UITextField *theCompany;
    IBOutlet UILabel *theTokenLabel;
    IBOutlet UITextField *theSpace;
    IBOutlet UITextField *theTokenDevice;
    IBOutlet UITextField *connectionStatus;
    
    NSMutableDictionary *ivContentsList;
    NSMutableArray *ivSectionKeys;
    
}

@property (nonatomic, retain) NSMutableArray *arrayArea;
@property (nonatomic, retain) UIPickerView *picker;
@property (nonatomic, retain) UITextField *activeTextField;
@property (nonatomic, retain) DuWebServiceSvc_contextHolder *theContext;
@property (nonatomic, retain) NSString *WSURL;
@property (nonatomic, retain) NSString *WSSuffix;
@property (nonatomic, retain) WebServiceConnection *connection;

-(IBAction)removeKeyBoard:(id)sender;

@end
