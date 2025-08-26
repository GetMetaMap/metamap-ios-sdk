//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/video.hpp"
#import "opencv2/video/tracking.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>
#import "Tracker.h"

@class TrackerDaSiamRPNParams;



NS_ASSUME_NONNULL_BEGIN

// C++: class TrackerDaSiamRPN
/**
 * The TrackerDaSiamRPN module
 *
 * Member of `Video`
 */
CV_EXPORTS @interface TrackerDaSiamRPN : Tracker


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::TrackerDaSiamRPN> nativePtrTrackerDaSiamRPN;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::TrackerDaSiamRPN>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::TrackerDaSiamRPN>)nativePtr;
#endif


#pragma mark - Methods


//
// static Ptr_TrackerDaSiamRPN cv::TrackerDaSiamRPN::create(TrackerDaSiamRPN_Params parameters = TrackerDaSiamRPN::Params())
//
/**
 * Constructor
 * @param parameters DaSiamRPN parameters TrackerDaSiamRPN::Params
 */
+ (TrackerDaSiamRPN*)create:(TrackerDaSiamRPNParams*)parameters NS_SWIFT_NAME(create(parameters:));

/**
 * Constructor
 */
+ (TrackerDaSiamRPN*)create NS_SWIFT_NAME(create());


//
// static Ptr_TrackerDaSiamRPN cv::TrackerDaSiamRPN::create(dnn_Net siam_rpn, dnn_Net kernel_cls1, dnn_Net kernel_r1)
//
// Unknown type 'dnn_Net' (I), skipping the function


//
//  float cv::TrackerDaSiamRPN::getTrackingScore()
//
/**
 * Return tracking score
 */
- (float)getTrackingScore NS_SWIFT_NAME(getTrackingScore());



@end

NS_ASSUME_NONNULL_END


