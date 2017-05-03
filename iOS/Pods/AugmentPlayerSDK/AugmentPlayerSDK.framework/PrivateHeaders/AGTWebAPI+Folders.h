//
//  AGTWebAPI+Folders.h
//  AugmentAPI
//
//  Created by Mert Buran on 8/18/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import "AGTWebAPI.h"
#import "AGTFolder.h"
#import "AGTUserSignInResponse.h"

NS_ASSUME_NONNULL_BEGIN

@interface AGTWebAPI (Folders)

- (AGTTaskContainer *)getFolderForUser:(AGTUserSignInResponse *)user
                            parameters:(nullable id)parameters
                            completion:(nullable void (^)(NSArray<AGTFolder*> * _Nullable folders, NSError * _Nullable error))completion;

- (AGTTaskContainer *)getFolderWithUUID:(NSString *)folderUUID
                             parameters:(nullable id)parameters
                             completion:(nullable void (^)(AGTFolder* _Nullable folders, NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
