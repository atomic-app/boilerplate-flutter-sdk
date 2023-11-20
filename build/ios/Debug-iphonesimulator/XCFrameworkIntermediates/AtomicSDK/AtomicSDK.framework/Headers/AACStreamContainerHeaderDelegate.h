//
// AACStreamContainerHeaderDelegate.h
// AtomicSDK
// Copyright © 2022 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@class AACStreamContainerViewController;
@class UIView;

/**
 Optional delegate called when a custom header is required by the stream
 container.
 */
@protocol AACStreamContainerHeaderDelegate <NSObject>
@required
/**
 A custom header view is required by the stream container. Delegate must
 initialise the view before passing it back to the stream container.
 The size of this custom header view cannot be changed after passing.
 The stream container holds a strong reference to the returned view.
 
 @param streamContainer The stream container view controller that initiated the request.
 @param proposedWidth The width provided by the stream container. Delegate can use this value
 to resize the view so that it fits in the stream container.
 */
- (UIView *__nonnull)streamContainerDidRequestCustomHeader:(AACStreamContainerViewController* __nonnull)streamContainer
                                             proposedWidth:(CGFloat)proposedWidth;

@optional

/**
 The custom header is displayed by the stream container. Use this method to do some post
 displaying actions.
 
 @param streamContainer The stream container view controller that initiated the request.
 @param customHeaderView The displayed custom header.
 */
- (void)streamContainerDidDisplayCustomHeader:(AACStreamContainerViewController* __nonnull)streamContainer
                                 customHeader:(UIView* __nonnull)customHeaderView;

@end

