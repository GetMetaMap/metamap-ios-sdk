#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySampleDecision.h"
#import "MetaMapSentrySerializable.h"
#import "MetaMapSentrySpanStatus.h"

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryId, MetaMapSentrySpanId;

static NSString const *MetaMapSentry_TRACE_TYPE = @"trace";

NS_SWIFT_NAME(SpanContext)
@interface MetaMapSentrySpanContext : NSObject <MetaMapSentrySerializable>
MetaMapSentry_NO_INIT

/**
 * Determines which trace the Span belongs to.
 */
@property (nonatomic, readonly) MetaMapSentryId *traceId;

/**
 * Span id.
 */
@property (nonatomic, readonly) MetaMapSentrySpanId *spanId;

/**
 * Id of a parent span.
 */
@property (nullable, nonatomic, readonly) MetaMapSentrySpanId *parentSpanId;

/**
 * If trace is sampled.
 */
@property (nonatomic, readonly) MetaMapSentrySampleDecision sampled;

/**
 * Short code identifying the type of operation the span is measuring.
 */
@property (nonatomic, copy, readonly) NSString *operation;

/**
 * Longer description of the span's operation, which uniquely identifies the span but is
 * consistent across instances of the span.
 */
@property (nullable, nonatomic, copy, readonly) NSString *spanDescription;

/**
 * The origin of the span indicates what created the span.
 *
 * @note Gets set by the SDK. It is not expected to be set manually by users. Although the protocol
 * allows this value to be optional, we make it nonnullable as we always send the value.
 *
 * @see <https://develop.MetaMapSentry.dev/sdk/performance/trace-origin>
 */
@property (nonatomic, copy) NSString *origin;

/**
 * Init a @c MetaMapSentryContext with an operation code.
 * @note @c traceId and @c spanId with be randomly created; @c sampled by default is
 * @c kMetaMapSentrySampleDecisionUndecided .
 */
- (instancetype)initWithOperation:(NSString *)operation;

/**
 * Init a @c MetaMapSentryContext with an operation code and mark it as sampled or not.
 * TraceId and SpanId with be randomly created.
 * @param operation The operation this span is measuring.
 * @param sampled Determines whether the trace should be sampled.
 */
- (instancetype)initWithOperation:(NSString *)operation sampled:(MetaMapSentrySampleDecision)sampled;

/**
 * @param traceId Determines which trace the Span belongs to.
 * @param spanId The Span Id.
 * @param operation The operation this span is measuring.
 * @param parentId Id of a parent span.
 * @param sampled Determines whether the trace should be sampled.
 */
- (instancetype)initWithTraceId:(MetaMapSentryId *)traceId
                         spanId:(MetaMapSentrySpanId *)spanId
                       parentId:(nullable MetaMapSentrySpanId *)parentId
                      operation:(NSString *)operation
                        sampled:(MetaMapSentrySampleDecision)sampled;

/**
 * @param traceId Determines which trace the Span belongs to.
 * @param spanId The Span Id.
 * @param operation The operation this span is measuring.
 * @param parentId Id of a parent span.
 * @param description The span description.
 * @param sampled Determines whether the trace should be sampled.
 */
- (instancetype)initWithTraceId:(MetaMapSentryId *)traceId
                         spanId:(MetaMapSentrySpanId *)spanId
                       parentId:(nullable MetaMapSentrySpanId *)parentId
                      operation:(NSString *)operation
                spanDescription:(nullable NSString *)description
                        sampled:(MetaMapSentrySampleDecision)sampled;

@end

NS_ASSUME_NONNULL_END
