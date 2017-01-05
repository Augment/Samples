//
//  AGTAugmentSDK.h
//  Augment
//
//  Created by Mert Buran on 6/24/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AGTTargetConditionals.h"
#import "AGTBlocks.h"

#import "AGTAugmentPlayer.h"
#import "AGTProductsDataController.h"

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Constants

/**
 AGTAugmentSDK is the main class of the SDK
 it has a built-in AGTAugmentPlayer property whose lifecycle is controlled by AGTAugmentSDK
 you can add model3Ds to AugmentPlayer via AGTAugmentSDK
 this header also contains all the public headers to make full use of this SDK
 */
@interface AGTAugmentSDK : NSObject

/**
 You can set your SDK's shared keys before
 creating your first AugmentSDK in your app's lifetime
 
 Once you set new values, you can NOT modify them again in your app's lifetime.
 Once shared SDK keys are used for any reason, you can NOT modify them.
 
 If you don't set values, AugmentPlayerSDK uses keys
 in your app's Info.plist, which must be structured in the following way:
 *  {AugmentPlayerSDKKeys: {clientID: "your client ID",
 *                          clientSecret: "your client secret",
 *                          VuforiaKey: "your Vuforia key"}
 *  }
 
 @param sharedClientID     your client ID
 @param sharedClientSecret your client secret
 @param sharedVuforiaKey   your Vuforia key
 
 @return YES if parameters are set as shared SDK keys,
 NO if shared keys aren't changed since they were already used or set before
 */
+ (BOOL)setSharedClientID:(NSString *)clientID
       sharedClientSecret:(NSString *)clientSecret
         sharedVuforiaKey:(NSString *)VuforiaKey;

/**
 *  IMPORTANT NOTE:
 *  you MUST add a DICTIONARY in your Info.plist like the following:
 *  {AugmentPlayerSDKKeys: {clientID: "your client ID",
 *                          clientSecret: "your client secret",
 *                          VuforiaKey: "your Vuforia key"}
 *  }
 *  OR
 *  you must call setSharedClientID:sharedClientSecret:sharedVuforiaKey: before calling this `init` method
 *
 *  create and initialize AGTAugmentSDK instance
 *  this method doesn't register and authenticate you into Augment webservice
 *  if your clientID and/or clientSecret is invalid, you will have an auth error during your first network request to Augment webservices
 *
 *  @param clientID     client identifier to register Augment webservice
 *  @param clientSecret client secret string to register Augment webservice
 *
 *  @return a newly created AGTAugmentSDK instance
 */
- (instancetype)init;

/**
 *  already created and initialized AugmentPlayer instance
 *  you can use it to provide augmented reality experience in your application
 */
@property (nonatomic, strong, readonly) AGTAugmentPlayer *augmentPlayer;

/**
 *  downloads the required asset or reads it from the disk and then adds corresponding model to its AugmentPlayer property
 *  in order to have required product object, you need to make query to Augment database via productsDataController property of AugmentSDK
 *
 *  @param product                                  AGTProduct instance that is created by AGTProductsDataController property of AugmentSDK
 *  @param downloadProgress                         progress block to be executed if download is needed. runs on background thread
 *  @param operationCompletionWithModelIdentifier   completion block that returns unique AugmentPlayer model identifier,
 *                                                  if whole process completes successfully and adding model to AugmentPlayer is successful. runs on main thread
 *
 *  @return a newly created download task for downloading asset if needed. returns nil if no download initiated
 */
- (nullable NSURLSessionDownloadTask *)addProductToAugmentPlayer:(AGTProduct *)product
                                                downloadProgress:(nullable AGTOperationProgressBlock)downloadProgress
                          operationCompletionWithModelIdentifier:(nullable AGTOperationCompletedWithIdentifierBlock)operationCompletionWithModelIdentifier;

/**
 *  deletes model3D asset and metadata of model3D that corresponds to given AGTProduct from disk
 *
 *  @param product product whose model3D assets and metadata to be deleted from disk
 */
- (void)deleteProductFromDisk:(AGTProduct *)product;

/**
 *  already created and initialized ProductsDataController instance
 *  you can use it in order to check if your product does exist in Augment database or not
 */
@property (nonatomic, strong, readonly) AGTProductsDataController *productsDataController;

@end

NS_ASSUME_NONNULL_END
