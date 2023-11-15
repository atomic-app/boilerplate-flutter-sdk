//
// AACEventPayload.h
// AtomicSDK
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents a request to trigger an event on the Atomic Platform.
 */
@interface AACEventPayload: NSObject

- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 Creates a new event payload, for the event with the specified name.
 
 @param name The name of the event to trigger on the Atomic Platform.
 */
- (instancetype __nonnull)initWithName:(NSString* __nonnull)name;

/**
 The name of the event to trigger. Required.
 */
@property (nonatomic, copy, nonnull, readonly) NSString *name;

/**
 An optional lifecycle ID to use for the event.
 */
@property (nonatomic, copy, nullable) NSString* lifecycleId;

/**
 A dictionary of optional key-value pairs to provide to the event.
 */
@property (nonatomic, copy, nullable) NSDictionary* detail;

/**
 A dictionary of optional key-value pairs to use as metadata for the event.
 */
@property (nonatomic, copy, nullable) NSDictionary* metadata;

/**
 A dictionary of optional key-value pairs to use as custom data for push notifications for the event.
 */
@property (nonatomic, copy, nullable) NSDictionary* notificationDetail;

@end
