//
// AACCardCustomAction.h
// AtomicSDK
// Copyright © 2020 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents a custom action triggered by a link button on a card.
 */
@interface AACCardCustomAction: NSObject

/**
 This object cannot be instantiated directly.
 */
- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 The instance ID of the card where the action was triggered.
 */
@property (nonatomic, copy, readonly, nonnull) NSString* cardInstanceId;

/**
 The ID of the stream container that the card is contained within.
 */
@property (nonatomic, copy, readonly, nonnull) NSString* containerId;

/**
 A custom action payload that is associated with the link button.
 Inspect the data in this payload to determine which action to take.
 */
@property (nonatomic, copy, readonly, nonnull) NSDictionary *actionPayload;

@end
