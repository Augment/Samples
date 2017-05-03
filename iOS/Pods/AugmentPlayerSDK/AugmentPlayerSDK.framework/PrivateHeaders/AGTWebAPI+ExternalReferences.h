//
//  AGTWebAPI+ExternalReferences.h
//  AugmentPlayerSDK
//
//  Created by Mert Buran on 10/16/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import "AGTWebAPI.h"
#import "AGTExternalReference.h"

NS_ASSUME_NONNULL_BEGIN

@interface AGTWebAPI (ExternalReferences)

- (AGTTaskContainer *)getExternalReferenceWithUUID:(NSString *)externalReferenceUUID
                                        parameters:(nullable id)parameters
                                        completion:(nullable void (^)(AGTExternalReference * _Nullable externalReference, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
