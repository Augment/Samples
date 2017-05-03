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

@end

NS_ASSUME_NONNULL_END
