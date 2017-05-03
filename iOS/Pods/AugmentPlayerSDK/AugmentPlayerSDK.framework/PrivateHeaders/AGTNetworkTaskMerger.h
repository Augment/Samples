//
//  AGTNetworkTaskMerger.h
//  AugmentPlayerSDK
//
//  Created by Mert Buran on 10/11/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AugmentPlayerSDK/AGTNetworkManager.h>

typedef void(^AGTProgressBlock)(NSProgress *downloadProgress);
typedef void(^AGTCompletionBlock)(NSURLResponse *response, NSURL *filePath, NSError *error);

@interface AGTNetworkTaskMerger : NSObject


/**
 Init method

 @param networkManager                      object to create download tasks. 
                                            if HTTPMaximumConnectionsPerHost value is less or equal to 1, then you will have exception as you call suspendAllActiveDownloadTasksExceptForRequest
 @param maxParallelDownloadOperationCount   the size of active download tasks queue. 
                                            it can NOT be greater than networkManager's HTTPMaximumConnectionsPerHost; if so HTTPMaximumConnectionsPerHost value is used
 @return newly created AGTNetworkTaskMerger instance
 */
- (instancetype)initWithNetworkManager:(AGTNetworkManager *)networkManager
     maxParallelDownloadOperationCount:(NSInteger)maxParallelDownloadOperationCount;

- (BOOL)makeRequestHighPriorityIfExists:(NSURLRequest *)highPriorityRequest;
- (void)resumeAllActiveDownloadTasks;
- (void)suspendAllActiveDownloadTasksExceptForRequest:(NSURLRequest *)exceptionRequest;

- (void)cancelAllDownloadTasks;
- (void)cancelDownloadTaskWithRequest:(NSURLRequest *)request
                             callerID:(NSUUID *)callerID;

- (NSURLSessionDownloadTask *)downloadTaskWithRequest:(NSURLRequest *)request
                                             callerID:(NSUUID **)callerID
                                             progress:(AGTProgressBlock)downloadProgressBlock
                                          destination:(NSURL *)destination
                                    completionHandler:(AGTCompletionBlock)completionHandler;

@property (nonatomic, readonly) NSInteger maxParallelDownloadOperationCount;

/**
 Returned arrays are NOT in priority order.
 */
@property (nonatomic, strong, readonly) NSArray<NSURLSessionDownloadTask*> *activelyRunningDownloadTasks;
@property (nonatomic, strong, readonly) NSArray<NSURLSessionDownloadTask*> *queuedDownloadTasks;

@end
