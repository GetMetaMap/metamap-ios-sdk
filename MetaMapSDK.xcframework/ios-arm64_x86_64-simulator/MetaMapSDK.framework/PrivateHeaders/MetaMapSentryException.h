#import <Foundation/Foundation.h>

#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryStacktrace, MetaMapSentryMechanism;

NS_SWIFT_NAME(Exception)
@interface MetaMapSentryException : NSObject <MetaMapSentrySerializable>
MetaMapSentry_NO_INIT

/**
 * The name of the exception
 */
@property (nonatomic, copy) NSString *value;

/**
 * Type of the exception
 */
@property (nonatomic, copy) NSString *type;

/**
 * Additional information about the exception
 */
@property (nonatomic, strong) MetaMapSentryMechanism *_Nullable mechanism;

/**
 * Can be set to define the module
 */
@property (nonatomic, copy) NSString *_Nullable module;

/**
 * An optional value which refers to a thread in @c MetaMapSentryEvent.threads
 */
@property (nonatomic, copy) NSNumber *_Nullable threadId;

/**
 * Stacktrace containing frames of this exception.
 */
@property (nonatomic, strong) MetaMapSentryStacktrace *_Nullable stacktrace;

/**
 * Initialize an MetaMapSentryException with value and type
 * @param value String
 * @param type String
 * @return MetaMapSentryException
 */
- (instancetype)initWithValue:(NSString *)value type:(NSString *)type;

@end

NS_ASSUME_NONNULL_END
