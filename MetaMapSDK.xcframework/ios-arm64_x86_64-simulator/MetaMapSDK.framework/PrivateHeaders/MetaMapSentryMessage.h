#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Carries a log message that describes an event or error. Optionally, it can carry a format string
 * and structured parameters. This can help to group similar messages into the same issue.
 * @see https://develop.MetaMapSentry.dev/sdk/event-payloads/message/
 */
@interface MetaMapSentryMessage : NSObject <MetaMapSentrySerializable>
MetaMapSentry_NO_INIT

/**
 * Returns a @c MetaMapSentryMessage with setting formatted.
 * @param formatted The fully formatted message. If missing, MetaMapSentry will try to interpolate the
 * message. It must not exceed 8192 characters. Longer messages will be truncated.
 */
- (instancetype)initWithFormatted:(NSString *)formatted;

/**
 * The fully formatted message. If missing, MetaMapSentry will try to interpolate the message. It must not
 * exceed 8192 characters. Longer messages will be truncated.
 */
@property (nonatomic, readonly, copy) NSString *formatted;

/**
 * The raw message string (uninterpolated). It must not exceed 8192 characters. Longer messages will
 * be truncated.
 */
@property (nonatomic, copy) NSString *_Nullable message;

/**
 * A list of formatting parameters for the raw message.
 */
@property (nonatomic, strong) NSArray<NSString *> *_Nullable params;

@end

NS_ASSUME_NONNULL_END
