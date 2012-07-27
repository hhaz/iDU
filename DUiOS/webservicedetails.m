//
//  webservicedetails.m
//  DUiOS
//
//  Created by Hervé Azoulay on 04/02/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import "webservicedetails.h"
#import "settings.h"
#import "duiosAppDelegate.h"

@implementation webservicedetails
@synthesize  contentsList;
@synthesize  sectionKeys;
@synthesize myTableView;
@synthesize aSettings;

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

    NSMutableArray *keys = [[NSMutableArray alloc] init];
    NSMutableDictionary *contents = [[NSMutableDictionary alloc] init];
	
    NSString *url = @"Web Service URL";
	
    [contents setObject:[NSArray arrayWithObjects:@"URL",@"Suffix",nil] forKey:url];
	
    [keys addObject:url];
	
    [self setSectionKeys:keys];
    [self setContentsList:contents];
    
    aSettings = [self.navigationController.viewControllers  objectAtIndex:0];
    
    //[keys release], keys = nil;
    //[contents release], contents = nil;
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
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
}

- (void)viewWillDisappear:(BOOL)animated
{
    [super viewWillDisappear:animated];
    
    if(theURL.text != nil && theSuffix.text != nil)
    {
        aSettings.WSURL     = theURL.text;
        aSettings.WSSuffix  = theSuffix.text;
    }

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

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    NSString *key = [[self sectionKeys] objectAtIndex:[indexPath section]];
    NSArray *contents = [[self contentsList] objectForKey:key];
    NSString *contentForThisRow = [contents objectAtIndex:[indexPath row]];
    
    duiosAppDelegate *appDelegate = (duiosAppDelegate *)[[UIApplication sharedApplication] delegate];

    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    
    if (cell == nil)
	{
		cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
    // Configure the cell...
    
    if ([indexPath section] == 0) {
        UITextField *url = [[UITextField alloc] initWithFrame:CGRectMake(100, 10, 185, 30)];
        url.adjustsFontSizeToFitWidth = YES;
        url.textColor = [UIColor blackColor];
        if ([indexPath row] == 0) {
            url.placeholder = @"http://server:port";
            url.keyboardType = UIKeyboardTypeURL;
            url.returnKeyType = UIReturnKeyDefault;
            url.text = appDelegate.url;
            theURL = url;
        }
        if ([indexPath row] == 1) {
            url.placeholder = @"/du6ws/DuwsSEI";
            url.keyboardType = UIKeyboardTypeURL;
            url.returnKeyType = UIReturnKeyDefault;
            url.text = appDelegate.suffix;
            theSuffix = url;
        }
        [url addTarget:self 
                action:@selector(removeKeyBoard:)
      forControlEvents:UIControlEventEditingDidEndOnExit];
        [cell addSubview:url];
    }

    [[cell textLabel] setText:contentForThisRow];
        
    }
    return cell;
}

-(IBAction)removeKeyBoard:(id)sender {
    [sender resignFirstResponder];
}

#pragma mark - Table view delegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    // Navigation logic may go here. Create and push another view controller.
    /*
     <#DetailViewController#> *detailViewController = [[<#DetailViewController#> alloc] initWithNibName:@"<#Nib name#>" bundle:nil];
     // ...
     // Pass the selected object to the new view controller.
     [self.navigationController pushViewController:detailViewController animated:YES];
     [detailViewController release];
     */
}

@end
