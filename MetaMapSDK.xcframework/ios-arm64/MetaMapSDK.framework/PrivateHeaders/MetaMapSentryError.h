#import "MetaMapSentryDefines.h"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, MetaMapSentryError) {
    kMetaMapSentryErrorUnknownError = -1,
    kMetaMapSentryErrorInvalidDsnError = 100,
    kMetaMapSentryErrorMetaMapSentryCrashNotInstalledError = 101,
    kMetaMapSentryErrorInvalidCrashReportError = 102,
    kMetaMapSentryErrorCompressionError = 103,
    kMetaMapSentryErrorJsonConversionError = 104,
    kMetaMapSentryErrorCouldNotFindDirectory = 105,
    kMetaMapSentryErrorRequestError = 106,
    kMetaMapSentryErrorEventNotSent = 107,
    kMetaMapSentryErrorFileIO = 108,
    kMetaMapSentryErrorKernel = 109,
};

MetaMapSentry_EXTERN NSError *_Nullable NSErrorFromMetaMapSentryError(MetaMapSentryError error, NSString *description);
MetaMapSentry_EXTERN NSError *_Nullable NSErrorFromMetaMapSentryErrorWithUnderlyingError(
    MetaMapSentryError error, NSString *description, NSError *underlyingError);
MetaMapSentry_EXTERN NSError *_Nullable NSErrorFromMetaMapSentryErrorWithException(
    MetaMapSentryError error, NSString *description, NSException *exception);
MetaMapSentry_EXTERN NSError *_Nullable NSErrorFromMetaMapSentryErrorWithKernelError(
    MetaMapSentryError error, NSString *description, kern_return_t kernelErrorCode);

MetaMapSentry_EXTERN NSString *const MetaMapSentryErrorDomain;

NS_ASSUME_NONNULL_END
