//
// AACCardEvent.h
// AtomicSDK
// Copyright © 2020 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Card events that the SDK can communicate back to the host app.
 */
typedef NS_ENUM(NSUInteger, AACCardEventKind) {
    /// A card was successfully submitted.
    AACCardEventKindSubmitted,
    /// A card was successfully dismissed.
    AACCardEventKindDismissed,
    /// A card was successfully snoozed.
    AACCardEventKindSnoozed,
    /// A card was voted as useful.
    AACCardEventKindVotedUseful,
    /// A card was voted as not useful.
    AACCardEventKindVotedNotUseful,
    /// A card failed to submit, either due to an API error or lack of network connectivity.
    AACCardEventKindSubmitFailed,
    /// A card failed to dismiss, either due to an API error or lack of network connectivity.
    AACCardEventKindDismissFailed,
    /// A card failed to snooze, either due to an API error or lack of network connectivity.
    AACCardEventKindSnoozeFailed
};

/**
 An event pertaining to a card, such as when a card is submitted,
 dismissed, snoozed or voted on.
 */
@interface AACCardEvent: NSObject

- (instancetype)init NS_UNAVAILABLE;

/// The kind of card event that this object represents.
@property (nonatomic, readonly) AACCardEventKind kind;

@end
