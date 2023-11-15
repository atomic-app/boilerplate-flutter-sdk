//
// AACUserMetrics.h
// AtomicSDK
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Returns card-related metrics for the current user.
 
 Metrics include:
 - How many cards are visible for the user in a given stream container;
 - How many cards _in total_ are visible for the user;
 - How many cards remain unseen for the user in a given stream container;
 - How many cards _in total_ are unseen for the user.
 */
@interface AACUserMetrics: NSObject

/**
 The total number of cards available in the stream container with the given ID, or 0 if
 the user does not have any cards in the given stream container.
 
 @param identifier The identifier for the stream container to calculate the total cards for.
 */
- (NSInteger)totalCardsForStreamContainerWithId:(NSString* __nonnull)identifier;

/**
 The total number of cards unseen by the user in the stream container with the given ID, or 0 if
 the stream container does not exist, or the user has seen all cards in the stream container.
 
 @param identifier The identifier for the stream container to calculate the unseen cards for.
 */
- (NSInteger)unseenCardsForStreamContainerWithId:(NSString* __nonnull)identifier;

/**
 The total number of cards available across all stream containers for the user.
 */
- (NSInteger)totalCards;

/**
 The total number of cards unseen across all stream containers for the user.
 */
- (NSInteger)unseenCards;

@end
