#import <Foundation/Foundation.h>

#ifdef __cplusplus
#    define MetaMapSentry_EXTERN extern "C" __attribute__((visibility("default")))
#else
#    define MetaMapSentry_EXTERN extern __attribute__((visibility("default")))
#endif

#if TARGET_OS_IOS || TARGET_OS_TV
#    define MetaMapSentry_HAS_UIDEVICE 1
#else
#    define MetaMapSentry_HAS_UIDEVICE 0
#endif

#if MetaMapSentry_HAS_UIDEVICE
#    define MetaMapSentry_HAS_UIKIT 1
#else
#    define MetaMapSentry_HAS_UIKIT 0
#endif

#if TARGET_OS_IOS || TARGET_OS_OSX || TARGET_OS_MACCATALYST
#    define MetaMapSentry_HAS_METRIC_KIT 1
#else
#    define MetaMapSentry_HAS_METRIC_KIT 0
#endif

#define MetaMapSentry_NO_INIT                                                                             \
    -(instancetype)init NS_UNAVAILABLE;                                                            \
    +(instancetype) new NS_UNAVAILABLE;

@class MetaMapSentryEvent, MetaMapSentryBreadcrumb, MetaMapSentrySamplingContext;
@protocol MetaMapSentrySpan;

/**
 * Block used for returning after a request finished
 */
typedef void (^MetaMapSentryRequestFinished)(NSError *_Nullable error);

/**
 * Block used for request operation finished, @c shouldDiscardEvent is @c YES if event
 * should be deleted regardless if an error occurred or not
 */
typedef void (^MetaMapSentryRequestOperationFinished)(
    NSHTTPURLResponse *_Nullable response, NSError *_Nullable error);
/**
 * Block can be used to mutate a breadcrumb before it's added to the scope.
 * To avoid adding the breadcrumb altogether, return @c nil instead.
 */
typedef MetaMapSentryBreadcrumb *_Nullable (^MetaMapSentryBeforeBreadcrumbCallback)(
    MetaMapSentryBreadcrumb *_Nonnull breadcrumb);

/**
 * Block can be used to mutate event before its send.
 * To avoid sending the event altogether, return nil instead.
 */
typedef MetaMapSentryEvent *_Nullable (^MetaMapSentryBeforeSendEventCallback)(MetaMapSentryEvent *_Nonnull event);

/**
 * A callback to be notified when the last program execution terminated with a crash.
 */
typedef void (^MetaMapSentryOnCrashedLastRunCallback)(MetaMapSentryEvent *_Nonnull event);

/**
 * Block can be used to determine if an event should be queued and stored
 * locally. It will be tried to send again after next successful send. Note that
 * this will only be called once the event is created and send manually. Once it
 * has been queued once it will be discarded if it fails again.
 */
typedef BOOL (^MetaMapSentryShouldQueueEvent)(
    NSHTTPURLResponse *_Nullable response, NSError *_Nullable error);

/**
 * Function pointer for a sampler callback.
 * @param samplingContext context of the sampling.
 * @return A sample rate that is >=  @c 0.0 and \<= @c 1.0 or @c nil if no sampling decision has
 * been taken. When returning a value out of range the SDK uses the default of @c 0.
 */
typedef NSNumber *_Nullable (^MetaMapSentryTracesSamplerCallback)(
    MetaMapSentrySamplingContext *_Nonnull samplingContext);

/**
 * Function pointer for span manipulation.
 * @param span The span to be used.
 */
typedef void (^MetaMapSentrySpanCallback)(id<MetaMapSentrySpan> _Nullable span);

/**
 * Log level.
 */
typedef NS_ENUM(NSInteger, MetaMapSentryLogLevel) {
    kMetaMapSentryLogLevelNone = 1,
    kMetaMapSentryLogLevelError,
    kMetaMapSentryLogLevelDebug,
    kMetaMapSentryLogLevelVerbose
};

/**
 * MetaMapSentry level.
 */
typedef NS_ENUM(NSUInteger, MetaMapSentryLevel) {
    // Defaults to None which doesn't get serialized
    kMetaMapSentryLevelNone = 0,
    // Goes from Debug to Fatal so possible to: (level > Info) { .. }
    kMetaMapSentryLevelDebug = 1,
    kMetaMapSentryLevelInfo = 2,
    kMetaMapSentryLevelWarning = 3,
    kMetaMapSentryLevelError = 4,
    kMetaMapSentryLevelFatal = 5
};

/**
 * Static internal helper to convert enum to string.
 */
static DEPRECATED_MSG_ATTRIBUTE(
    "Use nameForMetaMapSentryLevel() instead.") NSString *_Nonnull const MetaMapSentryLevelNames[]
    = {
          @"none",
          @"debug",
          @"info",
          @"warning",
          @"error",
          @"fatal",
      };

static NSUInteger const defaultMaxBreadcrumbs = 100;

/**
 * Transaction name source.
 */
typedef NS_ENUM(NSInteger, MetaMapSentryTransactionNameSource) {
    kMetaMapSentryTransactionNameSourceCustom = 0,
    kMetaMapSentryTransactionNameSourceUrl,
    kMetaMapSentryTransactionNameSourceRoute,
    kMetaMapSentryTransactionNameSourceView,
    kMetaMapSentryTransactionNameSourceComponent,
    kMetaMapSentryTransactionNameSourceTask
};
