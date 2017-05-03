//
//  AGTWebAPI+Model3Ds.h
//  Pods
//
//  Created by Mert Buran on 8/8/16.
//
//

#import "AGTWebAPI.h"
#import <AugmentPlayerSDK/AGTModel3D.h>

@class AGTGallery;
@class AGTFolder;

NS_ASSUME_NONNULL_BEGIN

@interface AGTWebAPI (Model3Ds)

- (AGTTaskContainer *)getModel3DsWithModelUUID:(NSString *)modelUUID
                                    parameters:(nullable id)parameters
                                    completion:(nullable void (^)(AGTModel3D * _Nullable model3D, NSError * _Nullable error))completion;

- (AGTTaskContainer *)getModel3DsInGallery:(AGTGallery *)gallery
                                parameters:(nullable id)parameters
                                completion:(nullable void (^)(NSArray<AGTModel3D*> * _Nullable model3Ds, NSError * _Nullable error))completion;

- (AGTTaskContainer *)getModel3DsWithKeyword:(NSString *)keyword
                                  parameters:(nullable id)parameters
                                  completion:(nullable void (^)(NSArray<AGTModel3D*> * _Nullable model3Ds, NSError * _Nullable error))completion;

- (AGTTaskContainer *)getModel3DsInFolder:(AGTFolder *)folder
                               parameters:(nullable id)parameters
                               completion:(nullable void (^)(NSArray<AGTModel3D*> * _Nullable model3Ds, NSError * _Nullable error))completion;

- (AGTTaskContainer *)updateModel3D:(AGTModel3D *)model3D
                         parameters:(nullable id)parameters
                         completion:(nullable void (^)(AGTModel3D* _Nullable updatedModel3D, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
