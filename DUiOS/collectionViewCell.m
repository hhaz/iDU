//
//  collectionViewCell.m
//  iDU
//
//  Created by Hervé AZOULAY on 17/09/12.
//  Copyright (c) 2012 HAZ. All rights reserved.
//

#import "collectionViewCell.h"

@implementation collectionViewCell
@synthesize imgProfile;
@synthesize imgNotification;
@synthesize lblTitle;


- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        // Initialization code
    }
    return self;
}

/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect
{
    // Drawing code
}
*/

@end
