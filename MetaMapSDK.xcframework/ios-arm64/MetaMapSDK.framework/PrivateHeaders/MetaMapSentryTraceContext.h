#if __has_include(<MetaMapSentry/MetaMapSentrySerializable.h>)
#    import <MetaMapSentry/MetaMapSentrySerializable.h>
#else
#    import "MetaMapSentrySerializable.h"
#endif

#if __has_include(<MetaMapSentry/MetaMapSentryId.h>)
#    import <MetaMapSentry/MetaMapSentryId.h>
#else
#    import "MetaMapSentryId.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryScope, MetaMapSentryOptions, MetaMapSentryTracer, MetaMapSentryUser, MetaMapSentryBaggage;

@interface MetaMapSentryTraceContext : NSObject <MetaMapSentrySerializable>

/**
 * UUID V4 encoded as a hexadecimal sequence with no dashes (e.g. 771a43a4192642f0b136d5159a501700)
 * that is a sequence of 32 hexadecimal digits.
 */
@property (nonatomic, readonly) MetaMapSentryId *traceId;

/**
 * Public key from the DSN used by the SDK.
 */
@property (nonatomic, readonly) NSString *publicKey;

/**
 * The release name as specified in client options, usually: package@x.y.z+build.
 */
@property (nullable, nonatomic, readonly) NSString *releaseName;

/**
 * The environment name as specified in client options, for example staging.
 */
@property (nullable, nonatomic, readonly) NSString *environment;

/**
 * The transaction name set on the scope.
 */
@property (nullable, nonatomic, readonly) NSString *transaction;

/**
 * A subset of the scope's user context.
 */
@property (nullable, nonatomic, readonly) NSString *userSegment;

/**
 * Sample rate used for this trace.
 */
@property (nullable, nonatomic, strong) NSString *sampleRate;

/**
 * Initializes a MetaMapSentryTraceContext with given properties.
 */
- (instancetype)initWithTraceId:(MetaMapSentryId *)traceId
                      publicKey:(NSString *)publicKey
                    releaseName:(nullable NSString *)releaseName
                    environment:(nullable NSString *)environment
                    transaction:(nullable NSString *)transaction
                    userSegment:(nullable NSString *)userSegment
                     sampleRate:(nullable NSString *)sampleRate;

/**
 * Initializes a MetaMapSentryTraceContext with data from scope and options.
 */
- (nullable instancetype)initWithScope:(MetaMapSentryScope *)scope options:(MetaMapSentryOptions *)options;

/**
 * Initializes a MetaMapSentryTraceContext with data from a dictionary.
 */
- (nullable instancetype)initWithDict:(NSDictionary<NSString *, id> *)dictionary;

/**
 * Initializes a MetaMapSentryTraceContext with data from a trace, scope and options.
 */
- (nullable instancetype)initWithTracer:(MetaMapSentryTracer *)tracer
                                  scope:(nullable MetaMapSentryScope *)scope
                                options:(MetaMapSentryOptions *)options;

/**
 * Create a MetaMapSentryBaggage with the information of this MetaMapSentryTraceContext.
 */
- (MetaMapSentryBaggage *)toBaggage;
@end

NS_ASSUME_NONNULL_END
