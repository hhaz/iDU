//
//  webservicedetails.h
//  DUiOS
//
//  Created by Hervé Azoulay on 04/02/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "settings.h"

@interface webservicedetails : UITableViewController <UINavigationBarDelegate, UITableViewDelegate, UITableViewDataSource> {
    
    NSMutableDictionary *ivContentsList;
    NSMutableArray *ivSectionKeys;
    
    IBOutlet UITextField *theURL;
    IBOutlet UITextField *theSuffix;
    
    NSString *WSURL;
}

// Properties
@property (nonatomic, retain) NSMutableDictionary *contentsList;
@property (nonatomic, retain) IBOutlet UITableView *myTableView;
@property (nonatomic, retain) NSMutableArray *sectionKeys;
@property (retain) IBOutlet settings *aSettings;


@end
