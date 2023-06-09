#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySampleDecision.h"

@class MetaMapSentryId, MetaMapSentrySpanId;

NS_ASSUME_NONNULL_BEGIN

static NSString *const MetaMapSentry_TRACE_HEADER = @"MetaMapSentry-trace";

NS_SWIFT_NAME(TraceHeader)
@interface MetaMapSentryTraceHeader : NSObject
MetaMapSentry_NO_INIT
/**
 * Trace ID.
 */
@property (nonatomic, readonly) MetaMapSentryId *traceId;

/**
 * Span ID.
 */
@property (nonatomic, readonly) MetaMapSentrySpanId *spanId;

/**
 * The trace sample decision.
 */
@property (nonatomic, readonly) MetaMapSentrySampleDecision sampled;

/**
 * @param traceId The trace id.
 * @param spanId The span id.
 * @param sampled The decision made to sample the trace related to this header.
 */
- (instancetype)initWithTraceId:(MetaMapSentryId *)traceId
                         spanId:(MetaMapSentrySpanId *)spanId
                        sampled:(MetaMapSentrySampleDecision)sampled;

/**
 * Return the value to use in a request header.
 */
- (NSString *)value;

@end

NS_ASSUME_NONNULL_END
