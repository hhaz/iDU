//
//  ManageDefaults.m
//  DUiOS
//
//  Created by Hervé Azoulay on 10/06/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "ManageDefaults.h"

@implementation ManageDefaults


- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)loadDefaults
{
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    
    appDelegate.uvmsPort        = [defaults objectForKey:@"uvmsPort"];
    appDelegate.uvmsHost        = [defaults objectForKey:@"uvmsHost"];
    appDelegate.uvmsUser        = [defaults objectForKey:@"uvmsUser"];
    appDelegate.company         = [defaults objectForKey:@"company"];
    appDelegate.area            = [defaults objectForKey:@"area"];
    appDelegate.url             = [defaults objectForKey:@"url"];
    appDelegate.suffix          = [defaults objectForKey:@"suffix"];
    appDelegate.nbJobs          = [defaults objectForKey:@"nbJobs"];
    appDelegate.period          = [defaults objectForKey:@"period"];
    appDelegate.nbPeriods       = [defaults objectForKey:@"nbPeriods"];
    appDelegate.defaultSaved    = [defaults objectForKey:@"defaultSaved"];
    if (appDelegate.defaultSaved == nil) {
        appDelegate.uvmsHost = @"idu.orsypgroup.com";
        appDelegate.uvmsPort = @"4184";
        appDelegate.uvmsUser = @"admin";
        appDelegate.area     = @"X";
        appDelegate.url      = @"https://idu.orsypgroup.com";
        appDelegate.suffix   = @"/du6ws/DuwsSEI";
        appDelegate.company  = @"UNIV60";
    }
    if (appDelegate.nbJobs == nil) {
        appDelegate.nbJobs = @"100";
    }
    if (appDelegate.period == nil) {
        appDelegate.period = @"Days";
    }
    if (appDelegate.nbPeriods == nil) {
        appDelegate.nbPeriods = @"5";
    }
    
}

- (void)saveDefaults
{
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    
    NSUserDefaults *defaults = [NSUserDefaults standardUserDefaults];
    
    [defaults setObject:appDelegate.uvmsHost forKey:@"uvmsHost"];
    [defaults setObject:appDelegate.uvmsUser forKey:@"uvmsUser"];
    [defaults setObject:appDelegate.uvmsPort forKey:@"uvmsPort"];
    [defaults setObject:appDelegate.company forKey:@"company"];    
    [defaults setObject:appDelegate.area forKey:@"area"];      
    [defaults setObject:appDelegate.url forKey:@"url"];
    [defaults setObject:appDelegate.suffix forKey:@"suffix"];
    [defaults setObject:appDelegate.nbJobs forKey:@"nbJobs"];
    [defaults setObject:appDelegate.period forKey:@"period"];
    [defaults setObject:appDelegate.nbPeriods forKey:@"nbPeriods"];
    [defaults setObject:appDelegate.defaultSaved forKey:@"yes"];
    
    [defaults synchronize];

    
}


/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
