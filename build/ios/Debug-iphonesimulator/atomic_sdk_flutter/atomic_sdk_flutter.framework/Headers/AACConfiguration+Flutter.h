//
// AACConfiguration+Flutter.h
// Atomic SDK - Flutter
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

@import AtomicSDK;

@interface AACConfiguration (Flutter)

/**
 Converts the provided dictionary instance from Flutter to a configuration object that can be used by
 the Atomic SDK.
 */
+ (AACConfiguration *)fromFlutterDictionary:(NSDictionary *)dict;

@end
