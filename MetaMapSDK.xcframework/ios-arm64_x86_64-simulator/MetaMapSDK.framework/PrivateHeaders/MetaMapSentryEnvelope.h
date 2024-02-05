#import "PrivatesHeader.h"
#if __has_include(<MetaMapSentry/MetaMapSentryEnvelopeItemHeader.h>)
#    import <MetaMapSentry/MetaMapSentryEnvelopeItemHeader.h>
#else
#    import "MetaMapSentryEnvelopeItemHeader.h"
#endif

#if COCOAPODS
@class MetaMapSentrySdkInfo, MetaMapSentryTraceContext;
#else
#    import "MetaMapSentrySdkInfo.h"
#    import "MetaMapSentryTraceContext.h"

#endif

@class MetaMapSentryEvent, MetaMapSentrySession, MetaMapSentryId, MetaMapSentryUserFeedback, MetaMapSentryAttachment,
    MetaMapSentryTransaction, MetaMapSentryClientReport, MetaMapSentryEnvelopeItemHeader;

NS_ASSUME_NONNULL_BEGIN

@interface MetaMapSentryEnvelopeHeader : NSObject
MetaMapSentry_NO_INIT

/**
 * Initializes an @c MetaMapSentryEnvelopeHeader object with the specified eventId.
 * @note Sets the @c sdkInfo from @c MetaMapSentryMeta.
 * @param eventId The identifier of the event. Can be nil if no event in the envelope or attachment
 * related to event.
 */
- (instancetype)initWithId:(MetaMapSentryId *_Nullable)eventId;

/**
 * Initializes a @c MetaMapSentryEnvelopeHeader object with the specified @c eventId and @c traceContext.
 * @param eventId The identifier of the event. Can be @c nil if no event in the envelope or
 * attachment related to event.
 * @param traceContext Current trace state.
 */
- (instancetype)initWithId:(nullable MetaMapSentryId *)eventId
              traceContext:(nullable MetaMapSentryTraceContext *)traceContext;

/**
 * Initializes a @c MetaMapSentryEnvelopeHeader object with the specified @c eventId, @c skdInfo and
 * @c traceContext. It is recommended to use @c initWithId:traceContext: because it sets the
 * @c sdkInfo for you.
 * @param eventId The identifier of the event. Can be @c nil if no event in the envelope or
 * attachment related to event.
 * @param sdkInfo Describes the MetaMapSentry SDK. Can be @c nil for backwards compatibility. New
 * instances should always provide a version.
 * @param traceContext Current trace state.
 */
- (instancetype)initWithId:(nullable MetaMapSentryId *)eventId
                   sdkInfo:(nullable MetaMapSentrySdkInfo *)sdkInfo
              traceContext:(nullable MetaMapSentryTraceContext *)traceContext NS_DESIGNATED_INITIALIZER;

/**
 * The event identifier, if available.
 * An event id exist if the envelope contains an event of items within it are related. i.e
 * Attachments
 */
@property (nullable, nonatomic, readonly, copy) MetaMapSentryId *eventId;

@property (nullable, nonatomic, readonly, copy) MetaMapSentrySdkInfo *sdkInfo;

@property (nullable, nonatomic, readonly, copy) MetaMapSentryTraceContext *traceContext;

/**
 * The timestamp when the event was sent from the SDK as string in RFC 3339 format. Used
 * for clock drift correction of the event timestamp. The time zone must be UTC.
 *
 * The timestamp should be generated as close as possible to the transmision of the event,
 * so that the delay between sending the envelope and receiving it on the server-side is
 * minimized.
 */
@property (nullable, nonatomic, copy) NSDate *sentAt;

@end

@interface MetaMapSentryEnvelopeItem : NSObject
MetaMapSentry_NO_INIT

- (instancetype)initWithEvent:(MetaMapSentryEvent *)event;
- (instancetype)initWithSession:(MetaMapSentrySession *)session;
- (instancetype)initWithUserFeedback:(MetaMapSentryUserFeedback *)userFeedback;
- (_Nullable instancetype)initWithAttachment:(MetaMapSentryAttachment *)attachment
                           maxAttachmentSize:(NSUInteger)maxAttachmentSize;
- (instancetype)initWithHeader:(MetaMapSentryEnvelopeItemHeader *)header
                          data:(NSData *)data NS_DESIGNATED_INITIALIZER;

/**
 * The envelope item header.
 */
@property (nonatomic, readonly, strong) MetaMapSentryEnvelopeItemHeader *header;

/**
 * The envelope payload.
 */
@property (nonatomic, readonly, strong) NSData *data;

@end

@interface MetaMapSentryEnvelope : NSObject
MetaMapSentry_NO_INIT

// If no event, or no data related to event, id will be null
- (instancetype)initWithId:(MetaMapSentryId *_Nullable)id singleItem:(MetaMapSentryEnvelopeItem *)item;

- (instancetype)initWithHeader:(MetaMapSentryEnvelopeHeader *)header singleItem:(MetaMapSentryEnvelopeItem *)item;

// If no event, or no data related to event, id will be null
- (instancetype)initWithId:(MetaMapSentryId *_Nullable)id items:(NSArray<MetaMapSentryEnvelopeItem *> *)items;

/**
 * Initializes a @c MetaMapSentryEnvelope with a single session.
 * @param session to init the envelope with.
 */
- (instancetype)initWithSession:(MetaMapSentrySession *)session;

/**
 * Initializes a @c MetaMapSentryEnvelope with a list of sessions.
 * Can be used when an operation that starts a session closes an ongoing session.
 * @param sessions to init the envelope with.
 */
- (instancetype)initWithSessions:(NSArray<MetaMapSentrySession *> *)sessions;

- (instancetype)initWithHeader:(MetaMapSentryEnvelopeHeader *)header
                         items:(NSArray<MetaMapSentryEnvelopeItem *> *)items NS_DESIGNATED_INITIALIZER;

/**
 * Convenience init for a single event.
 */
- (instancetype)initWithEvent:(MetaMapSentryEvent *)event;

- (instancetype)initWithUserFeedback:(MetaMapSentryUserFeedback *)userFeedback;

/**
 * The envelope header.
 */
@property (nonatomic, readonly, strong) MetaMapSentryEnvelopeHeader *header;

/**
 * The envelope items.
 */
@property (nonatomic, readonly, strong) NSArray<MetaMapSentryEnvelopeItem *> *items;

@end

NS_ASSUME_NONNULL_END
