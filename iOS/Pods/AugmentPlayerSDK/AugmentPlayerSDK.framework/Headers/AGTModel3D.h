//
//  AGTModel3D.h
//  Augment2
//
//  Created by Mert Buran on 1/26/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AGTThumbnail.h"
#import "AGTDimension.h"
#import "AGTDisplayConfiguration.h"

@interface AGTModel3DFile : NSObject

@property (nonatomic, copy, readonly) NSString *uuid;
@property (nonatomic, copy, readonly) NSString *owner_uuid;

@end

@interface AGTModel3D : NSObject

@property (nonatomic, copy, readonly) NSString *uuid;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSString *model_url;
@property (nonatomic, copy, readonly) NSString *author;
@property (nonatomic, copy, readonly) NSString *category;
@property (nonatomic, copy, readonly) NSString *model_description;
@property (nonatomic, copy, readonly) NSString *tags;
@property (nonatomic, copy, readonly) NSString *owner_username;
@property (nonatomic, copy, readonly) NSString *owner_uuid;
@property (nonatomic, copy, readonly) NSString *owner_google_analytics_id;
@property (nonatomic, copy, readonly) NSString *website_url;
@property (nonatomic, copy, readonly) NSString *watermark_url;
@property (nonatomic, copy, readonly) NSString *processing_state;

@property (nonatomic, copy, readonly) NSDate *created_at;
@property (nonatomic, copy, readonly) NSDate *updated_at;

@property (nonatomic, copy, readonly) AGTThumbnail *small_thumbnail;
@property (nonatomic, copy, readonly) AGTThumbnail *large_thumbnail;

@property (nonatomic, copy, readonly) NSNumber *is_public;
@property (nonatomic, copy, readonly) NSNumber *is_enabled;

@property (nonatomic, copy, readonly) AGTModel3DFile *model3d_file;
@property (nonatomic, copy, readonly) AGTDimension *computed_dimension;
@property (nonatomic, copy, readonly) AGTDisplayConfiguration *display_configuration;

@end
