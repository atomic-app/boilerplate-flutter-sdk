//
//  AACFlutterSessionDelegateResolutionRequest.h
//  atomic_sdk_flutter
//
//  Created by Eric on 15/12/22.
//

#import <Foundation/Foundation.h>
@import AtomicSDK;

/**
 Used internally by the SDK to match an auth token response to its original request.
 */
@interface AACFlutterSessionDelegateResolutionRequest: NSObject

/**
 Handler returned by the AACSessionDelegate implementation, called when a token is provided.
 */
@property (nonatomic, copy, nonnull) AACSessionAuthenticationTokenHandler handler;

/**
 Generated identifier that represents a specific authentication token request.
 */
@property (nonatomic, readonly, nonnull) NSString* identifier;

@end
