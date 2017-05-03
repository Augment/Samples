//
//  AGTError.h
//  Augment
//
//  Created by Mert Buran on 6/29/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <Foundation/Foundation.h>

#pragma mark - Errors

//*****************************************//
#pragma mark - Augment Player Errors
#pragma mark - Error domains

/**
 *  domain for errors come from Augment Player/augmented reality realm
 */
extern NSString * const AGTAugmentPlayerErrorDomain;

#pragma mark - Error codes
/**
 *  error codes for Augment Player/augmented reality realm
 */
NS_ENUM(NSInteger) {
    /**
     *  unknown error
     */
    AGTAugmentPlayerErrorUnknown = -1,
    /**
     *  error occurred during initialization environment
     */
    AGTAugmentPlayerErrorInitializationError = -100,
    /**
     *  error occurred during accessing the camera
     */
    AGTAugmentPlayerErrorCameraNotAccessible = -101,
    /**
     *  error occurred during adding a model to Augment Player
     */
    AGTAugmentPlayerErrorInvalidModelToAdd = -200,
    /**
     *  model 3D asset or metadata does not exist in local disk
     */
    AGTAugmentPlayerErrorAssetDoesNotExist = -404,
    /**
     *  createTracker method failed for some reason
     */
    AGTAugmentPlayerErrorTrackerCreationFailed = -500,
    /**
     *  No Model3d is selected to change its material
     */
    AGTAugmentPlayerErrorMaterialNoModel3dSelected = -600,
};
