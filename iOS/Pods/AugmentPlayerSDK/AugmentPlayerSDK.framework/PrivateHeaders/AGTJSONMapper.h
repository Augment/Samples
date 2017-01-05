//
//  AGTJSONMapper.h
//  Pods
//
//  Created by Mert Buran on 8/2/16.
//
//

#import <Foundation/Foundation.h>
#import "AGTJSONSerializable.h"

/**
 *  adapter class for JSON<>Object serialization
 */
@interface AGTJSONMapper : NSObject

/**
 *  creates object from JSON dictionary
 *
 *  @param dictionary  JSON dictionary
 *  @param objectClass class of object to be created
 *
 *  @return a newly created objectClass instance if dictionary not nil, otherwise nil
 */

+ (id<AGTJSONSerializable>)objectOfClass:(Class<AGTJSONSerializable>)objectClass fromJSONDictionary:(NSDictionary *)dictionary;


/**
 *  dictionary representation of JSON serializable object
 *
 *  @param object JSON serializable object
 *
 *  @return newly created dictionary that represents object
 */
+ (NSDictionary *)JSONDictionaryFromObject:(id<AGTJSONSerializable>)object;

/**
 * Array of objects from an array of JSON dictionaries.
 */
+ (NSArray<id<AGTJSONSerializable>>*)objectsOfClass:(Class<AGTJSONSerializable>)objectClass fromJSONArray:(NSArray<NSDictionary*>*)array;

/**
 * Array of JSON dictionaries from an array of objects.
 */
+ (NSArray<NSDictionary*>*)JSONArrayFromObjects:(NSArray<id<AGTJSONSerializable>>*)objects;

@end
