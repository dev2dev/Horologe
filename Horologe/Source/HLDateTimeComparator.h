/*
 * DateTimeComparator.h
 * 
 * Horologe
 * Copyright (c) 2011 Pilgrimage Software
 *
 * A Cocoa version of the Joda-Time Java date/time library.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#import <Foundation/Foundation.h>


@class HLDateTimeFieldType;

/**
 * DateTimeComparator provides comparators to compare one date with another.
 * <p>
 * Dates may be specified using any object recognised by the
 * {@link org.joda.time.convert.ConverterManager ConverterManager} class.
 * <p>
 * The default objects recognised by the comparator are:
 * <ul>
 * <li>ReadableInstant
 * <li>String
 * <li>Calendar
 * <li>Date
 * <li>Long (milliseconds)
 * <li>nil (now)
 * </ul>
 *
 * <p>
 * DateTimeComparator is thread-safe and immutable.
 *
 * @author Guy Allard
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLDateTimeComparator : NSObject {
    
@private
    /** The lower limit of fields to compare, nil if no limit */
    HLDateTimeFieldType* _iLowerLimit;
    /** The upper limit of fields to compare, nil if no limit */
    HLDateTimeFieldType* _iUpperLimit;
    
}

//-----------------------------------------------------------------------
/**
 * Returns a DateTimeComparator the compares the entire date time value.
 * 
 * @return a comparator over all fields
 */
+ (HLDateTimeComparator*)instance;

/**
 * Returns a DateTimeComparator with a lower limit only. Fields of a
 * magnitude less than the lower limit are excluded from comparisons.
 *
 * @param lowerLimit  inclusive lower limit for fields to be compared, nil means no limit
 * @return a comparator over all fields above the lower limit
 */
+ (HLDateTimeComparator*)instanceWithLowerLimit:(HLDateTimeFieldType*)lowerLimit;

/**
 * Returns a DateTimeComparator with a lower and upper limit. Fields of a
 * magnitude less than the lower limit are excluded from comparisons.
 * Fields of a magnitude greater than or equal to the upper limit are also
 * excluded from comparisons. Either limit may be specified as nil, which
 * indicates an unbounded limit.
 *
 * @param lowerLimit  inclusive lower limit for fields to be compared, nil means no limit
 * @param upperLimit  exclusive upper limit for fields to be compared, nil means no limit
 * @return a comparator over all fields between the limits
 */
+ (HLDateTimeComparator*)instanceWithLowerLimit:(HLDateTimeFieldType*)lowerLimit
                                     upperLimit:(HLDateTimeFieldType*)upperLimit;

/**
 * Returns a comparator that only considers date fields.
 * Time of day is ignored.
 * 
 * @return a comparator over all date fields
 */
+ (HLDateTimeComparator*)dateOnlyInstance;

/**
 * Returns a comparator that only considers time fields.
 * Date is ignored.
 * 
 * @return a comparator over all time fields
 */
+ (HLDateTimeComparator*)timeOnlyInstance;

/**
 * Restricted constructor.
 * 
 * @param lowerLimit  the lower field limit, nil means no limit
 * @param upperLimit  the upper field limit, nil means no limit
 */
- (Id)initWithLowerLimit:(HLDateTimeFieldType*)lowerLimit
              upperLimit:(HLDateTimeFieldType*)upperLimit;

//-----------------------------------------------------------------------
/**
 * Gets the field type that represents the lower limit of comparison.
 * 
 * @return the field type, nil if no upper limit
 */
- (HLDateTimeFieldType*)lowerLimit;

/**
 * Gets the field type that represents the upper limit of comparison.
 * 
 * @return the field type, nil if no upper limit
 */
- (HLDateTimeFieldType*)upperLimit;

/**
 * Compare two objects against only the range of date time fields as
 * specified in the constructor.
 * 
 * @param lhsObj  the first object,
 *      logically on the left of a &lt; comparison, nil means now
 * @param rhsObj  the second object,
 *      logically on the right of a &lt; comparison, nil means now
 * @return zero if order does not matter,
 *      negative value if lhsObj &lt; rhsObj, positive value otherwise.
 * @throws IllegalArgumentException if either argument is not supported
 */
- (NSComparisonResult)compareLeftSide:(id)lhsObj
                          toRightSide:(id)rhsObj;

//-----------------------------------------------------------------------
/**
 * Compares this comparator to another.
 * 
 * @param object  the object to compare to
 * @return true if equal
 */
- (BOOL)isEqualTo:(id)object;

/**
 * Gets a suitable hashcode.
 * 
 * @return the hashcode
 */
- (NSInteger)hash;

@end
