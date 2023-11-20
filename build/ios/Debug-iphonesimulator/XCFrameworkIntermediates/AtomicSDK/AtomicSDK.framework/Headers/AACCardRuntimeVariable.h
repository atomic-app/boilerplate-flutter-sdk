//
// AACCardRuntimeVariable.h
// ActionCardsSDK
// Copyright © 2019 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents a runtime variable for a given card.
 Runtime variables are resolved by the host app via `AACSessionDelegate`.
 */
@interface AACCardRuntimeVariable: NSObject

- (instancetype)init NS_UNAVAILABLE;

/**
 The name used to identify the runtime variable in a card.
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 The default value to use for the runtime variable, used if the host app cannot provide a value.
 */
@property (nonatomic, copy, readonly) NSString *defaultValue;

@end
