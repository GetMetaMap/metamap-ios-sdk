#import <Foundation/Foundation.h>

#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryThread, MetaMapSentryException, MetaMapSentryStacktrace, MetaMapSentryUser, MetaMapSentryDebugMeta, MetaMapSentryContext,
    MetaMapSentryBreadcrumb, MetaMapSentryId, MetaMapSentryMessage, MetaMapSentryRequest;

NS_SWIFT_NAME(Event)
@interface MetaMapSentryEvent : NSObject <MetaMapSentrySerializable>

/**
 * This will be set by the initializer.
 */
@property (nonatomic, strong) MetaMapSentryId *eventId;

/**
 * Message of the event.
 */
@property (nonatomic, strong) MetaMapSentryMessage *_Nullable message;

/**
 * The error of the event. This property adds convenience to access the error directly in
 * @c beforeSend. This property is not serialized. Instead when preparing the event the
 * @c MetaMapSentryClient puts the error into exceptions.
 */
@property (nonatomic, copy) NSError *_Nullable error;

/**
 * @c NSDate of when the event occurred.
 */
@property (nonatomic, strong) NSDate *_Nullable timestamp;

/**
 * @c NSDate of when the event started, mostly useful if event type transaction.
 */
@property (nonatomic, strong) NSDate *_Nullable startTimestamp;

/**
 * @c MetaMapSentryLevel of the event.
 */
@property (nonatomic) enum MetaMapSentryLevel level;

/**
 * This will be used for symbolicating on the server should be "cocoa".
 */
@property (nonatomic, copy) NSString *platform;

/**
 * Define the logger name.
 */
@property (nonatomic, copy) NSString *_Nullable logger;

/**
 * Define the server name.
 */
@property (nonatomic, copy) NSString *_Nullable serverName;

/**
 * @note This property will be filled before the event is sent.
 * @warning This is maintained automatically, and shouldn't normally need to be modified.
 */
@property (nonatomic, copy) NSString *_Nullable releaseName;

/**
 * @note This property will be filled before the event is sent.
 * @warning This is maintained automatically, and shouldn't normally need to be modified.
 */
@property (nonatomic, copy) NSString *_Nullable dist;

/**
 * The environment used for this event.
 */
@property (nonatomic, copy) NSString *_Nullable environment;

/**
 * The name of the transaction which caused this event.
 */
@property (nonatomic, copy) NSString *_Nullable transaction;

/**
 * The type of the event, null, default or transaction.
 */
@property (nonatomic, copy) NSString *_Nullable type;

/**
 * Arbitrary key:value (string:string ) data that will be shown with the event.
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *_Nullable tags;

/**
 * Arbitrary additional information that will be sent with the event.
 */
@property (nonatomic, strong) NSDictionary<NSString *, id> *_Nullable extra;

/**
 * Information about the SDK. For example:
 * @code
 * {
 *  version: "6.0.1",
 *  name: "MetaMapSentry.cocoa",
 *  integrations: [
 *      "react-native"
 *  ]
 * }
 * @endcode
 * @warning This is automatically maintained and should not normally need to be modified.
 */
@property (nonatomic, strong) NSDictionary<NSString *, id> *_Nullable sdk;

/**
 * Modules of the event.
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *_Nullable modules;

/**
 * Set the fingerprint of an event to determine the grouping
 */
@property (nonatomic, strong) NSArray<NSString *> *_Nullable fingerprint;

/**
 * Set the @c MetaMapSentryUser for the event.
 */
@property (nonatomic, strong) MetaMapSentryUser *_Nullable user;

/**
 * This object contains meta information.
 * @warning This is maintained automatically, and shouldn't normally need to be modified.
 */
@property (nonatomic, strong)
    NSDictionary<NSString *, NSDictionary<NSString *, id> *> *_Nullable context;

/**
 * Contains @c MetaMapSentryThread if a crash occurred or for a user reported exception.
 */
@property (nonatomic, strong) NSArray<MetaMapSentryThread *> *_Nullable threads;

/**
 * General information about the @c MetaMapSentryException, usually there is only one
 * exception in the array.
 */
@property (nonatomic, strong) NSArray<MetaMapSentryException *> *_Nullable exceptions;

/**
 * Separate @c MetaMapSentryStacktrace that can be sent with the event, besides threads.
 */
@property (nonatomic, strong) MetaMapSentryStacktrace *_Nullable stacktrace;

/**
 * Containing images loaded during runtime.
 */
@property (nonatomic, strong) NSArray<MetaMapSentryDebugMeta *> *_Nullable debugMeta;

/**
 * This contains all breadcrumbs available at the time when the event
 * occurred/will be sent.
 */
@property (nonatomic, strong) NSArray<MetaMapSentryBreadcrumb *> *_Nullable breadcrumbs;

/**
 * Set the HTTP request information.
 */
@property (nonatomic, strong, nullable) MetaMapSentryRequest *request;

/**
 * Init an @c MetaMapSentryEvent will set all needed fields by default.
 */
- (instancetype)init;

/**
 * Init a @c MetaMapSentryEvent with a @c MetaMapSentryLevelError and set all needed fields by default.
 */
- (instancetype)initWithLevel:(enum MetaMapSentryLevel)level NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a @c MetaMapSentryEvent with an @c NSError and sets the level to @c MetaMapSentryLevelError.
 * @param error The error of the event.
 */
- (instancetype)initWithError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
