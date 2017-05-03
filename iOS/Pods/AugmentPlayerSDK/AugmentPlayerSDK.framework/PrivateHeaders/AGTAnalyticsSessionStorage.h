//
//  AGTAnalyticsSessionStorage.h
//  AugmentPlayerSDK
//
//  Created by Mert Buran on 1/8/17.
//  Copyright © 2017 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AGTAnalyticsSession.h"

extern NSTimeInterval const AGTTimeDifferenceMarginInSeconds;

NS_ASSUME_NONNULL_BEGIN

@interface AGTAnalyticsSessionStorage : NSObject

+ (BOOL)storeSession:(AGTAnalyticsSession *)session withUUID:(NSUUID *)sessionUUID;
+ (nullable AGTAnalyticsSession *)sessionWithUUID:(NSUUID *)sessionUUID;
+ (nullable NSDictionary<NSUUID*, AGTAnalyticsSession*> *)sessionsModifiedAfterDate:(nullable NSDate *)date;
+ (BOOL)deleteSessionWithUUID:(NSUUID *)sessionUUID;
+ (BOOL)deleteAllSessions;

@end

NS_ASSUME_NONNULL_END
