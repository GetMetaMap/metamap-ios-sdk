#import <Foundation/Foundation.h>

static NSString *const MetaMapSentryDebugImageType = @"macho";

/**
 * Abort if assertion fails in debug, and log a warning if it fails in production.
 * @return The result of the assertion condition, so it can be used to e.g. early return from the
 * point of it's check if that's also desirable in production.
 */
#define MetaMapSentry_ASSERT(cond, ...)                                                                   \
    ({                                                                                             \
        const auto __cond_result = (cond);                                                         \
        if (!__cond_result) {                                                                      \
            MetaMapSentry_LOG_WARN(__VA_ARGS__);                                                          \
            NSAssert(NO, __VA_ARGS__);                                                             \
        }                                                                                          \
        (__cond_result);                                                                           \
    })

/**
 * Abort if assertion fails in a C context in debug, and log a warning if it fails in production.
 * @return The result of the assertion condition, so it can be used to e.g. early return from the
 * point of it's check if that's also desirable in production.
 */
#define MetaMapSentry_CASSERT(cond, ...)                                                                  \
    ({                                                                                             \
        const auto __cond_result = (cond);                                                         \
        if (!__cond_result) {                                                                      \
            MetaMapSentry_LOG_WARN(__VA_ARGS__);                                                          \
            NSCAssert(NO, __VA_ARGS__);                                                            \
        }                                                                                          \
        (__cond_result);                                                                           \
    })

#define BLOCKED_MAIN_THREAD @"blocked_main_thread"
