//
//  settings.m
//  DUiOS
//
//  Created by Hervé Azoulay on 04/02/12.
//  Copyright (c) 2012 Hervé Azoulay. All rights reserved.
//

#import "settings.h"
#import "iDUAppDelegate.h"
#import "ManageDefaults.h"

@implementation settings
@synthesize myTableView;
@synthesize contentsList = ivContentsList;
@synthesize sectionKeys = ivSectionKeys;
@synthesize theContext;
@synthesize WSURL;
@synthesize delegate;
@synthesize arrayArea;
@synthesize WSSuffix;
@synthesize connection;


// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    //static NSString *CellIdentifier = @"Cell";
    NSString *key = [[self sectionKeys] objectAtIndex:[indexPath section]];
    NSArray *contents = [[self contentsList] objectForKey:key];
    NSString *contentForThisRow = [contents objectAtIndex:[indexPath row]];
    
    NSString *imageFile;
    
    NSString *CellIdentifier = [contents objectAtIndex:[indexPath row]];   
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
        
    if(appDelegate.isConnected)
    {
        connectionStatus.textLabel.text = @"Connected";
    }
    else {
        connectionStatus.textLabel.text = @"Not connected";
    }
    
    if (cell == nil)
	{
		cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    
    if ([indexPath section] == 0) {
            connectionStatus = cell;
            imageFile = @"question.png";
    }
        
    if ([indexPath section] == 1) {
        UITextField *url = [[UITextField alloc] initWithFrame:CGRectMake(95, 10, 185, 30)];
        url.adjustsFontSizeToFitWidth = YES;
        url.textColor = [UIColor blackColor];
        if ([indexPath row] == 0) {
            url.placeholder = @"http://server/du6ws/DuwsSEI";
            url.enabled = false;
            url.keyboardType = UIKeyboardTypeURL;
            url.returnKeyType = UIReturnKeyDefault;
            url.text = appDelegate.url;
            theURL = url;
            imageFile = @"URL.jpeg";
        }
        [url addTarget:self 
                 action:@selector(removeKeyBoard:)
       forControlEvents:UIControlEventEditingDidEndOnExit];
        cell.accessoryType = UITableViewCellAccessoryDetailDisclosureButton;

         [cell addSubview:url];
    }
    
    if ([indexPath section] == 2) {
        UITextField *uvms = [[UITextField alloc] initWithFrame:CGRectMake(155, 10, 185, 30)];
        uvms.adjustsFontSizeToFitWidth = YES;
        uvms.textColor = [UIColor blackColor];
        if ([indexPath row] == 0) {
            uvms.placeholder = @"192.168.0.1";
            uvms.keyboardType = UIKeyboardTypeURL;
            uvms.returnKeyType = UIReturnKeyDefault;
            uvms.text = appDelegate.uvmsHost;
            theUVMS = uvms;
            imageFile = @"server.png";
        }
        if ([indexPath row] == 1) {
            uvms.placeholder = @"UVMS Port Number";
            uvms.keyboardType = UIKeyboardTypeNumberPad;
            uvms.returnKeyType = UIReturnKeyDefault;
            uvms.text = appDelegate.uvmsPort;
            thePort = uvms;
             imageFile = @"port.png";
        }
        if ([indexPath row] == 2) {
            uvms.placeholder = @"User Name";
            uvms.keyboardType = UIKeyboardTypeAlphabet;
            uvms.returnKeyType = UIReturnKeyDefault;
            uvms.text = appDelegate.uvmsUser;
            theUserName = uvms;
             imageFile = @"user.png";
        }
        uvms.clearButtonMode = UITextFieldViewModeWhileEditing;
        [uvms addTarget:self 
                 action:@selector(removeKeyBoard:)
        forControlEvents:UIControlEventEditingDidEndOnExit];
        [cell addSubview:uvms];
    }
    
    if ([indexPath section] == 3) {
        UITextField *node = [[UITextField alloc] initWithFrame:CGRectMake(155, 10, 185, 30)];
        node.adjustsFontSizeToFitWidth = YES;
        node.textColor = [UIColor blackColor];
        if ([indexPath row] == 0) {
            node.placeholder = @"required";
            node.keyboardType = UIKeyboardTypeDefault;
            node.returnKeyType = UIReturnKeyDefault;
            node.text = appDelegate.company;
            theCompany = node;
            imageFile = @"company.png";
        }
        if ([indexPath row] == 1) {
            node.placeholder = @"required";
            UIPickerView *picker = [[UIPickerView alloc] init ];
            
            [picker sizeToFit];
            picker.autoresizingMask = (UIViewAutoresizingFlexibleWidth | UIViewAutoresizingFlexibleHeight);
            [picker setDataSource: self];
            [picker setDelegate: self];		
            picker.showsSelectionIndicator = YES;
            
            node.inputView =  picker;
            
            UIToolbar* keyboardDoneButtonView = [[UIToolbar alloc] init];
            keyboardDoneButtonView.barStyle = UIBarStyleBlack;
            keyboardDoneButtonView.translucent = YES;
            keyboardDoneButtonView.tintColor = nil;
            [keyboardDoneButtonView sizeToFit];
            
            UIBarButtonItem* doneButton = [[UIBarButtonItem alloc] initWithTitle:@"Done"
                                                                           style:UIBarButtonItemStyleBordered target:self
                                                                          action:@selector(pickerDoneClicked:)];
            
            [keyboardDoneButtonView setItems:[NSArray arrayWithObjects:doneButton, nil]];
            
            // Plug the keyboardDoneButtonView into the text field...
            node.inputAccessoryView = keyboardDoneButtonView;  
            
            node.returnKeyType = UIReturnKeyDefault;
            node.text = @"X";
            node.text = appDelegate.area;
            theSpace = node;
            imageFile = @"area.png";
        }

        [node addTarget:self 
                 action:@selector(removeKeyBoard:)
       forControlEvents:UIControlEventEditingDidEndOnExit];
        [cell addSubview:node];
    }
        
    if ([indexPath section] == 4)
    {
        UITextField *textField = [[UITextField alloc] initWithFrame:CGRectMake(30, 10, 270, 30)];
        textField.adjustsFontSizeToFitWidth = YES;
        textField.textColor = [UIColor blackColor];
        textField.keyboardType = UIKeyboardTypeURL;
        textField.returnKeyType = UIReturnKeyDefault;

        NSString *dToken = [[appDelegate.tokenDevice description] stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"<>"]];
        dToken = [dToken stringByReplacingOccurrencesOfString:@" " withString:@""];
        
        textField.text = dToken;

        textField.clearButtonMode = UITextFieldViewModeWhileEditing;
        [textField addTarget:self
                 action:@selector(removeKeyBoard:)
       forControlEvents:UIControlEventEditingDidEndOnExit];
        [cell addSubview:textField];
    }
    UIImage *tableImage = [UIImage imageNamed:imageFile];
    [cell.imageView setImage:tableImage];
    CGSize imageSize = CGSizeMake(25,25);
    UIGraphicsBeginImageContext(imageSize);
    CGRect imageRect = CGRectMake(1.0, 0.5, imageSize.width, imageSize.height);
    [tableImage drawInRect:imageRect];
    cell.imageView.image = UIGraphicsGetImageFromCurrentImageContext();
	[[cell textLabel] setText:contentForThisRow];
    }
	
    return cell;
}

-(IBAction)pickerDoneClicked:(id)sender {
    [theSpace resignFirstResponder];
}

// Do something with the selected row.
-(void)pickerView:(UIPickerView *)pickerView didSelectRow:(NSInteger)row inComponent:(NSInteger)component{
    theSpace.text = [arrayArea objectAtIndex: row];
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

-(IBAction)removeKeyBoard:(id)sender {
    [sender resignFirstResponder];
}

-(IBAction)TryConnection
{
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    connection = [[WebServiceConnection alloc]init];
    
    appDelegate.uvmsPort    = thePort.text;
    appDelegate.uvmsHost    = theUVMS.text;
    appDelegate.uvmsUser    = theUserName.text;
    appDelegate.url         = WSURL;
    appDelegate.suffix      = WSSuffix;
    appDelegate.company     = theCompany.text;
    appDelegate.area        = theSpace.text;    
    
    [connection TryConnection:nil];
    
    ManageDefaults *duiosDefault = [[ManageDefaults alloc]init];
    [duiosDefault saveDefaults];
    
}


- (id)initWithStyle:(UITableViewStyle)style
{
    self = [super initWithStyle:style];
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

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
        
    theCompany.text     = appDelegate.company;
    theSpace.text       = appDelegate.area;
    theUVMS.text        = appDelegate.uvmsHost;
    theUserName.text    = appDelegate.uvmsUser;
    thePort.text        = appDelegate.uvmsPort;
    WSURL               = appDelegate.url;
    WSSuffix            = appDelegate.suffix;

    if(appDelegate.isConnected)
    {
        connectionStatus.textLabel.text = @"Connected";
    }
    else {
        connectionStatus.textLabel.text = @"Not connected";
    }
       
    NSMutableArray *keys = [[NSMutableArray alloc] init];
    NSMutableDictionary *contents = [[NSMutableDictionary alloc] init];
	
    NSString *status = @"Connection Status";
    NSString *url = @"Web Service URL";
    NSString *uvms = @"UVMS";
    NSString *nodeInfo = @"Node Information";
    NSString *tokenInfo = @"Notification Device Token";
	
    [contents setObject:[NSArray arrayWithObject:@"Not connected"] forKey:status];
    [contents setObject:[NSArray arrayWithObject:@"URL"] forKey:url];
    [contents setObject:[NSArray arrayWithObjects:@"Mgt server", @"Port", @"User Name", nil] forKey:uvms];
    [contents setObject:[NSArray arrayWithObjects:@"Company", @"Area", nil] forKey:nodeInfo];
    [contents setObject:[NSArray arrayWithObject:@""] forKey:tokenInfo];
   /* if(appDelegate.tokenDevice != nil)
    {
        NSString *dToken = [[appDelegate.tokenDevice description] stringByTrimmingCharactersInSet:[NSCharacterSet characterSetWithCharactersInString:@"<>"]];
        dToken = [dToken stringByReplacingOccurrencesOfString:@" " withString:@""];
        [contents setObject:[NSArray arrayWithObject:dToken] forKey:tokenInfo];
    }
    else
    {
        [contents setObject:[NSArray arrayWithObject:@""] forKey:tokenInfo];
    }*/
	
    [keys addObject:status];
    [keys addObject:url];
    [keys addObject:uvms];
    [keys addObject:nodeInfo];
    [keys addObject:tokenInfo];
	
    [self setSectionKeys:keys];
    [self setContentsList:contents];
	
    
    arrayArea = [[NSMutableArray alloc] init];
    [arrayArea addObject:@"X"];
    [arrayArea addObject:@"A"];
    [arrayArea addObject:@"I"];
    [arrayArea addObject:@"S"];
   

}

- (void)viewDidUnload
{
    [super viewDidUnload];
    // Release any retained subviews of the main view.
    // e.g. self.myOutlet = nil;
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    if(WSURL != @""  && WSURL !=nil)
    {
        theURL.placeholder = @"";
        theURL.text = [NSString stringWithFormat:@"%@%@", WSURL , WSSuffix];
        appDelegate.url = WSURL;
        appDelegate.suffix = WSSuffix;
    }
    if(appDelegate.isConnected)
    {
        connectionStatus.textLabel.text = @"Connected";
    }
    else {
        connectionStatus.textLabel.text = @"Not connected";
    }

}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    iDUAppDelegate *appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    if (appDelegate.isConnected) {
        connectionStatus.textLabel.text = @"Connected";    
    }
    else {
        connectionStatus.textLabel.text = @"Not connected";
    }
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    // Return YES for supported orientations
    return (interfaceOrientation == UIInterfaceOrientationPortrait);
}

#pragma mark - Table view data source

- (NSString *)tableView:(UITableView *)tableView
titleForHeaderInSection:(NSInteger)section
{
    NSString *key = [[self sectionKeys] objectAtIndex:section];
    
    return key;
}

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView
{
   	NSInteger sections = [[self contentsList] count];
    
    return sections;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    NSString *key = [[self sectionKeys] objectAtIndex:section];
    NSArray *contents = [[self contentsList] objectForKey:key];
    NSInteger rows = [contents count];
    
    return rows;
}


#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if ([indexPath section] == 1) {
        UITableViewCell *cell = [tableView cellForRowAtIndexPath:indexPath];
        [self performSegueWithIdentifier:@"urlDetails" sender:cell];}
}

@end
