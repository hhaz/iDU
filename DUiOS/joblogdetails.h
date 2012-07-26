//
//  joblogdetails.h
//  DUiOS
//
//  Created by Hervé Azoulay on 18/02/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "DuWebServiceSvc.h"
#import "joblog.h"


@interface joblogdetails : UIViewController <UINavigationBarDelegate, UITextViewDelegate> {
    
}

@property (nonatomic, retain) IBOutlet UITextView *myTextView;
@property (nonatomic, retain) NSString *theLog;
@property (nonatomic, retain) DuWebServiceSvc_executionItem *currentJob;

@end
