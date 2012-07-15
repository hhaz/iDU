//
//  WebServiceConnection.h
//  DUiOS
//
//  Created by Hervé Azoulay on 09/06/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DuWebServiceSvc.h"
#import "duiosAppDelegate.h"

@protocol WebServiceConnection;



@interface WebServiceConnection : UIViewController <UITextViewDelegate> {
    
    
}

@property (nonatomic, retain) DuWebServiceSvc_contextHolder *theContext;
@property (nonatomic, retain) NSString *bindingAddress;
@property (nonatomic, retain) UITableView *myNodeView;;
@property (nonatomic, retain) duiosAppDelegate *appDelegate;

-(void)TryConnection:(UITableView *)nodeView;

@end
