#import "MetaMapSentryBaseIntegration.h"
#import "MetaMapSentryBreadcrumbDelegate.h"
#import "MetaMapSentryIntegrationProtocol.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This automatically adds breadcrumbs for different user actions.
 */
@interface MetaMapSentryAutoBreadcrumbTrackingIntegration
    : MetaMapSentryBaseIntegration <MetaMapSentryIntegrationProtocol, MetaMapSentryBreadcrumbDelegate>

@end

NS_ASSUME_NONNULL_END
