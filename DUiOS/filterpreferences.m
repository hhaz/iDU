//
//  filterpreferences.m
//  DUiOS
//
//  Created by Hervé Azoulay on 02/06/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "filterpreferences.h"
#import "iDUAppDelegate.h"
#import "computePeriod.h"


@implementation filterpreferences
@synthesize myTableView;
@synthesize contentsList = ivContentsList;
@synthesize sectionKeys = ivSectionKeys;
@synthesize arrayPeriods;
@synthesize activeTextField;


- (void)viewWillDisappear:(BOOL)animated {
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];

    appDelegate.nbJobs = nbJobs.text;
    appDelegate.period = periods.text;
    appDelegate.nbPeriods = nbPeriods.text;
    
    computePeriod *computeDate = [[computePeriod alloc] init];
    [computeDate compute];

}

-(IBAction)displayPicker:(id)sender
{
    activeTextField = (UITextField *)sender;
    
    if (self) {
        picker = [[UIPickerView alloc] init ];
        
        [picker sizeToFit];
        picker.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
        [picker setDataSource:self];
        [picker setDelegate:self];
        picker.showsSelectionIndicator = YES;
        
        activeTextField.inputView = picker;
        
        UIToolbar* keyboardDoneButtonView = [[UIToolbar alloc] init];
        keyboardDoneButtonView.barStyle = UIBarStyleBlack;
        keyboardDoneButtonView.translucent = YES;
        keyboardDoneButtonView.tintColor = nil;
        [keyboardDoneButtonView sizeToFit];
        
        UIBarButtonItem* doneButton = [[UIBarButtonItem alloc] initWithTitle:@"Done"
                                                                       style:UIBarButtonItemStyleBordered target:self
                                                                      action:@selector(pickerDoneClicked:)];
        
        [keyboardDoneButtonView setItems:[NSArray arrayWithObjects:doneButton, nil]];
        
        activeTextField.inputAccessoryView = keyboardDoneButtonView;
        
    }
    
}


- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    nbJobs.text         = appDelegate.nbJobs;
    periods.text        = appDelegate.period;
    nbPeriods.text      = appDelegate.nbPeriods;

    arrayPeriods = [[NSMutableArray alloc] init];
    [arrayPeriods addObject:@"Minutes"];
    [arrayPeriods addObject:@"Hours"];
    [arrayPeriods addObject:@"Days"];
    [arrayPeriods addObject:@"Weeks"];
	    
}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - Table view data source


-(IBAction)pickerDoneClicked:(id)sender {
    [periods resignFirstResponder];
}

// Do something with the selected row.
-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component{
    periods.text = [arrayPeriods objectAtIndex: row];
}
-(NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    //One column
    return 1;
}

-(NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    //set number of rows
    return [arrayPeriods count];
}

-(NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    //set item per row
    return [arrayPeriods objectAtIndex:row];
}

-(IBAction)removeKeyBoard:(id)sender {
    [sender resignFirstResponder];
}


@end
