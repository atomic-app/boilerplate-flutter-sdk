//
// AACFlutterSessionDelegate.h
// Atomic SDK - Flutter
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
@import AtomicSDK;

/**
 Callback used internally by the SDK to fetch an authentication token.
 */
typedef void(^AACFlutterAuthTokenCallback)(NSString* __nullable);

/**
 Session delegate that immediately returns the specified token when requested.
 */
@interface AACFlutterSessionDelegate: NSObject <AACSessionDelegate>

/**
 Callback used to retrieve an authentication token from the host app.
 */
@property (nonatomic, copy, nullable) AACFlutterAuthTokenCallback authTokenCallback;

/**
 Interval stored to return to iOS SDK.
 */
@property (nonatomic) NSTimeInterval retryIntervalFromFlutter;

/**
 Interval stored to return to iOS SDK.
 */
@property (nonatomic) NSTimeInterval expiryIntervalFromFlutter;

/**
 Invoked by the SDK when a new authentication token is provided by the React Native app.
 */
- (void)didReceiveAuthenticationToken:(NSString* __nullable)token forIdentifier:(NSString* __nonnull)identifier;

@end
