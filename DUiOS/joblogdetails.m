//
//  joblogdetails.m
//  DUiOS
//
//  Created by Hervé Azoulay on 18/02/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import "joblogdetails.h"

@implementation joblogdetails
@synthesize myTextView;
@synthesize theLog;
@synthesize aJoblog;
@synthesize currentJob;


- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)didReceiveMemoryWarning
{
    // Releases the view if it doesn't have a superview.
    [super didReceiveMemoryWarning];
    
    // Release any cached data, images, etc that aren't in use.
}

#pragma mark - View lifecycle

/*
// Implement loadView to create a view hierarchy programmatically, without using a nib.
- (void)loadView
{
}
*/


// Implement viewDidLoad to do additional setup after loading the view, typically from a nib.
- (void)viewDidLoad
{
    [super viewDidLoad];
    aJoblog = [self.navigationController.viewControllers objectAtIndex:2]; 
    
    theLog = aJoblog.theLog;
    currentJob = aJoblog.currentJob;
    myTextView.editable = false;
    
    
    myTextView.text = theLog;
}


- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

@end