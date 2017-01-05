//
//  AGTTokenStorage.h
//  Pods
//
//  Created by Mert Buran on 8/10/16.
//
//

#import <Foundation/Foundation.h>
#import "AGTTokenPersistenceController.h"

typedef NS_ENUM(NSUInteger, AGTStorageType) {
    AGTStorageInMemory,
    AGTStorageKeychain,
};

@interface AGTTokenStorage : NSObject <AGTTokenPersistenceController>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithStorageType:(AGTStorageType)storageType;

@property (nonatomic, readonly) AGTStorageType storageType;

@end
