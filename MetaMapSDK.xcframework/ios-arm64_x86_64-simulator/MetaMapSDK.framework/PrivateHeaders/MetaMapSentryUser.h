#import "MetaMapSentryDefines.h"
#import "MetaMapSentryGeo.h"
#import "MetaMapSentrySerializable.h"

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryGeo;

NS_SWIFT_NAME(User)
@interface MetaMapSentryUser : NSObject <MetaMapSentrySerializable, NSCopying>

/**
 * Optional: Id of the user
 */
@property (atomic, copy) NSString *_Nullable userId;

/**
 * Optional: Email of the user
 */
@property (atomic, copy) NSString *_Nullable email;

/**
 * Optional: Username
 */
@property (atomic, copy) NSString *_Nullable username;

/**
 * Optional: IP Address
 */
@property (atomic, copy) NSString *_Nullable ipAddress;

/**
 * The user segment, for apps that divide users in user segments.
 */
@property (atomic, copy) NSString *_Nullable segment;

/**
 * Optional: Human readable name
 */
@property (atomic, copy) NSString *_Nullable name;

/**
 * Optional: Geo location of user
 */
@property (nullable, nonatomic, strong) MetaMapSentryGeo *geo;

/**
 * Optional: Additional data
 */
@property (atomic, strong) NSDictionary<NSString *, id> *_Nullable data;

/**
 * Initializes a MetaMapSentryUser with the id
 * @param userId NSString
 * @return MetaMapSentryUser
 */
- (instancetype)initWithUserId:(NSString *)userId;

- (instancetype)init;

- (BOOL)isEqual:(id _Nullable)other;

- (BOOL)isEqualToUser:(MetaMapSentryUser *)user;

- (NSUInteger)hash;

@end

NS_ASSUME_NONNULL_END
