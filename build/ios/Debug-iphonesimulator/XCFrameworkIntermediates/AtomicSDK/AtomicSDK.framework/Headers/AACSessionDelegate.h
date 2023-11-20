//
// AACSessionDelegate.h
// Atomic SDK
// Copyright © 2019 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A block used to hand an authentication token back to the SDK when requested.

 @param authToken An authentication token (JWT) resolved by your app, or `nil` if no token is
 available.
 */
typedef void(^AACSessionAuthenticationTokenHandler)(NSString* __nullable authToken);

/**
 An AACSessionDelegate supplies information to the SDK relating to the user's session.
 
 The method `cardSessionDidRequestAuthenticationTokenWithHandler:` must be implemented,
 and is used to supply an authentication token to the SDK. If you do not supply a valid
 authentication token, API requests within the SDK will fail.
 */
@protocol AACSessionDelegate <NSObject>

@required

/**
 Called when the SDK has requested an authentication token.
 
 @param handler A block that you must call when an authentication token has been resolved. The sole argument
 to this block is expected to be an authentication token (JWT), or `nil` if there is no token available.
 */
- (void)cardSessionDidRequestAuthenticationTokenWithHandler:(AACSessionAuthenticationTokenHandler __nonnull)handler;

@optional

/**
 (Optional) Returns the time interval used to determine whether the authentication token has expired. If the interval between the
 current time and the token's `exp` field is smaller than that interval, the token is considered to be expired.
 
 If this method is not set, the default value is 60 seconds. The interval must not be smaller than zero.
 
 You must return a constant value from this method, as the value is only retrieved by the SDK once.
 */
- (NSTimeInterval)expiryInterval;

/**
 (Optional) Returns the time interval used to determine whether Atomic SDK should retry to fetch a token from the session delegate.
 The SDK won't fetch the JWT in a frequency higher than `1/interval`.
 
 If this method is not set, the default interval is 0 seconds, which means the SDK will retry immediately after failing to get a valid
 token.
 
 You must return a constant value from this method, as the value is only retrieved by the SDK once.
 */
- (NSTimeInterval)retryInterval;

@end
