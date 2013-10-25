//
//  StalledAppDelegate.m
//  Stalled
//
//  Created by jeff on 11/19/09.
//  Copyright Jeff LaMarche 2009. All rights reserved.
//

#import "StalledAppDelegate.h"
#import "StalledViewController.h"

@implementation StalledAppDelegate

@synthesize window;
@synthesize viewController;


- (void)applicationDidFinishLaunching:(UIApplication *)application {    
    
    // Override point for customization after app launch    
    [window addSubview:viewController.view];
    [window makeKeyAndVisible];
}


- (void)dealloc {
    [viewController release];
    [window release];
    [super dealloc];
}


@end
