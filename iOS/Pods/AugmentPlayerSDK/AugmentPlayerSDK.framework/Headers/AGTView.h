//
//  EAGLView.h
//  AugmentSdkIos
//
//  Created by Augment on 12/12/12.
//  Copyright (c) 2012 AugmenteDev. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AGTTargetConditionals.h"

@class AGTView;
@class AGTAugmentPlayer;

NS_ASSUME_NONNULL_BEGIN

@protocol AGTViewDelegate <NSObject>

@optional

/****
 These parameters have the same meaning for all AGTViewDelegate methods

 @param view                   sender instance
 @param gestureRecognizer      active gesture recognizer
 @param success                YES if the gesture applied on a model 3D in the scene, NO otherwise
 *///

// Starts animating model 3D
- (void)view:(AGTView *)view appliedOneFingerTap:(UITapGestureRecognizer *)oneFingerTapRecognizer withSuccess:(BOOL)success;
// Moves model 3D in the scene
- (void)view:(AGTView *)view appliedOneFingerPan:(UIPanGestureRecognizer *)oneFingerPanRecognizer withSuccess:(BOOL)success;
// Rotates model 3D in the scene
- (void)view:(AGTView *)view appliedTwoFingerPan:(UIPanGestureRecognizer *)twoFingerPanRecognizer withSuccess:(BOOL)success;
// Scales model 3D in the scene
- (void)view:(AGTView *)view appliedPinch:(UIPinchGestureRecognizer *)pinchRecognizer withSuccess:(BOOL)success;
// Rotates model 3D in the scene
- (void)view:(AGTView *)view appliedRotation:(UIRotationGestureRecognizer *)rotationRecognizer withSuccess:(BOOL)success;

@end

/**
 *  Scope: Public
 *  UIView subclass that displays output of AugmentPlayer
 */
@interface AGTView : UIView

@property (nonatomic, weak, nullable) IBOutlet id<AGTViewDelegate> delegate;

#if AGT_AR_AVAILABLE

/**
 *  AugmentPlayer instance of whose output is displayed by this instance
 */
@property (nonatomic, weak, nullable) IBOutlet AGTAugmentPlayer *augmentPlayer;

#endif

@end

NS_ASSUME_NONNULL_END
