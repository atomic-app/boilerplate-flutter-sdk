//
// AACFlutterViewFactory.h
// Atomic SDK - Flutter
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
@import Flutter;

/**
 Base view factory for Atomic stream containers or single card views.
 */
@interface AACFlutterViewFactory: NSObject <FlutterPlatformViewFactory>

/**
 Creates a new factory for an Atomic stream container or single card view, using the supplied binary messenger.
 */
- (instancetype)initWithMessenger:(NSObject<FlutterBinaryMessenger>*)messenger;

/**
 The binary messenger to use when communicating back to Flutter.
 */
@property (nonatomic, strong, readonly) NSObject<FlutterBinaryMessenger>* messenger;

@end
