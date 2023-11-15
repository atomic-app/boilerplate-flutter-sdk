//
// AACFeatureFlags.h
// AtomicSDK
// Copyright © 2020 Atomic.io Limited. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Represents features that can be turned on or off in the Atomic SDK.
 */
@interface AACFeatureFlags: NSObject <NSCopying>

/**
 Whether the `runtime-vars-updated` analytics event, which includes resolved values of each
 runtime variable, should be sent when runtime variables are resolved. Defaults to `NO`.
 
 When setting this flag to `YES`, ensure that the resolved values of your runtime variables
 do not include any sensitive information that should not appear in analytics.
 */
@property (nonatomic) BOOL runtimeVariableAnalytics;

@end
