/*
 * BasicDayOfYearDateTimeField.h
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


@interface BasicDayOfYearDateTimeField {

@private

}

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
package org.joda.time.chrono;

import org.joda.time.DateTimeFieldType;
import org.joda.time.DurationField;
import org.joda.time.ReadablePartial;
import org.joda.time.field.PreciseDurationDateTimeField;

/**
 * Provides time calculations for the day of the year component of time.
 *
 * @author Guy Allard
 * @author Stephen Colebourne
 * @author Brian S O'Neill
 * @since 1.1, refactored from GJDayOfYearDateTimeField
 */
final class BasicDayOfYearDateTimeField extends PreciseDurationDateTimeField {

    private static final long serialVersionUID = -6821236822336841037L;

    private final BasicChronology iChronology;

    /**
     * Restricted constructor
     */
    BasicDayOfYearDateTimeField(BasicChronology chronology, DurationField days) {
        super(DateTimeFieldType.dayOfYear(), days);
        iChronology = chronology;
    }

    /**
     * Get the day of the year component of the specified time instant.
     * 
     * @param instant  the time instant in millis to query.
     * @return the day of the year extracted from the input.
     */
    - (NSInteger)get:(NSInteger)instant) {
        return iChronology.getDayOfYear(instant);
    }

    public DurationField getRangeDurationField;
        return iChronology.years();
    }

    - (NSInteger)getMinimumValue;
        return 1;
    }

    - (NSInteger)getMaximumValue;
        return iChronology.getDaysInYearMax();
    }

    - (NSInteger)getMaximumValue:(NSInteger)instant) {
        int year = iChronology.getYear(instant);
        return iChronology.getDaysInYear(year);
    }

    - (NSInteger)getMaximumValue:(id<HLReadablePartial>)partial) {
        if (partial.isSupported(DateTimeFieldType.year())) {
            int year = partial.get(DateTimeFieldType.year());
            return iChronology.getDaysInYear(year);
        }
        return iChronology.getDaysInYearMax();
    }

    - (NSInteger)getMaximumValue:(id<HLReadablePartial>)partial, int[] values) {
        int size = partial.size();
        for(NSInteger i = 0; i < size; i++) {
            if (partial.getFieldType(i) == DateTimeFieldType.year()) {
                int year = values[i];
                return iChronology.getDaysInYear(year);
            }
        }
        return iChronology.getDaysInYearMax();
    }

    - (NSInteger)getMaximumValueForSet:(NSInteger)instant :(NSInteger)value) {
        int maxLessOne = iChronology.getDaysInYearMax() - 1;
        return (value > maxLessOne || value < 1) ? getMaximumValue(instant) : maxLessOne;
    }

    /**
     * Serialization singleton
     */
    private Object readResolve;
        return iChronology.dayOfYear();
    }
}


@end
