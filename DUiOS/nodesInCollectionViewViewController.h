//
//  jobsInCollectionViewViewController.h
//  iDU
//
//  Created by Hervé AZOULAY on 17/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "iDUAppDelegate.h"
#import "getJobs.h"

@interface nodesInCollectionViewViewController : UICollectionViewController
{
    UIRefreshControl *refresh;
    IBOutlet UICollectionView *theNodes;
}

@property (nonatomic, retain) iDUAppDelegate *appDelegate;
@property (nonatomic, retain) NSString *theNode;
@property (nonatomic, retain) getJobs *retrieveJobs;

@end
