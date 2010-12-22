/*
 * HLInterval.m
 *
 * Horologe
 * Copyright (c) 2010 Pilgrimage Software
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
 
#import "HLInterval.h"


@implementation HLInterval

//-----------------------------------------------------------------------
public Interval(long startInstant, long endInstant) {
    super(startInstant, endInstant, null);
}

public Interval(long startInstant, long endInstant, DateTimeZone zone) {
    super(startInstant, endInstant, ISOChronology.getInstance(zone));
}

public Interval(long startInstant, long endInstant, Chronology chronology) {
    super(startInstant, endInstant, chronology);
}

public Interval(ReadableInstant start, ReadableInstant end) {
    super(start, end);
}

public Interval(ReadableInstant start, ReadableDuration duration) {
    super(start, duration);
}

public Interval(ReadableDuration duration, ReadableInstant end) {
    super(duration, end);
}

public Interval(ReadableInstant start, ReadablePeriod period) {
    super(start, period);
}

public Interval(ReadablePeriod period, ReadableInstant end) {
    super(period, end);
}

public Interval(Object interval) {
    super(interval, null);
}

public Interval(Object interval, Chronology chronology) {
    super(interval, chronology);
}

//-----------------------------------------------------------------------
public Interval toInterval() {
    return this;
}

//-----------------------------------------------------------------------
public Interval overlap(ReadableInterval interval) {
    interval = DateTimeUtils.getReadableInterval(interval);
    if (overlaps(interval) == false) {
        return null;
    }
    long start = Math.max(getStartMillis(), interval.getStartMillis());
    long end = Math.min(getEndMillis(), interval.getEndMillis());
    return new Interval(start, end, getChronology());
}

//-----------------------------------------------------------------------
public Interval gap(ReadableInterval interval) {
    interval = DateTimeUtils.getReadableInterval(interval);
    long otherStart = interval.getStartMillis();
    long otherEnd = interval.getEndMillis();
    long thisStart = getStartMillis();
    long thisEnd = getEndMillis();
    if (thisStart > otherEnd) {
        return new Interval(otherEnd, thisStart, getChronology());
    } else if (otherStart > thisEnd) {
        return new Interval(thisEnd, otherStart, getChronology());
    } else {
        return null;
    }
}

//-----------------------------------------------------------------------
public boolean abuts(ReadableInterval interval) {
    if (interval == null) {
        long now = DateTimeUtils.currentTimeMillis();
        return (getStartMillis() == now || getEndMillis() == now);
    } else {
        return (interval.getEndMillis() == getStartMillis() ||
                getEndMillis() == interval.getStartMillis());
    }
}

//-----------------------------------------------------------------------
public Interval withChronology(Chronology chronology) {
    if (getChronology() == chronology) {
        return this;
    }
    return new Interval(getStartMillis(), getEndMillis(), chronology);
}

public Interval withStartMillis(long startInstant) {
    if (startInstant == getStartMillis()) {
        return this;
    }
    return new Interval(startInstant, getEndMillis(), getChronology());
}

public Interval withStart(ReadableInstant start) {
    long startMillis = DateTimeUtils.getInstantMillis(start);
    return withStartMillis(startMillis);
}

public Interval withEndMillis(long endInstant) {
    if (endInstant == getEndMillis()) {
        return this;
    }
    return new Interval(getStartMillis(), endInstant, getChronology());
}

public Interval withEnd(ReadableInstant end) {
    long endMillis = DateTimeUtils.getInstantMillis(end);
    return withEndMillis(endMillis);
}

//-----------------------------------------------------------------------
public Interval withDurationAfterStart(ReadableDuration duration) {
    long durationMillis = DateTimeUtils.getDurationMillis(duration);
    if (durationMillis == toDurationMillis()) {
        return this;
    }
    Chronology chrono = getChronology();
    long startMillis = getStartMillis();
    long endMillis = chrono.add(startMillis, durationMillis, 1);
    return new Interval(startMillis, endMillis, chrono);
}

public Interval withDurationBeforeEnd(ReadableDuration duration) {
    long durationMillis = DateTimeUtils.getDurationMillis(duration);
    if (durationMillis == toDurationMillis()) {
        return this;
    }
    Chronology chrono = getChronology();
    long endMillis = getEndMillis();
    long startMillis = chrono.add(endMillis, durationMillis, -1);
    return new Interval(startMillis, endMillis, chrono);
}

//-----------------------------------------------------------------------
public Interval withPeriodAfterStart(ReadablePeriod period) {
    if (period == null) {
        return withDurationAfterStart(null);
    }
    Chronology chrono = getChronology();
    long startMillis = getStartMillis();
    long endMillis = chrono.add(period, startMillis, 1);
    return new Interval(startMillis, endMillis, chrono);
}

public Interval withPeriodBeforeEnd(ReadablePeriod period) {
    if (period == null) {
        return withDurationBeforeEnd(null);
    }
    Chronology chrono = getChronology();
    long endMillis = getEndMillis();
    long startMillis = chrono.add(period, endMillis, -1);
    return new Interval(startMillis, endMillis, chrono);
}

@end
