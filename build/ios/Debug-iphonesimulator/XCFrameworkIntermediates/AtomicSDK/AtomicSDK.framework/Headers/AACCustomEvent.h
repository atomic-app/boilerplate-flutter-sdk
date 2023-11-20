//
// AACCustomEvent.h
// AtomicSDK
// Copyright © 2022 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents a custom event being sent to the platform. A custom event can be used in the Workbench
 to create segments for card targeting, or to kick off Action Flows via event triggers.
 */
@interface AACCustomEvent: NSObject

- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 Creates a new custom event for the event with the specified name and optional properties.
 
 @param eventName The name of the custom event.
 @param properties A dictionary of optional key-value pairs to provide to the event, can be `nil`.
 */
- (instancetype __nonnull)initWithName:(NSString* __nonnull)eventName properties:(NSDictionary* __nullable)properties;

/**
 The name of the event this object was initialised with.
 */
@property (nonatomic, readonly, nonnull) NSString *eventName;

/**
 Custom properties pertaining to this particular event instance.
 */
@property (nonatomic, readonly, nullable) NSDictionary *properties;

@end
