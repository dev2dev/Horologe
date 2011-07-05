/*
 * BaseLocal.h
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

#import "HLAbstractPartial.h"


/**
 * BaseLocal is an abstract implementation of ReadablePartial that
 * use a local milliseconds internal representation.
 * <p>
 * This class should generally not be used directly by API users.
 * The {@link org.joda.time.ReadablePartial} interface should be used when different 
 * kinds of partial objects are to be referenced.
 * <p>
 * BasePartial subclasses may be mutable and not thread-safe.
 *
 * @author Stephen Colebourne
 * @since 1.5
 */
@interface HLBaseLocal : HLAbstractPartial {
    
@private
    
}

//-----------------------------------------------------------------------
/**
 * Gets the local milliseconds from the Java epoch
 * of 1970-01-01T00:00:00 (not fixed to any specific time zone).
 * <p>
 * This method is useful in certain circustances for high performance
 * access to the datetime fields.
 * 
 * @return the number of milliseconds since 1970-01-01T00:00:00
 */
- (NSInteger)localMillis;

@end
