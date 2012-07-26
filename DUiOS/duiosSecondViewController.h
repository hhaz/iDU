//
//  duiosSecondViewController.h
//  DUiOS
//
//  Created by Hervé Azoulay on 28/01/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol duiosSecondViewController;
#import "DuWebServiceSvc.h"


@interface duiosSecondViewController : UIViewController <UITextViewDelegate> {
    
    id<duiosSecondViewController> delegate;
 }

@property (nonatomic,retain) id <duiosSecondViewController> delegate;
@end


