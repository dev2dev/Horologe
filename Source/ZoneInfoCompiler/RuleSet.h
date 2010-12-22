//
//  RuleSet.h
//  Horologe
//
//  Created by Paul Schifferer on 10/18/10.
//  Copyright (c) 2010 Pilgrim Age Software. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <Foundation/Foundation.h>


@class HLRule;
@class HLDateTimeZoneBuilder;

@interface HLRuleSet : NSObject {
    
@private
    NSMutableArray* iRules;
    
}

- (id)initWithRule:(HLRule*)rule;

- (void)addRule:(HLRule*)rule;

/**
 * Adds recurring savings rules to the builder.
 */
- (void)addRecurring:(HLDateTimeZoneBuilder*)builder
          nameFormat:(NSString*)nameFormat;

@end
