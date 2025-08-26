//
// This file is auto-generated. Please don't modify it!
//
#pragma once

#ifdef __cplusplus
//#import "opencv.hpp"
#import "opencv2/objdetect.hpp"
#import "opencv2/objdetect/aruco_dictionary.hpp"
#else
#define CV_EXPORTS
#endif

#import <Foundation/Foundation.h>


@class Mat;



NS_ASSUME_NONNULL_BEGIN

// C++: class Dictionary
/**
 * Dictionary is a set of unique ArUco markers of the same size
 *
 * `bytesList` storing as 2-dimensions Mat with 4-th channels (CV_8UC4 type was used) and contains the marker codewords where:
 * - bytesList.rows is the dictionary size
 * - each marker is encoded using `nbytes = ceil(markerSize*markerSize/8.)` bytes
 * - each row contains all 4 rotations of the marker, so its length is `4*nbytes`
 * - the byte order in the bytesList[i] row:
 * `//bytes without rotation/bytes with rotation 1/bytes with rotation 2/bytes with rotation 3//`
 * So `bytesList.ptr(i)[k*nbytes + j]` is the j-th byte of i-th marker, in its k-th rotation.
 * NOTE: Python bindings generate matrix with shape of bytesList `dictionary_size x nbytes x 4`,
 * but it should be indexed like C++ version. Python example for j-th byte of i-th marker, in its k-th rotation:
 * `aruco_dict.bytesList[id].ravel()[k*nbytes + j]`
 *
 * Member of `Objdetect`
 */
CV_EXPORTS @interface Dictionary : NSObject


#ifdef __cplusplus
@property(readonly)cv::Ptr<cv::aruco::Dictionary> nativePtr;
#endif

#ifdef __cplusplus
- (instancetype)initWithNativePtr:(cv::Ptr<cv::aruco::Dictionary>)nativePtr;
+ (instancetype)fromNative:(cv::Ptr<cv::aruco::Dictionary>)nativePtr;
#endif


#pragma mark - Methods


//
//   cv::aruco::Dictionary::Dictionary()
//
- (instancetype)init;


//
//   cv::aruco::Dictionary::Dictionary(Mat bytesList, int _markerSize, int maxcorr = 0)
//
/**
 * Basic ArUco dictionary constructor
 *
 * @param bytesList bits for all ArUco markers in dictionary see memory layout in the class description
 * @param _markerSize ArUco marker size in units
 * @param maxcorr maximum number of bits that can be corrected
 */
- (instancetype)initWithBytesList:(Mat*)bytesList _markerSize:(int)_markerSize maxcorr:(int)maxcorr;

/**
 * Basic ArUco dictionary constructor
 *
 * @param bytesList bits for all ArUco markers in dictionary see memory layout in the class description
 * @param _markerSize ArUco marker size in units
 */
- (instancetype)initWithBytesList:(Mat*)bytesList _markerSize:(int)_markerSize;


//
//  bool cv::aruco::Dictionary::readDictionary(FileNode fn)
//
// Unknown type 'FileNode' (I), skipping the function


//
//  void cv::aruco::Dictionary::writeDictionary(FileStorage fs, String name = String())
//
// Unknown type 'FileStorage' (I), skipping the function


//
//  bool cv::aruco::Dictionary::identify(Mat onlyBits, int& idx, int& rotation, double maxCorrectionRate)
//
/**
 * Given a matrix of bits. Returns whether if marker is identified or not.
 *
 * Returns reference to the marker id in the dictionary (if any) and its rotation.
 */
- (BOOL)identify:(Mat*)onlyBits idx:(int*)idx rotation:(int*)rotation maxCorrectionRate:(double)maxCorrectionRate NS_SWIFT_NAME(identify(onlyBits:idx:rotation:maxCorrectionRate:));


//
//  int cv::aruco::Dictionary::getDistanceToId(Mat bits, int id, bool allRotations = true)
//
/**
 * Returns Hamming distance of the input bits to the specific id.
 *
 * If `allRotations` flag is set, the four posible marker rotations are considered
 */
- (int)getDistanceToId:(Mat*)bits id:(int)id allRotations:(BOOL)allRotations NS_SWIFT_NAME(getDistanceToId(bits:id:allRotations:));

/**
 * Returns Hamming distance of the input bits to the specific id.
 *
 * If `allRotations` flag is set, the four posible marker rotations are considered
 */
- (int)getDistanceToId:(Mat*)bits id:(int)id NS_SWIFT_NAME(getDistanceToId(bits:id:));


//
//  void cv::aruco::Dictionary::generateImageMarker(int id, int sidePixels, Mat& _img, int borderBits = 1)
//
/**
 * Generate a canonical marker image
 */
- (void)generateImageMarker:(int)id sidePixels:(int)sidePixels _img:(Mat*)_img borderBits:(int)borderBits NS_SWIFT_NAME(generateImageMarker(id:sidePixels:_img:borderBits:));

/**
 * Generate a canonical marker image
 */
- (void)generateImageMarker:(int)id sidePixels:(int)sidePixels _img:(Mat*)_img NS_SWIFT_NAME(generateImageMarker(id:sidePixels:_img:));


//
// static Mat cv::aruco::Dictionary::getByteListFromBits(Mat bits)
//
/**
 * Transform matrix of bits to list of bytes with 4 marker rotations
 */
+ (Mat*)getByteListFromBits:(Mat*)bits NS_SWIFT_NAME(getByteListFromBits(bits:));


//
// static Mat cv::aruco::Dictionary::getBitsFromByteList(Mat byteList, int markerSize)
//
/**
 * Transform list of bytes to matrix of bits
 */
+ (Mat*)getBitsFromByteList:(Mat*)byteList markerSize:(int)markerSize NS_SWIFT_NAME(getBitsFromByteList(byteList:markerSize:));


    //
    // C++: Mat cv::aruco::Dictionary::bytesList
    //

@property Mat* bytesList;

    //
    // C++: int cv::aruco::Dictionary::markerSize
    //

@property int markerSize;

    //
    // C++: int cv::aruco::Dictionary::maxCorrectionBits
    //

@property int maxCorrectionBits;


@end

NS_ASSUME_NONNULL_END


