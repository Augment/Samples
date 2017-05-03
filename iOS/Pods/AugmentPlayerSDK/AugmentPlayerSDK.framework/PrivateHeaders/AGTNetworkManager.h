//
//  AGTNetworkManager.h
//  AugmentAPI
//
//  Created by Mert Buran on 8/18/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AGTOAuthCredential.h"

typedef NS_ENUM(NSUInteger, AGTHTTPMethod) {
    AGTHTTPGet = 1,
    AGTHTTPPost,
    AGTHTTPPut,
    AGTHTTPDelete,
};

typedef NS_ENUM(NSUInteger, AGTRequestType) {
    AGTDefaultHTTPRequest = 0,
    AGTJSONRequest,
};

NS_ASSUME_NONNULL_BEGIN

@interface AGTNetworkManager : NSObject

/**
 *  convenience initializer for AGTNetworkManager
 *  base URL is automatically set inside this method
 *
 *  @param clientID     clientID for Augment OAuth2
 *  @param clientSecret clientSecret for Augment OAuth2
 *
 *  @return newly created AGTNetworkManager instance
 */
+ (instancetype)managerWithClientID:(NSString *)clientID
                       clientSecret:(NSString *)clientSecret;

+ (instancetype)managerWithConfiguration:(NSURLSessionConfiguration *)configuration
                                clientID:(NSString *)clientID
                            clientSecret:(NSString *)clientSecret;

- (nullable NSURLSessionDataTask *)sendRequestWithMethod:(AGTHTTPMethod)method
                                             requestType:(AGTRequestType)requestType
                                             endpointURL:(NSString *)URLString
                                              parameters:(nullable id)parameters
                                                 success:(nullable void (^)(NSURLSessionDataTask *task, id _Nullable responseObject))success
                                                 failure:(nullable void (^)(NSURLSessionDataTask * _Nullable task, NSError *error))failure;

- (NSURLSessionDownloadTask *)downloadTaskWithRequest:(NSURLRequest *)request
                                             progress:(nullable void (^)(NSProgress *downloadProgress))downloadProgressBlock
                                          destination:(nullable NSURL * (^)(NSURL *targetPath, NSURLResponse *response))destination
                                    completionHandler:(nullable void (^)(NSURLResponse *response, NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler;

- (NSString *)headerValueForField:(NSString *)headerField;
- (void)setHeaderValue:(NSString *)value forField:(NSString *)field;

@property (readonly, nonatomic) NSString *serviceProviderIdentifier;
@property (readonly, nonatomic) NSString *clientID;
@property (readonly, nonatomic) NSURLSession *session;
@property (nonatomic, nullable) dispatch_queue_t completionQueue;

@end

NS_ASSUME_NONNULL_END
