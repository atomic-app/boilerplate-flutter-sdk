//
// AACCardEventDelegate.h
// AtomicSDK
// Copyright © 2020 Atomic.io Limited. All rights reserved.
//

@class AACStreamContainerViewController;
@class AACCardEvent;

/**
 A delegate that is triggered when a card event occurs.
 */
@protocol AACCardEventDelegate <NSObject>

/**
 A card in the specified stream container has triggered the given event.
 
 @param streamContainerVc The stream container that triggered the card event.
 @param event The card event that occurred.
 */
- (void)streamContainer:(AACStreamContainerViewController* __nonnull)streamContainerVc didTriggerCardEvent:(AACCardEvent* __nonnull)event;

@end
