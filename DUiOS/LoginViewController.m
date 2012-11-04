//
//  LoginViewController.m
//  iDU
//
//  Created by Hervé AZOULAY on 02/11/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import "LoginViewController.h"
#import "iDUAppDelegate.h"

@interface LoginViewController ()

@end

@implementation LoginViewController

@synthesize loginButton,connection,imageView;

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
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    user.text = appDelegate.uvmsUser;
    [user addTarget:self
             action:@selector(removeKeyBoard:)
   forControlEvents:UIControlEventEditingDidEndOnExit];
    [password addTarget:self
             action:@selector(removeKeyBoard:)
   forControlEvents:UIControlEventEditingDidEndOnExit];
    
    [UIView animateWithDuration:1
                          delay:0
                        options: UIViewAnimationCurveEaseIn
                     animations:^{
                         imageView.transform = CGAffineTransformMakeScale(18, 18);
                     }
                     completion:nil
                     ];

    
    
	// Do any additional setup after loading the view.
}

-(IBAction)removeKeyBoard:(id)sender {
    [sender resignFirstResponder];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void) login
{
    NSLog(@"Login");
    connection = [[WebServiceConnection alloc]init];
    [connection connect:user.text :password.text delegate:self];
}

-(void)connectionStatus
{
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    if (appDelegate.isConnected) {
        UINavigationController *controller = [[UINavigationController alloc] init ];
        
        controller = [appDelegate.tbController.viewControllers  objectAtIndex:0];
        
        appDelegate.tbController.selectedViewController = controller;
        
        [controller viewWillAppear:TRUE];
        
        [UIApplication sharedApplication].networkActivityIndicatorVisible = NO;
        [self dismissViewControllerAnimated:TRUE completion:nil];
    }
}

-(IBAction)cancel
{
    [self dismissViewControllerAnimated:TRUE completion:nil];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}

@end
