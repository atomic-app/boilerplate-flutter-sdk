//
// AACSingleCardConfiguration.h
// AtomicSDK
// Copyright © 2020 Atomic.io Limited. All rights reserved.
//

#import <AtomicSDK/AtomicSDK.h>

/**
 Specialised configuration object for use with a single card view.
 */
@interface AACSingleCardConfiguration: AACConfiguration

/**
 Whether the single card view should automatically display the next card in the list, if there is one,
 once the current card is actioned.
 Defaults to `NO`.
 */
@property (nonatomic) BOOL automaticallyLoadNextCard;

@end
