// We need this because if MetaMapSentry library is added as a Framework
// the reference should be in the form of <module/header>.
// Otherwise, the reference is direct.
#if __has_include(<MetaMapSentry/MetaMapSentryDefines.h>)
#    import <MetaMapSentry/MetaMapSentryDefines.h>
#else
#    import "MetaMapSentryDefines.h"
#endif

#if __has_include(<MetaMapSentry/MetaMapSentryProfilingConditionals.h>)
#    import <MetaMapSentry/MetaMapSentryProfilingConditionals.h>
#else
#    import "MetaMapSentryProfilingConditionals.h"
#endif
