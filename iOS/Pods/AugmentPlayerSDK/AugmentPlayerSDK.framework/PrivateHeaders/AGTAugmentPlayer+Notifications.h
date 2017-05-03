//
//  AGTAugmentPlayer+Notifications.h
//  AugmentPlayerSDK
//
//  Created by Mert Buran on 12/29/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <AugmentPlayerSDK/AGTAugmentPlayer.h>

typedef NS_ENUM(NSUInteger, AGTAugmentPlayerNotificationType) {
    AGTScannerScanning = 1,         // Try to find a cloud tracker.
    AGTScannerQrCodeFound,          // A Qrcode has been found
    AGTScannerCloudTrackerFound,    // A cloud tracker has been found
    AGTScannerTimeout,              // The user stayed too long in Scanning mode
    AGTScannerIsNotTrackingWarning, // Explain to user that scanning mode is not tracking if he detects a tracker
    
    AGTTrackingTrackerless = 101,    // Tracking did not found trackers.
    AGTTrackingCustomTracker,       // A user defined tracker has been detected.
    AGTTrackingCloudTracker,        // A cloud tracker has been detected.
    AGTTrackingAugmentTracker,      // The Augment standard tracker has been detected.
    
    AGTBuilderBuilding = 201,       // The target builder is started.
    AGTBuilderNoQuality,            // No quality, the builder has not started.
    AGTBuilderBadQuality,           // Bad quality frame.
    AGTBuilderMediumQuality,        // Medium quality frame.
    AGTBuilderGoodQuality,          // Good quality frame.
    AGTBuilderCreationPending,      // Pending for custom tracker creation (in 2 or 3 frames).
    AGTBuilderSuccess,
    
    AGTModelSizeDidChange = 301,    // Model size did change
    AGTEngineDidSendModelURLSignal, // Model URL signal is sent
};

// AGTScannerCloudTrackerFound & AGTScannerQrCodeFound
extern NSString * const AGTScannerNotificationUserInfoURL;

// AGTModelSizeDidChange
extern NSString * const AGTModelSizeDidChangeUserInfoX;
extern NSString * const AGTModelSizeDidChangeUserInfoY;
extern NSString * const AGTModelSizeDidChangeUserInfoZ;
extern NSString * const AGTModelSizeDidChangeUserInfoScale;
extern NSString * const AGTModelSizeDidChangeUserInfoUnitString;

// AGTEngineDidSendModelURLSignal
extern NSString * const AGTEngineDidSendModelURLSignalUserInfoURL;

@interface AGTARNotificationCenter : NSObject

+ (instancetype)sharedCenter;

- (BOOL)isBroadcastingNotifications;
- (void)beginBroadcastingNotifications;
- (void)endBroadcastingNotifications;

- (void)addObserver:(id)observer forNotification:(AGTAugmentPlayerNotificationType)notificationType selector:(SEL)selector;
- (void)removeObserver:(id)observer forNotification:(AGTAugmentPlayerNotificationType)notificationType;

@end
