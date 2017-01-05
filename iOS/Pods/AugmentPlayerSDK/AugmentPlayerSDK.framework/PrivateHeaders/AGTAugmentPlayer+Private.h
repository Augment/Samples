//
//  AGTAugmentPlayer+Private.h
//  Augment
//
//  Created by Mert Buran on 5/4/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <AugmentPlayerSDK/AGTAugmentPlayer.h>
#import <AugmentPlayerSDK/AGTModel3D.h>
#import <AugmentPlayerSDK/AGTMaterial.h>
#import <AugmentPlayerSDK/AGTDisplayConfiguration.h>
@class  UIImage;

// TODO: rename to verbs: Tracking, Viewing, CreatingTracker and etc.
typedef NS_ENUM(NSUInteger, AGTAugmentPlayerMode) {
    AGTAugmentPlayerModeNone = 0,
    AGTAugmentPlayerModeTracker = 1,
    AGTAugmentPlayerModeScanner,
    AGTAugmentPlayerModeViewer,
    AGTAugmentPlayerModeCreateTracker,
};

#pragma mark - Scanner mode

typedef NS_ENUM(NSUInteger, AGTAugmentPlayerNotificationType) {
    AGTScannerScanning = 1,         // Try to find a cloud tracker.
    AGTScannerQrCodeFound,          // A Qrcode has been found
    AGTScannerCloudTrackerFound,    // A cloud tracker has been found
    AGTScannerTimeout,              // The user stayed too long in Scanning mode
    AGTScannerIsNotTrackingWarning, // Explain to user that scanning mode is not tracking if he detects a tracker
    
    AGTBuilderBuilding = 11,        // The target builder is started.
    AGTBuilderNoQuality,            // No quality, the builder has not started.
    AGTBuilderBadQuality,           // Bad quality frame.
    AGTBuilderMediumQuality,        // Medium quality frame.
    AGTBuilderGoodQuality,          // Good quality frame.
    AGTBuilderCreationPending,      // Pending for custom tracker creation (in 2 or 3 frames).
    AGTBuilderSuccess,
    
    AGTTrackerModelSizeChange = 21, // Model size did change
    AGTMaterialListChanged,         // A new list of materials is available for selected model
};

struct AGTModelSize {
    double x, y, z, scale;
};

#pragma mark - Model adding support

/**
 *  Scope: Private
 *  category that provides required keys and methods for scanning functionality of AugmentPlayer
 */
@interface AGTAugmentPlayer (Private)

#if AGT_AR_AVAILABLE

/**
 *  describes the kind of augmented reality experience
 *  example: Tracker, Scanning, Tracker creation and etc.
 */
@property (nonatomic) AGTAugmentPlayerMode playerMode;

#pragma mark - Notifications mode

// NOTE 4/10/2016
// At the moment, notifications methods don't have to be instance methods
// But there are 2 reasons that I declare them as so:
// 1- In the future, we may stop using NSNotificationCenter
// 2- If you don't retain an AGTAugmentPlayer instance, you shouldn't be using these notifications

/**
 if set YES: AugmentPlayer starts posting notifications related to scanning events
 if set NO: AugmentPlayer stops posting notifications related to scanning events
 */
@property (nonatomic, getter=isBroadcastingNotifications) BOOL broadcastingNotifications;

- (void)addObserver:(id)observer forNotification:(AGTAugmentPlayerNotificationType)notificationType selector:(SEL)selector;
- (void)removeObserver:(id)observer forNotification:(AGTAugmentPlayerNotificationType)notificationType;

#pragma mark - Scanner mode

- (NSURL *)detectedURL;

#pragma mark - Tracker Creation

- (NSError *)createTracker;

#pragma mark - Scenery actions

- (void)fitModel3DsToView;
- (void)rotateLastTouchedModel3DAroundXAxisBy90Degrees;
- (void)setModel3DsShadowsEnabled:(BOOL)enabled;
- (void)updateModel3DSettings:(AGTModel3D*)model3D withIdentifier:(NSString*)identifier;

#pragma mark - Change Materials

- (BOOL)hasChangeableMaterials;
- (void)startChangeMaterialMode:(void (^)(NSArray<AGTMaterial*> *selectableMaterials, NSInteger selectedMaterialIndex, NSError *error))availableMaterialListChangedBlock;
- (void)stopChangeMaterialMode;
- (void)setMaterial:(AGTMaterial*)material;

#pragma mark - Model information

- (struct AGTModelSize)getSelectedModelSize;
- (NSString *)getSelectedModelUnit;
- (AGTDisplayConfiguration *)getSelectedDisplayConfiguration;

#endif

#pragma mark - Model adding support

/**
 *  adds model to AugmentPlayer
 *
 *  @param model3D         model metadata associated to model 3D asset
 *  @param modelAssetsPath path of folder that contains model 3D asset
 *
 *  @return unique identifier that identifies the model among others that are added to AugmentPlayer
 */
- (NSString *)addModel3D:(AGTModel3D *)model3D
         modelAssetsPath:(NSString*)modelAssetsPath
                   error:(NSError **)error;

@end
