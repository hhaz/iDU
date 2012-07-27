//
//  filterpreferences.m
//  DUiOS
//
//  Created by Hervé Azoulay on 02/06/12.
//  Copyright (c) 2012 ORSYP. All rights reserved.
//

#import "filterpreferences.h"
#import "duiosAppDelegate.h"
#import "computePeriod.h"


@implementation filterpreferences
@synthesize myTableView;
@synthesize contentsList = ivContentsList;
@synthesize sectionKeys = ivSectionKeys;
@synthesize arrayPeriods;


// Customize the appearance of table view cells.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    
    //static NSString *CellIdentifier = @"Cell";
    NSString *key = [[self sectionKeys] objectAtIndex:[indexPath section]];
    NSArray *contents = [[self contentsList] objectForKey:key];
    NSString *contentForThisRow = [contents objectAtIndex:[indexPath row]];
    
    NSString *CellIdentifier = [contents objectAtIndex:[indexPath row]];   
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:CellIdentifier];
    
    duiosAppDelegate *appDelegate = (duiosAppDelegate *)[[UIApplication sharedApplication] delegate];
    
    if (cell == nil)
	{
		cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:CellIdentifier];
        
        if ([indexPath section] == 0) {
             UITextField *node = [[UITextField alloc] initWithFrame:CGRectMake(210, 13, 185, 30)];
            if ([indexPath row] == 0) {
                node.adjustsFontSizeToFitWidth = YES;
                node.textColor = [UIColor blackColor];

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
                node.text = appDelegate.period;
                periods = node;
               
            }
            if ([indexPath row] == 1) {
                node.placeholder = @"required";
                node.keyboardType = UIKeyboardTypeNumberPad;
                node.returnKeyType = UIReturnKeyDefault;
                node.text = appDelegate.nbPeriods;
                nbPeriods = node;
            }
            [node addTarget:self 
                     action:@selector(removeKeyBoard:)
           forControlEvents:UIControlEventEditingDidEndOnExit];
            [cell addSubview:node];
        }
        
        if ([indexPath section] == 1) {
            UITextField *node = [[UITextField alloc] initWithFrame:CGRectMake(210, 13, 185, 30)];
            node.placeholder = @"required";
            node.keyboardType = UIKeyboardTypeNumberPad;
            node.returnKeyType = UIReturnKeyDefault;
            node.text = appDelegate.nbJobs;
            nbJobs = node;
            [node addTarget:self 
                     action:@selector(removeKeyBoard:)
           forControlEvents:UIControlEventEditingDidEndOnExit];
            [cell addSubview:node];
        }
         
        [[cell textLabel] setText:contentForThisRow];
    }
	
    return cell;
}

- (void)viewWillDisappear:(BOOL)animated {
    duiosAppDelegate *appDelegate = (duiosAppDelegate *)[[UIApplication sharedApplication] delegate];

    appDelegate.nbJobs = nbJobs.text;
    appDelegate.period = periods.text;
    appDelegate.nbPeriods = nbPeriods.text;
    
    computePeriod *computeDate = [[computePeriod alloc] init];
    [computeDate compute];

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

    NSMutableArray *keys = [[NSMutableArray alloc] init];
    NSMutableDictionary *contents = [[NSMutableDictionary alloc] init];
	
    NSString *period = @"Periods";
    NSString *nbrJobs = @"Max. Number of Jobs to Display";
    	
    [contents setObject:[NSArray arrayWithObjects:@"Period Type",@"Number of periods",nil] forKey:period];
    [contents setObject:[NSArray arrayWithObject:@"Number of Jobs"] forKey:nbrJobs];
    
    [keys addObject:period];
    [keys addObject:nbrJobs];
    
    [self setSectionKeys:keys];
    [self setContentsList:contents];
    
    arrayPeriods = [[NSMutableArray alloc] init];
    [arrayPeriods addObject:@"Minutes"];
    [arrayPeriods addObject:@"Hours"];
    [arrayPeriods addObject:@"Days"];
    [arrayPeriods addObject:@"Weeks"];
	
    //[keys release], keys = nil;
    //[contents release], contents = nil;
    
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
