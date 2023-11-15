//
// AACRuntimeVariableDelegate.h
// AtomicSDK
// Copyright © 2022 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AtomicSDK/AACCardInstance.h>

/**
 A completion handler provided to the integrator when resolving runtime variables.
 Once you have resolved all runtime variables, this completion handler must be called with the array of resolved cards.
 
 @param resolvedCards The cards provided to the delegate, but with all variables resolved. If a variable is not
 resolved, that variable uses its default value as defined in the Atomic Workbench.
 */
typedef void(^AACSessionRuntimeVariablesHandler)(NSArray<AACCardInstance*>* __nonnull resolvedCards);

/**
 Implements logic to resolve runtime variables on cards, when requested by the SDK.
 */
@protocol AACRuntimeVariableDelegate <NSObject>

@required

/**
 Delegate method that can be implemented when one or more cards include runtime variables.
 If the card includes runtime variables to be resolved, the SDK will call this method to ask that you resolve them.
 If this method is not implemented, or you do not resolve a given variable, the default values for that variable
 will be used (as defined in the Atomic Workbench).
 
 Variables are resolved on each card by calling `resolveRuntimeVariableWithName:value:`.
 
 @param cardsToResolve An array of cards containing runtime variables that need to be resolved.
 @param completionHandler A completion handler to call, with a resolved array of cards, when variable resolution is complete.
 */
- (void)cardSessionDidRequestRuntimeVariables:(NSArray<AACCardInstance*>* __nonnull)cardsToResolve
                            completionHandler:(AACSessionRuntimeVariablesHandler __nonnull)completionHandler;

@end

