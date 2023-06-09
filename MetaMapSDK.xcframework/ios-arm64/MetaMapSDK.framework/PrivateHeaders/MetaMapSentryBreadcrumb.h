#import <Foundation/Foundation.h>

#import "MetaMapSentryDefines.h"
#import "MetaMapSentrySerializable.h"

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Breadcrumb)
@interface MetaMapSentryBreadcrumb : NSObject <MetaMapSentrySerializable>

/**
 * Level of breadcrumb
 */
@property (nonatomic) MetaMapSentryLevel level;

/**
 * Category of bookmark, can be any string
 */
@property (nonatomic, copy) NSString *category;

/**
 * @c NSDate when the breadcrumb happened
 */
@property (nonatomic, strong) NSDate *_Nullable timestamp;

/**
 * Type of breadcrumb, can be e.g.: http, empty, user, navigation
 * This will be used as icon of the breadcrumb
 */
@property (nonatomic, copy) NSString *_Nullable type;

/**
 * Message for the breadcrumb
 */
@property (nonatomic, copy) NSString *_Nullable message;

/**
 * Arbitrary additional data that will be sent with the breadcrumb
 */
@property (nonatomic, strong) NSDictionary<NSString *, id> *_Nullable data;

/**
 * Initializer for @c MetaMapSentryBreadcrumb
 * @param level MetaMapSentryLevel
 * @param category String
 */
- (instancetype)initWithLevel:(MetaMapSentryLevel)level category:(NSString *)category;
- (instancetype)init;
+ (instancetype)new NS_UNAVAILABLE;

- (NSDictionary<NSString *, id> *)serialize;

- (BOOL)isEqual:(id _Nullable)other;

- (BOOL)isEqualToBreadcrumb:(MetaMapSentryBreadcrumb *)breadcrumb;

- (NSUInteger)hash;

@end

NS_ASSUME_NONNULL_END
