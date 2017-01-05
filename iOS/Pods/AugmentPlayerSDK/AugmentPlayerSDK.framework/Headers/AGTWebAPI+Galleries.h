//
//  AGTWebAPI+Galleries.h
//  Pods
//
//  Created by Mert Buran on 8/8/16.
//
//

#import "AGTWebAPI.h"
#import "AGTGallery.h"

NS_ASSUME_NONNULL_BEGIN

@interface AGTWebAPI (Galleries)

- (AGTTaskContainer *)getGalleriesWithParameters:(nullable id)parameters
                                      completion:(nullable void (^)(NSArray<AGTGallery*> * _Nullable galleries, NSError * _Nullable error))completion;

- (AGTTaskContainer *)getGalleryWithUUID:(NSString*)galleryUUID
                              parameters:(nullable id)parameters
                                    completion:(nullable void (^)(AGTGallery* _Nullable gallery, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
