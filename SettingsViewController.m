//
//  SettingsViewController.m
//  iDU
//
//  Created by Hervé AZOULAY on 19/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import "SettingsViewController.h"
#import "ManageDefaults.h"
#import "LoginViewController.h"

@interface SettingsViewController ()

@end

@implementation SettingsViewController
@synthesize arrayArea,picker,activeTextField;

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
    arrayArea = [[NSMutableArray alloc] init];
    [arrayArea addObject:@"X"];
    [arrayArea addObject:@"A"];
    [arrayArea addObject:@"I"];
    [arrayArea addObject:@"S"];

    [super viewDidLoad];
    
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    theCompany.text     = appDelegate.company;
    theSpace.text       = appDelegate.area;
    theUVMS.text        = appDelegate.uvmsHost;
    theUserName.text    = appDelegate.uvmsUser;
    thePort.text        = appDelegate.uvmsPort;
    _WSURL              = appDelegate.url;
    _WSSuffix           = appDelegate.suffix;
    
    NSString *dToken = [[appDelegate.tokenDevice description] stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"<>"]];
    dToken = [dToken stringByReplacingOccurrencesOfString:@" " withString:@""];
    
    theTokenDevice.text = dToken;
    
    if(appDelegate.isConnected)
    {
        connectionStatus.text = @"Connected";
    }
    else {
        connectionStatus.text = @"Not connected";
    }

}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    if(_WSURL != @""  && _WSURL !=nil)
    {
        theURL.placeholder = @"";
        theURL.text = [NSString stringWithFormat:@"%@%@", _WSURL , _WSSuffix];
        appDelegate.url = _WSURL;
        appDelegate.suffix = _WSSuffix;
    }
    if(appDelegate.isConnected)
    {
        connectionStatus.text = @"Connected";
    }
    else {
        connectionStatus.text = @"Not connected";
    }
    
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    if (appDelegate.isConnected) {
        connectionStatus.text = @"Connected";
    }
    else {
        connectionStatus.text = @"Not connected";
    }
}


- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)removeKeyBoard:(id)sender {
    [sender resignFirstResponder];
}

-(IBAction)displayPicker:(id)sender
{
    activeTextField = (UITextField *)sender;
    
    arrayArea = [[NSMutableArray alloc] init];
    [arrayArea addObject:@"X"];
    [arrayArea addObject:@"A"];
    [arrayArea addObject:@"I"];
    [arrayArea addObject:@"S"];
    
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

-(IBAction)pickerDoneClicked:(id)sender {
    [activeTextField resignFirstResponder];
}

// Do something with the selected row.
-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component{
    activeTextField.text = [arrayArea objectAtIndex: row];
}
-(NSInteger)numberOfComponentsInPickerView:(UIPickerView *)pickerView
{
    //One column
    return 1;
}

-(NSInteger)pickerView:(UIPickerView *)pickerView numberOfRowsInComponent:(NSInteger)component
{
    //set number of rows
    return [arrayArea count];
}

-(NSString *)pickerView:(UIPickerView *)pickerView titleForRow:(NSInteger)row forComponent:(NSInteger)component
{
    //set item per row
    return [arrayArea objectAtIndex:row];
}

-(IBAction)TryConnection
{
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    _connection = [[WebServiceConnection alloc]init];
    
    appDelegate.uvmsPort    = thePort.text;
    appDelegate.uvmsHost    = theUVMS.text;
    appDelegate.uvmsUser    = theUserName.text;
    appDelegate.url         = _WSURL;
    appDelegate.suffix      = _WSSuffix;
    appDelegate.company     = theCompany.text;
    appDelegate.area        = theSpace.text;
    
    //[_connection TryConnection:nil delegate:self];
    
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"MainStoryboard" bundle:nil];
    
    LoginViewController *loginView = [storyboard instantiateViewControllerWithIdentifier:@"LoginViewController"];
    
    [self presentViewController:loginView animated:YES completion:nil];
    
    ManageDefaults *duiosDefault = [[ManageDefaults alloc]init];
    [duiosDefault saveDefaults];
    
}

-(void)connectionStatus
{
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    if (appDelegate.isConnected) {
       
    }
    
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 1) {
        UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
        [self performSegueWithIdentifier:@"urlDetails" sender:cell];}
}

@end
