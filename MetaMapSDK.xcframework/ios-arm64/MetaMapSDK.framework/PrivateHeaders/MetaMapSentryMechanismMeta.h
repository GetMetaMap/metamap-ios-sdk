#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"
#import <Foundation/Foundation.h>

@class MetaMapSentryNSError;

NS_ASSUME_NONNULL_BEGIN

/**
 * The mechanism metadata usually carries error codes reported by the runtime or operating system,
 * along with a platform-dependent interpretation of these codes.
 * @see https://develop.MetaMapSentry.dev/sdk/event-payloads/exception/#meta-information.
 */
NS_SWIFT_NAME(MechanismMeta)
@interface MetaMapSentryMechanismMeta : NSObject <MetaMapSentrySerializable>

- (instancetype)init;

/**
 * Information on the POSIX signal. On Apple systems, signals also carry a code in addition to the
 * signal number describing the signal in more detail. On Linux, this code does not exist.
 */
@property (nullable, nonatomic, strong) NSDictionary<NSString *, id> *signal;

/**
 * A Mach Exception on Apple systems comprising a code triple and optional descriptions.
 */
@property (nullable, nonatomic, strong) NSDictionary<NSString *, id> *machException;

/**
 * MetaMapSentry uses the @c NSErrors domain and code for grouping. Only domain and code are serialized.
 */
@property (nullable, nonatomic, strong) MetaMapSentryNSError *error;

@end

NS_ASSUME_NONNULL_END
