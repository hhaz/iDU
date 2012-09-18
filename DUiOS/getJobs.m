//
//  getJobs.m
//  iDU
//
//  Created by Hervé AZOULAY on 16/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import "getJobs.h"
#import "ActivityAlertView.h"
#import "computePeriod.h"

@implementation getJobs

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
    }
    return self;
}

- (void) getJobs:(id)sender:(NSString *)node:(NSString *)segue:(Boolean)alert
{
    if (_appDelegate == nil) {
        _appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    }
    
    Boolean goNext = TRUE;
    computePeriod *computeDate = [[computePeriod alloc] init];
    
    // Show the alert
    
    ActivityAlertView *activityAlert = [[ActivityAlertView alloc]
                                        initWithTitle:@"Retrieving Information"
                                        message:@"Please wait..."
                                        delegate:self cancelButtonTitle:nil
                                        otherButtonTitles:nil];
    if(alert)
    {
        [activityAlert show];
    }
    
    [UIApplication sharedApplication].networkActivityIndicatorVisible = YES;
    
    [computeDate compute];
    
    NSDateFormatter *dateFormatter = [[NSDateFormatter alloc] init];
    [dateFormatter setDateFormat:@"yyyyMMdd"];
    [dateFormatter setTimeZone:[NSTimeZone localTimeZone]];
    NSDateFormatter *hourFormatter = [[NSDateFormatter alloc] init];
    [hourFormatter setDateFormat:@"HHmmss"];
    [hourFormatter setTimeZone:[NSTimeZone localTimeZone]];
    
    NSString *endDateMin = [dateFormatter stringFromDate:[_appDelegate.periodArray lastObject]];
    NSString *endDateMax = [dateFormatter stringFromDate:[_appDelegate.periodArray objectAtIndex:0]];
    
    DuWebServiceSvc_launchFilter *filter = [[DuWebServiceSvc_launchFilter alloc] init];
    
    DuWebServiceSvc_getListLaunch *listLaunch = [[DuWebServiceSvc_getListLaunch alloc] init];
    
    DuWebServiceSvc_getListLaunchResponse *listLaunchResponse = [[DuWebServiceSvc_getListLaunchResponse alloc] init];
    
    filter.mu = @"*";
    filter.beginDateMax = endDateMax;
    filter.beginDateMin = endDateMin;
    filter.maximumResults = _appDelegate.nbJobs;
    filter.order = @"ASC";
    
    _appDelegate.theContext.context.envir.node_ = node;
    
    listLaunch.context = _appDelegate.theContext;
    listLaunch.filter = filter;
    
    // GetLaunchList
    
    DuWebServiceSoapBindingResponse *response = [_appDelegate.binding getListLaunchUsingParameters:listLaunch];
    
    if (response.error == 0 && goNext ) {
        
        @try {
            listLaunchResponse = (DuWebServiceSvc_getListLaunchResponse *)([response.bodyParts objectAtIndex:0]);
            
            _launchList = [[NSMutableArray alloc] initWithCapacity:listLaunchResponse.launchList.count];
            
            for (DuWebServiceSvc_launchItem *s in listLaunchResponse.launchList )
            {
                [_launchList addObject:s];
            }
        }
        @catch (NSException *excep) {
            goNext  = FALSE;
            SOAPFault *result = (SOAPFault *)[response.bodyParts objectAtIndex:0];
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        @finally {
            NSLog(@"Finally");
        }
    }
    
    // GetExecutionList
    
    DuWebServiceSvc_executionFilter *executionFilter = [[DuWebServiceSvc_executionFilter alloc] init];
    
    DuWebServiceSvc_getListExecution *listExecution = [[DuWebServiceSvc_getListExecution alloc] init];
    
    DuWebServiceSvc_getListExecutionResponse *listExecutionResponse = [[DuWebServiceSvc_getListExecutionResponse alloc] init];
    
    executionFilter.mu = @"*";
    executionFilter.beginDateMax = endDateMax;
    executionFilter.beginDateMin = endDateMin;
    executionFilter.maximumResults = _appDelegate.nbJobs;
    executionFilter.order = @"ASC";
    
    _appDelegate.theContext.context.envir.node_ = node;
    
    listExecution.context = _appDelegate.theContext;
    listExecution.filter = executionFilter;
    
    DuWebServiceSoapBindingResponse *responseExecution = [_appDelegate.binding getListExecutionUsingParameters:listExecution];
    
    if (responseExecution.error == 0 && goNext) {
        @try {
            listExecutionResponse = (DuWebServiceSvc_getListExecutionResponse *)([responseExecution.bodyParts objectAtIndex:0]);
            
            _executionList = [[NSMutableArray alloc] initWithCapacity:listExecutionResponse.executionList.count];
            
            for (DuWebServiceSvc_executionItem *s in listExecutionResponse.executionList )
            {
                [_executionList addObject:s];
            }
        }
        @catch (NSException *excep) {
            SOAPFault *result = (SOAPFault *)[responseExecution.bodyParts objectAtIndex:0];
            UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:result.faultstring delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
            [alert show];
        }
        @finally {
            NSLog(@"Finally");
        }
    }

    [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
    
    if (goNext) {
        if(![segue isEqualToString:@""])
        {
            [sender performSegueWithIdentifier:segue sender:self];
        }
        else
        {
            [sender viewWillAppear:TRUE];
        }
    }
    
    if(alert)
    {
        [activityAlert close];
    }
    
}


@end
