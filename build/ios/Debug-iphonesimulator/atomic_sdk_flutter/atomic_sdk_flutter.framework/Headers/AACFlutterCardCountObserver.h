//
// AACFlutterCardCountObserver.h
// Atomic SDK - Flutter
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AACFlutterSessionDelegate.h"

/**
 Object that wraps a native iOS SDK card count observer, for use in Flutter.
 */
@interface AACFlutterCardCountObserver: NSObject

/// Identifier used by the Flutter wrapper to distinguish card count observers.
@property (nonatomic, copy) NSString *identifier;

/// Native object used when observing card counts, used when interacting with the iOS SDK.
@property (nonatomic, strong) id<NSObject> token;

@end
