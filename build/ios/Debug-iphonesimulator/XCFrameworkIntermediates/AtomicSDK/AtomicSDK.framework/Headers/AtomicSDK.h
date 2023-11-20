//
// AtomicSDK.h
// Atomic SDK
// Copyright © 2019 Atomic.io Limited. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for Atomic SDK.
FOUNDATION_EXPORT double AtomicSDKVersionNumber;

//! Project version string for Atomic SDK.
FOUNDATION_EXPORT const unsigned char AtomicSDKVersionString[];

#if __IPHONE_OS_VERSION_MIN_REQUIRED < __IPHONE_10_0
#error The Atomic SDK supports iOS 10.0 and above.
#endif

#import <AtomicSDK/AACSessionDelegate.h>
#import <AtomicSDK/AACRuntimeVariableDelegate.h>
#import <AtomicSDK/AACCardEventDelegate.h>
#import <AtomicSDK/AACCardEvent.h>
#import <AtomicSDK/AACEventPayload.h>
#import <AtomicSDK/AACEventResponse.h>

#import <AtomicSDK/AACConfiguration.h>
#import <AtomicSDK/AACFeatureFlags.h>
#import <AtomicSDK/AACSingleCardConfiguration.h>
#import <AtomicSDK/AACHorizontalContainerConfiguration.h>
#import <AtomicSDK/AACStreamContainerViewController.h>
#import <AtomicSDK/AACSession.h>
#import <AtomicSDK/AACStreamContainerActionDelegate.h>
#import <AtomicSDK/AACPushNotification.h>
#import <AtomicSDK/AACCardCustomAction.h>

#import <AtomicSDK/AACCardInstance.h>
#import <AtomicSDK/AACCardRuntimeVariable.h>
#import <AtomicSDK/AACSingleCardView.h>
#import <AtomicSDK/AACHorizontalContainerView.h>

#import <AtomicSDK/AACRequestDelegate.h>
#import <AtomicSDK/AACRequestDisposition.h>
#import <AtomicSDK/AACCertificatePin.h>

#import <AtomicSDK/AACCardFilter.h>

#import <AtomicSDK/AACEmbeddedFont.h>
#import <AtomicSDK/AACUserMetrics.h>

#import <AtomicSDK/AACCustomEvent.h>
