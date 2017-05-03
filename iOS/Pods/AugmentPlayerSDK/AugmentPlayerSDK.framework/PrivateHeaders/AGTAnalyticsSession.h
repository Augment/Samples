//
//  AGTAnalyticsSession.h
//  AugmentPlayerSDK
//
//  Created by Mert Buran on 1/9/17.
//  Copyright © 2017 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const AGTAnalyticsSessionStartDate;
extern NSString * const AGTAnalyticsSessionEndDate;

extern NSString * const AGTAnalyticsProduct;
extern NSString * const AGTAnalyticsProductRequestID;
extern NSString * const AGTAnalyticsModel3D;
extern NSString * const AGTAnalyticsModel3DIdentifier;
extern NSString * const AGTAnalyticsProductIdentifier;

extern NSString * const AGTAnalyticsOneFingerTapGestureCount;
extern NSString * const AGTAnalyticsOneFingerPanGestureCount;
extern NSString * const AGTAnalyticsTwoFingerPanGestureCount;
extern NSString * const AGTAnalyticsTwoFingerPinchGestureCount;
extern NSString * const AGTAnalyticsRotationGestureCount;

extern NSString * const AGTTrackerDetectionCount;

typedef NSDictionary AGTAnalyticsSession;
typedef NSMutableDictionary AGTMutableAnalyticsSession;
