#import "MetaMapSentryInternalDefines.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MetaMapSentryBreadcrumbDelegate <NSObject>

- (void)addBreadcrumb:(MetaMapSentryBreadcrumb *)crumb;

@end

NS_ASSUME_NONNULL_END
