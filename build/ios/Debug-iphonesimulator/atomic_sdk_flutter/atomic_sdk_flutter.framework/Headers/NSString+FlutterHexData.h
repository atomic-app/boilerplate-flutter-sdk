//
// NSString+FlutterHexData.h
// Atomic SDK - Flutter
// Copyright © 2021 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (FlutterHexData)

/**
 Scans each character in this string, converting it to a hexidecimal digit,
 and returning the result as an NSData instance.
 
 If a character does not represent a valid hex digit, the character is skipped.
 */
- (NSData*)aacFlutter_dataFromHexString;

@end
