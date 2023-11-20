//
// AACCardInstance.h
// ActionCardsSDK
// Copyright © 2019 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AtomicSDK/AACCardRuntimeVariable.h>
@import UIKit;

/**
 Represents an individual card displayed to the end user.
 */
@interface AACCardInstance: NSObject

- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 The name of the event, as defined in the Atomic Workbench, that caused this card
 to be created.
 */
@property (nonatomic, readonly, nonnull) NSString *eventName;

/**
 The lifecycle ID sent with the event that created this card.
 */
@property (nonatomic, readonly, nonnull) NSString *lifecycleId;

/**
 All runtime variables in use by this card.
 */
@property (nonatomic, strong, nonnull, readonly) NSArray<AACCardRuntimeVariable*>* runtimeVariables;

/**
 The priority of the card, the value of which can be any number from 1 - 10, with 1 being the highest priority,
 and 10 being the lowest priority. Cards with higher priority appear higher in the card feed.
 
 For example a card with priority 3 will be ordered above a card with priority 4.
 
 If no priority is supplied, the default priority is 5.
 */
@property (nonatomic, readonly) NSInteger priority;

/**
 The last active time of the card.
 */
@property (nonatomic, strong, nonnull, readonly) NSDate* lastCardActiveTime;

/**
 Assigns the given `value` to the variable with the given `name`.
 If the variable with the given name does not exist on this card, this method does nothing for that variable.
 
 @param name The name of the variable.
 @param value The resolved, string value for that variable.
 */
- (void)resolveRuntimeVariableWithName:(NSString* __nonnull)name
                                 value:(NSString* __nonnull)value;

@end
