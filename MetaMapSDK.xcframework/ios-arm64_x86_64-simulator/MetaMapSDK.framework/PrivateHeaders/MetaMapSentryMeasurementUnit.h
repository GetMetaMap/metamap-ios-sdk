#import "MetaMapSentryDefines.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * The unit of measurement of a metric value.
 * @discussion Units augment metric values by giving them a magnitude and semantics. There are
 * certain types of units that are subdivided in their precision, such as the
 * @c MetaMapSentryMeasurementUnitDuration for time measurements. The following unit types are available:
 * @c MetaMapSentryMeasurementUnitDuration ,
 * @c MetaMapSentryMeasurementUnitInformation ,  and @c MetaMapSentryMeasurementUnitFraction .
 * @note When using the units to custom measurements, MetaMapSentry will apply formatting to display
 * measurement values in the UI.
 */
NS_SWIFT_NAME(MeasurementUnit)
@interface MetaMapSentryMeasurementUnit : NSObject <NSCopying>
MetaMapSentry_NO_INIT

/**
 * Returns an initialized MetaMapSentryMeasurementUnit with a custom measurement unit.
 * @param unit Your own custom unit without built-in conversion in MetaMapSentry.
 */
- (instancetype)initWithUnit:(NSString *)unit;

/**
 * The @c NSString representation of the measurement unit.
 */
@property (readonly, copy) NSString *unit;

/**
 * Untyped value without a unit.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnit *none;

@end

/**
 * Time duration units.
 */
NS_SWIFT_NAME(MeasurementUnitDuration)
@interface MetaMapSentryMeasurementUnitDuration : MetaMapSentryMeasurementUnit
MetaMapSentry_NO_INIT

/**
 * Nanosecond, 10^-9 seconds.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitDuration *nanosecond;

/**
 * Microsecond , 10^-6 seconds.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitDuration *microsecond;

/**
 * Millisecond, 10^-3 seconds.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitDuration *millisecond;

/**
 * Full second.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitDuration *second;

/**
 * Minute, 60 seconds.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitDuration *minute;

/**
 * Hour, 3600 seconds.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitDuration *hour;

/**
 * Day, 86,400 seconds.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitDuration *day;

/**
 * Week, 604,800 seconds.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitDuration *week;

@end

/**
 * Size of information units derived from bytes.
 * @see https://en.wikipedia.org/wiki/Units_of_information
 */
NS_SWIFT_NAME(MeasurementUnitInformation)
@interface MetaMapSentryMeasurementUnitInformation : MetaMapSentryMeasurementUnit
MetaMapSentry_NO_INIT

/**
 * Bit, corresponding to 1/8 of a byte
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *bit;

/**
 * Byte.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *byte;

/**
 * Kilobyte, 10^3 bytes
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *kilobyte;

/**
 * Kibibyte, 2^10 bytes.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *kibibyte;

/**
 * Megabyte, 10^6 bytes
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *megabyte;

/**
 * Mebibyte, 2^20 bytes.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *mebibyte;

/**
 * Gigabyte, 10^9 bytes
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *gigabyte;

/**
 * Gibibyte, 2^30 bytes.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *gibibyte;

/**
 * Terabyte, 10^12 bytes
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *terabyte;

/**
 * Tebibyte, 2^40 bytes.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *tebibyte;

/**
 * Petabyte, 10^15 bytes
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *petabyte;

/**
 * Pebibyte, 2^50 bytes.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *pebibyte;

/**
 * Exabyte, 10^18 bytes
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *exabyte;

/**
 * Exbibyte, 2^60 bytes.
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitInformation *exbibyte;

@end

/**
 * Units of fraction.
 */
NS_SWIFT_NAME(MeasurementUnitFraction) @interface MetaMapSentryMeasurementUnitFraction
    : MetaMapSentryMeasurementUnit
MetaMapSentry_NO_INIT

/**
 * Floating point fraction of @c 1 . g
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitFraction *ratio;

/**
 * Ratio expressed as a fraction of @c 100  @c 100% equals a ratio of @c 1.0
 */
@property (class, readonly, copy) MetaMapSentryMeasurementUnitFraction *percent;

@end

NS_ASSUME_NONNULL_END
