//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/videoio.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>






NS_ASSUME_NONNULL_BEGIN

// C++: class IStreamReader
/**
 * Read data stream interface
 *
 * Member of `Videoio`
 */
CV_EXPORTS @interface IStreamReader : NSObject


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::IStreamReader> nativePtr;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::IStreamReader>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::IStreamReader>)nativePtr;
#endif


#pragma mark - Methods


//
//  long long cv::IStreamReader::read(c_string buffer, long long size)
//
    // Return type 'long long' is not supported, skipping the function


//
//  long long cv::IStreamReader::seek(long long offset, int origin)
//
    // Return type 'long long' is not supported, skipping the function



@end

NS_ASSUME_NONNULL_END


