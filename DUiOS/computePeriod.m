//
//  computePeriod.m
//  DUiOS
//
//  Created by Hervé Azoulay on 16/06/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "computePeriod.h"
#import "iDUAppDelegate.h"

@implementation computePeriod

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

-(void)compute
{
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate]; 
    
    [appDelegate.periodArray removeAllObjects];
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setTimeZone:[NSTimeZone localTimeZone]];
    [dateFormatter setDateFormat:@"dd MMMM yyyy HH:mm"];
    NSString *currentTime = [dateFormatter stringFromDate:[NSDate date]];
    NSDate *refDate = [dateFormatter dateFromString:currentTime];
    
    NSDateFormatter *dateFormatter2 = [[NSDateFormatter alloc] init];
    [dateFormatter2 setDateFormat:@"dd MMMM yyyy"];
    [dateFormatter2 setTimeZone:[NSTimeZone localTimeZone]];
    NSDate *refDay = [NSDate date];
    
    integer_t offset = [[NSTimeZone localTimeZone] secondsFromGMT] / 3600;
    
    NSTimeInterval delayGMT = offset * 60 * 60;
    
       // Manage timezone differences
    refDay = [refDay dateByAddingTimeInterval:delayGMT];

    
    NSDate *newDate;
   
    NSTimeInterval delay;
    
    if([appDelegate.period isEqualToString:@"Minutes"])
    {
        // Minutes. 
         newDate = refDate;
        [appDelegate.periodArray addObject:newDate];
        delay = 1 * 60; 
        for(int i = 1; i < [appDelegate.nbPeriods intValue] ; i++)
        {    
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];
        }
    }
    
    if([appDelegate.period isEqualToString:@"Hours"])
    {
        // Hours. 
        newDate = refDate;
        delay = 1 * 60 * 60; 
        [appDelegate.periodArray addObject:newDate];
        for(int i = 1; i <[appDelegate.nbPeriods intValue] ; i++)
        {    
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];
        }
    }
    
    if([appDelegate.period isEqualToString:@"Days"])
    {
        // Days.
        newDate = refDay;
        delay = 24 * 60 * 60; 
        [appDelegate.periodArray addObject:newDate];
        for(int i = 1; i < [appDelegate.nbPeriods intValue] ; i++)
        {    
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];            
        }
    }
    
    if([appDelegate.period isEqualToString:@"Weeks"])
    {
        // Weeks. 4 weeks
        // Days.
        newDate = refDay;
        delay = 7 * 24 * 60 * 60; 
        [appDelegate.periodArray addObject:newDate];
        for(int i = 1; i < [appDelegate.nbPeriods intValue] ; i++)
        {    
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];
        }
    }
}
@end
