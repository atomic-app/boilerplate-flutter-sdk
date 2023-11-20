//
// AACRequestDisposition.h
// AtomicSDK
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AtomicSDK/AACCertificatePin.h>

/**
 A request disposition represents the action that the SDK should take in response to a network request.
 */
@interface AACRequestDisposition: NSObject

- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 The request is allowed to proceed, without any further validation.
 */
+ (instancetype __nonnull)allow;

/**
 The request is allowed to proceed, provided that the hash of its certificate's public key matches one of the pins contained
 in the given set.
 
 @param pinSet The set of valid pins for the given URL.
 */
+ (instancetype __nonnull)allowWithCertificatePins:(NSSet<AACCertificatePin*>* __nonnull)pinSet;

/**
 The request is not allowed to proceed.
 */
+ (instancetype __nonnull)deny;

@end
