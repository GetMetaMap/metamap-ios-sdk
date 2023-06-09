#import <Foundation/Foundation.h>

#import "MetaMapSentryDefines.h"
#import "MetaMapSentryOptions.h"

NS_ASSUME_NONNULL_BEGIN

@protocol MetaMapSentryIntegrationProtocol <NSObject>

/**
 * Installs the integration and returns YES if successful.
 */
- (BOOL)installWithOptions:(MetaMapSentryOptions *)options;

/**
 * Uninstalls the integration.
 */
@optional
- (void)uninstall;

@end

NS_ASSUME_NONNULL_END
