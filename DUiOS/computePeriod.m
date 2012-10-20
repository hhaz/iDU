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


//Compute number of periods between two dates
-(void)compute2:(NSDate *)fromDate:(NSDate *)toDate
{
    
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    [appDelegate.periodArray removeAllObjects];
    
    NSCalendar *gregorian = [[NSCalendar alloc]
                             initWithCalendarIdentifier:NSGregorianCalendar];
    
    NSUInteger unitFlags = NSDayCalendarUnit;
    
    NSDateComponents *components = [gregorian components:unitFlags
                                                fromDate:fromDate
                                                  toDate:toDate options:0];
    NSInteger days = [components day];
    
    NSDate *newDate;
    NSTimeInterval delay;
    
    if([appDelegate.period isEqualToString:@"Minutes"])
    {
        // Minutes.
        newDate = toDate;
        [appDelegate.periodArray addObject:[newDate dateByAddingTimeInterval:delay]];
        delay = 1 * 60;
        for(int i = 1; i < days * 60 ; i++)
        {
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];
        }

    }

    if([appDelegate.period isEqualToString:@"Hours"])
    {
        // Hours.
        newDate = toDate;
        delay = 1 * 60 * 60;
        [appDelegate.periodArray addObject:[newDate dateByAddingTimeInterval:delay]];
        for(int i = 1; i < days*24; i++)
        {
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];
        }
    }
    
    if([appDelegate.period isEqualToString:@"Days"])
    {
        // Days.
        newDate = toDate;
        delay = 24 * 60 * 60;
        [appDelegate.periodArray addObject:[newDate dateByAddingTimeInterval:delay]];
        for(int i = 1; i < days ; i++)
        {
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];
        }
    }
    
    if([appDelegate.period isEqualToString:@"Weeks"])
    {
        // Weeks.
        newDate = toDate;
        delay = 7 * 24 * 60 * 60;
        [appDelegate.periodArray addObject:[newDate dateByAddingTimeInterval:delay]];
        for(int i = 1; i < days/7 +1 ; i++)
        {
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];
        }
    }
    
    appDelegate.nbPeriods = [NSString stringWithFormat:@"%i",[appDelegate.periodArray count]];
    
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
         [appDelegate.periodArray addObject:[newDate dateByAddingTimeInterval:delay]];
        delay = 1 * 60; 
        for(int i = 1; i < [appDelegate.nbPeriods intValue] +1 ; i++)
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
         [appDelegate.periodArray addObject:[newDate dateByAddingTimeInterval:delay]];
        for(int i = 1; i <[appDelegate.nbPeriods intValue] +1; i++)
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
        [appDelegate.periodArray addObject:[newDate dateByAddingTimeInterval:delay]];
        for(int i = 1; i < [appDelegate.nbPeriods intValue] + 1; i++)
        {    
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];            
        }
    }
    
    if([appDelegate.period isEqualToString:@"Weeks"])
    {
        // Weeks.
        newDate = refDay;
        delay = 7 * 24 * 60 * 60; 
         [appDelegate.periodArray addObject:[newDate dateByAddingTimeInterval:delay]];
        for(int i = 1; i < [appDelegate.nbPeriods intValue] +1 ; i++)
        {    
            newDate = [newDate dateByAddingTimeInterval:-delay];
            [appDelegate.periodArray addObject:newDate];
        }
    }
}
@end
