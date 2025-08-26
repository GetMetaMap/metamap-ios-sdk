//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/imgcodecs.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>


@class IntVector;
@class Mat;
@class Scalar;



NS_ASSUME_NONNULL_BEGIN

// C++: class Animation
/**
 * Represents an animation with multiple frames.
 * The `Animation` struct is designed to store and manage data for animated sequences such as those from animated formats (e.g., GIF, AVIF, APNG, WebP).
 * It provides support for looping, background color settings, frame timing, and frame storage.
 *
 * Member of `Imgcodecs`
 */
CV_EXPORTS @interface Animation : NSObject


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::Animation> nativePtr;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::Animation>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::Animation>)nativePtr;
#endif


#pragma mark - Methods


//
//   cv::Animation::Animation(int loopCount = 0, Scalar bgColor = Scalar())
//
/**
 * Constructs an Animation object with optional loop count and background color.
 *
 * @param loopCount An integer representing the number of times the animation should loop:
 *     - `0` (default) indicates infinite looping, meaning the animation will replay continuously.
 *     - Positive values denote finite repeat counts, allowing the animation to play a limited number of times.
 *     - If a negative value or a value beyond the maximum of `0xffff` (65535) is provided, it is reset to `0`
 *     (infinite looping) to maintain valid bounds.
 *
 * @param bgColor A `Scalar` object representing the background color in BGR format:
 *     - Defaults to `Scalar()`, indicating an empty color (usually transparent if supported).
 *     - This background color provides a solid fill behind frames that have transparency, ensuring a consistent display appearance.
 */
- (instancetype)initWithLoopCount:(int)loopCount bgColor:(Scalar*)bgColor;

/**
 * Constructs an Animation object with optional loop count and background color.
 *
 * @param loopCount An integer representing the number of times the animation should loop:
 *     - `0` (default) indicates infinite looping, meaning the animation will replay continuously.
 *     - Positive values denote finite repeat counts, allowing the animation to play a limited number of times.
 *     - If a negative value or a value beyond the maximum of `0xffff` (65535) is provided, it is reset to `0`
 *     (infinite looping) to maintain valid bounds.
 *
 *     - Defaults to `Scalar()`, indicating an empty color (usually transparent if supported).
 *     - This background color provides a solid fill behind frames that have transparency, ensuring a consistent display appearance.
 */
- (instancetype)initWithLoopCount:(int)loopCount;

/**
 * Constructs an Animation object with optional loop count and background color.
 *
 *     - `0` (default) indicates infinite looping, meaning the animation will replay continuously.
 *     - Positive values denote finite repeat counts, allowing the animation to play a limited number of times.
 *     - If a negative value or a value beyond the maximum of `0xffff` (65535) is provided, it is reset to `0`
 *     (infinite looping) to maintain valid bounds.
 *
 *     - Defaults to `Scalar()`, indicating an empty color (usually transparent if supported).
 *     - This background color provides a solid fill behind frames that have transparency, ensuring a consistent display appearance.
 */
- (instancetype)init;


    //
    // C++: int cv::Animation::loop_count
    //

@property int loop_count;

    //
    // C++: Scalar cv::Animation::bgcolor
    //

@property Scalar* bgcolor;

    //
    // C++: vector_int cv::Animation::durations
    //

@property IntVector* durations;

    //
    // C++: vector_Mat cv::Animation::frames
    //

@property Mat* frames;

    //
    // C++: Mat cv::Animation::still_image
    //

@property Mat* still_image;


@end

NS_ASSUME_NONNULL_END


