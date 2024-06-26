#import <Foundation/Foundation.h>

#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryNSError, MetaMapSentryMechanismMeta;

NS_SWIFT_NAME(Mechanism)
@interface MetaMapSentryMechanism : NSObject <MetaMapSentrySerializable>
MetaMapSentry_NO_INIT

/**
 * A unique identifier of this mechanism determining rendering and processing
 * of the mechanism data
 */
@property (nonatomic, copy) NSString *type;

/**
 * Human readable description of the error mechanism and a possible hint on how to solve this error.
 * We can't use description as it overlaps with NSObject.description.
 */
@property (nonatomic, copy) NSString *_Nullable desc;

/**
 * Arbitrary extra data that might help the user understand the error thrown by
 * this mechanism
 */
@property (nonatomic, strong) NSDictionary<NSString *, id> *_Nullable data;

/**
 * Flag indicating whether the exception has been handled by the user
 * (e.g. via @c try..catch )
 */
@property (nonatomic, copy) NSNumber *_Nullable handled;

/**
 * An optional flag indicating a synthetic exception. For more info visit
 * https://develop.MetaMapSentry.dev/sdk/event-payloads/exception/#exception-mechanism.
 */
@property (nonatomic, copy, nullable) NSNumber *synthetic;

/**
 * Fully qualified URL to an online help resource, possible
 * interpolated with error parameters
 */
@property (nonatomic, copy) NSString *_Nullable helpLink;

/**
 * Information from the operating system or runtime on the exception
 * mechanism.
 */
@property (nullable, nonatomic, strong) MetaMapSentryMechanismMeta *meta;

/**
 * Initialize an MetaMapSentryMechanism with a type
 * @param type String
 * @return MetaMapSentryMechanism
 */
- (instancetype)initWithType:(NSString *)type;

@end

NS_ASSUME_NONNULL_END
