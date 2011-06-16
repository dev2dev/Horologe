/*
 * HLISODateTimeFormat.h
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
 
#import <Foundation/Foundation.h>


@interface HLISODateTimeFormat : NSObject {

}

- (id)_init;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)forFields:(NSArray*)fields
                         extended:(BOOL)extended
                        strictISO:(BOOL)strictISO;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)dateParser;

/**
 */
+ (HLDateTimeFormatter*)localDateParser;

/**
 */
+ (HLDateTimeFormatter*)dateElementParser;

/**
 */
+ (HLDateTimeFormatter*)timeParser;

/**
 */
+ (HLDateTimeFormatter*)localTimeParser;

/**
 */
+ (HLDateTimeFormatter*)timeElementParser;

/**
 */
+ (HLDateTimeFormatter*)dateTimeParser;

/**
 */
+ (HLDateTimeFormatter*)dateOptionalTimeParser;

/**
 */
+ (HLDateTimeFormatter*)localDateOptionalTimeParser;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)date;

/**
 */
+ (HLDateTimeFormatter*)time;

/**
 */
+ (HLDateTimeFormatter*)timeNoMillis;

/**
 */
+ (HLDateTimeFormatter*)tTime;

/**
 */
+ (HLDateTimeFormatter*)tTimeNoMillis;

/**
 */
+ (HLDateTimeFormatter*)dateTime;

/**
 */
+ (HLDateTimeFormatter*)dateTimeNoMillis;

/**
 */
+ (HLDateTimeFormatter*)ordinalDate;

/**
 */
+ (HLDateTimeFormatter*)ordinalDateTime;

/**
 */
+ (HLDateTimeFormatter*)ordinalDateTimeNoMillis;

/**
 */
+ (HLDateTimeFormatter*)weekDate;

/**
 */
+ (HLDateTimeFormatter*)weekDateTime;

/**
 */
+ (HLDateTimeFormatter*)weekDateTimeNoMillis;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)basicDate;

/**
 */
+ (HLDateTimeFormatter*)basicTime;

/**
 */
+ (HLDateTimeFormatter*)basicTimeNoMillis;

/**
 */
+ (HLDateTimeFormatter*)basicTTime;

/**
 */
+ (HLDateTimeFormatter*)basicTTimeNoMillis;

/**
 */
+ (HLDateTimeFormatter*)basicDateTime;

/**
 */
+ (HLDateTimeFormatter*)basicDateTimeNoMillis;

/**
 */
+ (HLDateTimeFormatter*)basicOrdinalDate;

/**
 */
+ (HLDateTimeFormatter*)basicOrdinalDateTime;

/**
 */
+ (HLDateTimeFormatter*)basicOrdinalDateTimeNoMillis;

/**
 */
+ (HLDateTimeFormatter*)basicWeekDate;

/**
 */
+ (HLDateTimeFormatter*)basicWeekDateTime;

/**
 */
+ (HLDateTimeFormatter*)basicWeekDateTimeNoMillis;

//-----------------------------------------------------------------------
/**
 */
+ (HLDateTimeFormatter*)year;

/**
 */
+ (HLDateTimeFormatter*)yearMonth;

/**
 */
+ (HLDateTimeFormatter*)yearMonthDay;

/**
 */
+ (HLDateTimeFormatter*)weekyear;

/**
 */
+ (HLDateTimeFormatter*)weekyearWeek;

/**
 */
+ (HLDateTimeFormatter*)weekyearWeekDay;

/**
 */
+ (HLDateTimeFormatter*)hour;

/**
 */
+ (HLDateTimeFormatter*)hourMinute;

/**
 */
+ (HLDateTimeFormatter*)hourMinuteSecond;

/**
 */
+ (HLDateTimeFormatter*)hourMinuteSecondMillis;

/**
 */
+ (HLDateTimeFormatter*)hourMinuteSecondFraction;

/**
 */
+ (HLDateTimeFormatter*)dateHour;

/**
 */
+ (HLDateTimeFormatter*)dateHourMinute;

/**
 */
+ (HLDateTimeFormatter*)dateHourMinuteSecond;

/**
 */
+ (HLDateTimeFormatter*)dateHourMinuteSecondMillis;

/**
 */
+ (HLDateTimeFormatter*)dateHourMinuteSecondFraction;

@end
