#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A 16 character Id.
 */

NS_SWIFT_NAME(SpanId)
@interface MetaMapSentrySpanId : NSObject <NSCopying>

/**
 * Creates a MetaMapSentrySpanId with a random 16 character Id.
 */
- (instancetype)init;

/**
 * Creates a MetaMapSentrySpanId with the first 16 characters of the given UUID.
 */
- (instancetype)initWithUUID:(NSUUID *)uuid;

/**
 * Creates a MetaMapSentrySpanId from a 16 character string.
 * Returns a empty MetaMapSentrySpanId with the input is invalid.
 */
- (instancetype)initWithValue:(NSString *)value;

/**
 * Returns the Span Id Value
 */
@property (readonly, copy) NSString *MetaMapSentrySpanIdString;

/**
 * A MetaMapSentrySpanId with an empty Id "0000000000000000".
 */
@property (class, nonatomic, readonly, strong) MetaMapSentrySpanId *empty;

@end

NS_ASSUME_NONNULL_END
