//
// AACHorizontalContainerView.h
// AtomicSDK
// Copyright © 2022 Atomic.io Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AtomicSDK/AACSessionDelegate.h>
#import <AtomicSDK/AACHorizontalContainerConfiguration.h>
#import <AtomicSDK/AACCardFilter.h>
#import <AtomicSDK/AACRuntimeVariableDelegate.h>

@class AACHorizontalContainerView;

/**
 Delegate that responds to events in the horizontal container view.
 */
@protocol AACHorizontalContainerViewDelegate <NSObject>

@optional
/**
 The horizontal container view is about to change to the provided size, as a result of a card
 (dis)appearing due to card feed updating, being dismissed or snoozed.
 
 @param containerView The horizontal container view affected by the change.
 @param newSize The new size of the horizontal container view.
 */
- (void)horizontalContainerView:(AACHorizontalContainerView* __nonnull)containerView
                 willChangeSize:(CGSize)newSize;

@end

/**
 A view designed to display a horizontal list of cards for a given stream instance.
 Cards in a horizontal list have the same card width, which must be designated
 during initialisation. The stream container it displays is identified by its ID in the Workbench.
 */
@interface AACHorizontalContainerView: UIView

- (instancetype __nonnull)init NS_UNAVAILABLE;
- (instancetype __nonnull)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype __nonnull)initWithCoder:(NSCoder* __nonnull)coder NS_UNAVAILABLE;

/**
 Creates a new view for displaying a horizontal card list.
 
 @param frame The initial size of the horizontal container view. The `intrinsicSize` is updated when the card view resizes.
 @param containerId The ID of the stream container to render the first card from.
 @param configuration Horizontal card list configuration to apply to this container view.
 */
- (instancetype __nonnull)initWithFrame:(CGRect)frame
                    containerIdentifier:(NSString* __nonnull)containerId
                          configuration:(AACHorizontalContainerConfiguration* __nonnull)configuration;
/**
 Delegate that responds to events in the horizontal container view.
*/
@property (nonatomic, weak, nullable) id<AACHorizontalContainerViewDelegate> delegate;

/**
 Requests that runtime variables, across the horizontal container view, be updated.
 Must be called from the main thread.
 */
- (void)updateVariables;

/**
 Requests that the horizontal container view checks for new cards immediately.
 */
- (void)refresh;

/**
 Applies the specified card list filter to the horizontal container view.
 The horizontal container view will render the cards that match the specified filter, or no cards if there are no matches.
 In HTTP polling mode, calling this method immediately updates the horizontal container view and does not require waiting until the next feed update.
 
 @param filter The filter to apply. Pass `nil` to clear the active filter.
 */
- (void)applyFilter:(AACCardFilter* __nullable)filter;
@end
