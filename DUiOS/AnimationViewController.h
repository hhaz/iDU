//
//  AnimationViewController.h
//  iDU
//
//  Created by Hervé AZOULAY on 23/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface AnimationViewController : UIViewController{
    IBOutlet UIImageView *imageView;
    IBOutlet UILabel *D;
    IBOutlet UILabel *O;
    IBOutlet UILabel *L1;
    IBOutlet UILabel *L2;
    IBOutlet UILabel *A;
    IBOutlet UILabel *R;
    IBOutlet UILabel *UNIVERSE;
}

@property (nonatomic,retain) UIImageView *imageView;
@property (nonatomic,retain) UILabel *D;
@property (nonatomic,retain) UILabel *O;
@property (nonatomic,retain) UILabel *L1;
@property (nonatomic,retain) UILabel *L2;
@property (nonatomic,retain) UILabel *A;
@property (nonatomic,retain) UILabel *R;
@property (nonatomic,retain) UILabel *UNIVERSE;


@end
