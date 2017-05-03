//
//  AGTModel3DDataController.h
//  Augment
//
//  Created by Mert Buran on 6/24/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AGTBlocks.h"
#import "AGTModel3D.h"
#import "AGTTaskContainer.h"

/**
 *  completion block to be executed at the end of an query
 *
 *  @param product if query returns success, a new AGTProduct object is created an returned within block, if query returns failure product is nil
 *  @param error   error occurred during query, nil if no error occurred
 */
typedef void (^AGTModel3DQueryCompletionBlock)(AGTModel3D *_Nullable product, NSError *_Nullable error);

@interface AGTModel3DDataController : NSObject

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
- (AGTTaskContainer *)checkIfModel3DDoesExistForUuid:(nonnull NSUUID *)uuid
                                          completion:(nullable AGTModel3DQueryCompletionBlock)completion;

@end
