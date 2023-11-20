//
// AACRequestDelegate.h
// AtomicSDK
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AtomicSDK/AACRequestDisposition.h>

/**
 Optional delegate that provides logic for allowing or denying network requests originating
 from the Atomic SDK.
 */
@protocol AACRequestDelegate <NSObject>

@required

/**
 Returns the request disposition to use for the specified request URL. This allows you to provide logic for allowing or
 denying network requests originating from the Atomic SDK.
 
 There are 3 supported dispositions:
    - Allow the request;
    - Allow the request, provided that the request's certificate validates against a set of provided pins;
    - Deny the request.
 
 @param requestUrl The URL to validate.
 @return The request disposition. Supported dispositions are exposed as static methods on `AACRequestDisposition`.
 */
- (AACRequestDisposition* __nonnull)dispositionForAtomicRequest:(NSURL* __nonnull)requestUrl;

@end
