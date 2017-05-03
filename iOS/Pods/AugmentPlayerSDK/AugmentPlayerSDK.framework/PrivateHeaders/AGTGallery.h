//
//  AGTGallery.h
//  Pods
//
//  Created by Mert Buran on 8/8/16.
//
//

#import <Foundation/Foundation.h>

// TODO: there is a naming pb between gallery and category.
@interface AGTGallery : NSObject

@property (nonatomic, copy, readonly) NSString *uuid;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSDate *updated_at;
@property (nonatomic, copy, readonly) NSString *thumbnail_url;

@end
