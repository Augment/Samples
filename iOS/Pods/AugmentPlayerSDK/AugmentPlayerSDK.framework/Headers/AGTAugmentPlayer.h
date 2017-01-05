//
//  AGAugmentPlayer.h
//  Augment
//
//  Created by Stéphane GARAGNANI on 10/03/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "AGTTargetConditionals.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Scope: Public
 *  class that silently takes video input and user gestures to create video output to be displayed by AGTView
 */
@interface AGTAugmentPlayer : NSObject

@property (nonatomic, readonly, getter=isResuming) BOOL resuming;
@property (nonatomic, readonly, getter=isPaused) BOOL paused;

/**
 *  starts rendering inputs
 *  resumes or starts augmented reality experience
 *
 *  @return returns the error if occurs
 */
- (nullable NSError *)resume;

/**
 *  pauses rendering inputs
 */
- (void)pause;

/**
 *  unloads all the models that are added to the instance
 */
- (void)unloadAll;

/**
 * Take a screenshot of the current GL context with camera background and 3D models
 */
- (void)takeScreenshotWithCompletion:(void(^)(UIImage *_Nullable screenshotImage))completion;

@end

NS_ASSUME_NONNULL_END
