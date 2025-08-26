//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/objdetect.hpp"
#import "opencv2/objdetect/barcode.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>
#import "GraphicalCodeDetector.h"

@class FloatVector;
@class Mat;



NS_ASSUME_NONNULL_BEGIN

// C++: class BarcodeDetector
/**
 * The BarcodeDetector module
 *
 * Member of `Objdetect`
 */
CV_EXPORTS @interface BarcodeDetector : GraphicalCodeDetector


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::barcode::BarcodeDetector> nativePtrBarcodeDetector;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::barcode::BarcodeDetector>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::barcode::BarcodeDetector>)nativePtr;
#endif


#pragma mark - Methods


//
//   cv::barcode::BarcodeDetector::BarcodeDetector()
//
/**
 * Initialize the BarcodeDetector.
 */
- (instancetype)init;


//
//   cv::barcode::BarcodeDetector::BarcodeDetector(string prototxt_path, string model_path)
//
/**
 * Initialize the BarcodeDetector.
 *
 * Parameters allow to load _optional_ Super Resolution DNN model for better quality.
 * @param prototxt_path prototxt file path for the super resolution model
 * @param model_path model file path for the super resolution model
 */
- (instancetype)initWithPrototxt_path:(NSString*)prototxt_path model_path:(NSString*)model_path;


//
//  bool cv::barcode::BarcodeDetector::decodeWithType(Mat img, Mat points, vector_string& decoded_info, vector_string& decoded_type)
//
/**
 * Decodes barcode in image once it's found by the detect() method.
 *
 * @param img grayscale or color (BGR) image containing bar code.
 * @param points vector of rotated rectangle vertices found by detect() method (or some other algorithm).
 * For N detected barcodes, the dimensions of this array should be [N][4].
 * Order of four points in vector<Point2f> is bottomLeft, topLeft, topRight, bottomRight.
 * @param decoded_info UTF8-encoded output vector of string or empty vector of string if the codes cannot be decoded.
 * @param decoded_type vector strings, specifies the type of these barcodes
 * @return true if at least one valid barcode have been found
 */
- (BOOL)decodeWithType:(Mat*)img points:(Mat*)points decoded_info:(NSMutableArray<NSString*>*)decoded_info decoded_type:(NSMutableArray<NSString*>*)decoded_type NS_SWIFT_NAME(decodeWithType(img:points:decoded_info:decoded_type:));


//
//  bool cv::barcode::BarcodeDetector::detectAndDecodeWithType(Mat img, vector_string& decoded_info, vector_string& decoded_type, Mat& points = Mat())
//
/**
 * Both detects and decodes barcode
 *
 * @param img grayscale or color (BGR) image containing barcode.
 * @param decoded_info UTF8-encoded output vector of string(s) or empty vector of string if the codes cannot be decoded.
 * @param decoded_type vector of strings, specifies the type of these barcodes
 * @param points optional output vector of vertices of the found  barcode rectangle. Will be empty if not found.
 * @return true if at least one valid barcode have been found
 */
- (BOOL)detectAndDecodeWithType:(Mat*)img decoded_info:(NSMutableArray<NSString*>*)decoded_info decoded_type:(NSMutableArray<NSString*>*)decoded_type points:(Mat*)points NS_SWIFT_NAME(detectAndDecodeWithType(img:decoded_info:decoded_type:points:));

/**
 * Both detects and decodes barcode
 *
 * @param img grayscale or color (BGR) image containing barcode.
 * @param decoded_info UTF8-encoded output vector of string(s) or empty vector of string if the codes cannot be decoded.
 * @param decoded_type vector of strings, specifies the type of these barcodes
 * @return true if at least one valid barcode have been found
 */
- (BOOL)detectAndDecodeWithType:(Mat*)img decoded_info:(NSMutableArray<NSString*>*)decoded_info decoded_type:(NSMutableArray<NSString*>*)decoded_type NS_SWIFT_NAME(detectAndDecodeWithType(img:decoded_info:decoded_type:));


//
//  double cv::barcode::BarcodeDetector::getDownsamplingThreshold()
//
/**
 * Get detector downsampling threshold.
 *
 * @return detector downsampling threshold
 */
- (double)getDownsamplingThreshold NS_SWIFT_NAME(getDownsamplingThreshold());


//
//  BarcodeDetector cv::barcode::BarcodeDetector::setDownsamplingThreshold(double thresh)
//
/**
 * Set detector downsampling threshold.
 *
 * By default, the detect method resizes the input image to this limit if the smallest image size is is greater than the threshold.
 * Increasing this value can improve detection accuracy and the number of results at the expense of performance.
 * Correlates with detector scales. Setting this to a large value will disable downsampling.
 * @param thresh downsampling limit to apply (default 512)
 * @see `-setDetectorScales:`
 */
- (BarcodeDetector*)setDownsamplingThreshold:(double)thresh NS_SWIFT_NAME(setDownsamplingThreshold(thresh:));


//
//  void cv::barcode::BarcodeDetector::getDetectorScales(vector_float& sizes)
//
/**
 * Returns detector box filter sizes.
 *
 * @param sizes output parameter for returning the sizes.
 */
- (void)getDetectorScales:(FloatVector*)sizes NS_SWIFT_NAME(getDetectorScales(sizes:));


//
//  BarcodeDetector cv::barcode::BarcodeDetector::setDetectorScales(vector_float sizes)
//
/**
 * Set detector box filter sizes.
 *
 * Adjusts the value and the number of box filters used in the detect step.
 * The filter sizes directly correlate with the expected line widths for a barcode. Corresponds to expected barcode distance.
 * If the downsampling limit is increased, filter sizes need to be adjusted in an inversely proportional way.
 * @param sizes box filter sizes, relative to minimum dimension of the image (default [0.01, 0.03, 0.06, 0.08])
 */
- (BarcodeDetector*)setDetectorScales:(FloatVector*)sizes NS_SWIFT_NAME(setDetectorScales(sizes:));


//
//  double cv::barcode::BarcodeDetector::getGradientThreshold()
//
/**
 * Get detector gradient magnitude threshold.
 *
 * @return detector gradient magnitude threshold.
 */
- (double)getGradientThreshold NS_SWIFT_NAME(getGradientThreshold());


//
//  BarcodeDetector cv::barcode::BarcodeDetector::setGradientThreshold(double thresh)
//
/**
 * Set detector gradient magnitude threshold.
 *
 * Sets the coherence threshold for detected bounding boxes.
 * Increasing this value will generate a closer fitted bounding box width and can reduce false-positives.
 * Values between 16 and 1024 generally work, while too high of a value will remove valid detections.
 * @param thresh gradient magnitude threshold (default 64).
 */
- (BarcodeDetector*)setGradientThreshold:(double)thresh NS_SWIFT_NAME(setGradientThreshold(thresh:));



@end

NS_ASSUME_NONNULL_END


