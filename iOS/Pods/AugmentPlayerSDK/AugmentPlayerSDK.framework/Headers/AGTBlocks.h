//
//  AGTBlocks.h
//  Augment
//
//  Created by Mert Buran on 6/24/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#ifndef AGTBlocks_h
#define AGTBlocks_h

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

#pragma mark - Async operation blocks

/**
 *  Can be used for time-consuming async operations
 *
 *  @param progress NSProgress instance which contains current progress information
 */
typedef void (^AGTOperationProgressBlock)(NSProgress *progress);

/**
 *  Can be used for async operations in general
 *  NOTE: error can be NON-nil while success is YES
 *
 *  @param downloadStarted YES if download is needed and started, NO if no download started
 *  @param error NSError instance which contains error information. can be nil if no error occurred
 */
typedef void (^AGTDownloadIfNeededCompletionBlock)(BOOL downloadStarted, NSError * _Nullable error);

#pragma mark - Async operation with return value blocks

/**
 *  Can be used with async operations which returns a value at completion
 *  e.g: when AugmentPlayer adds a model to itself, it assigns an ID to the model and that ID should be returned
 *
 *  @param itemIdentifier a string value.
 *  @param errors         NSError array which contains error informations. can be nil if no error occurred, can contain one NSError from webservice and one error from AugmentPlayer
 */
typedef void (^AGTOperationCompletedWithIdentifierBlock)(NSUUID * _Nullable itemIdentifier, NSArray<NSError*> * _Nullable errors);

NS_ASSUME_NONNULL_END

#endif /* AGTBlocks_h */
