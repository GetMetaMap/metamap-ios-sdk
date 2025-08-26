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


@class Scalar;



NS_ASSUME_NONNULL_BEGIN

// C++: class Params
/**
 * The Params module
 *
 * Member of `Video`
 */
CV_EXPORTS @interface TrackerVitParams : NSObject


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::TrackerVit::Params> nativePtr;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::TrackerVit::Params>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::TrackerVit::Params>)nativePtr;
#endif


#pragma mark - Methods


//
//   cv::TrackerVit::Params::Params()
//
- (instancetype)init;


    //
    // C++: string cv::TrackerVit::Params::net
    //

@property NSString* net;

    //
    // C++: int cv::TrackerVit::Params::backend
    //

@property int backend;

    //
    // C++: int cv::TrackerVit::Params::target
    //

@property int target;

    //
    // C++: Scalar cv::TrackerVit::Params::meanvalue
    //

@property Scalar* meanvalue;

    //
    // C++: Scalar cv::TrackerVit::Params::stdvalue
    //

@property Scalar* stdvalue;

    //
    // C++: float cv::TrackerVit::Params::tracking_score_threshold
    //

@property float tracking_score_threshold;


@end

NS_ASSUME_NONNULL_END


