//
// AACSingleCardView.h
// AtomicSDK
// Copyright © 2020 Atomic.io Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AtomicSDK/AACSessionDelegate.h>
#import <AtomicSDK/AACConfiguration.h>
#import <AtomicSDK/AACCardFilter.h>
#import <AtomicSDK/AACRuntimeVariableDelegate.h>

@class AACSingleCardView;

/**
 Delegate that responds to events in the single card view.
 */
@protocol AACSingleCardViewDelegate <NSObject>

@optional
/**
 The single card view is about to change to the provided size, as a result of a card
 (dis)appearing due to card feed updating, being dismissed or snoozed.
 
 @param cardView The single card view affected by the change.
 @param newSize The new size of the single card view.
 */
- (void)singleCardView:(AACSingleCardView* __nonnull)cardView
        willChangeSize:(CGSize)newSize;

@end

/**
 A view designed to display a single card (the first in the user's stream).
 */
@interface AACSingleCardView: UIView

- (instancetype __nonnull)init NS_UNAVAILABLE;
- (instancetype __nonnull)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype __nonnull)initWithCoder:(NSCoder* __nonnull)coder NS_UNAVAILABLE;

/**
 Creates a new view for displaying a single card.
 
 @param frame The initial size of the single card view. The `intrinsicSize` is updated when the card view resizes.
 @param containerId The ID of the stream container to render the first card from.
 @param sessionDelegate A session delegate that provides a user's JWT and resolves runtime variables.
 @param configuration Stream container configuration to apply to this single card view.
 */
- (instancetype __nonnull)initWithFrame:(CGRect)frame
                    containerIdentifier:(NSString* __nonnull)containerId
                        sessionDelegate:(id<AACSessionDelegate> __nonnull)sessionDelegate
                          configuration:(AACConfiguration* __nonnull)configuration DEPRECATED_MSG_ATTRIBUTE("Session delegates are now configured globally, and are no longer supplied as a parameter (as of release 1.0.0). Please pass your session delegate to +[AACSession setSessionDelegate:], and use `initWithFrame:containerIdentifier:configuration:` instead.");

/**
 Creates a new view for displaying a single card.
 
 @param frame The initial size of the single card view. The `intrinsicSize` is updated when the card view resizes.
 @param containerId The ID of the stream container to render the first card from.
 @param configuration Stream container configuration to apply to this single card view. 
 */
- (instancetype __nonnull)initWithFrame:(CGRect)frame
                    containerIdentifier:(NSString* __nonnull)containerId
                          configuration:(AACConfiguration* __nonnull)configuration;

/**
 Delegate that responds to events in the single card view.
*/
@property (nonatomic, weak, nullable) id<AACSingleCardViewDelegate> delegate;

/**
 Requests that runtime variables, across the single card view, be updated.
 Must be called from the main thread.
 */
- (void)updateVariables;

/**
 Requests that the single card view check for new cards immediately.
 */
- (void)refresh;

/**
 Applies the specified card list filter to the single card view.
 The single card view will render the first card that matches the specified filter, or no cards if there are no matches.
 In HTTP polling mode, calling this method immediately updates the single card view and does not require waiting until the next polling interval.
 
 @param filter The filter to apply. Pass `nil` to clear the active filter.
 */
- (void)applyFilter:(AACCardFilter* __nullable)filter;

@end
