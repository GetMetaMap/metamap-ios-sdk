#import <Foundation/Foundation.h>

/**
 * Trace sample decision flag.
 */
typedef NS_ENUM(NSUInteger, MetaMapSentrySampleDecision) {
    /**
     * Used when the decision to sample a trace should be postponed.
     */
    kMetaMapSentrySampleDecisionUndecided,

    /**
     * The trace should be sampled.
     */
    kMetaMapSentrySampleDecisionYes,

    /**
     * The trace should not be sampled.
     */
    kMetaMapSentrySampleDecisionNo
};

static DEPRECATED_MSG_ATTRIBUTE("Use nameForMetaMapSentrySampleDecision() instead.")
    NSString *_Nonnull const MetaMapSentrySampleDecisionNames[]
    = { @"undecided", @"true", @"false" };

NS_ASSUME_NONNULL_BEGIN

FOUNDATION_EXPORT NSString *const kMetaMapSentrySampleDecisionNameUndecided;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySampleDecisionNameYes;
FOUNDATION_EXPORT NSString *const kMetaMapSentrySampleDecisionNameNo;

NSString *nameForMetaMapSentrySampleDecision(MetaMapSentrySampleDecision decision);

NS_ASSUME_NONNULL_END
