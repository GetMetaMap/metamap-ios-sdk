#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"

@class MetaMapSentryUser;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, MetaMapSentrySessionStatus) {
    kMetaMapSentrySessionStatusOk = 0,
    kMetaMapSentrySessionStatusExited = 1,
    kMetaMapSentrySessionStatusCrashed = 2,
    kMetaMapSentrySessionStatusAbnormal = 3,
};

/**
 * The SDK uses MetaMapSentrySession to inform MetaMapSentry about release and project associated project health.
 */
@interface MetaMapSentrySession : NSObject <MetaMapSentrySerializable, NSCopying>
MetaMapSentry_NO_INIT

- (instancetype)initWithReleaseName:(NSString *)releaseName;

/**
 * Initializes @c MetaMapSentrySession from a JSON object.
 * @param jsonObject The @c jsonObject containing the session.
 * @return The @c MetaMapSentrySession or @c nil if @c jsonObject contains an error.
 */
- (nullable instancetype)initWithJSONObject:(NSDictionary *)jsonObject;

- (void)endSessionExitedWithTimestamp:(NSDate *)timestamp;
- (void)endSessionCrashedWithTimestamp:(NSDate *)timestamp;
- (void)endSessionAbnormalWithTimestamp:(NSDate *)timestamp;

- (void)incrementErrors;

@property (nonatomic, readonly, strong) NSUUID *sessionId;
@property (nonatomic, readonly, strong) NSDate *started;
@property (nonatomic, readonly) enum MetaMapSentrySessionStatus status;
@property (nonatomic, readonly) NSUInteger errors;
@property (nonatomic, readonly) NSUInteger sequence;
@property (nonatomic, readonly, strong) NSString *distinctId;
/**
 * We can't use @c init because it overlaps with @c NSObject.init .
 */
@property (nonatomic, readonly, copy) NSNumber *_Nullable flagInit;
@property (nonatomic, readonly, strong) NSDate *_Nullable timestamp;
@property (nonatomic, readonly, strong) NSNumber *_Nullable duration;

@property (nonatomic, readonly, copy) NSString *_Nullable releaseName;
@property (nonatomic, copy) NSString *_Nullable environment;
@property (nonatomic, copy) MetaMapSentryUser *_Nullable user;

- (NSDictionary<NSString *, id> *)serialize;

@end

NS_ASSUME_NONNULL_END
