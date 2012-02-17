//
//  AppDelegate.m
//  Meo Remote
//
//  Created by Diogo Gomes on 23/01/12.
//  Copyright (c) 2012 Universidade de Aveiro. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

@synthesize window = _window;

void pressButton(int button)
{
    NSLog(@"pressed %d", button);
    dispatch_async(dispatch_get_global_queue(0, 0), ^{
        pressIRButton(button);
    });
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Insert code here to initialize your application
}

- (IBAction)Power:(NSButton *)sender {
    pressButton(BUTTON_POWER);
    
}

- (IBAction)Number1:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_1);
}

- (IBAction)Number2:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_2);
}

- (IBAction)Number3:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_3);
}

- (IBAction)Number4:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_4);
}

- (IBAction)Number5:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_5);
}

- (IBAction)Number6:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_6);
}

- (IBAction)Number7:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_7);
}

- (IBAction)Number8:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_8);
}

- (IBAction)Number9:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_9);
}

- (IBAction)Number0:(NSButton *)sender {
    pressButton(BUTTON_NUMBER_9);
}

- (IBAction)VolUp:(NSButton *)sender {
    pressButton(BUTTON_VOLUP);
}

- (IBAction)VolDown:(NSButton *)sender {
    pressButton(BUTTON_VOLDOWN);
}

- (IBAction)ProgUp:(NSButton *)sender {
    pressButton(BUTTON_PROGUP);
}

- (IBAction)ProgDown:(NSButton *)sender {
    pressButton(BUTTON_PROGDOWN);
}

- (IBAction)Up:(NSButton *)sender {
    pressButton(BUTTON_UP);
}

- (IBAction)Down:(NSButton *)sender {
    pressButton(BUTTON_DOWN);
}

- (IBAction)Ok:(NSButton *)sender {
    pressButton(BUTTON_OK);
}

- (IBAction)Left:(NSButton *)sender {
    pressButton(BUTTON_LEFT);
}

- (IBAction)Right:(NSButton *)sender {
    pressButton(BUTTON_RIGHT);
}


@end
