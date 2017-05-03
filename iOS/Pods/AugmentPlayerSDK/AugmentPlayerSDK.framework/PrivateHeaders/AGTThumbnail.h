//
//  AGTThumbnail.h
//  Augment2
//
//  Created by Mert Buran on 1/26/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AGTThumbnail : NSObject

@property (nonatomic, copy, readonly) NSString *url;
@property (nonatomic, copy, readonly) NSNumber *width;
@property (nonatomic, copy, readonly) NSNumber *height;

@end
