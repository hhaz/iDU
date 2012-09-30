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

@synthesize imageView;

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
                         // imageView.frame = imageFrame;
                         imageView.transform = CGAffineTransformMakeScale(25, 25);
                     }
                     completion:^(BOOL finished){
                         NSLog(@"Animation done!");
                     }];
    
    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationDuration:4.0f];
    
    imageView.alpha = 0.0f;
    
    [UIView commitAnimations];
    
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    [self performSelector:@selector(dismissModalViewControllerAnimated:) withObject:[NSNumber numberWithBool:YES] afterDelay:2.0];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
