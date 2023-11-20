//
// AACStreamContainerActionDelegate.h
// Atomic SDK
// Copyright © 2019 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AACStreamContainerViewController;
@class AACCardCustomAction;

/**
 Optional delegate called when external actions are triggered in the stream container.
 All methods on this delegate are also optional.
 */
@protocol AACStreamContainerActionDelegate <NSObject>

@optional
/**
 The user tapped on the button in the top left of the stream container.
 This method is only called when the `presentationStyle` of the stream container is set
 to `AACConfigurationPresentationStyleWithActionButton`.
 
 @param streamContainer The stream container view controller that initiated the request.
 */
- (void)streamContainerDidTapActionButton:(AACStreamContainerViewController* __nonnull)streamContainer;

/**
 The user tapped on a link button, which is configured with a custom action in the Atomic Workbench.
 The action object provided here includes a payload - a set of key-value pairs assigned in the Workbench to this link button.
 Use the information in this object to determine which action to take in your app.
 
 @param streamContainer The stream container view controller where the user tapped the link button.
 @param action Information associated with the action, including the card instance ID, stream container ID and action payload.
 */
- (void)streamContainerDidTapLinkButton:(AACStreamContainerViewController* __nonnull)streamContainer
                             withAction:(AACCardCustomAction* __nonnull)action;

/**
 The user submitted a card from a submit button that is configured with a custom action in the Atomic Workbench.
 The action object provided here includes a payload - a set of key-value pairs assigned in the Workbench to this submit button.
 Use the information in this object to determine which action to take in your app after the card has been submitted.
 
 @param streamContainer The stream container view controller where the user submitted the card.
 @param action Information associated with the action, including the card instance ID, stream container ID and action payload.
 */
- (void)streamContainerDidTapSubmitButton:(AACStreamContainerViewController* __nonnull)streamContainer
                               withAction:(AACCardCustomAction* __nonnull)action;

@end
