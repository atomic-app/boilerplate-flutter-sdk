//
// AACStreamContainerViewController.h
// Atomic SDK
// Copyright © 2019 Atomic.io Limited. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AtomicSDK/AACSessionDelegate.h>
#import <AtomicSDK/AACConfiguration.h>
#import <AtomicSDK/AACCardFilter.h>
/**
 Creates an instance of a stream container, which renders a list of
 cards for a given stream instance. A stream container is identified by
 its ID in the Workbench.
 
 This view controller supports several methods of presentation,
 defined in the `AACConfigurationPresentationStyle` and specified via the
 `AACConfiguration` object.
 
 The navigation flow is managed entirely by this view controller.
 
 @note Do not subclass this view controller.
 */
__attribute__((objc_subclassing_restricted))
@interface AACStreamContainerViewController: UIViewController

/**
 Creates a new view controller that renders a stream container by its identifier.
 
 @param containerId (Required) The ID for this stream container, as identified in the Workbench.
 @param sessionDelegate (Required) A delegate that supplies a user authentication token when requested
 by the SDK.
 @param configuration (Required) A configuration object for defining behaviour of the stream container.
 */
- (instancetype __nonnull)initWithIdentifier:(NSString* __nonnull)containerId
                             sessionDelegate:(id<AACSessionDelegate> __nonnull)sessionDelegate
                               configuration:(AACConfiguration* __nonnull)configuration NS_DESIGNATED_INITIALIZER DEPRECATED_MSG_ATTRIBUTE("Session delegates are now configured globally, and are no longer supplied as a parameter (as of release 1.0.0). Please pass your session delegate to +[AACSession setSessionDelegate:], and use `initWithIdentifier:configuration:` instead.");

/**
 Creates a new view controller that renders a stream container by its identifier.
 
 @param containerId (Required) The ID for this stream container, as identified in the Workbench.
 @param configuration (Required) A configuration object for defining behaviour of the stream container.
 */
- (instancetype __nonnull)initWithIdentifier:(NSString* __nonnull)containerId
                               configuration:(AACConfiguration* __nonnull)configuration NS_DESIGNATED_INITIALIZER;

- (instancetype __nonnull)init NS_UNAVAILABLE;
- (instancetype __nonnull)initWithCoder:(NSCoder* __nonnull)aDecoder NS_UNAVAILABLE;
- (instancetype __nonnull)initWithNibName:(NSString* __nullable)nibNameOrNil
                                   bundle:(NSBundle* __nullable)nibBundleOrNil NS_UNAVAILABLE;

/**
 The ID of this stream container, located in the Atomic Workbench.
 */
@property (nonatomic, copy, nonnull, readonly) NSString *identifier;

/**
 Requests that runtime variables, across all cards in the card list, be re-evaluated.
 Must be called from the main thread.
 */
- (void)updateVariables;

/**
 Requests that the stream container check for new cards immediately.
 This is equivalent to the user performing the pull-to-refresh action on the card list.
 */
- (void)refresh;

/**
 Updates the filter applied to cards in the stream container or single card view,
 and updates the card list to reflect the filter.
 
 Pass `nil` to clear the active filter.
 
 @param filter A filter to apply, retrieved from static methods on `AACCardListFilter`,
 or `nil` to clear the active filter.
 */
- (void)applyFilter:(AACCardFilter* __nonnull)filter;

@end
