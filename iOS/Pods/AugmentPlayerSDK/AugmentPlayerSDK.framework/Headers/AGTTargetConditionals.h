//
//  AGTTargetConditionals.h
//  Augment
//
//  Created by Mert Buran on 6/17/16.
//  Copyright © 2016 AugmenteDev. All rights reserved.
//

/**
 *  Scope: Public
 *  provides required macros in order to let the developer run project on simulator, which AugmentPlayerSDK doesn't support completely
 */

#ifndef AGTTargetConditionals_h
#define AGTTargetConditionals_h

#import <TargetConditionals.h>
#if !TARGET_OS_SIMULATOR

#define AGT_AR_AVAILABLE 1

#else

#define AGT_AR_AVAILABLE 0

#endif

#endif /* AGTTargetConditionals_h */
