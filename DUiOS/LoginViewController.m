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

@synthesize loginButton,connection,imageView,scrollView,currentTextField,activityIndicator;

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewWillAppear:(BOOL)animated
{

    
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    password.delegate = self;
    user.delegate = self;
    activityIndicator.hidesWhenStopped = TRUE;

    [self registerForKeyboardNotifications];
    scrollView.contentSize=scrollView.frame.size;
    
    //scrollView.contentSize=CGSizeMake(1000, 1000);
    
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
    [activityIndicator startAnimating];
    connection = [[WebServiceConnection alloc]init];
    [connection connect:user.text :password.text delegate:self];
    [activityIndicator stopAnimating];
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
    [activityIndicator stopAnimating];
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


- (void)registerForKeyboardNotifications
{
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWasShown:)
                                                 name:UIKeyboardDidShowNotification object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillBeHidden:)
                                                 name:UIKeyboardWillHideNotification object:nil];

    [[UIDevice currentDevice] beginGeneratingDeviceOrientationNotifications];
    [[NSNotificationCenter defaultCenter] addObserver: self selector: @selector(deviceOrientationDidChange:) name: UIDeviceOrientationDidChangeNotification object: nil];
    
}

- (void)deviceOrientationDidChange:(NSNotification *)notification
{
    scrollView.contentSize=scrollView.frame.size;;
}


// Called when the UIKeyboardDidShowNotification is sent.
- (void)keyboardWasShown:(NSNotification*)aNotification
{
    NSDictionary* info = [aNotification userInfo];
    CGSize kbSize = [[info objectForKey:UIKeyboardFrameBeginUserInfoKey] CGRectValue].size;
    CGPoint scrollPoint;
    
    UIDeviceOrientation orientation = [[UIDevice currentDevice] orientation];
    
    if (orientation == UIDeviceOrientationFaceUp || orientation == UIDeviceOrientationFaceDown || orientation == UIDeviceOrientationUnknown)
    {
        scrollPoint = CGPointMake(0.0, currentTextField.frame.origin.y-kbSize.height);
    }
    else
    {
        scrollPoint = CGPointMake(0.0, currentTextField.frame.origin.y);
    }
  
    [scrollView setContentOffset:scrollPoint animated:YES];

}
// Called when the UIKeyboardWillHideNotification is sent
- (void)keyboardWillBeHidden:(NSNotification*)aNotification
{
    UIEdgeInsets contentInsets = UIEdgeInsetsZero;
    scrollView.contentInset = contentInsets;
    scrollView.scrollIndicatorInsets = contentInsets;
}

- (void)textFieldDidBeginEditing:(UITextField *)textField
{
    currentTextField = textField;
    
}

- (void)textFieldDidEndEditing:(UITextField *)textField
{
    currentTextField = nil;
    CGPoint scrollPoint = CGPointMake(0.0, 0.0);
    [scrollView setContentOffset:scrollPoint animated:YES];

}

@end
