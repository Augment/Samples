//
//  AGTWebAPI+UserSession.h
//  Pods
//
//  Created by Mert Buran on 8/9/16.
//
//

#import "AGTWebAPI.h"
#import "AGTUserSignInRequest.h"
#import "AGTUserSignInResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface AGTWebAPI (UserSession)

- (AGTTaskContainer *)signInWithRequest:(AGTUserSignInRequest *)signInRequest
                             parameters:(nullable id)parameters
                             completion:(nullable void (^)(AGTUserSignInResponse * _Nullable userResponse, NSError * _Nullable error))completion;

- (AGTTaskContainer *)changeOldPassword:(NSString *)oldPassword
                        withNewPassword:(NSString *)newPassword
                             parameters:(nullable id)parameters
                             completion:(nullable void (^)(AGTUserSignInResponse * _Nullable userResponse, NSError * _Nullable error))completion;

- (AGTTaskContainer *)createDeviceWithParameters:(nullable id)parameters
                                      completion:(nullable void (^)(NSString * _Nullable deviceUUID, NSError * _Nullable error))completion;

- (AGTTaskContainer *)associateDevice:(NSString *)deviceUUID
                               toUser:(AGTUserSignInResponse *)user
                               attach:(BOOL)attach
                           parameters:(nullable id)parameters
                           completion:(nullable void (^)(BOOL success, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
