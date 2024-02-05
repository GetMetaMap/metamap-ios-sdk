#import <Foundation/Foundation.h>

#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryFrame;

@interface MetaMapSentryStacktrace : NSObject <MetaMapSentrySerializable>
MetaMapSentry_NO_INIT

/**
 * Array of all MetaMapSentryFrame in the stacktrace
 */
@property (nonatomic, strong) NSArray<MetaMapSentryFrame *> *frames;

/**
 * Registers of the thread for additional information used on the server
 */
@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *registers;

/**
 * Indicates that this stack trace is a snapshot triggered by an external signal.
 */
@property (nonatomic, copy, nullable) NSNumber *snapshot;

/**
 * Initialize a MetaMapSentryStacktrace with frames and registers
 * @param frames NSArray
 * @param registers NSArray
 * @return MetaMapSentryStacktrace
 */
- (instancetype)initWithFrames:(NSArray<MetaMapSentryFrame *> *)frames
                     registers:(NSDictionary<NSString *, NSString *> *)registers;

/**
 * This will be called internally, is used to remove duplicated frames for
 * certain crashes.
 */
- (void)fixDuplicateFrames;

@end

NS_ASSUME_NONNULL_END
