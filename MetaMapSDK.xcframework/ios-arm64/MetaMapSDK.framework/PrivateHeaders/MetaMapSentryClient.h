#import "MetaMapSentryDefines.h"

@class MetaMapSentryOptions, MetaMapSentryEvent, MetaMapSentryScope, MetaMapSentryFileManager, MetaMapSentryId, MetaMapSentryUserFeedback,
    MetaMapSentryTransaction;

NS_ASSUME_NONNULL_BEGIN

@interface MetaMapSentryClient : NSObject
MetaMapSentry_NO_INIT

@property (nonatomic, assign, readonly) BOOL isEnabled;

@property (nonatomic, strong) MetaMapSentryOptions *options;

/**
 * Initializes a @c MetaMapSentryClient. Pass in a dictionary of options.
 * @param options Options dictionary
 * @return An initialized @c MetaMapSentryClient or @c nil if an error occurred.
 */
- (_Nullable instancetype)initWithOptions:(MetaMapSentryOptions *)options;

/**
 * Captures a manually created event and sends it to MetaMapSentry.
 * @param event The event to send to MetaMapSentry.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureEvent:(MetaMapSentryEvent *)event NS_SWIFT_NAME(capture(event:));

/**
 * Captures a manually created event and sends it to MetaMapSentry.
 * @param event The event to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureEvent:(MetaMapSentryEvent *)event
                 withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(event:scope:));

/**
 * Captures an error event and sends it to MetaMapSentry.
 * @param error The error to send to MetaMapSentry.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureError:(NSError *)error NS_SWIFT_NAME(capture(error:));

/**
 * Captures an error event and sends it to MetaMapSentry.
 * @param error The error to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureError:(NSError *)error
                 withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(error:scope:));

/**
 * Captures an exception event and sends it to MetaMapSentry.
 * @param exception The exception to send to MetaMapSentry.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureException:(NSException *)exception NS_SWIFT_NAME(capture(exception:));

/**
 * Captures an exception event and sends it to MetaMapSentry.
 * @param exception The exception to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureException:(NSException *)exception
                     withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(exception:scope:));

/**
 * Captures a message event and sends it to MetaMapSentry.
 * @param message The message to send to MetaMapSentry.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureMessage:(NSString *)message NS_SWIFT_NAME(capture(message:));

/**
 * Captures a message event and sends it to MetaMapSentry.
 * @param message The message to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureMessage:(NSString *)message
                   withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(message:scope:));

/**
 * Captures a manually created user feedback and sends it to MetaMapSentry.
 * @param userFeedback The user feedback to send to MetaMapSentry.
 */
- (void)captureUserFeedback:(MetaMapSentryUserFeedback *)userFeedback
    NS_SWIFT_NAME(capture(userFeedback:));

/**
 * Waits synchronously for the SDK to flush out all queued and cached items for up to the specified
 * timeout in seconds. If there is no internet connection, the function returns immediately. The SDK
 * doesn't dispose the client or the hub.
 * @param timeout The time to wait for the SDK to complete the flush.
 */
- (void)flush:(NSTimeInterval)timeout NS_SWIFT_NAME(flush(timeout:));

/**
 * Disables the client and calls flush with @c MetaMapSentryOptions.shutdownTimeInterval .
 */
- (void)close;

@end

NS_ASSUME_NONNULL_END
