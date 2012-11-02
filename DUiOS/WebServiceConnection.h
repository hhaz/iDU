//
//  WebServiceConnection.h
//  DUiOS
//
//  Created by Hervé Azoulay on 09/06/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "DuWebServiceSvc.h"

@protocol WebServiceConnection
-(void)connectionStatus;
@end

@interface WebServiceConnection : UIViewController <UITextViewDelegate> {
        
}

@property (nonatomic, retain) DuWebServiceSvc_contextHolder *theContext;
@property (nonatomic, retain) NSString *bindingAddress;
@property (nonatomic, retain) UITableView *myNodeView;;


-(void)TryConnection:(UITableView *)nodeView delegate:(id<WebServiceConnection>)responseDelegate;
-(void)connect:(NSString *)user:(NSString *)password delegate:(id<WebServiceConnection>)responseDelegate;

@end
