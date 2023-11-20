//
// AACCardFilter.h
// AtomicSDK
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents an instance of a filter that can be applied to a list of cards.
 */
@interface AACCardFilter: NSObject

@end

/**
 Provides static methods to generate card list filters supported by the SDK.
 */
@interface AACCardListFilter: NSObject

- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 Generates a card list filter that is restricted to the card with the provided instance ID.
 This can be used in stream containers or single card view to show only a particular card.
 
 @param cardInstanceId The instance ID of the card to show.
 */
+ (AACCardFilter* __nonnull)filterByCardInstanceId:(NSString* __nonnull)cardInstanceId;

@end
