//
// AACCertificatePin.h
// AtomicSDK
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 A certificate pin is composed of a base64-encoded SHA-256 hash of a certificate's "Subject Public Key Info".
 */
@interface AACCertificatePin: NSObject

- (instancetype __nonnull)init NS_UNAVAILABLE;

/**
 Creates a certificate pin representing the given base64-encoded, SHA-256 hash of
 a certificate's public key info.
 
 @param hash The public key's SHA-256 hash, encoded as a base64 string.
 */
+ (instancetype __nonnull)pinWithSha256Hash:(NSString* __nonnull)hash;

@end
