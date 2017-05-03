//
//  AGTAugmentSDK+Private.h
//  Augment
//
//  Created by Mert Buran on 6/28/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <AugmentPlayerSDK/AGTAugmentSDK.h>
#import <AugmentPlayerSDK/AGTAssetsPathProvider.h>
@class AGTWebAPI;
@class AGTModel3DDataController;
@class AGTModel3D;

/**
 *  AGTAugmentSDK for in-house use
 */
@interface AGTAugmentSDK (Private)

/**
 Underlying WebAPI
 */
@property (nonatomic, strong, readonly) AGTWebAPI *webAPI;

/**
 *  deletes model3D asset and metadata of given model3D from disk
 *
 *  @param model3D model3D to be deleted from disk
 */
- (void)deleteModel3DFromDisk:(AGTModel3D *)model3D;

/**
 *  this method lets us add a model 3D to Augment Player without fetching its JSON
 *  if you cancel returned download task, the whole operation is cancelled and model isn't added to AugmentPlayer
 *
 *  @param model3D                                model to be added to augmented reality scene
 *  @param model3DDataController                  data controller to download model 3D asset if needed
 *  @param assetType                              asset type to be downloaded. specifies if the asset to be kept permanently or in cache folder
 *  @param downloadProgress                       download progress block to be executed if download is needed. runs on background thread
 *  @param operationCompletionWithModelIdentifier returns unique model id from Augment Player if model is added to player successfully, otherwise returns nil and an error. runs on main thread
 *
 *  @return a newly created download task for downloading asset if needed. returns nil if no download initiated
 */
- (NSURLSessionDownloadTask *)addModel3DToAugmentPlayer:(AGTModel3D *)model3D
                                  model3DDataController:(AGTModel3DDataController *)model3DDataController
                                              assetType:(AGTAssetType)assetType
                                       downloadProgress:(AGTOperationProgressBlock)downloadProgress
                 operationCompletionWithModelIdentifier:(AGTOperationCompletedWithIdentifierBlock)operationCompletionWithModelIdentifier;

@end
