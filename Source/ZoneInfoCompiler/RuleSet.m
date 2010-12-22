//
//  RuleSet.m
//  Horologe
//
//  Created by Paul Schifferer on 10/18/10.
//  Copyright (c) 2010 Pilgrim Age Software. All rights reserved.
//

#import "HLRuleSet.h"
#import "HLRule.h"

@implementation HLRuleSet

- (id)initWithRule:(HLRule*)rule {
    if ((self = [super init])) {
        // Initialization code here.
        iRules = [[NSMutableArray alloc] init];
        [iRules addObject:rule];
    }
    
    return self;
}

- (void)addRule:(HLRule*)rule {
    
    if (!([rule iName] isEqual:[[iRules objectAtIndex:0] iName])) {
        throw new IllegalArgumentException("Rule name mismatch");
    }
    
    [iRules addObject:rule];
}

/**
 * Adds recurring savings rules to the builder.
 */
- (void)addRecurring:(HLDateTimeZoneBuilder*)builder
          nameFormat:(NSString*)nameFormat {
    
    for (int i = 0; i < [iRules count]; i++) {
        HLRule* rule = [iRules objectAtIndex:i];
        [rule addRecurring:builder nameFormat:nameFormat];
    }
}

- (void)dealloc {
    // Clean-up code here.
    [iRules release];
    
    [super dealloc];
}

@end
