//
//  AGTWebAPI+Products.h
//  Pods
//
//  Created by Mert Buran on 8/2/16.
//
//

#import "AGTWebAPI.h"
#import "AGTProduct.h"

NS_ASSUME_NONNULL_BEGIN

@interface AGTWebAPI (Products)

- (AGTTaskContainer *)getProductWithIdentifier:(NSString *)productIdentifier
                                         brand:(NSString *)brand
                                          name:(NSString *)name
                                           ean:(nullable NSString *)ean
                                    parameters:(nullable id)parameters
                                    completion:(nullable void (^)(AGTProduct * _Nullable product, NSError * _Nullable error))completion;

- (AGTTaskContainer *)getProductsWithParameters:(nullable id)parameters
                                     completion:(nullable void (^)(AGTProduct * _Nullable product, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
