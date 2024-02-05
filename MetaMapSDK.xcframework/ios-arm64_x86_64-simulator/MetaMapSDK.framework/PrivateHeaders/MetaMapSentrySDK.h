#import "MetaMapSentryDefines.h"

@protocol MetaMapSentrySpan;

@class MetaMapSentryOptions, MetaMapSentryEvent, MetaMapSentryBreadcrumb, MetaMapSentryScope, MetaMapSentryUser, MetaMapSentryId,
    MetaMapSentryUserFeedback, MetaMapSentryTransactionContext;

NS_ASSUME_NONNULL_BEGIN

/**
 * The main entry point for the MetaMapSentrySDK.
 * We recommend using @c +[startWithConfigureOptions:] to initialize MetaMapSentry.
 */
@interface MetaMapSentrySDK : NSObject
MetaMapSentry_NO_INIT

/**
 * The current active transaction or span bound to the scope.
 */
@property (nullable, class, nonatomic, readonly) id<MetaMapSentrySpan> span;

/**
 * Indicates whether the MetaMapSentrySDK is enabled.
 */
@property (class, nonatomic, readonly) BOOL isEnabled;

/**
 * Inits and configures MetaMapSentry (MetaMapSentryHub, MetaMapSentryClient) and sets up all integrations. Make sure to
 * set a valid DSN.
 */
+ (void)startWithOptions:(MetaMapSentryOptions *)options NS_SWIFT_NAME(start(options:));

/**
 * Inits and configures MetaMapSentry (MetaMapSentryHub, MetaMapSentryClient) and sets up all integrations. Make sure to
 * set a valid DSN.
 */
+ (void)startWithConfigureOptions:(void (^)(MetaMapSentryOptions *options))configureOptions
    NS_SWIFT_NAME(start(configureOptions:));

/**
 * Captures a manually created event and sends it to MetaMapSentry.
 * @param event The event to send to MetaMapSentry.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureEvent:(MetaMapSentryEvent *)event NS_SWIFT_NAME(capture(event:));

/**
 * Captures a manually created event and sends it to MetaMapSentry. Only the data in this scope object will
 * be added to the event. The global scope will be ignored.
 * @param event The event to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureEvent:(MetaMapSentryEvent *)event
                 withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(event:scope:));

/**
 * Captures a manually created event and sends it to MetaMapSentry. Maintains the global scope but mutates
 * scope data for only this call.
 * @param event The event to send to MetaMapSentry.
 * @param block The block mutating the scope only for this call.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureEvent:(MetaMapSentryEvent *)event
            withScopeBlock:(void (^)(MetaMapSentryScope *scope))block NS_SWIFT_NAME(capture(event:block:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param name The transaction name.
 * @param operation Short code identifying the type of operation the span is measuring.
 * @return The created transaction.
 */
+ (id<MetaMapSentrySpan>)startTransactionWithName:(NSString *)name
                                 operation:(NSString *)operation
    NS_SWIFT_NAME(startTransaction(name:operation:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param name The transaction name.
 * @param operation Short code identifying the type of operation the span is measuring.
 * @param bindToScope Indicates whether the SDK should bind the new transaction to the scope.
 * @return The created transaction.
 */
+ (id<MetaMapSentrySpan>)startTransactionWithName:(NSString *)name
                                 operation:(NSString *)operation
                               bindToScope:(BOOL)bindToScope
    NS_SWIFT_NAME(startTransaction(name:operation:bindToScope:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param transactionContext The transaction context.
 * @return The created transaction.
 */
+ (id<MetaMapSentrySpan>)startTransactionWithContext:(MetaMapSentryTransactionContext *)transactionContext
    NS_SWIFT_NAME(startTransaction(transactionContext:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param transactionContext The transaction context.
 * @param bindToScope Indicates whether the SDK should bind the new transaction to the scope.
 * @return The created transaction.
 */
+ (id<MetaMapSentrySpan>)startTransactionWithContext:(MetaMapSentryTransactionContext *)transactionContext
                                  bindToScope:(BOOL)bindToScope
    NS_SWIFT_NAME(startTransaction(transactionContext:bindToScope:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param transactionContext The transaction context.
 * @param bindToScope Indicates whether the SDK should bind the new transaction to the scope.
 * @param customSamplingContext Additional information about the sampling context.
 * @return The created transaction.
 */
+ (id<MetaMapSentrySpan>)startTransactionWithContext:(MetaMapSentryTransactionContext *)transactionContext
                                  bindToScope:(BOOL)bindToScope
                        customSamplingContext:(NSDictionary<NSString *, id> *)customSamplingContext
    NS_SWIFT_NAME(startTransaction(transactionContext:bindToScope:customSamplingContext:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param transactionContext The transaction context.
 * @param customSamplingContext Additional information about the sampling context.
 * @return The created transaction.
 */
+ (id<MetaMapSentrySpan>)startTransactionWithContext:(MetaMapSentryTransactionContext *)transactionContext
                        customSamplingContext:(NSDictionary<NSString *, id> *)customSamplingContext
    NS_SWIFT_NAME(startTransaction(transactionContext:customSamplingContext:));

/**
 * Captures an error event and sends it to MetaMapSentry.
 * @param error The error to send to MetaMapSentry.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureError:(NSError *)error NS_SWIFT_NAME(capture(error:));

/**
 * Captures an error event and sends it to MetaMapSentry. Only the data in this scope object will be added
 * to the event. The global scope will be ignored.
 * @param error The error to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureError:(NSError *)error
                 withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(error:scope:));

/**
 * Captures an error event and sends it to MetaMapSentry. Maintains the global scope but mutates scope data
 * for only this call.
 * @param error The error to send to MetaMapSentry.
 * @param block The block mutating the scope only for this call.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureError:(NSError *)error
            withScopeBlock:(void (^)(MetaMapSentryScope *scope))block NS_SWIFT_NAME(capture(error:block:));

/**
 * Captures an exception event and sends it to MetaMapSentry.
 * @param exception The exception to send to MetaMapSentry.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureException:(NSException *)exception NS_SWIFT_NAME(capture(exception:));

/**
 * Captures an exception event and sends it to MetaMapSentry. Only the data in this scope object will be
 * added to the event. The global scope will be ignored.
 * @param exception The exception to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureException:(NSException *)exception
                     withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(exception:scope:));

/**
 * Captures an exception event and sends it to MetaMapSentry. Maintains the global scope but mutates scope
 * data for only this call.
 * @param exception The exception to send to MetaMapSentry.
 * @param block The block mutating the scope only for this call.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureException:(NSException *)exception
                withScopeBlock:(void (^)(MetaMapSentryScope *scope))block
    NS_SWIFT_NAME(capture(exception:block:));

/**
 * Captures a message event and sends it to MetaMapSentry.
 * @param message The message to send to MetaMapSentry.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureMessage:(NSString *)message NS_SWIFT_NAME(capture(message:));

/**
 * Captures a message event and sends it to MetaMapSentry. Only the data in this scope object will be added
 * to the event. The global scope will be ignored.
 * @param message The message to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureMessage:(NSString *)message
                   withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(message:scope:));

/**
 * Captures a message event and sends it to MetaMapSentry. Maintains the global scope but mutates scope
 * data for only this call.
 * @param message The message to send to MetaMapSentry.
 * @param block The block mutating the scope only for this call.
 * @return The @c MetaMapSentryId of the event or @c MetaMapSentryId.empty if the event is not sent.
 *
 */
+ (MetaMapSentryId *)captureMessage:(NSString *)message
              withScopeBlock:(void (^)(MetaMapSentryScope *scope))block
    NS_SWIFT_NAME(capture(message:block:));

/**
 * Captures a manually created user feedback and sends it to MetaMapSentry.
 * @param userFeedback The user feedback to send to MetaMapSentry.
 */
+ (void)captureUserFeedback:(MetaMapSentryUserFeedback *)userFeedback
    NS_SWIFT_NAME(capture(userFeedback:));

/**
 * Adds a Breadcrumb to the current Scope of the current Hub. If the total number of breadcrumbs
 * exceeds the @c MetaMapSentryOptions.maxBreadcrumbs  the SDK removes the oldest breadcrumb.
 * @param crumb The Breadcrumb to add to the current Scope of the current Hub.
 */
+ (void)addBreadcrumb:(MetaMapSentryBreadcrumb *)crumb NS_SWIFT_NAME(addBreadcrumb(_:));

/**
 * Use this method to modify the current Scope of the current Hub. The SDK uses the Scope to attach
 * contextual data to events.
 * @param callback The callback for configuring the current Scope of the current Hub.
 */
+ (void)configureScope:(void (^)(MetaMapSentryScope *scope))callback;

/**
 * Checks if the last program execution terminated with a crash.
 */
@property (nonatomic, class, readonly) BOOL crashedLastRun;

/**
 * Set user to the current Scope of the current Hub.
 * @param user The user to set to the current Scope.
 */
+ (void)setUser:(nullable MetaMapSentryUser *)user;

/**
 * Starts a new MetaMapSentrySession. If there's a running @c MetaMapSentrySession, it ends it before starting the
 * new one. You can use this method in combination with endSession to manually track
 * @c MetaMapSentrySessions. The SDK uses MetaMapSentrySession to inform MetaMapSentry about release and project
 * associated project health.
 */
+ (void)startSession;

/**
 * Ends the current @c MetaMapSentrySession. You can use this method in combination with @c startSession to
 * manually track @c MetaMapSentrySessions. The SDK uses MetaMapSentrySession to inform MetaMapSentry about release and
 * project associated project health.
 */
+ (void)endSession;

/**
 * This forces a crash, useful to test the @c MetaMapSentryCrash integration.
 *
 * @note The SDK can't report a crash when a debugger is attached. Your application needs to run
 * without a debugger attached to capture the crash and send it to MetaMapSentry the next time you launch
 * your application.
 */
+ (void)crash;

/**
 * Reports to the ongoing UIViewController transaction
 * that the screen contents are fully loaded and displayed,
 * which will create a new span.
 *
 * For more information see our documentation:
 * https://docs.MetaMapSentry.io/platforms/cocoa/performance/instrumentation/automatic-instrumentation/#time-to-full-display
 */
+ (void)reportFullyDisplayed;

/**
 * Waits synchronously for the SDK to flush out all queued and cached items for up to the specified
 * timeout in seconds. If there is no internet connection, the function returns immediately. The SDK
 * doesn't dispose the client or the hub.
 * @param timeout The time to wait for the SDK to complete the flush.
 */
+ (void)flush:(NSTimeInterval)timeout NS_SWIFT_NAME(flush(timeout:));

/**
 * Closes the SDK, uninstalls all the integrations, and calls flush with
 * @c MetaMapSentryOptions.shutdownTimeInterval .
 */
+ (void)close;

@end

NS_ASSUME_NONNULL_END
