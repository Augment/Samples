//
//  AGTExternalReference.h
//  AugmentPlayerSDK
//
//  Created by Mert Buran on 10/16/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AugmentPlayerSDK/AGTModel3D+Private.h>

// TODO: if ext ref are cleaned, just remove that and simply resolve the contained url.
@interface AGTExternalReference : NSObject

@property (nonatomic, copy, readonly) NSString *uuid;
@property (nonatomic, copy, readonly) NSURL *url;
@property (nonatomic, copy, readonly) NSDate *updated_at;
@property (nonatomic, copy, readonly) NSDate *expires_at;
@property (nonatomic, copy, readonly) AGTModel3D *content;
@property (nonatomic, copy, readonly) NSString *tracker_uuid;
@property (nonatomic, copy, readonly) NSString *tracker_name;
@property (nonatomic, copy, readonly) NSString *owner_uuid;
@property (nonatomic, copy, readonly) NSString *owner_username;
@property (nonatomic, copy, readonly) NSString *owner_google_analytics_id;
@property (nonatomic, copy, readonly) NSNumber *owner_is_free_trial;

@end
