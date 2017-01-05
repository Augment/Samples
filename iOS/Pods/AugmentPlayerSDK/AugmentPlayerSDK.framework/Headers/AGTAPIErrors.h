//
//  AGTAPIErrors.h
//  Pods
//
//  Created by Mert Buran on 8/2/16.
//
//

#import <Foundation/Foundation.h>

#pragma mark - Error domain

/**
 *  domain for errors come from Augment webservice operations
 */
extern NSString * const AGTAugmentWebserviceErrorDomain;

#pragma mark - Error codes
/**
 *  error codes specific for Augment webservice operations
 */
NS_ENUM(NSInteger) {
    /**
     *  unknown error
     */
    AGTAugmentWebserviceErrorUnknown                        = -1,
    /**
     *  it is not certain that model does exist in Augment database
     *  you should check if it exists via AGTProductsDataController
     */
    AGTAugmentWebserviceModelPresenceUndetermined           = -101,
    /**
     *  no model 3D asset found for requested product EAN
     */
    AGTAugmentWebserviceNoModel3DFound                      = -201,
    /**
     *  webservice exception: bad request
     */
    AGTAugmentWebserviceErrorBadRequest                     = 400,
    /**
     *  webservice exception: unauthorized
     */
    AGTAugmentWebserviceErrorUnauthorized                   = 401,
    /**
     *  webservice exception: payment required
     */
    AGTAugmentWebserviceErrorPaymentRequired                = 402,
    /**
     *  webservice exception: forbidden
     */
    AGTAugmentWebserviceErrorForbidden                      = 403,
    /**
     *  webservice exception: resource not found
     */
    AGTAugmentWebserviceErrorNotFound                       = 404,
    /**
     *  webservice exception: internal server error
     */
    AGTAugmentWebserviceErrorInternalServerError            = 500,
};

#pragma mark - Error user info keys

/**
 *  key for error response status code. example: 400
 */
extern NSString * const AGTAugmentWebserviceErrorResponseStatusCodeKey;
    
/**
 *  key for error type string. example: not_found
 */
extern NSString * const AGTAugmentWebserviceErrorTypeKey;

/**
 *  key for technical informations string
 */
extern NSString * const AGTAugmentWebserviceTechnicalInformationsKey;
