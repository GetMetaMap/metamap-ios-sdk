#import <Foundation/Foundation.h>

#if __has_include(<MetaMapSentry/MetaMapSentrySerializable.h>)
#    import <MetaMapSentry/MetaMapSentrySerializable.h>
#else
#    import "MetaMapSentrySerializable.h"
#endif

NS_ASSUME_NONNULL_BEGIN

/**
 * Describes the MetaMapSentry SDK and its configuration used to capture and transmit an event.
 * @note Both name and version are required.
 * @see https://develop.MetaMapSentry.dev/sdk/event-payloads/sdk/
 */
@interface MetaMapSentrySdkInfo : NSObject <MetaMapSentrySerializable>
MetaMapSentry_NO_INIT

/**
 * The name of the SDK. Examples: MetaMapSentry.cocoa, MetaMapSentry.cocoa.vapor, ...
 */
@property (nonatomic, readonly, copy) NSString *name;

/**
 * The version of the SDK. It should have the Semantic Versioning format MAJOR.MINOR.PATCH, without
 * any prefix (no v or anything else in front of the major version number). Examples:
 * 0.1.0, 1.0.0, 2.0.0-beta0
 */
@property (nonatomic, readonly, copy) NSString *version;

- (instancetype)initWithName:(NSString *)name
                  andVersion:(NSString *)version NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithDict:(NSDictionary *)dict;

- (instancetype)initWithDict:(NSDictionary *)dict orDefaults:(MetaMapSentrySdkInfo *)info;

@end

NS_ASSUME_NONNULL_END
