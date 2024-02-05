#import "MetaMapSentrySampleDecision.h"
#import "MetaMapSentrySpanContext.h"

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentrySpanId;
@class MetaMapSentryThread;

NS_SWIFT_NAME(TransactionContext)
@interface MetaMapSentryTransactionContext : MetaMapSentrySpanContext
MetaMapSentry_NO_INIT

/**
 * Transaction name
 */
@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) MetaMapSentryTransactionNameSource nameSource;

/**
 * Parent sampled
 */
@property (nonatomic) MetaMapSentrySampleDecision parentSampled;

/**
 * Sample rate used for this transaction
 */
@property (nonatomic, strong, nullable) NSNumber *sampleRate;

/**
 * @param name Transaction name
 * @param operation The operation this span is measuring.
 * @return MetaMapSentryTransactionContext
 */
- (instancetype)initWithName:(NSString *)name operation:(NSString *)operation;

/**
 * @param name Transaction name
 * @param operation The operation this span is measuring.
 * @param sampled Determines whether the trace should be sampled.
 */
- (instancetype)initWithName:(NSString *)name
                   operation:(NSString *)operation
                     sampled:(MetaMapSentrySampleDecision)sampled;

/**
 * @param name Transaction name
 * @param operation The operation this span is measuring.
 * @param traceId Trace Id
 * @param spanId Span Id
 * @param parentSpanId Parent span id
 * @param parentSampled Whether the parent is sampled
 */
- (instancetype)initWithName:(NSString *)name
                   operation:(NSString *)operation
                     traceId:(MetaMapSentryId *)traceId
                      spanId:(MetaMapSentrySpanId *)spanId
                parentSpanId:(nullable MetaMapSentrySpanId *)parentSpanId
               parentSampled:(MetaMapSentrySampleDecision)parentSampled;

@end

NS_ASSUME_NONNULL_END
