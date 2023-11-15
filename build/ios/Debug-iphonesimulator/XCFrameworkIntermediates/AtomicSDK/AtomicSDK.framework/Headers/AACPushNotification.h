//
// AACPushNotification.h
// AtomicSDK
// Copyright © 2020 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 An immutable object that represents a push notification received from the Atomic Platform.
 See +[AACSession notificationFromPushPayload:] .
 */
@interface AACPushNotification: NSObject

/**
 Do not instantiate this object directly - use +[AACSession notificationFromPushPayload:] instead.
 */
- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 The instance ID of the card that triggered this notification to be created.
 */
@property (nonatomic, copy, readonly, nonnull) NSString* cardInstanceId;

/**
 The ID of the stream container that the card is contained within.
 */
@property (nonatomic, copy, readonly, nonnull) NSString *containerId;

/**
 Custom data that is sent with the push notification payload, or an empty dictionary if there is no custom data.
 This data is sent in the `notificationDetail` object, in the event payload sent to the Atomic Platform.
 */
@property (nonatomic, copy, readonly, nonnull) NSDictionary *detail;

@end
