#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryId;

/**
 * Adds additional information about what happened to an event.
 */
NS_SWIFT_NAME(UserFeedback)
@interface MetaMapSentryUserFeedback : NSObject <MetaMapSentrySerializable>
MetaMapSentry_NO_INIT

/**
 * Initializes MetaMapSentryUserFeedback and sets the required eventId.
 * @param eventId The eventId of the event to which the user feedback is associated.
 */
- (instancetype)initWithEventId:(MetaMapSentryId *)eventId;

/**
 * The eventId of the event to which the user feedback is associated.
 */
@property (readonly, nonatomic, strong) MetaMapSentryId *eventId;

/**
 * The name of the user.
 */
@property (nonatomic, copy) NSString *name;

/**
 * The email of the user.
 */
@property (nonatomic, copy) NSString *email;

/**
 * Comments of the user about what happened.
 */
@property (nonatomic, copy) NSString *comments;

@end

NS_ASSUME_NONNULL_END
