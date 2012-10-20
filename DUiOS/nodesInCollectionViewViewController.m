//
//  jobsInCollectionViewViewController.m
//  iDU
//
//  Created by Hervé AZOULAY on 17/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import "nodesInCollectionViewViewController.h"
#import "collectionViewCell.h"
#import "DuWebServiceSvc.h"
#import "graphview.h"

@implementation nodesInCollectionViewViewController
@synthesize appDelegate;

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
    appDelegate = (iDUAppDelegate *)[[UIApplication sharedApplication] delegate];
    _retrieveJobs = [[getJobs alloc]init];
    
    if(refresh == nil)
    {
        refresh = [[UIRefreshControl alloc]initWithFrame:CGRectMake(0, 0 , 220, 22)];
        NSAttributedString *title = [[NSAttributedString alloc]initWithString:@"Refreshing Node List"];
        refresh.attributedTitle = title;
        [refresh addTarget:self action:@selector(refreshNodeList) forControlEvents:UIControlEventValueChanged];
    }
    
    [theNodes addSubview:refresh];
    
	// Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView *)collectionView
{
    return 1;
}

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return [appDelegate.nodeList count];
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *CellIdentifier = @"Cell";
    
    DuWebServiceSvc_envir *node = [appDelegate.nodeList objectAtIndex: [indexPath row]];
    DuWebServiceSvc_envirStatus status = node.status;
    NSString *imageFile = [[NSString alloc]init];
    NSString *nodeItem  = node.node_;
    
    if(status == DuWebServiceSvc_envirStatus_CONNECTED)
    {
        imageFile = @"DU.png";
    }
    else
    {
        imageFile = @"DUInactive.png";
    }

    collectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:CellIdentifier forIndexPath:indexPath];

    if (cell == nil) {
        cell = [[collectionViewCell alloc]init];

    }
    
    [cell.imgProfile setImage:[UIImage imageNamed:imageFile]];
    [cell.lblTitle setText:nodeItem];
    
    return cell;
}

- (void)collectionView:(UICollectionView *)collectionView didSelectItemAtIndexPath:(NSIndexPath *)indexPath
{
    collectionViewCell *cell = (collectionViewCell *)[collectionView  cellForItemAtIndexPath:indexPath];
    
    _theNode = cell.lblTitle.text;
    
    [_retrieveJobs getJobs:self :_theNode :@"seguegraph2" :TRUE :nil :nil];
    
}

-(void) prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender

{
    if ([[segue identifier] isEqualToString:@"seguegraph2"])
    {
        graphview *graphviewController = [segue destinationViewController];
        
        graphviewController.nodeName        = _theNode;
        graphviewController.launchList      = _retrieveJobs.launchList;
        graphviewController.executionList   = _retrieveJobs.executionList;
    }
}


@end
