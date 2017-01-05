//
//  AGAugmentPlayerDevice.h
//  AugmentPlayer
//
//  Created by Stéphane GARAGNANI on 10/03/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AGTTargetConditionals.h"

NS_ASSUME_NONNULL_BEGIN

#if AGT_AR_AVAILABLE

/**
 *  Scope: Public
 *  device model to control device features like flash, focus and etc.
 */
@interface AGTDevice : NSObject

#pragma mark - Singleton device

/**
 *  singleton device model that can control device features
 *
 *  @return singleton device model instance
 */
+ (instancetype)currentDevice;

#pragma mark - Actions and states

/**
 *  triggers device camera's autofocus action. the action takes place momentarily, it is not continuous
 */
- (void)triggerAutoFocus;

/**
 checks if device has torch

 @return YES if device has torch, NO otherwise
 */
- (BOOL)hasTorch;

/**
 get state of device camera's torch/flash

 @return YES if torch is turned on, NO otherwise
 */
- (BOOL)isTorchOn;

/**
 set state of device camera's torch/flash

 @param on YES to turn on, NO to turn off

 @return YES if operation successful, NO otherwise
 */
- (BOOL)setTorchOn:(BOOL)on;

@end

#endif

NS_ASSUME_NONNULL_END
