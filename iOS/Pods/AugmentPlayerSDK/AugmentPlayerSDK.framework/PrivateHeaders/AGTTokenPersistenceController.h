//
//  AGTTokenPersistenceController.h
//  Pods
//
//  Created by Mert Buran on 8/10/16.
//
//

#import <Foundation/Foundation.h>
#import "AGTOAuthCredential.h"

NS_ASSUME_NONNULL_BEGIN

@protocol AGTTokenPersistenceController <NSObject>

/**
 *  store credential
 *
 *  @param credential credential to be stored
 *  @param identifier identifier for credential
 *
 *  @return YES if success, NO otherwise
 */
- (BOOL)storeCredential:(AGTOAuthCredential *)credential identifier:(NSString *)identifier;

/**
 *  read credential
 *
 *  @param identifier credential identifier
 *
 *  @return AGOAuthCredential instance if found, nil otherwise
 */
- (nullable AGTOAuthCredential *)readCredentialWithIdentifier:(NSString *)identifier;

/**
 *  delete credential
 *
 *  @param identifier identifier of credential
 *
 *  @return YES if success, NO otherwise
 */
- (BOOL)removeCredentialWithIdentifier:(NSString *)identifier;

@end

NS_ASSUME_NONNULL_END
