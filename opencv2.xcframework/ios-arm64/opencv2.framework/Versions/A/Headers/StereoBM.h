//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/calib3d.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>
#import "StereoMatcher.h"

@class Rect2i;



NS_ASSUME_NONNULL_BEGIN

// C++: class StereoBM
/**
 * Class for computing stereo correspondence using the block matching algorithm, introduced and contributed to OpenCV by K. Konolige.
 * This class implements a block matching algorithm for stereo correspondence, which is used to compute disparity maps from stereo image pairs. It provides methods to fine-tune parameters such as pre-filtering, texture thresholds, uniqueness ratios, and regions of interest (ROIs) to optimize performance and accuracy.
 *
 * Member of `Calib3d`
 */
CV_EXPORTS @interface StereoBM : StereoMatcher


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::StereoBM> nativePtrStereoBM;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::StereoBM>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::StereoBM>)nativePtr;
#endif


#pragma mark - Class Constants


@property (class, readonly) int PREFILTER_NORMALIZED_RESPONSE NS_SWIFT_NAME(PREFILTER_NORMALIZED_RESPONSE);
@property (class, readonly) int PREFILTER_XSOBEL NS_SWIFT_NAME(PREFILTER_XSOBEL);

#pragma mark - Methods


//
//  int cv::StereoBM::getPreFilterType()
//
/**
 * Gets the type of pre-filtering currently used in the algorithm.
 * @return The current pre-filter type: 0 for PREFILTER_NORMALIZED_RESPONSE or 1 for PREFILTER_XSOBEL.
 */
- (int)getPreFilterType NS_SWIFT_NAME(getPreFilterType());


//
//  void cv::StereoBM::setPreFilterType(int preFilterType)
//
/**
 * Sets the type of pre-filtering used in the algorithm.
 * @param preFilterType The type of pre-filter to use. Possible values are:
 * - PREFILTER_NORMALIZED_RESPONSE (0): Uses normalized response for pre-filtering.
 * - PREFILTER_XSOBEL (1): Uses the X-Sobel operator for pre-filtering.
 * The pre-filter type affects how the images are prepared before computing the disparity map. Different pre-filtering methods can enhance specific image features or reduce noise, influencing the quality of the disparity map.
 */
- (void)setPreFilterType:(int)preFilterType NS_SWIFT_NAME(setPreFilterType(preFilterType:));


//
//  int cv::StereoBM::getPreFilterSize()
//
/**
 * Gets the current size of the pre-filter kernel.
 * @return The current pre-filter size.
 */
- (int)getPreFilterSize NS_SWIFT_NAME(getPreFilterSize());


//
//  void cv::StereoBM::setPreFilterSize(int preFilterSize)
//
/**
 * Sets the size of the pre-filter kernel.
 * @param preFilterSize The size of the pre-filter kernel. Must be an odd integer, typically between 5 and 255.
 * The pre-filter size determines the spatial extent of the pre-filtering operation, which prepares the images for disparity computation by normalizing brightness and enhancing texture. Larger sizes reduce noise but may blur details, while smaller sizes preserve details but are more susceptible to noise.
 */
- (void)setPreFilterSize:(int)preFilterSize NS_SWIFT_NAME(setPreFilterSize(preFilterSize:));


//
//  int cv::StereoBM::getPreFilterCap()
//
/**
 * Gets the current truncation value for prefiltered pixels.
 * @return The current pre-filter cap value.
 */
- (int)getPreFilterCap NS_SWIFT_NAME(getPreFilterCap());


//
//  void cv::StereoBM::setPreFilterCap(int preFilterCap)
//
/**
 * Sets the truncation value for prefiltered pixels.
 * @param preFilterCap The truncation value. Typically in the range [1, 63].
 * This value caps the output of the pre-filter to [-preFilterCap, preFilterCap], helping to reduce the impact of noise and outliers in the pre-filtered image.
 */
- (void)setPreFilterCap:(int)preFilterCap NS_SWIFT_NAME(setPreFilterCap(preFilterCap:));


//
//  int cv::StereoBM::getTextureThreshold()
//
/**
 * Gets the current texture threshold value.
 * @return The current texture threshold.
 */
- (int)getTextureThreshold NS_SWIFT_NAME(getTextureThreshold());


//
//  void cv::StereoBM::setTextureThreshold(int textureThreshold)
//
/**
 * Sets the threshold for filtering low-texture regions.
 * @param textureThreshold The threshold value. Must be non-negative.
 * This parameter filters out regions with low texture, where establishing correspondences is difficult, thus reducing noise in the disparity map. Higher values filter more aggressively but may discard valid information.
 */
- (void)setTextureThreshold:(int)textureThreshold NS_SWIFT_NAME(setTextureThreshold(textureThreshold:));


//
//  int cv::StereoBM::getUniquenessRatio()
//
/**
 * Gets the current uniqueness ratio value.
 * @return The current uniqueness ratio.
 */
- (int)getUniquenessRatio NS_SWIFT_NAME(getUniquenessRatio());


//
//  void cv::StereoBM::setUniquenessRatio(int uniquenessRatio)
//
/**
 * Sets the uniqueness ratio for filtering ambiguous matches.
 * @param uniquenessRatio The uniqueness ratio value. Typically in the range [5, 15], but can be from 0 to 100.
 * This parameter ensures that the best match is sufficiently better than the next best match, reducing false positives. Higher values are stricter but may filter out valid matches in difficult regions.
 */
- (void)setUniquenessRatio:(int)uniquenessRatio NS_SWIFT_NAME(setUniquenessRatio(uniquenessRatio:));


//
//  int cv::StereoBM::getSmallerBlockSize()
//
/**
 * Gets the current size of the smaller block used for texture check.
 * @return The current smaller block size.
 */
- (int)getSmallerBlockSize NS_SWIFT_NAME(getSmallerBlockSize());


//
//  void cv::StereoBM::setSmallerBlockSize(int blockSize)
//
/**
 * Sets the size of the smaller block used for texture check.
 * @param blockSize The size of the smaller block. Must be an odd integer between 5 and 255.
 * This parameter determines the size of the block used to compute texture variance. Smaller blocks capture finer details but are more sensitive to noise, while larger blocks are more robust but may miss fine details.
 */
- (void)setSmallerBlockSize:(int)blockSize NS_SWIFT_NAME(setSmallerBlockSize(blockSize:));


//
//  Rect cv::StereoBM::getROI1()
//
/**
 * Gets the current Region of Interest (ROI) for the left image.
 * @return The current ROI for the left image.
 */
- (Rect2i*)getROI1 NS_SWIFT_NAME(getROI1());


//
//  void cv::StereoBM::setROI1(Rect roi1)
//
/**
 * Sets the Region of Interest (ROI) for the left image.
 * @param roi1 The ROI rectangle for the left image.
 * By setting the ROI, the stereo matching computation is limited to the specified region, improving performance and potentially accuracy by focusing on relevant parts of the image.
 */
- (void)setROI1:(Rect2i*)roi1 NS_SWIFT_NAME(setROI1(roi1:));


//
//  Rect cv::StereoBM::getROI2()
//
/**
 * Gets the current Region of Interest (ROI) for the right image.
 * @return The current ROI for the right image.
 */
- (Rect2i*)getROI2 NS_SWIFT_NAME(getROI2());


//
//  void cv::StereoBM::setROI2(Rect roi2)
//
/**
 * Sets the Region of Interest (ROI) for the right image.
 * @param roi2 The ROI rectangle for the right image.
 * Similar to setROI1, this limits the computation to the specified region in the right image.
 */
- (void)setROI2:(Rect2i*)roi2 NS_SWIFT_NAME(setROI2(roi2:));


//
// static Ptr_StereoBM cv::StereoBM::create(int numDisparities = 0, int blockSize = 21)
//
/**
 * Creates StereoBM object
 * @param numDisparities The disparity search range. For each pixel, the algorithm will find the best disparity from 0 (default minimum disparity) to numDisparities. The search range can be shifted by changing the minimum disparity.
 * @param blockSize The linear size of the blocks compared by the algorithm. The size should be odd (as the block is centered at the current pixel). Larger block size implies smoother, though less accurate disparity map. Smaller block size gives more detailed disparity map, but there is a higher chance for the algorithm to find a wrong correspondence.
 * @return A pointer to the created StereoBM object.
 * The function creates a StereoBM object. You can then call StereoBM::compute() to compute disparity for a specific stereo pair.
 */
+ (StereoBM*)create:(int)numDisparities blockSize:(int)blockSize NS_SWIFT_NAME(create(numDisparities:blockSize:));

/**
 * Creates StereoBM object
 * @param numDisparities The disparity search range. For each pixel, the algorithm will find the best disparity from 0 (default minimum disparity) to numDisparities. The search range can be shifted by changing the minimum disparity.
 * @return A pointer to the created StereoBM object.
 * The function creates a StereoBM object. You can then call StereoBM::compute() to compute disparity for a specific stereo pair.
 */
+ (StereoBM*)create:(int)numDisparities NS_SWIFT_NAME(create(numDisparities:));

/**
 * Creates StereoBM object
 * @return A pointer to the created StereoBM object.
 * The function creates a StereoBM object. You can then call StereoBM::compute() to compute disparity for a specific stereo pair.
 */
+ (StereoBM*)create NS_SWIFT_NAME(create());



@end

NS_ASSUME_NONNULL_END


