//
// AACFlutterLogger.h
// Atomic SDK - Flutter
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AACFlutterLogger: NSObject

/**
 Sets whether debug logging should be enabled within the Flutter wrapper. This can be useful in debug
 builds when integrating the wrapper. Defaults to `NO`. Turning this on or off takes immediate effect.
 
 @param enabled Whether logging should be enabled within the Flutter wrapper.
 */
+ (void)setLoggingEnabled:(BOOL)enabled;

/**
 Sends a log message to the system log, if logging is enabled using the above method.
 
 @param format An NSString format with variable, optional format parameters following it.
 */
+ (void)log:(NSString*)format, ...;

/**
 Logs an error message using the Unified Logging Framework, if logging is enabled using the above method.
 
 Use this method to send out a message indicating a failed situation or action.
 
 @param format An NSString format with variable, optional format parameters following it.
 */
+ (void)error:(NSString*)format, ...;

/**
 Logs a warning message using the Unified Logging Framework, if logging is enabled using the above method.
 
 Use this method to send out a message indicating a situation or event that needs to be
 noticed and examined but is not a failure.
 
 @param format An NSString format with variable, optional format parameters following it.
 */
+ (void)warn:(NSString*)format, ...;

@end
