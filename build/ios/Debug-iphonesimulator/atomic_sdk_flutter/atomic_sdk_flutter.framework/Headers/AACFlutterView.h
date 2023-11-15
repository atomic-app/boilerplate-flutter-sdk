//
// AACFlutterView.h
// Atomic SDK - Flutter
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>
@import Flutter;
@import AtomicSDK;
@import UIKit;

/**
 Base view for Atomic stream containers or single card views.
 */
@interface AACFlutterView: NSObject <FlutterPlatformView, AACStreamContainerActionDelegate, AACCardEventDelegate, AACRuntimeVariableDelegate>

/**
 Method channel used to communicate from the native view back to Flutter.
 */
@property (nonatomic, strong, readonly) FlutterMethodChannel *channel;

/**
 Identifier for this view instance, used internally by the Flutter wrapper.
 */
@property (nonatomic, copy, readonly) NSString *viewType;

/**
 Creates a new view that wraps an Atomic stream container or single card view.
 
 @param frame The frame to use for the container or single card view.
 @param viewId Used to identify the unique view instance for Flutter.
 @param args Creation params supplied to the view when created.
 @param messenger Binary messenger used to establish message channels in Flutter.
 */
- (instancetype)initWithFrame:(CGRect)frame
               viewIdentifier:(int64_t)viewId
                    arguments:(id)args
              binaryMessenger:(NSObject<FlutterBinaryMessenger>*)messenger;

/**
 Overridden by subclasses to generate a native view for a stream container or single card view.
 */
- (void)createViewWithFrame:(CGRect)frame
                containerId:(NSString*)containerId
              configuration:(AACConfiguration*)configuration;

/**
 Returns the Flutter app's root view controller.
 */
- (UIViewController*)rootViewController;

/**
 Applies the specified filter to the card list, showing only cards that match this filter.
 */
- (void)applyFilter:(AACCardFilter*)filter;

/**
 Instructs the stream container to check for new cards immediately.
 */
-(void)refresh;

@end
