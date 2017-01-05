//
//  AGTAugmentSDK+Private.h
//  Augment
//
//  Created by Mert Buran on 6/28/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <AugmentPlayerSDK/AGTAugmentSDK.h>
#import "AGTModel3DDataController.h"
@class AGTModel3D;

/**
 *  AGTAugmentSDK for in-house use
 */
@interface AGTAugmentSDK (Private)

@property (nonatomic, strong) AGTModel3DDataController *model3DDataController;
@property (nonatomic, strong, readwrite) AGTProductsDataController *productsDataController;
@property (nonatomic, strong, readwrite) AGTAugmentPlayer *augmentPlayer;


- (instancetype)initWithClientID:(NSString *)clientID clientSecret:(NSString *)clientSecret;

- (instancetype)initWithModel3DDataController:(AGTModel3DDataController *)model3DDataController
                       productsDataController:(AGTProductsDataController *)productsDataController
                                augmentPlayer:(AGTAugmentPlayer *)augmentPlayer;

/**
 *  this method lets us add a model 3D to Augment Player without fetching its JSON
 *
 *  @param model3D                                model to be added to augmented reality scene
 *  @param downloadProgress                       download progress block to be executed if download is needed. runs on background thread
 *  @param operationCompletionWithModelIdentifier returns unique model id from Augment Player if model is added to player successfully, otherwise returns nil and an error. runs on main thread
 *
 *  @return a newly created download task for downloading asset if needed. returns nil if no download initiated
 */
- (NSURLSessionDownloadTask *)addModel3DToAugmentPlayer:(AGTModel3D *)model3D
                                       downloadProgress:(AGTOperationProgressBlock)downloadProgress
                 operationCompletionWithModelIdentifier:(AGTOperationCompletedWithIdentifierBlock)operationCompletionWithModelIdentifier;

/**
 *  deletes model3D asset and metadata of given model3D from disk
 *
 *  @param model3D model3D to be deleted from disk
 */
- (void)deleteModel3DFromDisk:(AGTModel3D *)model3D;

@end
