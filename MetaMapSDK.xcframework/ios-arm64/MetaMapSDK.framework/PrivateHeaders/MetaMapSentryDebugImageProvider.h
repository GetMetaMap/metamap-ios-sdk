#import "MetaMapSentryDefines.h"
#import <Foundation/Foundation.h>

@class MetaMapSentryDebugMeta, MetaMapSentryThread, MetaMapSentryFrame;

NS_ASSUME_NONNULL_BEGIN

/**
 * Reserved for hybrid SDKs that the debug image list for symbolication.
 */
@interface MetaMapSentryDebugImageProvider : NSObject

- (instancetype)init;

/**
 * Returns a list of debug images that are being referenced in the given threads.
 * @param threads A list of @c MetaMapSentryThread that may or may not contain stacktracse.
 */
- (NSArray<MetaMapSentryDebugMeta *> *)getDebugImagesForThreads:(NSArray<MetaMapSentryThread *> *)threads;

/**
 * Returns a list of debug images that are being referenced by the given frames.
 * @param frames A list of stack frames.
 */
- (NSArray<MetaMapSentryDebugMeta *> *)getDebugImagesForFrames:(NSArray<MetaMapSentryFrame *> *)frames;

/**
 * Returns the current list of debug images. Be aware that the @c MetaMapSentryDebugMeta is actually
 * describing a debug image.
 * @todo This class should be renamed to @c MetaMapSentryDebugImage in a future version.
 */
- (NSArray<MetaMapSentryDebugMeta *> *)getDebugImages;

@end

NS_ASSUME_NONNULL_END
