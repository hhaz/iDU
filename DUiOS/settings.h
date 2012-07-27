//
//  settings.h
//  DUiOS
//
//  Created by Hervé Azoulay on 04/02/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DuWebServiceSvc.h"
#import "WebServiceConnection.h"

@protocol settings;

@interface settings : UITableViewController <UINavigationBarDelegate, UITableViewDelegate, UITableViewDataSource,UIPickerViewDelegate,UIPickerViewDataSource> {
    
    id<settings> delegate;
    IBOutlet UITableView *theSettings;
    
    IBOutlet UITextField *theUserName;
    IBOutlet UITextField *theURL;
    IBOutlet UITextField *theToken;
    IBOutlet UITextField *theUVMS;
    IBOutlet UITextField *thePort;
    IBOutlet UITextField *theCompany;
    IBOutlet UILabel *theTokenLabel;
    IBOutlet UITextField *theSpace;
    UITableViewCell *connectionStatus;
    
    NSMutableDictionary *ivContentsList;
    NSMutableArray *ivSectionKeys;

}

// Properties
@property (nonatomic,retain) id <settings> delegate;
@property (nonatomic, retain) NSMutableDictionary *contentsList;
@property (nonatomic, retain) IBOutlet UITableView *myTableView;
@property (nonatomic, retain) NSMutableArray *sectionKeys;
@property (nonatomic, retain) NSMutableArray *arrayArea;
@property (nonatomic, retain) DuWebServiceSvc_contextHolder *theContext;
@property (nonatomic, retain) NSString *WSURL;
@property (nonatomic, retain) NSString *WSSuffix;
@property (nonatomic, retain) WebServiceConnection *connection;


@end
