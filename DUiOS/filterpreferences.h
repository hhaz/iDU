//
//  filterpreferences.h
//  DUiOS
//
//  Created by Hervé Azoulay on 02/06/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface filterpreferences : UITableViewController<UINavigationBarDelegate, UITableViewDelegate, UITableViewDataSource,UIPickerViewDelegate,UIPickerViewDataSource> {
    
    IBOutlet UITableView *theSettings;
    
    IBOutlet UITextField *periods;
    IBOutlet UITextField *nbPeriods;
    IBOutlet UITextField *nbJobs;
    
    IBOutlet UIPickerView  *picker;
    
    NSMutableDictionary *ivContentsList;
    NSMutableArray *ivSectionKeys;
}

@property (nonatomic, retain) NSMutableDictionary *contentsList;
@property (nonatomic, retain) IBOutlet UITableView *myTableView;
@property (nonatomic, retain) NSMutableArray *sectionKeys;
@property (nonatomic, retain) NSMutableArray *arrayPeriods;
@property (nonatomic, retain) UITextField *activeTextField;

@end
