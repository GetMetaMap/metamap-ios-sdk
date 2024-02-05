#import "MetaMapSentryDefines.h"
#import "MetaMapSentryIntegrationProtocol.h"
#import "MetaMapSentrySpanProtocol.h"

@class MetaMapSentryEvent, MetaMapSentryClient, MetaMapSentryScope, MetaMapSentryUser, MetaMapSentryBreadcrumb, MetaMapSentryId,
    MetaMapSentryUserFeedback, MetaMapSentryTransactionContext;

NS_ASSUME_NONNULL_BEGIN
@interface MetaMapSentryHub : NSObject
MetaMapSentry_NO_INIT

- (instancetype)initWithClient:(MetaMapSentryClient *_Nullable)client
                      andScope:(MetaMapSentryScope *_Nullable)scope;

/**
 * Starts a new MetaMapSentrySession. If there's a running MetaMapSentrySession, it ends it before starting the
 * new one. You can use this method in combination with endSession to manually track MetaMapSentrySessions.
 * The SDK uses MetaMapSentrySession to inform MetaMapSentry about release and project associated project health.
 */
- (void)startSession;

/**
 * Ends the current MetaMapSentrySession. You can use this method in combination with startSession to
 * manually track MetaMapSentrySessions. The SDK uses MetaMapSentrySession to inform MetaMapSentry about release and
 * project associated project health.
 */
- (void)endSession;

/**
 * Ends the current session with the given timestamp.
 * @param timestamp The timestamp to end the session with.
 */
- (void)endSessionWithTimestamp:(NSDate *)timestamp;

/**
 * Captures a manually created event and sends it to MetaMapSentry.
 * @param event The event to send to MetaMapSentry.
 * @return The MetaMapSentryId of the event or MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureEvent:(MetaMapSentryEvent *)event NS_SWIFT_NAME(capture(event:));

/**
 * Captures a manually created event and sends it to MetaMapSentry.
 * @param event The event to send to MetaMapSentry.
 * @param scope The scope containing event metadata.
 * @return The MetaMapSentryId of the event or MetaMapSentryId.empty if the event is not sent.
 */
- (MetaMapSentryId *)captureEvent:(MetaMapSentryEvent *)event
                 withScope:(MetaMapSentryScope *)scope NS_SWIFT_NAME(capture(event:scope:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param name The transaction name.
 * @param operation Short code identifying the type of operation the span is measuring.
 * @return The created transaction.
 */
- (id<MetaMapSentrySpan>)startTransactionWithName:(NSString *)name
                                 operation:(NSString *)operation
    NS_SWIFT_NAME(startTransaction(name:operation:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param name The transaction name.
 * @param operation Short code identifying the type of operation the span is measuring.
 * @param bindToScope Indicates whether the SDK should bind the new transaction to the scope.
 * @return The created transaction.
 */
- (id<MetaMapSentrySpan>)startTransactionWithName:(NSString *)name
                                 operation:(NSString *)operation
                               bindToScope:(BOOL)bindToScope
    NS_SWIFT_NAME(startTransaction(name:operation:bindToScope:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param transactionContext The transaction context.
 * @return The created transaction.
 */
- (id<MetaMapSentrySpan>)startTransactionWithContext:(MetaMapSentryTransactionContext *)transactionContext
    NS_SWIFT_NAME(startTransaction(transactionContext:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param transactionContext The transaction context.
 * @param bindToScope Indicates whether the SDK should bind the new transaction to the scope.
 * @return The created transaction.
 */
- (id<MetaMapSentrySpan>)startTransactionWithContext:(MetaMapSentryTransactionContext *)transactionContext
                                  bindToScope:(BOOL)bindToScope
    NS_SWIFT_NAME(startTransaction(transactionContext:bindToScope:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param transactionContext The transaction context.
 * @param bindToScope Indicates whether the SDK should bind the new transaction to the scope.
 * @param customSamplingContext Additional information about the sampling context.
 * @return The created transaction.
 */
- (id<MetaMapSentrySpan>)startTransactionWithContext:(MetaMapSentryTransactionContext *)transactionContext
                                  bindToScope:(BOOL)bindToScope
                        customSamplingContext:(NSDictionary<NSString *, id> *)customSamplingContext
    NS_SWIFT_NAME(startTransaction(transactionContext:bindToScope:customSamplingContext:));

/**
 * Creates a transaction, binds it to the hub and returns the instance.
 * @param transactionContext The transaction context.
 * @param customSamplingContext Additional information about the sampling context.
 * @return The created transaction.
 */
- (id<MetaMapSentrySpan>)startTransactionWithContext:(MetaMapSentryTransactionContext *)transactionContext
                        customSamplingContext:(NSDictionary<NSString *, id> *)customSamplingContext
    NS_SWIFT_NAME(startTransaction(transactionContext:customSamplingContext:));

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
 * Use this method to modify the Scope of the Hub. The SDK uses the Scope to attach
 * contextual data to events.
 * @param callback The callback for configuring the Scope of the Hub.
 */
- (void)configureScope:(void (^)(MetaMapSentryScope *scope))callback;

/**
 * Adds a breadcrumb to the Scope of the Hub.
 * @param crumb The Breadcrumb to add to the Scope of the Hub.
 */
- (void)addBreadcrumb:(MetaMapSentryBreadcrumb *)crumb;

/**
 * Returns a client if there is a bound client on the Hub.
 */
- (MetaMapSentryClient *_Nullable)getClient;

/**
 * Returns either the current scope or a new one if it was @c nil .
 */
@property (nonatomic, readonly, strong) MetaMapSentryScope *scope;

/**
 * Binds a different client to the hub.
 */
- (void)bindClient:(MetaMapSentryClient *_Nullable)client;

/**
 * Checks if integration is activated.
 */
- (BOOL)hasIntegration:(NSString *)integrationName;

/**
 * Checks if a specific Integration (@c integrationClass) has been installed.
 * @return @c YES if instance of @c integrationClass exists within
 * @c MetaMapSentryHub.installedIntegrations
 */
- (BOOL)isIntegrationInstalled:(Class)integrationClass;

/**
 * Set user to the Scope of the Hub.
 * @param user The user to set to the Scope.
 */
- (void)setUser:(MetaMapSentryUser *_Nullable)user;

/**
 * Reports to the ongoing UIViewController transaction
 * that the screen contents are fully loaded and displayed,
 * which will create a new span.
 */
- (void)reportFullyDisplayed;

/**
 * Waits synchronously for the SDK to flush out all queued and cached items for up to the specified
 * timeout in seconds. If there is no internet connection, the function returns immediately. The SDK
 * doesn't dispose the client or the hub.
 * @param timeout The time to wait for the SDK to complete the flush.
 */
- (void)flush:(NSTimeInterval)timeout NS_SWIFT_NAME(flush(timeout:));

/**
 * Calls flush with @c MetaMapSentryOptions/shutdownTimeInterval .
 */
- (void)close;

@end

NS_ASSUME_NONNULL_END
