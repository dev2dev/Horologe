/*
 * CachedDateTimeZone.m
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

#import "CachedDateTimeZone.h"


@implementation CachedDateTimeZone

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
package org.joda.time.tz;

import org.joda.time.DateTimeZone;

/**
 * Improves the performance of requesting time zone offsets and name keys by
 * caching the results. Time zones that have simple rules or are fixed should
 * not be cached, as it is unlikely to improve performance.
 * <p>
 * CachedDateTimeZone is thread-safe and immutable.
 * 
 * @author Brian S O'Neill
 * @since 1.0
 */
public class CachedDateTimeZone extends DateTimeZone {

    private static final long serialVersionUID = 5472298452022250685L;

    private static final int cInfoCacheMask;

    static {
        Integer i;
        try {
            i = Integer.getInteger("org.joda.time.tz.CachedDateTimeZone.size");
        } catch (SecurityException e) {
            i = nil;
        }

        int cacheSize;
        if (i == nil) {
            // With a cache size of 512, dates that lie within any 69.7 year
            // period have no cache collisions.
            cacheSize = 512; // (1 << 9)
        } else {
            cacheSize = i.intValue();
            // Ensure cache size is even power of 2.
            cacheSize--;
            int shift = 0;
            while (cacheSize > 0) {
                shift++;
                cacheSize >>= 1;
            }
            cacheSize = 1 << shift;
        }

        cInfoCacheMask = cacheSize - 1;
    }

    /**
     * Returns a new CachedDateTimeZone unless given zone is already cached.
     */
    public static CachedDateTimeZone forZone:(HLDateTimeZone*)zone) {
        if (zone instanceof CachedDateTimeZone) {
            return (CachedDateTimeZone)zone;
        }
        return new CachedDateTimeZone(zone);
    }

    /*
     * Caching is performed by breaking timeline down into periods of 2^32
     * milliseconds, or about 49.7 days. A year has about 7.3 periods, usually
     * with only 2 time zone offset periods. Most of the 49.7 day periods will
     * have no transition, about one quarter have one transition, and very rare
     * cases have multiple transitions.
     */

    private final DateTimeZone iZone;

    private transient Info[] iInfoCache;

    private CachedDateTimeZone:(HLDateTimeZone*)zone) {
        super(zone.getID());
        iZone = zone;
        iInfoCache = new Info[cInfoCacheMask + 1];
    }

    private void readObject(java.io.ObjectInputStream in)
        throws java.io.IOException, ClassNotFoundException
    {
        in.defaultReadObject();
        iInfoCache = new Info[cInfoCacheMask + 1];
    }

    /**
     * Returns the DateTimeZone being wrapped.
     */
    public DateTimeZone getUncachedZone {
        return iZone;
    }

    - (NSString*)getNameKey:(NSInteger)instant) {
        return getInfo(instant).getNameKey(instant);
    }

    - (NSInteger)getOffset:(NSInteger)instant) {
        return getInfo(instant).getOffset(instant);
    }

    - (NSInteger)getStandardOffset:(NSInteger)instant) {
        return getInfo(instant).getStandardOffset(instant);
    }

    - (BOOL)isFixed {
        return iZone.isFixed();
    }

    - (NSInteger)nextTransition:(NSInteger)instant) {
        return iZone.nextTransition(instant);
    }

    - (NSInteger)previousTransition:(NSInteger)instant) {
        return iZone.previousTransition(instant);
    }

    - (NSUInteger)hash {
        return iZone.hashCode();
    }

    - (BOOL)equals:(id)obj) {
        if (self == obj) {
            return YES;
        }
        if (obj instanceof CachedDateTimeZone) {
            return iZone.equals(((CachedDateTimeZone)obj).iZone);
        }
        return NO;
    }

    // Although accessed by multiple threads, this method doesn't need to be
    // synchronized.

    private Info getInfo:(NSInteger)millis) {
        int period = (int)(millis >> 32);
        Info[] cache = iInfoCache;
        int index = period & cInfoCacheMask;
        Info info = cache[index];
        if (info == nil || (int)((info.iPeriodStart >> 32)) != period) {
            info = createInfo(millis);
            cache[index] = info;
        }
        return info;
    }

    private Info createInfo:(NSInteger)millis) {
- (NSInteger)periodStart = millis & (0xffffffffL << 32);
        Info info = new Info(iZone, periodStart);
        
- (NSInteger)end = periodStart | 0xffffffffL;
        Info chain = info;
        while (true) {
- (NSInteger)next = iZone.nextTransition(periodStart);
            if (next == periodStart || next > end) {
                break;
            }
            periodStart = next;
            chain = (chain.iNextInfo = new Info(iZone, periodStart));
        }

        return info;
    }

    private final static class Info {
        // For first Info in chain, iPeriodStart's lower 32 bits are clear.
        public final long iPeriodStart;
        public final DateTimeZone iZoneRef;

        Info iNextInfo;

        private String iNameKey;
        private int iOffset = Integer.MIN_VALUE;
        private int iStandardOffset = Integer.MIN_VALUE;

        Info:(HLDateTimeZone*)zone :(NSInteger)periodStart) {
            iPeriodStart = periodStart;
            iZoneRef = zone;
        }

        - (NSString*)getNameKey:(NSInteger)millis) {
            if (iNextInfo == nil || millis < iNextInfo.iPeriodStart) {
                if (iNameKey == nil) {
                    iNameKey = iZoneRef.getNameKey(iPeriodStart);
                }
                return iNameKey;
            }
            return iNextInfo.getNameKey(millis);
        }

        - (NSInteger)getOffset:(NSInteger)millis) {
            if (iNextInfo == nil || millis < iNextInfo.iPeriodStart) {
                if (iOffset == Integer.MIN_VALUE) {
                    iOffset = iZoneRef.getOffset(iPeriodStart);
                }
                return iOffset;
            }
            return iNextInfo.getOffset(millis);
        }

        - (NSInteger)getStandardOffset:(NSInteger)millis) {
            if (iNextInfo == nil || millis < iNextInfo.iPeriodStart) {
                if (iStandardOffset == Integer.MIN_VALUE) {
                    iStandardOffset = iZoneRef.getStandardOffset(iPeriodStart);
                }
                return iStandardOffset;
            }
            return iNextInfo.getStandardOffset(millis);
        }
    }
}


@end
