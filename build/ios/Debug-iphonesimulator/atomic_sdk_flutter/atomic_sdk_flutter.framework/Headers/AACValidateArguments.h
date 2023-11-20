//
//  AACValidateArguments.h
//  atomic_sdk_flutter
//
//  Created by Eric on 23/10/21.
//

#import "AACFlutterLogger.h"

static BOOL AACValidateArgumentsImpl(id arguments, NSArray<Class>* types) {
    if([arguments isKindOfClass:NSArray.class] == NO) {
        [AACFlutterLogger log:@"Argument validation failed: expected NSArray but received %@.", arguments];
        return NO;
    }
    
    NSArray *args = (NSArray*)arguments;
    
    // Check we have the right number of arguments.
    if(args.count != types.count) {
        [AACFlutterLogger log:@"Argument validation failed: count mismatch. Expected %@ arguments but received %@.", @(types.count), @(args.count)];
        return NO;
    }
    
    // Check each argument is of the correct type.
    for(int i = 0; i < args.count; i++) {
        if([args[i] isKindOfClass:types[i]] == NO) {
            [AACFlutterLogger log:@"Argument validation failed: argument at index %@ was not of type %@, got %@ instead.", @(i), NSStringFromClass(types[i]), args[i]];
            return NO;
        }
    }
    
    return YES;
};
#define AACValidateArguments(args, types, result) if(AACValidateArgumentsImpl(args, types) == NO) { result(@(NO)); return; }

