#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class MetaMapSentryTransactionContext;

NS_SWIFT_NAME(SamplingContext)
@interface MetaMapSentrySamplingContext : NSObject

/**
 * Transaction context.
 */
@property (nonatomic, readonly) MetaMapSentryTransactionContext *transactionContext;

/**
 * Custom data used for sampling.
 */
@property (nullable, nonatomic, readonly) NSDictionary<NSString *, id> *customSamplingContext;

/**
 * Init a MetaMapSentryTransactionSamplingContext.
 * @param transactionContext The context of the transaction being sampled.
 */
- (instancetype)initWithTransactionContext:(MetaMapSentryTransactionContext *)transactionContext;

/**
 * Init a MetaMapSentryTransactionSamplingContext.
 * @param transactionContext The context of the transaction being sampled.
 * @param customSamplingContext Custom data used for sampling.
 */
- (instancetype)initWithTransactionContext:(MetaMapSentryTransactionContext *)transactionContext
                     customSamplingContext:(NSDictionary<NSString *, id> *)customSamplingContext;

@end

NS_ASSUME_NONNULL_END
