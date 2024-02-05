#import "PrivatesHeader.h"

NS_ASSUME_NONNULL_BEGIN

#if MetaMapSentry_HAS_UIKIT

/** An array of dictionaries that each contain a start and end timestamp for a rendered frame. */
#    if MetaMapSentry_TARGET_PROFILING_SUPPORTED
typedef NSArray<NSDictionary<NSString *, NSNumber *> *> MetaMapSentryFrameInfoTimeSeries;
#    endif // MetaMapSentry_TARGET_PROFILING_SUPPORTED

@interface MetaMapSentryScreenFrames : NSObject
MetaMapSentry_NO_INIT

- (instancetype)initWithTotal:(NSUInteger)total frozen:(NSUInteger)frozen slow:(NSUInteger)slow;

#    if MetaMapSentry_TARGET_PROFILING_SUPPORTED
- (instancetype)initWithTotal:(NSUInteger)total
                       frozen:(NSUInteger)frozen
                         slow:(NSUInteger)slow
          slowFrameTimestamps:(MetaMapSentryFrameInfoTimeSeries *)slowFrameTimestamps
        frozenFrameTimestamps:(MetaMapSentryFrameInfoTimeSeries *)frozenFrameTimestamps
          frameRateTimestamps:(MetaMapSentryFrameInfoTimeSeries *)frameRateTimestamps;
#    endif // MetaMapSentry_TARGET_PROFILING_SUPPORTED

@property (nonatomic, assign, readonly) NSUInteger total;
@property (nonatomic, assign, readonly) NSUInteger frozen;
@property (nonatomic, assign, readonly) NSUInteger slow;

#    if MetaMapSentry_TARGET_PROFILING_SUPPORTED
/**
 * Array of dictionaries describing slow frames' timestamps. Each dictionary has a start and end
 * timestamp for every such frame, keyed under @c start_timestamp and @c end_timestamp.
 */
@property (nonatomic, copy, readonly) MetaMapSentryFrameInfoTimeSeries *slowFrameTimestamps;

/**
 * Array of dictionaries describing frozen frames' timestamps. Each dictionary has a start and end
 * timestamp for every such frame, keyed under @c start_timestamp and @c end_timestamp.
 */
@property (nonatomic, copy, readonly) MetaMapSentryFrameInfoTimeSeries *frozenFrameTimestamps;

/**
 * Array of dictionaries describing the screen refresh rate at all points in time that it changes,
 * which can happen when modern devices e.g. go into low power mode. Each dictionary contains keys
 * @c timestamp and @c frame_rate.
 */
@property (nonatomic, copy, readonly) MetaMapSentryFrameInfoTimeSeries *frameRateTimestamps;
#    endif // MetaMapSentry_TARGET_PROFILING_SUPPORTED

@end

#endif

NS_ASSUME_NONNULL_END
