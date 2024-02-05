#ifndef MetaMapSentryProfilingConditionals_h
#define MetaMapSentryProfilingConditionals_h

#include <TargetConditionals.h>

// tvOS and watchOS do not support the kernel APIs required by our profiler
// e.g. mach_msg, thread_suspend, thread_resume
#if TARGET_OS_WATCH || TARGET_OS_TV
#    define MetaMapSentry_TARGET_PROFILING_SUPPORTED 0
#else
#    define MetaMapSentry_TARGET_PROFILING_SUPPORTED 1
#endif

#endif /* MetaMapSentryProfilingConditionals_h */
