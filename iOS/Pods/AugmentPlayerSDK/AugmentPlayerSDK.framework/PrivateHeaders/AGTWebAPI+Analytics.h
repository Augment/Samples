//
//  AGTWebAPI+Analytics.h
//  AugmentPlayerSDK
//
//  Created by Stéphane GARAGNANI on 24/11/2016.
//  Copyright © 2016 Augment. All rights reserved.
//

#import "AGTWebAPI.h"
#import "AGTAnalyticsSession.h"

NS_ASSUME_NONNULL_BEGIN

@interface AGTWebAPI (Analytics)

- (AGTTaskContainer *)sendAnalyticsSession:(AGTAnalyticsSession *)analyticsSession
                                completion:(nullable void(^)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
