//
// AACHorizontalContainerConfiguration.h
// AtomicSDK
// Copyright © 2022 Atomic.io Limited. All rights reserved.
//

#import <AtomicSDK/AACConfiguration.h>

/**
 The style of empty state (when there are no cards) for the horizontal container.
 */
typedef NS_ENUM(NSUInteger, AACHorizontalContainerConfigurationEmptyStyle) {
    /**
     The horizontal container should always display a no card user interface.
     */
    AACHorizontalContainerConfigurationEmptyStyleStandard,
    /**
     The horizontal container should shrink itself when there are no cards.
     */
    AACHorizontalContainerConfigurationEmptyStyleShrink
};

/**
 Options that specify the alignment of the title in the horizontal header.
 */
typedef NS_ENUM(NSUInteger, AACHorizontalContainerConfigurationHeaderAlignment) {
    /**
     The title is aligned in the middle of the header.
     */
    AACHorizontalContainerConfigurationHeaderAlignmentCenter,
    /**
     The title is aligned to the left of the header.
     */
    AACHorizontalContainerConfigurationHeaderAlignmentLeft
};

/**
 Options that control the alignment of the last card in the horizontal container.
 This option only applies when there is only one card in the container.
 */
typedef NS_ENUM(NSUInteger, AACHorizontalContainerConfigurationLastCardAlignment) {
    /**
     The last card is aligned to the left of the container.
     */
    AACHorizontalContainerConfigurationLastCardAlignmentLeft,
    /**
     The last card is aligned in the middle of the container.
     */
    AACHorizontalContainerConfigurationLastCardAlignmentCenter
};

/**
 Options that control the scroll mode of the horizontal container.
 */
typedef NS_ENUM(NSUInteger, AACHorizontalContainerConfigurationScrollMode) {
    /**
     The container scrolls over one card at a time, where applicable the card is placed
     in the middle of the view port when the scroll terminates.
     */
    AACHorizontalContainerConfigurationScrollModeSnap,
    /**
     The container scrolls freely.
     */
    AACHorizontalContainerConfigurationScrollModeFree
};

/**
 Specialised configuration object for use with a horizontal container view.
 */
@interface AACHorizontalContainerConfiguration: AACConfiguration

/**
 The width of every card displayed in the horizontal container view.
 */
@property (nonatomic) CGFloat cardWidth;

/**
 The empty style of a horizontal container view. It determines how the view displays
 when there are no cards. Defaults to `AACHorizontalContainerConfigurationEmptyStyleStandard`
 */
@property (nonatomic) AACHorizontalContainerConfigurationEmptyStyle emptyStyle;

/**
 The option for aligning the title of the header horizontally.
 Defaults to `AACHorizontalContainerConfigurationHeaderAlignmentCenter`.
 */
@property (nonatomic) AACHorizontalContainerConfigurationHeaderAlignment headerAlignment;

/**
 The option for aligning the last card in a horizontal container.
 Defaults to `AACHorizontalContainerConfigurationLastCardAlignmentLeft`.
 */
@property (nonatomic) AACHorizontalContainerConfigurationLastCardAlignment lastCardAlignment;

/**
 The option for controlling the scroll mode of the container. Defaults to `AACHorizontalContainerConfigurationScrollModeSnap`.
 */
@property (nonatomic) AACHorizontalContainerConfigurationScrollMode scrollMode;

@end
