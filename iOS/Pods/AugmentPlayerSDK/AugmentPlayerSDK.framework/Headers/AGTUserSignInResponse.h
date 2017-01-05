//
//  AGTUserSignInResponse.h
//  Pods
//
//  Created by Mert Buran on 8/9/16.
//
//

#import <Foundation/Foundation.h>

@interface AGTPasswordPolicy : NSObject

@property (nonatomic, copy, readonly) NSNumber *min_length;
@property (nonatomic, copy, readonly) NSNumber *max_length;
@property (nonatomic, copy, readonly) NSNumber *min_digits_count;
@property (nonatomic, copy, readonly) NSNumber *min_symbols_count;
@property (nonatomic, copy, readonly) NSNumber *requires_mixed_case;

@end

@interface AGTUserSignInResponse : NSObject

@property (nonatomic, copy, readonly) NSString *email;
@property (nonatomic, copy, readonly) NSString *uuid;
@property (nonatomic, copy, readonly) NSString *api_key;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSDate *updated_at;
@property (nonatomic, copy, readonly) NSNumber *model3ds_count;
@property (nonatomic, copy, readonly) NSNumber *is_paying;
@property (nonatomic, copy, readonly) AGTPasswordPolicy *password_policy;

@end
