//
//  WebServiceConnection.m
//  DUiOS
//
//  Created by Hervé Azoulay on 09/06/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import "WebServiceConnection.h"
#import "DuWebServiceSvc.h"
#import "duiosAppDelegate.h"
#import "ActivityAlertView.h"

@implementation WebServiceConnection
@synthesize bindingAddress,theContext,myNodeView,appDelegate;


-(void)alertView:(UIAlertView *)alertView clickedButtonAtIndex:(NSInteger)buttonIndex {
    
    switch (alertView.tag) {
        case 1: // Try to connect to the Web Service
        if (buttonIndex == 1)
        {           
            // Show the alert
            ActivityAlertView *activityAlert = [[[ActivityAlertView alloc] 
                                                 initWithTitle:@"Connecting"
                                                 message:@"Please wait..."
                                                 delegate:self cancelButtonTitle:nil 
                                                 otherButtonTitles:nil] autorelease];                                    
            [activityAlert show];
            
            // Check connection values
            NSString *incorrectField = [[NSString alloc] init];
            
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
                [activityAlert close];
                
                UIAlertView *alert = [[[UIAlertView alloc] initWithTitle:@"Connection Error" message:[NSString stringWithFormat:@"%@%@",incorrectField, @" cannot be empty"] delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil] autorelease];
                [alert show];
                return;
            }
            
            appDelegate.binding = [[DuWebServiceSvc DuWebServiceSoapBinding] initWithAddress:bindingAddress];
            appDelegate.binding.logXMLInOut = YES; 
            
            DuWebServiceSvc_uvmsContext *uvmsContext = [[DuWebServiceSvc_uvmsContext alloc] init];
            
            UITextField *username = [alertView textFieldAtIndex:0];
            UITextField *password = [alertView textFieldAtIndex:1];
            
            uvmsContext.uvmsHost        = appDelegate.uvmsHost;
            uvmsContext.uvmsUser        = username.text;
            uvmsContext.uvmsPassword    = password.text;
            
            uvmsContext.uvmsPort = [NSNumber numberWithInteger:[appDelegate.uvmsPort integerValue ]];
            
            DuWebServiceSvc_login *login = [[DuWebServiceSvc_login alloc] init];
            login.uvms = uvmsContext;
            
            DuWebServiceSvc_loginResponse *loginResponse = [[DuWebServiceSvc_loginResponse alloc] init];    
            DuWebServiceSoapBindingResponse *response = [appDelegate.binding loginUsingParameters:login];
            
            if (response.error == 0) {
                @try {
                    loginResponse = (DuWebServiceSvc_loginResponse *)([response.bodyParts objectAtIndex:0]);
                    NSString *token = loginResponse.token;
                    NSLog(@"Token : %@", token);
                }
                @catch (NSException *excep) {
                    NSLog(@"Exception during connection");
                    [activityAlert close];
                    appDelegate.isConnected = FALSE;
                    SOAPFault *result = (SOAPFault *)[response.bodyParts objectAtIndex:0];
                    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
                    alert.tag = 2;
                    [alert show];
                    return;
                }
                @finally {
                    NSLog(@"Finally connection");
                }                
            }
            else
            {
                [activityAlert close];
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
            
            environment.company = appDelegate.company;
            environment.area = appDelegate.area;
                    
            context.envir = environment;
            ctxHolder.context = context;
            ctxHolder.token = loginResponse.token;
            
            appDelegate.theContext = ctxHolder;
            
            
            DuWebServiceSvc_uvmsNodeFilter *nodeFilter = [[DuWebServiceSvc_uvmsNodeFilter alloc] init];
            nodeFilter.node_ = @"*";
            nodeFilter.company = environment.company;
            
            DuWebServiceSvc_getDUEnvironmentList *EnvirList = [[DuWebServiceSvc_getDUEnvironmentList alloc]init];
            EnvirList.token = ctxHolder.token;
            EnvirList.nodeFilter = nodeFilter;
            
            DuWebServiceSvc_getDUEnvironmentListResponse *EnvirListResponse = [[DuWebServiceSvc_getDUEnvironmentListResponse alloc]init];
            
            DuWebServiceSoapBindingResponse *responseEnvir = [appDelegate.binding getDUEnvironmentListUsingParameters:EnvirList];
            
            
            if (responseEnvir.error == 0) {
                @try {    
                    EnvirListResponse = (DuWebServiceSvc_getDUEnvironmentListResponse *)([responseEnvir.bodyParts objectAtIndex:0]);
                    NSMutableArray *returnArray = [[NSMutableArray alloc] initWithCapacity:EnvirListResponse.envList.count];
                    
                    for (DuWebServiceSvc_envir *s in EnvirListResponse.envList ) 
                    {
                        if( [s.area isEqualToString:environment.area])
                        {
                            [returnArray addObject:s.node_];
                        }
                    }
                    
                    appDelegate.nodeList = returnArray;
                    [myNodeView reloadData];
                }
                @catch (NSException *excep) {
                    NSLog(@"Exception during node list retrieval");
                    [activityAlert close];
                    appDelegate.isConnected = FALSE;
                    SOAPFault *result = (SOAPFault *)[response.bodyParts objectAtIndex:0];
                    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
                    [alert show];
                    return;
                }
                @finally {
                    NSLog(@"Finally");
                }
                
            }
            
            // Refresh node list
            
            UINavigationController *controller = [[UINavigationController alloc] init ];
            
            controller = [appDelegate.tbController.viewControllers  objectAtIndex:0];
            
            appDelegate.tbController.selectedViewController = controller;
            
            [controller viewWillAppear:TRUE];

            
            //Remove the alert
            [activityAlert close];
            
        }
        break;

        case 2: // Connection failed display the login window again
            if (alertView.tag == 2) {
                [self TryConnection:myNodeView];
            }
            break;
    }
}


-(void)TryConnection:(UITableView *)nodeView
{
    appDelegate = (duiosAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    UIAlertView *messageBox = [[UIAlertView alloc] initWithTitle:@"Credentials" message:@"Enter UVMS User & Password" delegate:self cancelButtonTitle:@"Cancel" otherButtonTitles:@"OK", nil];
    messageBox.tag = 1;
    messageBox.alertViewStyle = UIAlertViewStyleLoginAndPasswordInput;
    
    UITextField *username = [messageBox textFieldAtIndex:0];
    
    username.text = appDelegate.uvmsUser;
    
    myNodeView = nodeView;
    
    [messageBox show];
    
    
}


@end
