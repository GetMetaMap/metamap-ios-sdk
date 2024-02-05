#import <Foundation/Foundation.h>

/**
 * Describes the status of the Span/Transaction.
 */
typedef NS_ENUM(NSUInteger, MetaMapSentrySpanStatus) {
    /**
     * An undefined status.
     */
    kMetaMapSentrySpanStatusUndefined,

    /**
     * Not an error, returned on success.
     */
    kMetaMapSentrySpanStatusOk,

    /**
     * The deadline expired before the operation could succeed.
     */
    kMetaMapSentrySpanStatusDeadlineExceeded,

    /**
     * The requester doesn't have valid authentication credentials for the operation.
     */
    kMetaMapSentrySpanStatusUnauthenticated,

    /**
     * The caller doesn't have permission to execute the specified operation.
     */
    kMetaMapSentrySpanStatusPermissionDenied,

    /**
     * Content was not found or request was denied for an entire class of users.
     */
    kMetaMapSentrySpanStatusNotFound,

    /**
     * The resource has been exhausted e.g. per-user quota exhausted, file system out of space.
     */
    kMetaMapSentrySpanStatusResourceExhausted,

    /**
     * The client specified an invalid argument.
     */
    kMetaMapSentrySpanStatusInvalidArgument,

    /**
     * 501 Not Implemented.
     */
    kMetaMapSentrySpanStatusUnimplemented,

    /**
     * The operation is not implemented or is not supported/enabled for this operation.
     */
    kMetaMapSentrySpanStatusUnavailable,

    /**
     * Some invariants expected by the underlying system have been broken. This code is reserved for
     * serious errors.
     */
    kMetaMapSentrySpanStatusInternalError,

    /**
     * An unknown error raised by APIs that don't return enough error information.
     */
    kMetaMapSentrySpanStatusUnknownError,

    /**
     * The operation was cancelled, typically by the caller.
     */
    kMetaMapSentrySpanStatusCancelled,

    /**
     * The entity attempted to be created already exists.
     */
    kMetaMapSentrySpanStatusAlreadyExists,

    /**
     * The client shouldn't retry until the system state has been explicitly handled.
     */
    kMetaMapSentrySpanStatusFailedPrecondition,

    /**
     * The operation was aborted.
     */
    kMetaMapSentrySpanStatusAborted,

    /**
     * The operation was attempted past the valid range e.g. seeking past the end of a file.
     */
    kMetaMapSentrySpanStatusOutOfRange,

    /**
     * Unrecoverable data loss or corruption.
     */
    kMetaMapSentrySpanStatusDataLoss,
};

static DEPRECATED_MSG_ATTRIBUTE(
    "Use nameForMetaMapSentrySpanStatus() instead.") NSString *_Nonnull const MetaMapSentrySpanStatusNames[]
    = { @"undefined", @"ok", @"deadline_exceeded", @"unauthenticated", @"permission_denied",
          @"not_found", @"resource_exhausted", @"invalid_argument", @"unimplemented",
          @"unavailable", @"internal_error", @"unknown_error", @"cancelled", @"already_exists",
          @"failed_precondition", @"aborted", @"out_of_range", @"data_loss" };

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameUndefined;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameOk;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameDeadlineExceeded;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameUnauthenticated;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNamePermissionDenied;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameNotFound;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameResourceExhausted;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameInvalidArgument;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameUnimplemented;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameUnavailable;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameInternalError;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameUnknownError;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameCancelled;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameAlreadyExists;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameFailedPrecondition;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameAborted;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameOutOfRange;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySpanStatusNameDataLoss;

NSString *nameForMetaMapSentrySpanStatus(MetaMapSentrySpanStatus status);

NS_ASSUME_NONNULL_END
