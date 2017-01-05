//
//  AGTProduct.h
//  Pods
//
//  Created by Mert Buran on 8/2/16.
//
//

#import <Foundation/Foundation.h>

@interface AGTProduct : NSObject

@property (nonatomic, copy, readonly, nullable) NSString *identifier;
@property (nonatomic, copy, readonly, nullable) NSString *brand;
@property (nonatomic, copy, readonly, nullable) NSString *name;
@property (nonatomic, copy, readonly, nullable) NSString *model_number;
@property (nonatomic, copy, readonly, nullable) NSString *ean;

@end
