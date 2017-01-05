//
//  AGTWebAPI.h
//  Pods
//
//  Created by Mert Buran on 8/2/16.
//
//

#import <Foundation/Foundation.h>
#import "AGTNetworkManager.h"
#import "AGTTokenPersistenceController.h"
#import "AGTAPIErrors.h"
#import "AGTTaskContainer.h"

NS_ASSUME_NONNULL_BEGIN

typedef void(^AGTWebAPICompletion)(id _Nullable serializedResponseObject, NSError * _Nullable error);

@interface AGTWebAPI : NSObject

/**
 *  inits AGTWebAPI instance
 *
 *  @param networkManager object that is responsible for making network requests
 *
 *  @return newly created AGTWebAPI instance
 */
- (instancetype)initWithNetworkManager:(AGTNetworkManager *)networkManager;

/**
 *  inits AGTWebAPI instance with custom token persistence controller
 *  if you do NOT want to use custom token persistence controller, you should use initWithNetworkManager:
 *  default token persistence controller is AGTTokenStorage object with in-memory storage type
 *
 *  @param networkManager             object that is responsible for making network requests
 *  @param tokenPersistenceController object that is responsible for storing/reading/deleting OAuth2 tokens
 *
 *  @return newly created AGTWebAPI instance with custom tokenPersistenceController
 */
- (instancetype)initWithNetworkManager:(AGTNetworkManager *)networkManager
            tokenPersistenceController:(nullable id<AGTTokenPersistenceController>)tokenPersistenceController;

/**
 *  responsible for making network requests
 */
@property (nonatomic, strong, readonly) AGTNetworkManager *networkManager;

/**
 *  responsible for persisting OAuth2 tokens
 *  store/read/delete are main responsibilities
 *  
 *  NOTE! : default token persistence controller is AGTTokenStorage with in-memory storage type
 */
@property (nonatomic, strong, readonly) id<AGTTokenPersistenceController> tokenPersistenceController;

@end

NS_ASSUME_NONNULL_END
