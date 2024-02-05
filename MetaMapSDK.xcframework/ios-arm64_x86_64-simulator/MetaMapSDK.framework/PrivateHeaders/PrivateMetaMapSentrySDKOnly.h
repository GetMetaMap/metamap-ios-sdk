#import "PrivatesHeader.h"
#import "MetaMapSentryAppStartMeasurement.h"
#import "MetaMapSentryEnvelope.h"
#import "MetaMapSentryEnvelopeItemType.h"
#import "MetaMapSentryScreenFrames.h"

@class MetaMapSentryDebugMeta, MetaMapSentryAppStartMeasurement, MetaMapSentryScreenFrames, MetaMapSentryOptions,
    MetaMapSentryBreadcrumb, MetaMapSentryUser;

NS_ASSUME_NONNULL_BEGIN

/**
 * A callback to be notified when the @c AppStartMeasurement is available.
 */
typedef void (^MetaMapSentryOnAppStartMeasurementAvailable)(
    MetaMapSentryAppStartMeasurement *_Nullable appStartMeasurement);

/**
 * @warning This class is reserved for hybrid SDKs. Methods may be changed, renamed or removed
 * without notice. If you want to use one of these methods here please open up an issue and let us
 * know.
 * @note The name of this class is supposed to be a bit weird and ugly. The name starts with private
 * on purpose so users don't see it in code completion when typing MetaMapSentry. We also add only at the
 * end to make it more obvious you shouldn't use it.
 */
@interface PrivateMetaMapSentrySDKOnly : NSObject

/**
 * For storing an envelope synchronously to disk.
 */
+ (void)storeEnvelope:(MetaMapSentryEnvelope *)envelope;

+ (void)captureEnvelope:(MetaMapSentryEnvelope *)envelope;

/**
 * Create an envelope from @c NSData. Needed for example by Flutter.
 */
+ (nullable MetaMapSentryEnvelope *)envelopeWithData:(NSData *)data;

/**
 * Returns the current list of debug images. Be aware that the @c MetaMapSentryDebugMeta is actually
 * describing a debug image.
 * @todo This class should be renamed to @c MetaMapSentryDebugImage in a future version.
 */
+ (NSArray<MetaMapSentryDebugMeta *> *)getDebugImages;

/**
 * Override SDK information.
 */
+ (void)setSdkName:(NSString *)sdkName andVersionString:(NSString *)versionString;

/**
 * Override SDK information.
 */
+ (void)setSdkName:(NSString *)sdkName;

/**
 * Retrieves the SDK name
 */
+ (NSString *)getSdkName;

/**
 * Retrieves the SDK version string
 */
+ (NSString *)getSdkVersionString;

/**
 * Retrieves extra context
 */
+ (NSDictionary *)getExtraContext;

@property (class, nullable, nonatomic, copy)
    MetaMapSentryOnAppStartMeasurementAvailable onAppStartMeasurementAvailable;

@property (class, nullable, nonatomic, readonly) MetaMapSentryAppStartMeasurement *appStartMeasurement;

@property (class, nonatomic, readonly, copy) NSString *installationID;

@property (class, nonatomic, readonly, copy) MetaMapSentryOptions *options;

/**
 * If enabled, the SDK won't send the app start measurement with the first transaction. Instead, if
 * @c enableAutoPerformanceTracing is enabled, the SDK measures the app start and then calls
 * @c onAppStartMeasurementAvailable. Furthermore, the SDK doesn't set all values for the app start
 * measurement because the HybridSDKs initialize the Cocoa SDK too late to receive all
 * notifications. Instead, the SDK sets the @c appStartDuration to @c 0 and the
 * @c didFinishLaunchingTimestamp to @c timeIntervalSinceReferenceDate.
 * @note Default is @c NO.
 */
@property (class, nonatomic, assign) BOOL appStartMeasurementHybridSDKMode;

#if MetaMapSentry_HAS_UIKIT
/**
 * Allows hybrid SDKs to enable frame tracking measurements despite other options.
 */
@property (class, nonatomic, assign) BOOL framesTrackingMeasurementHybridSDKMode;

@property (class, nonatomic, assign, readonly) BOOL isFramesTrackingRunning;

@property (class, nonatomic, assign, readonly) MetaMapSentryScreenFrames *currentScreenFrames;

+ (NSArray<NSData *> *)captureScreenshots;

+ (NSData *)captureViewHierarchy;
#endif

+ (MetaMapSentryUser *)userWithDictionary:(NSDictionary *)dictionary;

+ (MetaMapSentryBreadcrumb *)breadcrumbWithDictionary:(NSDictionary *)dictionary;

@end

NS_ASSUME_NONNULL_END
