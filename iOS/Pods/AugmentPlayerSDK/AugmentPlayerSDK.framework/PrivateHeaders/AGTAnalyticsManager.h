//
//  AGTAnalyticsManager.h
//  AugmentPlayerSDK
//
//  Created by Mert Buran on 1/8/17.
//  Copyright © 2017 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AGTAnalyticsSession.h"
#import "AGTWebAPI.h"

@interface AGTAnalyticsManager : NSObject

+ (instancetype)sharedManager;

@property (nonatomic, strong, readonly) AGTWebAPI *analyticsAPI;
@property (nonatomic, strong, readonly) NSArray<NSUUID*> *aliveSessionUUIDs;

- (BOOL)startAnalyticsSessionWithSessionUUID:(NSUUID *)sessionUUID;
- (void)endAnalyticsSessionWithUUID:(NSUUID *)sessionUUID;

- (BOOL)modifySession:(AGTAnalyticsSession*(^)(AGTMutableAnalyticsSession *session))modifyBlock
             withUUID:(NSUUID *)sessionUUID;

- (void)sendTrackedSessionsWithCompletion:(void(^)())completion;

@end
