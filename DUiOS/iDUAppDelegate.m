//
//  duiosAppDelegate.m
//  DUiOS
//
//  Created by Hervé Azoulay on 28/01/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "iDUAppDelegate.h"
#import "ManageDefaults.h"
#import "WebServiceConnection.h"

@implementation iDUAppDelegate

@synthesize window = _window;
@synthesize navigationController;
@synthesize binding;
@synthesize uvmsHost,uvmsPort,uvmsUser,company,area,url,nodeList,isConnected,theContext,nbJobs,nbPeriods,period,suffix;
@synthesize periodArray;
@synthesize statusKeys;
@synthesize contentStatus;
@synthesize tbController;
@synthesize args;
@synthesize isRemoteNotif;
@synthesize connection;
@synthesize tokenDevice;
@synthesize defaultSaved;

- (void)dealloc
{
 
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    // Override point for customization after application launch.
    ManageDefaults *duiosDefault = [[ManageDefaults alloc]init];
    periodArray = [[NSMutableArray alloc] init];
    [duiosDefault loadDefaults];
    
    [window addSubview:[navigationController view]];
    
    isConnected     = FALSE;
    isRemoteNotif   = FALSE;
      
    // Initialize status dictionary
    
    NSMutableArray *keys = [[NSMutableArray alloc] init];
    NSMutableDictionary *contents = [[NSMutableDictionary alloc] init];
	
    NSString *completed     = @"COMPLETED";
    NSString *running       = @"RUNNING";
    NSString *timeoverrun   = @"TIME_OVERRUN";
    NSString *eventwait     = @"EVENT_WAIT";
    NSString *aborted       = @"ABORTED";
    NSString *refused       = @"REFUSED";
    NSString *pending       = @"PENDING";
    NSString *launching     = @"LAUNCH_WAIT";
    
	
    [contents setObject:[NSArray arrayWithObjects:@"Completed",[UIColor greenColor],@"greenflag.png",nil] forKey:completed];
    [contents setObject:[NSArray arrayWithObjects:@"Running",[UIColor blueColor],@"greenflag.png",nil] forKey:running];
    [contents setObject:[NSArray arrayWithObjects:@"Time Overrun",[UIColor orangeColor],@"redflag.png",nil] forKey:timeoverrun];
    [contents setObject:[NSArray arrayWithObjects:@"Event Wait",[UIColor purpleColor],@"redflag.png",nil] forKey:eventwait];
    [contents setObject:[NSArray arrayWithObjects:@"Aborted",[UIColor redColor],@"redflag.png",nil] forKey:aborted];
    [contents setObject:[NSArray arrayWithObjects:@"Refused",[UIColor redColor],@"redflag.png",nil] forKey:refused];
    [contents setObject:[NSArray arrayWithObjects:@"Pending",[UIColor redColor],@"redflag.png",nil] forKey:pending];
    [contents setObject:[NSArray arrayWithObjects:@"Launch Wait",[UIColor yellowColor],@"redflag.png",nil] forKey:launching];
    
    [keys addObject:completed];
    [keys addObject:running];
    [keys addObject:timeoverrun];
    [keys addObject:eventwait];
    [keys addObject:aborted];
    [keys addObject:refused];
    [keys addObject:pending];
    [keys addObject:launching];
	
    [self setStatusKeys:keys];
    [self setContentStatus:contents];
	    
    // Let the device know we want to receive push notifications
	[[UIApplication sharedApplication] registerForRemoteNotificationTypes:
     (UIRemoteNotificationTypeBadge | UIRemoteNotificationTypeSound | UIRemoteNotificationTypeAlert)];

    connection = [[WebServiceConnection alloc]init];
    
    [self performSelector:@selector(performConnection) withObject:nil afterDelay:1];
    
    NSDictionary *remoteNotif = [launchOptions objectForKey:UIApplicationLaunchOptionsRemoteNotificationKey];
    if (remoteNotif != nil)
    {              
        [self handleRemoteNotification:application userInfo:remoteNotif];        
    }

    return YES;
}

- (void)performConnection
{
    if(!isConnected)
    {
     [connection TryConnection:nil];
    }
}
							
- (void)applicationWillResignActive:(UIApplication *)application
{
    /*
     Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
     Use this method to pause ongoing tasks, disable timers, and throttle down OpenGL ES frame rates. Games should use this method to pause the game.
     */
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
    /*
     Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later. 
     If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
     */
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
    /*
     Called as part of the transition from the background to the inactive state; here you can undo many of the changes made on entering the background.
     */
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
    /*
     Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
     */
    
    NSLog(@"Application activated");
}

- (void)applicationWillTerminate:(UIApplication *)application
{
    /*
     Called when the application is about to terminate.
     Save data if appropriate.
     See also applicationDidEnterBackground:.
     */
}

- (void)application:(UIApplication*)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken
{
	NSLog(@"My token is: %@", deviceToken);
    
    tokenDevice = deviceToken;
}

- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error
{
	NSLog(@"Failed to get token, error: %@", error);
    
    tokenDevice = nil;
}


- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
{ 
    isRemoteNotif = TRUE;
    application.applicationIconBadgeNumber = 0;
    
    args = [[NSArray alloc] initWithArray:[[[userInfo objectForKey:@"aps"] objectForKey:@"alert"] objectForKey:@"loc-args"]];
    
     UINavigationController *controller = [tbController.viewControllers  objectAtIndex:0];
    
    tbController.selectedViewController = controller;
    
    [controller viewWillAppear:TRUE];
}

-(void) handleRemoteNotification:(UIApplication *)application userInfo:(NSDictionary *)userInfo {

    isRemoteNotif = TRUE;
    application.applicationIconBadgeNumber = 0;
    
    args = [[NSArray alloc] initWithArray:[[[userInfo objectForKey:@"aps"] objectForKey:@"alert"] objectForKey:@"loc-args"]];
    
    //args = [[[userInfo objectForKey:@"aps"] objectForKey:@"alert"] objectForKey:@"loc-args"];
    
    NSLog(@"User info : %d", [userInfo count]);
    NSLog(@"%d",[args count]);
    
}

@end
