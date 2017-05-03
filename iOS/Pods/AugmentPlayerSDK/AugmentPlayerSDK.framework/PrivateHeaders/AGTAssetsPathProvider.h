//
//  AGTAssetsPathProvider.h
//  Augment
//
//  Created by Mert Buran on 5/31/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Reserved for future use
 *  e.g. static backgrounds and etc.
 */
typedef NS_ENUM(NSUInteger, AGTAssetType) {
    AGTAssetTypePermanentModel3D,
    AGTAssetTypeDiscardableModel3D,
};

/**
 *  Scope: Private
 *  this class is responsible for providing file paths for assets with given asset identifier
 */
@interface AGTAssetsPathProvider : NSObject

+ (NSString *)basePathForAsseType:(AGTAssetType)assetType;
+ (NSArray<NSString*> *)existingAssetIdentifiersOnDiskForAssetType:(AGTAssetType)assetType;

@property (nonatomic, readonly) AGTAssetType assetType;
@property (nonatomic, copy, readonly) NSString *assetIdentifier;

/**
 *  once you create an instance, then you can access the information below via that instance
 */
@property (nonatomic, readonly) NSString *destinationPath;
@property (nonatomic, readonly) NSString *assetFilePath;
@property (nonatomic, readonly) NSString *metadataFilePath;
@property (nonatomic, readonly) NSString *innerFolderPath;
@property (nonatomic, readonly) BOOL isAssetOnDisk;
@property (nonatomic, readonly) BOOL isMetadataOnDisk;

@end

@interface AGTAssetsPathProviderContainer : NSObject

- (instancetype)initWithAssetIdentifier:(NSString *)assetIdentifier;
- (AGTAssetsPathProvider *)pathProviderForType:(AGTAssetType)assetType;

@property (nonatomic, copy, readonly) NSString *assetIdentifier;

@end
