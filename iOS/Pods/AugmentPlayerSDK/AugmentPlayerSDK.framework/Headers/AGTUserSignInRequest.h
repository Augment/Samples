//
//  AGTUserSignInRequest.h
//  Pods
//
//  Created by Mert Buran on 8/9/16.
//
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AGTUserSignInRequest : NSObject

- (instancetype)initWithUsername:(NSString *)username
                        password:(NSString *)password;

@property (nonatomic, copy, readonly) NSString *username;
@property (nonatomic, copy, readonly) NSString *password;

@end

NS_ASSUME_NONNULL_END
