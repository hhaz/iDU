//
//  AnimationViewController.m
//  iDU
//
//  Created by Hervé AZOULAY on 23/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import "AnimationViewController.h"

@interface AnimationViewController ()

@end

@implementation AnimationViewController

@synthesize imageView,D,O,L1,L2,A,R,UNIVERSE;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

    [UIView animateWithDuration:1
                          delay:0
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         D.alpha = 1;
                     }
                     completion:nil
                     ];
 
    [UIView animateWithDuration:1
                          delay:0.2
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         O.alpha = 1;
                     }
                     completion:nil
     ];
    [UIView animateWithDuration:1
                          delay:0.4
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         L1.alpha = 1;
                     }
                     completion:nil
     ];
    [UIView animateWithDuration:1
                          delay:0.6
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         L2.alpha = 1;
                     }
                     completion:nil
     ];
    [UIView animateWithDuration:1
                          delay:0.8
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         A.alpha = 1;
                     }
                     completion:nil
     ];
    [UIView animateWithDuration:1
                          delay:1
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         R.alpha = 1;
                     }
                     completion:nil
     ];

    [UIView animateWithDuration:1
                          delay:1.2
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         UNIVERSE.alpha = 1;
                     }
                     completion:nil
     ];

    [UIView animateWithDuration:1
                          delay:0
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         imageView.transform = CGAffineTransformMakeScale(25, 25);
                     }
                     completion:^(BOOL finished){
                         [UIView animateWithDuration:2.0
                                               delay: 0.5
                                             options:UIViewAnimationOptionCurveEaseOut
                                          animations:^{
                                              imageView.alpha = 0.0;
                                          }
                                          completion:nil];
                     }];
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [self performSelector:@selector(dismissModalViewControllerAnimated:) withObject:[NSNumber numberWithBool:YES] afterDelay:4.0];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
