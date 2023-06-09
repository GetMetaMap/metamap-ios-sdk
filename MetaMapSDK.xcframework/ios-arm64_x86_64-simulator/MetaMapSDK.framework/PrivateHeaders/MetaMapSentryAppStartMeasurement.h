#import "PrivatesHeader.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MetaMapSentryAppStartType) {
    MetaMapSentryAppStartTypeWarm,
    MetaMapSentryAppStartTypeCold,
    MetaMapSentryAppStartTypeUnknown,
};

@interface MetaMapSentryAppStartMeasurement : NSObject
MetaMapSentry_NO_INIT

/**
 * Initializes MetaMapSentryAppStartMeasurement with the given parameters.
 */
- (instancetype)initWithType:(MetaMapSentryAppStartType)type
              appStartTimestamp:(NSDate *)appStartTimestamp
                       duration:(NSTimeInterval)duration
           runtimeInitTimestamp:(NSDate *)runtimeInitTimestamp
    didFinishLaunchingTimestamp:(NSDate *)didFinishLaunchingTimestamp
    DEPRECATED_MSG_ATTRIBUTE("Use "
                             "initWithType:appStartTimestamp:duration:mainTimestamp:"
                             "runtimeInitTimestamp:didFinishLaunchingTimestamp instead.");

/**
 * Initializes MetaMapSentryAppStartMeasurement with the given parameters.
 */
- (instancetype)initWithType:(MetaMapSentryAppStartType)type
                      isPreWarmed:(BOOL)isPreWarmed
                appStartTimestamp:(NSDate *)appStartTimestamp
                         duration:(NSTimeInterval)duration
             runtimeInitTimestamp:(NSDate *)runtimeInitTimestamp
    moduleInitializationTimestamp:(NSDate *)moduleInitializationTimestamp
      didFinishLaunchingTimestamp:(NSDate *)didFinishLaunchingTimestamp;

/**
 * The type of the app start.
 */
@property (readonly, nonatomic, assign) MetaMapSentryAppStartType type;

@property (readonly, nonatomic, assign) BOOL isPreWarmed;

/**
 * How long the app start took. From appStartTimestamp to when the SDK creates the
 * AppStartMeasurement, which is done when the OS posts UIWindowDidBecomeVisibleNotification.
 */
@property (readonly, nonatomic, assign) NSTimeInterval duration;

/**
 * The timestamp when the app started, which is the process start timestamp and for prewarmed app
 * starts the moduleInitializationTimestamp.
 */
@property (readonly, nonatomic, strong) NSDate *appStartTimestamp;

/**
 * When the runtime was initialized / when MetaMapSentryAppStartTracker is added to the Objective-C runtime
 */
@property (readonly, nonatomic, strong) NSDate *runtimeInitTimestamp;

/**
 * When application main function is called.
 */
@property (readonly, nonatomic, strong) NSDate *moduleInitializationTimestamp;

/**
 * When OS posts UIApplicationDidFinishLaunchingNotification.
 */
@property (readonly, nonatomic, strong) NSDate *didFinishLaunchingTimestamp;

@end

NS_ASSUME_NONNULL_END
