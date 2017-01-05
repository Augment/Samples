//
//  AGTDisplayConfiguration.h
//  Augment2
//
//  Created by Mert Buran on 1/26/16.
//  Copyright © 2016 Augment. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AGTDisplayConfiguration : NSObject

@property (nonatomic, copy) NSString *initial_position_unit;

@property (nonatomic, copy) NSNumber *is_fit_to_view_computed;
@property (nonatomic, copy) NSNumber *is_initial_position_fixed;
@property (nonatomic, copy) NSNumber *is_initial_scale_fixed;
@property (nonatomic, copy) NSNumber *is_initial_rotation_fixed;
@property (nonatomic, copy) NSNumber *is_culling_enabled;
@property (nonatomic, copy) NSNumber *are_lights_enabled;
@property (nonatomic, copy) NSNumber *are_shadows_enabled;
@property (nonatomic, copy) NSNumber *is_envmap_enabled;
@property (nonatomic, copy) NSNumber *is_bumpmap_enabled;
@property (nonatomic, copy) NSNumber *is_fog_enabled;
@property (nonatomic, copy) NSNumber *is_animation_autorun;

@property (nonatomic, copy) NSNumber *initial_rotation_x;
@property (nonatomic, copy) NSNumber *initial_rotation_y;
@property (nonatomic, copy) NSNumber *initial_rotation_z;

@property (nonatomic, copy) NSNumber *initial_position_x;
@property (nonatomic, copy) NSNumber *initial_position_y;
@property (nonatomic, copy) NSNumber *initial_position_z;

@property (nonatomic, copy) NSNumber *initial_scale;

@end
