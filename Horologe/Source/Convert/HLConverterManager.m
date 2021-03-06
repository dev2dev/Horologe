/*
 * ConverterManager.m
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

#import "HLConverterManager.h"


@implementation HLConverterManager

/*
 *  Copyright 2001-2005 Stephen Colebourne
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */
package org.joda.time.convert;

import org.joda.time.JodaTimePermission;

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
public final class ConverterManager {

    /**
     * Singleton instance, lazily loaded to avoid class loading.
     */
    private static ConverterManager INSTANCE;

    public static ConverterManager getInstance {
        if (INSTANCE == nil) {
            INSTANCE = new ConverterManager();
        }
        return INSTANCE;
    }
    
    private ConverterSet iInstantConverters;
    private ConverterSet iPartialConverters;
    private ConverterSet iDurationConverters;
    private ConverterSet iPeriodConverters;
    private ConverterSet iIntervalConverters;
    
    /**
     * Restricted constructor.
     */
    protected ConverterManager {
        super();

        iInstantConverters = new ConverterSet(new Converter[] {
            ReadableInstantConverter.INSTANCE,
            StringConverter.INSTANCE,
            CalendarConverter.INSTANCE,
            DateConverter.INSTANCE,
            LongConverter.INSTANCE,
            NullConverter.INSTANCE,
        });

        iPartialConverters = new ConverterSet(new Converter[] {
            ReadablePartialConverter.INSTANCE,
            ReadableInstantConverter.INSTANCE,
            StringConverter.INSTANCE,
            CalendarConverter.INSTANCE,
            DateConverter.INSTANCE,
            LongConverter.INSTANCE,
            NullConverter.INSTANCE,
        });

        iDurationConverters = new ConverterSet(new Converter[] {
            ReadableDurationConverter.INSTANCE,
            ReadableIntervalConverter.INSTANCE,
            StringConverter.INSTANCE,
            LongConverter.INSTANCE,
            NullConverter.INSTANCE,
        });

        iPeriodConverters = new ConverterSet(new Converter[] {
            ReadableDurationConverter.INSTANCE,
            ReadablePeriodConverter.INSTANCE,
            ReadableIntervalConverter.INSTANCE,
            StringConverter.INSTANCE,
            NullConverter.INSTANCE,
        });

        iIntervalConverters = new ConverterSet(new Converter[] {
            ReadableIntervalConverter.INSTANCE,
            StringConverter.INSTANCE,
            NullConverter.INSTANCE,
        });
    }

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
    - (HLInstantConverter*)getInstantConverter:(id)object) {
        InstantConverter converter =
            (InstantConverter)iInstantConverters.select(object == nil ? nil : object.getClass());
        if (converter != nil) {
            return converter;
        }
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@"No instant converter found for type: " +
            (object == nil ? "nil" : object.getClass().getName()));
    }
    
    //-----------------------------------------------------------------------
    /**
     * Gets a copy of the set of converters.
     * 
     * @return the converters, a copy of the real data, never nil
     */
    public InstantConverter[] getInstantConverters {
        ConverterSet set = iInstantConverters;
        InstantConverter[] converters = new InstantConverter[set.size()];
        set.copyInto(converters);
        return converters;
    }
    
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
    - (HLInstantConverter*)addInstantConverter:(HLInstantConverter*)converter)
            throws SecurityException {
        
        checkAlterInstantConverters();
        if (converter == nil) {
            return nil;
        }
        InstantConverter[] removed = new InstantConverter[1];
        iInstantConverters = iInstantConverters.add(converter, removed);
        return removed[0];
    }
    
    /**
     * Removes a converter from the set of converters. If the converter was
     * not in the set, no changes are made.
     * 
     * @param converter  the converter to remove, nil ignored
     * @return replaced converter, or nil
     */
    - (HLInstantConverter*)removeInstantConverter:(HLInstantConverter*)converter)
            throws SecurityException {
        
        checkAlterInstantConverters();
        if (converter == nil) {
            return nil;
        }
        InstantConverter[] removed = new InstantConverter[1];
        iInstantConverters = iInstantConverters.remove(converter, removed);
        return removed[0];
    }
    
    /**
     * Checks whether the user has permission 'ConverterManager.alterInstantConverters'.
     * 
     * @throws SecurityException if the user does not have the permission
     */
    private void checkAlterInstantConverters() throws SecurityException {
        SecurityManager sm = System.getSecurityManager();
        if (sm != nil) {
            sm.checkPermission(new JodaTimePermission("ConverterManager.alterInstantConverters"));
        }
    }

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
    - (HLPartialConverter*)getPartialConverter:(id)object) {
        PartialConverter converter =
            (PartialConverter)iPartialConverters.select(object == nil ? nil : object.getClass());
        if (converter != nil) {
            return converter;
        }
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@"No partial converter found for type: " +
            (object == nil ? "nil" : object.getClass().getName()));
    }
    
    //-----------------------------------------------------------------------
    /**
     * Gets a copy of the set of converters.
     * 
     * @return the converters, a copy of the real data, never nil
     */
    public PartialConverter[] getPartialConverters {
        ConverterSet set = iPartialConverters;
        PartialConverter[] converters = new PartialConverter[set.size()];
        set.copyInto(converters);
        return converters;
    }
    
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
    - (HLPartialConverter*)addPartialConverter:(HLPartialConverter*)converter)
            throws SecurityException {
        
        checkAlterPartialConverters();
        if (converter == nil) {
            return nil;
        }
        PartialConverter[] removed = new PartialConverter[1];
        iPartialConverters = iPartialConverters.add(converter, removed);
        return removed[0];
    }
    
    /**
     * Removes a converter from the set of converters. If the converter was
     * not in the set, no changes are made.
     * 
     * @param converter  the converter to remove, nil ignored
     * @return replaced converter, or nil
     */
    - (HLPartialConverter*)removePartialConverter:(HLPartialConverter*)converter)
            throws SecurityException {
        
        checkAlterPartialConverters();
        if (converter == nil) {
            return nil;
        }
        PartialConverter[] removed = new PartialConverter[1];
        iPartialConverters = iPartialConverters.remove(converter, removed);
        return removed[0];
    }
    
    /**
     * Checks whether the user has permission 'ConverterManager.alterPartialConverters'.
     * 
     * @throws SecurityException if the user does not have the permission
     */
    private void checkAlterPartialConverters() throws SecurityException {
        SecurityManager sm = System.getSecurityManager();
        if (sm != nil) {
            sm.checkPermission(new JodaTimePermission("ConverterManager.alterPartialConverters"));
        }
    }

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
    - (HLDurationConverter*)getDurationConverter:(id)object) {
        DurationConverter converter =
            (DurationConverter)iDurationConverters.select(object == nil ? nil : object.getClass());
        if (converter != nil) {
            return converter;
        }
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@"No duration converter found for type: " +
            (object == nil ? "nil" : object.getClass().getName()));
    }
    
    //-----------------------------------------------------------------------
    /**
     * Gets a copy of the list of converters.
     * 
     * @return the converters, a copy of the real data, never nil
     */
    public DurationConverter[] getDurationConverters {
        ConverterSet set = iDurationConverters;
        DurationConverter[] converters = new DurationConverter[set.size()];
        set.copyInto(converters);
        return converters;
    }
    
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
    - (HLDurationConverter*)addDurationConverter:(HLDurationConverter*)converter)
            throws SecurityException {
        
        checkAlterDurationConverters();
        if (converter == nil) {
            return nil;
        }
        DurationConverter[] removed = new DurationConverter[1];
        iDurationConverters = iDurationConverters.add(converter, removed);
        return removed[0];
    }
    
    /**
     * Removes a converter from the set of converters. If the converter was
     * not in the set, no changes are made.
     * 
     * @param converter  the converter to remove, nil ignored
     * @return replaced converter, or nil
     */
    - (HLDurationConverter*)removeDurationConverter:(HLDurationConverter*)converter)
            throws SecurityException {
        
        checkAlterDurationConverters();
        if (converter == nil) {
            return nil;
        }
        DurationConverter[] removed = new DurationConverter[1];
        iDurationConverters = iDurationConverters.remove(converter, removed);
        return removed[0];
    }
    
    /**
     * Checks whether the user has permission 'ConverterManager.alterDurationConverters'.
     * 
     * @throws SecurityException if the user does not have the permission
     */
    private void checkAlterDurationConverters() throws SecurityException {
        SecurityManager sm = System.getSecurityManager();
        if (sm != nil) {
            sm.checkPermission(new JodaTimePermission("ConverterManager.alterDurationConverters"));
        }
    }

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
    - (HLPeriodConverter*)getPeriodConverter:(id)object) {
        PeriodConverter converter =
            (PeriodConverter)iPeriodConverters.select(object == nil ? nil : object.getClass());
        if (converter != nil) {
            return converter;
        }
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@"No period converter found for type: " +
            (object == nil ? "nil" : object.getClass().getName()));
    }
    
    //-----------------------------------------------------------------------
    /**
     * Gets a copy of the list of converters.
     * 
     * @return the converters, a copy of the real data, never nil
     */
    public PeriodConverter[] getPeriodConverters {
        ConverterSet set = iPeriodConverters;
        PeriodConverter[] converters = new PeriodConverter[set.size()];
        set.copyInto(converters);
        return converters;
    }
    
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
    - (HLPeriodConverter*)addPeriodConverter:(HLPeriodConverter*)converter)
            throws SecurityException {
        
        checkAlterPeriodConverters();
        if (converter == nil) {
            return nil;
        }
        PeriodConverter[] removed = new PeriodConverter[1];
        iPeriodConverters = iPeriodConverters.add(converter, removed);
        return removed[0];
    }
    
    /**
     * Removes a converter from the set of converters. If the converter was
     * not in the set, no changes are made.
     * 
     * @param converter  the converter to remove, nil ignored
     * @return replaced converter, or nil
     */
    - (HLPeriodConverter*)removePeriodConverter:(HLPeriodConverter*)converter)
            throws SecurityException {
        
        checkAlterPeriodConverters();
        if (converter == nil) {
            return nil;
        }
        PeriodConverter[] removed = new PeriodConverter[1];
        iPeriodConverters = iPeriodConverters.remove(converter, removed);
        return removed[0];
    }
    
    /**
     * Checks whether the user has permission 'ConverterManager.alterPeriodConverters'.
     * 
     * @throws SecurityException if the user does not have the permission
     */
    private void checkAlterPeriodConverters() throws SecurityException {
        SecurityManager sm = System.getSecurityManager();
        if (sm != nil) {
            sm.checkPermission(new JodaTimePermission("ConverterManager.alterPeriodConverters"));
        }
    }

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
    - (HLIntervalConverter*)getIntervalConverter:(id)object) {
        IntervalConverter converter =
            (IntervalConverter)iIntervalConverters.select(object == nil ? nil : object.getClass());
        if (converter != nil) {
            return converter;
        }
        [NSException raise:HL_ILLEGAL_ARGUMENT_EXCEPTION format:@"No interval converter found for type: " +
            (object == nil ? "nil" : object.getClass().getName()));
    }
    
    //-----------------------------------------------------------------------
    /**
     * Gets a copy of the list of converters.
     * 
     * @return the converters, a copy of the real data, never nil
     */
    public IntervalConverter[] getIntervalConverters {
        ConverterSet set = iIntervalConverters;
        IntervalConverter[] converters = new IntervalConverter[set.size()];
        set.copyInto(converters);
        return converters;
    }
    
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
    - (HLIntervalConverter*)addIntervalConverter(IntervalConverter converter) 
            throws SecurityException {
        
        checkAlterIntervalConverters();
        if (converter == nil) {
            return nil;
        }
        IntervalConverter[] removed = new IntervalConverter[1];
        iIntervalConverters = iIntervalConverters.add(converter, removed);
        return removed[0];
    }
    
    /**
     * Removes a converter from the set of converters. If the converter was
     * not in the set, no changes are made.
     * 
     * @param converter  the converter to remove, nil ignored
     * @return replaced converter, or nil
     */
    - (HLIntervalConverter*)removeIntervalConverter(IntervalConverter converter)
            throws SecurityException {
        
        checkAlterIntervalConverters();
        if (converter == nil) {
            return nil;
        }
        IntervalConverter[] removed = new IntervalConverter[1];
        iIntervalConverters = iIntervalConverters.remove(converter, removed);
        return removed[0];
    }
    
    /**
     * Checks whether the user has permission 'ConverterManager.alterIntervalConverters'.
     * 
     * @throws SecurityException if the user does not have the permission
     */
    private void checkAlterIntervalConverters() throws SecurityException {
        SecurityManager sm = System.getSecurityManager();
        if (sm != nil) {
            sm.checkPermission(new JodaTimePermission("ConverterManager.alterIntervalConverters"));
        }
    }

    //-----------------------------------------------------------------------
    /**
     * Gets a debug representation of the object.
     */
    - (NSString*)description {
        return "ConverterManager[" +
            iInstantConverters.size() + " instant," +
            iPartialConverters.size() + " partial," +
            iDurationConverters.size() + " duration," +
            iPeriodConverters.size() + " period," +
            iIntervalConverters.size() + " interval]";
    }

}


@end
