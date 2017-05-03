//
//  AGTProductsDataController.h
//  Augment
//
//  Created by Mert Buran on 7/4/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AGTProduct.h"
#import "AGTTaskContainer.h"

NS_ASSUME_NONNULL_BEGIN

@interface AGTProduct (UnfoundProduct)

+ (AGTProduct *)unfoundProduct;

@end

/**
 *  completion block to be executed at the end of an query
 *
 *  @param product if query returns success, a new AGTProduct object is created an returned within block, if query returns failure product is nil
 *  @param error   error occurred during query, nil if no error occurred
 */
typedef void (^AGTProductQueryCompletionBlock)(AGTProduct *_Nullable product, NSError *_Nullable error);

/**
 *  this class is responsible for querying Augment Products API in order to have model availability information
 */
@interface AGTProductsDataController : NSObject

/**
 *  makes a chain of network requests to Augment webservice in order to check if model in-demand does exist
 *
 *  @param productIdentifier  identifier of the product whose model 3D asset to be queried in your product catalog
 *  @param brand              brand/manufacturer of the requested product
 *  @param name               complete commercial name of the requested product
 *  @param ean                optionnal ean of the requested product
 *  @param completion         completion block to be executed at the end of network request. runs in MAIN thread.
 *          -product if productEAN does exist in Augment database, newly created AGTProduct object; otherwise nil
 *          -error   error object that occurred during network request, nil if no error occurred
 *
 *  @return a newly created AGTTaskContainer object which contains a variable activeTask property
 */
- (AGTTaskContainer *)checkIfModelDoesExistForProductIdentifier:(NSString *)productIdentifier
                                                          brand:(NSString *)brand
                                                           name:(NSString *)name
                                                            EAN:(nullable NSString *)ean
                                                     completion:(nullable AGTProductQueryCompletionBlock)completion;

/**
 *  as different product IDs are queried, their corresponding model UUIDs are cached within a map
 *  we can use this map to avoid making another request to get model UUID that corresponds to a certain product ID
 *
 *  @param productIdentifier identifier of product
 *          https://en.wikipedia.org/wiki/International_Article_Number_(EAN)
 *
 *  @return AGTProduct object that corresponds to given product identifier if there has already been created before
 *  if productEAN was queried via checkIfModelDoesExistForProductEAN:completion: and it does NOT exist in Augment database, this method returns [AGTProduct unfoundProduct] singleton object
 *  if productEAN was NOT queried via checkIfModelDoesExistForProductEAN:completion: before, this method returns nil
 */
- (nullable AGTProduct *)productForIdentifier:(NSString *)productIdentifier;

@end

NS_ASSUME_NONNULL_END
