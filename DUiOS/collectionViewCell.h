//
//  collectionViewCell.h
//  iDU
//
//  Created by Hervé AZOULAY on 17/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface collectionViewCell : UICollectionViewCell{
    
    IBOutlet UIImageView *imgProfile;
    IBOutlet UIImageView *imgNotification;
    IBOutlet UILabel     *lblTitle;
    
}

@property (nonatomic, retain) IBOutlet UIImageView *imgProfile;
@property (nonatomic, retain) IBOutlet UIImageView *imgNotification;
@property (nonatomic, retain) IBOutlet UILabel     *lblTitle;


@end
