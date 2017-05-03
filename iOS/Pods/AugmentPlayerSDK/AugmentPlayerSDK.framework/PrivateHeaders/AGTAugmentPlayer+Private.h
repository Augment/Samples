//
//  AGTAugmentPlayer+Private.h
//  Augment
//
//  Created by Mert Buran on 5/4/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <AugmentPlayerSDK/AGTAugmentPlayer.h>
#import <AugmentPlayerSDK/AGTModel3D.h>
#import <AugmentPlayerSDK/AGTModel3D+Private.h>
#import <AugmentPlayerSDK/AGTMaterial.h>

NS_ASSUME_NONNULL_BEGIN

// TODO: rename to verbs: Tracking, Viewing, CreatingTracker and etc.
typedef NS_ENUM(NSUInteger, AGTAugmentPlayerMode) {
    AGTAugmentPlayerModeNone = 0,
    AGTAugmentPlayerModeTracker = 1,
    AGTAugmentPlayerModeScanner,
    AGTAugmentPlayerModeViewer,
    AGTAugmentPlayerModeCreateTracker,
};

#pragma mark - Model adding support

/**
 *  Scope: Private
 *  category that provides required keys and methods for scanning functionality of AugmentPlayer
 */
@interface AGTAugmentPlayer (Private)

@property (nonatomic, strong, readonly) NSArray<NSUUID*> *model3DSceneIdentifiers;

#if AGT_AR_AVAILABLE

/**
 *  describes the kind of augmented reality experience
 *  example: Tracker, Scanning, Tracker creation and etc.
 */
@property (nonatomic) AGTAugmentPlayerMode playerMode;

#pragma mark - Tracker Creation

- (nullable NSError *)createTracker;

#pragma mark - Scenery actions

- (void)rotateLastTouchedModel3DAroundXAxisBy90Degrees;
- (void)setModel3DsShadowsEnabled:(BOOL)enabled;
- (AGTDisplayConfiguration *)getSelectedDisplayConfiguration;
- (void)updateModel3DSettings:(AGTModel3D *)model3D withIdentifier:(NSUUID *)identifier;

#pragma mark - Change Materials

- (BOOL)hasChangeableMaterials;
- (void)startChangeMaterialMode:(void (^)(NSArray<AGTMaterial*> *selectableMaterials, NSInteger selectedMaterialIndex, NSError * _Nullable error))availableMaterialListChangedBlock;
- (void)stopChangeMaterialMode;
- (void)setMaterial:(AGTMaterial *)material;

#pragma mark - Model adding support

/**
 *  adds model to AugmentPlayer
 *
 *  @param model3D         model metadata associated to model 3D asset
 *  @param modelAssetsPath path of folder that contains model 3D asset
 *
 *  @return unique identifier that identifies the model among others that are added to AugmentPlayer
 */
- (nullable NSUUID *)addModel3D:(AGTModel3D *)model3D
                modelAssetsPath:(NSString*)modelAssetsPath
                          error:(NSError **)error;

/**
 removes model 3Ds with their scene idenfifiers
 
 @param model3DSceneIdentifiers scene identifiers of model 3Ds that are already added to scene
 */
- (void)removeModel3DsFromSceneWithSceneIdentifiers:(NSArray<NSUUID*> *)model3DSceneIdentifiers;

#endif

@end

NS_ASSUME_NONNULL_END
