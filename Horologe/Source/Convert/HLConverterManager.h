/*
 * ConverterManager.h
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


@class HLConverterSet;
@class HLInstantConverter;
@class HLPartialConverter;
@class HLDurationConverter;
@class HLIntervalConverter;
@class HLPeriodConverter;

/**
 * ConverterManager controls the date and time converters.
 * <p>
 * This class enables additional conversion classes to be added via
 * {@link #addInstantConverter(InstantConverter)}, which may replace an
 * existing converter. Similar methods exist for duration, time period and
 * interval converters.
 * <p>
 * This class is threadsafe, so adding/removing converters can be done at any
 * time. Updating the set of convertors is relatively expensive, and so should
 * not be performed often.
 * <p>
 * The default instant converters are:
 * <ul>
 * <li>ReadableInstant
 * <li>String
 * <li>Calendar
 * <li>Date (includes sql package subclasses)
 * <li>Long (milliseconds)
 * <li>nil (now)
 * </ul>
 * 
 * The default partial converters are:
 * <ul>
 * <li>ReadablePartial
 * <li>ReadableInstant
 * <li>String
 * <li>Calendar
 * <li>Date (includes sql package subclasses)
 * <li>Long (milliseconds)
 * <li>nil (now)
 * </ul>
 * 
 * The default duration converters are:
 * <ul>
 * <li>ReadableDuration
 * <li>ReadableInterval
 * <li>String
 * <li>Long (milliseconds)
 * <li>nil (zero ms)
 * </ul>
 *
 * The default time period converters are:
 * <ul>
 * <li>ReadablePeriod
 * <li>ReadableInterval
 * <li>String
 * <li>nil (zero)
 * </ul>
 * 
 * The default interval converters are:
 * <ul>
 * <li>ReadableInterval
 * <li>String
 * <li>nil (zero-length from now to now)
 * </ul>
 *
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.0
 */
@interface HLConverterManager : NSObject {
    
@private
    HLConverterSet* _iInstantConverters;
    HLConverterSet* _iPartialConverters;
    HLConverterSet* _iDurationConverters;
    HLConverterSet* _iPeriodConverters;
    HLConverterSet* _iIntervalConverters;
    
}

+ (HLConverterManager*)instance;

/**
 * Restricted constructor.
 */
- (id)_init;

//-----------------------------------------------------------------------
/**
 * Gets the best converter for the object specified.
 * 
 * @param object  the object to convert
 * @return the converter to use
 * @throws IllegalArgumentException if no suitable converter
 * @throws IllegalStateException if multiple converters match the type
 * equally well
 */
- (HLInstantConverter*)instantConverter:(id)object;

//-----------------------------------------------------------------------
/**
 * Gets a copy of the set of converters.
 * 
 * @return the converters, a copy of the real data, never nil
 */
- (NSArray*)instantConverters;

/**
 * Adds a converter to the set of converters. If a matching converter is
 * already in the set, the given converter replaces it. If the converter is
 * exactly the same as one already in the set, no changes are made.
 * <p>
 * The order in which converters are added is not relevent. The best
 * converter is selected by examining the object hierarchy.
 * 
 * @param converter  the converter to add, nil ignored
 * @return replaced converter, or nil
 */
- (HLInstantConverter*)addInstantConverter:(HLInstantConverter*)converter;

/**
 * Removes a converter from the set of converters. If the converter was
 * not in the set, no changes are made.
 * 
 * @param converter  the converter to remove, nil ignored
 * @return replaced converter, or nil
 */
- (HLInstantConverter*)removeInstantConverter:(HLInstantConverter*)converter;

/**
 * Checks whether the user has permission 'ConverterManager.alterInstantConverters'.
 * 
 * @throws SecurityException if the user does not have the permission
 */
- (void)_checkAlterInstantConverters;

//-----------------------------------------------------------------------
/**
 * Gets the best converter for the object specified.
 * 
 * @param object  the object to convert
 * @return the converter to use
 * @throws IllegalArgumentException if no suitable converter
 * @throws IllegalStateException if multiple converters match the type
 * equally well
 */
- (HLPartialConverter*)partialConverter:(id)object;

//-----------------------------------------------------------------------
/**
 * Gets a copy of the set of converters.
 * 
 * @return the converters, a copy of the real data, never nil
 */
- (NSArray*)partialConverters;

/**
 * Adds a converter to the set of converters. If a matching converter is
 * already in the set, the given converter replaces it. If the converter is
 * exactly the same as one already in the set, no changes are made.
 * <p>
 * The order in which converters are added is not relevent. The best
 * converter is selected by examining the object hierarchy.
 * 
 * @param converter  the converter to add, nil ignored
 * @return replaced converter, or nil
 */
- (HLPartialConverter*)addPartialConverter:(HLPartialConverter*)converter;

/**
 * Removes a converter from the set of converters. If the converter was
 * not in the set, no changes are made.
 * 
 * @param converter  the converter to remove, nil ignored
 * @return replaced converter, or nil
 */
- (HLPartialConverter*)removePartialConverter:(HLPartialConverter*)converter;

/**
 * Checks whether the user has permission 'ConverterManager.alterPartialConverters'.
 * 
 * @throws SecurityException if the user does not have the permission
 */
- (void)_checkAlterPartialConverters;

//-----------------------------------------------------------------------
/**
 * Gets the best converter for the object specified.
 * 
 * @param object  the object to convert
 * @return the converter to use
 * @throws IllegalArgumentException if no suitable converter
 * @throws IllegalStateException if multiple converters match the type
 * equally well
 */
- (HLDurationConverter*)durationConverter:(id)object;

//-----------------------------------------------------------------------
/**
 * Gets a copy of the list of converters.
 * 
 * @return the converters, a copy of the real data, never nil
 */
- (NSArray*)durationConverters;

/**
 * Adds a converter to the set of converters. If a matching converter is
 * already in the set, the given converter replaces it. If the converter is
 * exactly the same as one already in the set, no changes are made.
 * <p>
 * The order in which converters are added is not relevent. The best
 * converter is selected by examining the object hierarchy.
 * 
 * @param converter  the converter to add, nil ignored
 * @return replaced converter, or nil
 */
- (HLDurationConverter*)addDurationConverter:(HLDurationConverter*)converter;

/**
 * Removes a converter from the set of converters. If the converter was
 * not in the set, no changes are made.
 * 
 * @param converter  the converter to remove, nil ignored
 * @return replaced converter, or nil
 */
- (HLDurationConverter*)removeDurationConverter:(HLDurationConverter*)converter;

/**
 * Checks whether the user has permission 'ConverterManager.alterDurationConverters'.
 * 
 * @throws SecurityException if the user does not have the permission
 */
- (void)_checkAlterDurationConverters;

//-----------------------------------------------------------------------
/**
 * Gets the best converter for the object specified.
 * 
 * @param object  the object to convert
 * @return the converter to use
 * @throws IllegalArgumentException if no suitable converter
 * @throws IllegalStateException if multiple converters match the type
 * equally well
 */
- (HLPeriodConverter*)periodConverter:(id)object;

//-----------------------------------------------------------------------
/**
 * Gets a copy of the list of converters.
 * 
 * @return the converters, a copy of the real data, never nil
 */
- (NSArray*)periodConverters;

/**
 * Adds a converter to the set of converters. If a matching converter is
 * already in the set, the given converter replaces it. If the converter is
 * exactly the same as one already in the set, no changes are made.
 * <p>
 * The order in which converters are added is not relevent. The best
 * converter is selected by examining the object hierarchy.
 * 
 * @param converter  the converter to add, nil ignored
 * @return replaced converter, or nil
 */
- (HLPeriodConverter*)addPeriodConverter:(HLPeriodConverter*)converter;

/**
 * Removes a converter from the set of converters. If the converter was
 * not in the set, no changes are made.
 * 
 * @param converter  the converter to remove, nil ignored
 * @return replaced converter, or nil
 */
- (HLPeriodConverter*)removePeriodConverter:(HLPeriodConverter*)converter;

/**
 * Checks whether the user has permission 'ConverterManager.alterPeriodConverters'.
 * 
 * @throws SecurityException if the user does not have the permission
 */
- (void)_checkAlterPeriodConverters;

//-----------------------------------------------------------------------
/**
 * Gets the best converter for the object specified.
 * 
 * @param object  the object to convert
 * @return the converter to use
 * @throws IllegalArgumentException if no suitable converter
 * @throws IllegalStateException if multiple converters match the type
 * equally well
 */
- (HLIntervalConverter*)intervalConverter:(id)object;

//-----------------------------------------------------------------------
/**
 * Gets a copy of the list of converters.
 * 
 * @return the converters, a copy of the real data, never nil
 */
- (NSArray*)intervalConverters;

/**
 * Adds a converter to the set of converters. If a matching converter is
 * already in the set, the given converter replaces it. If the converter is
 * exactly the same as one already in the set, no changes are made.
 * <p>
 * The order in which converters are added is not relevent. The best
 * converter is selected by examining the object hierarchy.
 * 
 * @param converter  the converter to add, nil ignored
 * @return replaced converter, or nil
 */
- (HLIntervalConverter*)addIntervalConverter:(HLIntervalConverter*)converter;

/**
 * Removes a converter from the set of converters. If the converter was
 * not in the set, no changes are made.
 * 
 * @param converter  the converter to remove, nil ignored
 * @return replaced converter, or nil
 */
- (HLIntervalConverter*)removeIntervalConverter:(HLIntervalConverter*)converter;

/**
 * Checks whether the user has permission 'ConverterManager.alterIntervalConverters'.
 * 
 * @throws SecurityException if the user does not have the permission
 */
- (void)_checkAlterIntervalConverters;

//-----------------------------------------------------------------------
/**
 * Gets a debug representation of the object.
 */
- (NSString*)description;

@end
