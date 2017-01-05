//
//  AGTTaskContainer.h
//  AugmentAPI
//
//  Created by Mert Buran on 8/23/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 *  state affects tasks that AGTTaskContainer instance proceeds with
 */
typedef NS_ENUM(NSUInteger, AGTTaskContainerState) {
    /**
     *  activeTask resumes, new tasks resume
     */
    AGTTaskContainerStateDefault = 0,
    /**
     *  activeTask suspends and does not change, new tasks cancel
     */
    AGTTaskContainerStateSuspending,
    /**
     *  activeTask cancels and becomes nil, new tasks cancel
     */
    AGTTaskContainerStateCancelling,
};

/**
 *  example use case of this class:
 *  the caller tells the API to fetch items that requires authentication before fetching actual items
 *  the caller is returned AGTTaskContainer synchronously and 
 *      the caller can keep track of network requsts made after this point without knowing anything about them
 */
@interface AGTTaskContainer : NSObject

/**
 *  please refer to enum documentation above
 */
@property (atomic) AGTTaskContainerState state;

/**
 *  ongoing network task at the moment
 *  it becomes nil as soon as the task completes or cancels
 */
@property (nonatomic, strong, readonly, nullable) NSURLSessionTask *activeTask;

/**
 *  callback block to control active network task changes
 *  if you return NO in this block, newActiveTask cancels and activeTask doesn't change
 *  if this block is nil, AGTTaskContainer assumes it returns YES
 */
@property (nonatomic, copy, nullable) BOOL (^shouldActiveTaskChange)(NSURLSessionTask *_Nullable currentActiveTask, NSURLSessionTask *_Nullable newActiveTask);

/**
 *  adding network tasks to container
 *  NOTE: AGTTaskContainer supports only one single activeTask at the moment for the sake of simplicity
 *        if you proceedWithNewTask:, you will lose the track of previous activeTask but its state is not affected 
 *
 *  @param newTask network task object to be added into container
 *
 *  @return return YES if newTask becomes activeTask, otherwise NO
 */
- (BOOL)proceedWithNewTask:(NSURLSessionTask *)newTask;

@end

NS_ASSUME_NONNULL_END
