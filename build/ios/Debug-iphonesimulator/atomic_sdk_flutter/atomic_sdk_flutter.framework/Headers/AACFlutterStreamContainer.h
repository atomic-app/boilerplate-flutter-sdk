//
// AACFlutterStreamContainer.h
// Atomic SDK - Flutter
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Flutter/Flutter.h>
#import "AACFlutterView.h"
#import "AACFlutterViewFactory.h"

/**
 Factory responsible for creating stream containers in Flutter.
 */
@interface AACFlutterStreamContainerFactory: AACFlutterViewFactory

@end

/**
 View that wraps a stream container view controller in the Atomic SDK, for use in Flutter.
 */
@interface AACFlutterStreamContainer: AACFlutterView

@end
