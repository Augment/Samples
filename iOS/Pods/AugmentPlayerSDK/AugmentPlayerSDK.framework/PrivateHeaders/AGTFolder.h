//
//  AGTFolder.h
//  Pods
//
//  Created by Mert Buran on 8/8/16.
//
//

#import <Foundation/Foundation.h>
#import "AGTThumbnail.h"

typedef NS_ENUM(NSUInteger, AGFolderLicenseStatus) {
    AGFolderLicenseInvalid = 0,
    AGFolderLicenseValid
};

@interface AGTFolder : NSObject

@property (nonatomic, copy, readonly) NSString *uuid;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSDate *updated_at;
@property (nonatomic, copy, readonly) NSString *owner_uuid;
@property (nonatomic, copy, readonly) AGTThumbnail *small_thumbnail;
@property (nonatomic, copy, readonly) AGTThumbnail *large_thumbnail;

@property (nonatomic) AGFolderLicenseStatus licenseStatus;
@property (nonatomic, copy, readonly) NSNumber *is_accessible;

@end
