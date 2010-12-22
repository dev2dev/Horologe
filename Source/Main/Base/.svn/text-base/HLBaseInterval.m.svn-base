/*
 * HLBaseInterval.m
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
 
#import "Base/HLBaseInterval.h"


@implementation HLBaseInterval

- (id)_initWithStart:(NSInteger)startInstant 
                 end:(NSInteger)endInstant 
          chronology:(HLChronology*)chrono {
    
    if(self = [super _init]) {
        iChronology = [HLDateTimeUtils chronology:chrono];
        [self _checkIntervalStart:startInstant end:endInstant];
    iStartMillis = startInstant;
    iEndMillis = endInstant;
    }
    
    return self;
}

- (id)_initWithReadableStart:(id<HLReadableInstant>)start 
                         end:(id<HLReadableInstant>)end {
    
    if(self = [super _init]) {
    if (start == nil && end == nil) {
        iStartMillis = iEndMillis = [HLDateTimeUtils currentTimeMillis];
        iChronology = [[HLISOChronology instance] retain];
    } 
    else {
        iChronology = [[HLDateTimeUtils instantChronology:start] retain];
        iStartMillis = [HLDateTimeUtils instantMillis:start];
        iEndMillis = [HLDateTimeUtils instantMillis:end];
        [self _checkIntervalStart:iStartMillis end:iEndMillis];
    }
    }
    
    return self;
}

- (id)_initWithReadableStart:(id <HLReadableInstant>)start 
                    duration:(id<HLReadableDuration>)duration {

    if(self = [super _init]) {
        iChronology = [[HLDateTimeUtils instantChronology:start] retain];
        iStartMillis = [HLDateTimeUtils instantMillis:start];
        NSInteger durationMillis = [HLDateTimeUtils durationMillis:duration];
        iEndMillis = [HLFieldUtils safeAdd:iStartMillis val2:durationMillis];
        [self _checkIntervalStart:iStartMillis end:iEndMillis];
    }
    
    return self;
}

protected BaseInterval(ReadableDuration duration, ReadableInstant end) {
    super();
    iChronology = DateTimeUtils.getInstantChronology(end);
    iEndMillis = DateTimeUtils.getInstantMillis(end);
    long durationMillis = DateTimeUtils.getDurationMillis(duration);
    iStartMillis = FieldUtils.safeAdd(iEndMillis, -durationMillis);
    checkInterval(iStartMillis, iEndMillis);
}

protected BaseInterval(ReadableInstant start, ReadablePeriod period) {
    super();
    Chronology chrono = DateTimeUtils.getInstantChronology(start);
    iChronology = chrono;
    iStartMillis = DateTimeUtils.getInstantMillis(start);
    if (period == null) {
        iEndMillis = iStartMillis;
    } else {
        iEndMillis = chrono.add(period, iStartMillis, 1);
    }
    checkInterval(iStartMillis, iEndMillis);
}

protected BaseInterval(ReadablePeriod period, ReadableInstant end) {
    super();
    Chronology chrono = DateTimeUtils.getInstantChronology(end);
    iChronology = chrono;
    iEndMillis = DateTimeUtils.getInstantMillis(end);
    if (period == null) {
        iStartMillis = iEndMillis;
    } else {
        iStartMillis = chrono.add(period, iEndMillis, -1);
    }
    checkInterval(iStartMillis, iEndMillis);
}

protected BaseInterval(Object interval, Chronology chrono) {
    super();
    IntervalConverter converter = ConverterManager.getInstance().getIntervalConverter(interval);
    if (converter.isReadableInterval(interval, chrono)) {
        ReadableInterval input = (ReadableInterval) interval;
        iChronology = (chrono != null ? chrono : input.getChronology());
        iStartMillis = input.getStartMillis();
        iEndMillis = input.getEndMillis();
    } else if (this instanceof ReadWritableInterval) {
        converter.setInto((ReadWritableInterval) this, interval, chrono);
    } else {
        MutableInterval mi = new MutableInterval();
        converter.setInto(mi, interval, chrono);
        iChronology = mi.getChronology();
        iStartMillis = mi.getStartMillis();
        iEndMillis = mi.getEndMillis();
    }
    checkInterval(iStartMillis, iEndMillis);
}

//-----------------------------------------------------------------------
public Chronology getChronology() {
    return iChronology;
}

public long getStartMillis() {
    return iStartMillis;
}

public long getEndMillis() {
    return iEndMillis;
}

//-----------------------------------------------------------------------
protected void setInterval(long startInstant, long endInstant, Chronology chrono) {
    checkInterval(startInstant, endInstant);
    iStartMillis = startInstant;
    iEndMillis = endInstant;
    iChronology = DateTimeUtils.getChronology(chrono);
}

@end
