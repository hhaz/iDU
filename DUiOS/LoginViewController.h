//
//  LoginViewController.h
//  iDU
//
//  Created by Hervé AZOULAY on 02/11/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WebServiceConnection.h"

@interface LoginViewController : UIViewController<WebServiceConnection>
{
    IBOutlet UIButton *loginButton;
    IBOutlet UITextField *user;
    IBOutlet UITextField *password;
}

@property IBOutlet UIButton *loginButton;
@property (nonatomic,retain) WebServiceConnection *connection;

- (IBAction)login;
-(IBAction)cancel;

@end
