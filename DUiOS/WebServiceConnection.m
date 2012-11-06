//
//  WebServiceConnection.m
//  DUiOS
//
//  Created by Hervé Azoulay on 09/06/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "WebServiceConnection.h"
#import "DuWebServiceSvc.h"
#import "iDUAppDelegate.h"
#import "ActivityAlertView.h"

@implementation WebServiceConnection
@synthesize bindingAddress,theContext,myNodeView;

-(void)connect:(NSString *)user:(NSString *)password delegate:(id<WebServiceConnection>)responseDelegate
{
    [UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
    
    // Check connection values
    NSString *incorrectField = [[NSString alloc] init];
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    incorrectField = @"";
    
    bindingAddress = [NSString stringWithFormat:@"%@", [NSString stringWithFormat:@"%@%@", appDelegate.url , appDelegate.suffix]];
    
    
    if([appDelegate.uvmsHost isEqualToString:@""] || [appDelegate.uvmsHost length] ==0)
    {
        incorrectField = @"UVMS";
    }
    
    if([appDelegate.uvmsPort isEqualToString:@""] || [appDelegate.uvmsPort length] ==0)
    {
        incorrectField = @"UVMS Port";
    }
    
    if([appDelegate.company isEqualToString:@""] || [appDelegate.company length] ==0)
    {
        incorrectField = @"Company";
    }
    
    if([appDelegate.area isEqualToString:@""] || [appDelegate.area length] ==0)
    {
        incorrectField = @"Area";
    }
    
    if (incorrectField != nil && incorrectField != @"")
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Connection Error" message:[NSString stringWithFormat:@"%@%@",incorrectField, @" cannot be empty"] delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
        return;
    }
    
    appDelegate.binding = [[DuWebServiceSvc DuWebServiceSoapBinding] initWithAddress:bindingAddress];
    appDelegate.binding.logXMLInOut = YES;
    
    DuWebServiceSvc_uvmsContext *uvmsContext = [[DuWebServiceSvc_uvmsContext alloc] init];
    
    uvmsContext.uvmsHost        = appDelegate.uvmsHost;
    uvmsContext.uvmsUser        = user;
    uvmsContext.uvmsPassword    = password;
    
    uvmsContext.uvmsPort = [NSNumber numberWithInteger:[appDelegate.uvmsPort integerValue ]];
    
    DuWebServiceSvc_login *login = [[DuWebServiceSvc_login alloc] init];
    login.uvms = uvmsContext;
    
    DuWebServiceSvc_loginResponse *loginResponse = [[DuWebServiceSvc_loginResponse alloc] init];
    DuWebServiceSoapBindingResponse *response = [appDelegate.binding loginUsingParameters:login];
    
    if (response.error == 0) {
        @try {
            loginResponse = (DuWebServiceSvc_loginResponse *)([response.bodyParts objectAtIndex:0]);
            NSString *token = loginResponse.token;
             appDelegate.isConnected = TRUE;
            NSLog(@"Token : %@", token);
        }
        @catch (NSException *excep) {
            NSLog(@"Exception during connection");

            appDelegate.isConnected = FALSE;
            SOAPFault *result = (SOAPFault *)[response.bodyParts objectAtIndex:0];
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
            [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
            return;
        }
        @finally {
            NSLog(@"Finally connection");
        }
    }
    else
    {
        appDelegate.isConnected = FALSE;
        
        NSString *errorMessage = [NSString stringWithFormat:@"%@%@%@", [NSString stringWithFormat:@"%d",response.error.code], @" : ", response.error.localizedDescription];
        
        UIAlertView *connectionError = [[UIAlertView alloc] initWithTitle:@"Error" message:errorMessage delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [connectionError show];
        return;
    }
    
    appDelegate.isConnected = TRUE;
    
    DuWebServiceSvc_context *context = [[DuWebServiceSvc_context alloc] init];
    DuWebServiceSvc_envir *environment = [[DuWebServiceSvc_envir alloc] init];
    DuWebServiceSvc_contextHolder *ctxHolder = [[DuWebServiceSvc_contextHolder alloc] init];
    
    environment.company     = appDelegate.company;
    environment.area        = appDelegate.area;
    
    context.envir           = environment;
    ctxHolder.context       = context;
    ctxHolder.token         = loginResponse.token;
    
    appDelegate.theContext  = ctxHolder;
    
  	[responseDelegate connectionStatus];
     
    // Refresh node list
  
    
    [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
    
 
}

-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
      switch (alertView.tag) {
        case 1: // Try to connect to the Web Service
        if (buttonIndex == 1)
        {
            // Show the alert
            ActivityAlertView *activityAlert = [[ActivityAlertView alloc]
                                                 initWithTitle:@"Connecting"
                                                 message:@"Please wait..."
                                                 delegate:nil cancelButtonTitle:nil
                                                 otherButtonTitles:nil];                                    
            [activityAlert show];
            [UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
            
                      
            UITextField *username = [alertView textFieldAtIndex:0];
            UITextField *password = [alertView textFieldAtIndex:1];
            
            [self connect:username.text :password.text delegate:(id)self];
            
            [activityAlert close];
            
        }
        break;

        case 2: // Connection failed display the login window again
            if (alertView.tag == 2) {
                [self TryConnection:myNodeView delegate:(id)self];
            }
            break;
    }
}

-(void)connectionStatus
{
    return;
}

-(void)TryConnection:(UITableView *)nodeView delegate:(id<WebServiceConnection>)responseDelegate
{
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    UIAlertView *messageBox = [[UIAlertView alloc] initWithTitle:@"Login" message:@"Enter UVMS User & Password" delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"OK", nil];
    messageBox.tag = 1;
    messageBox.alertViewStyle = UIAlertViewStyleLoginAndPasswordInput;
    
    UITextField *username = [messageBox textFieldAtIndex:0];
    
    username.text = appDelegate.uvmsUser;
    
    myNodeView = nodeView;
    
    [messageBox show];

}


@end
