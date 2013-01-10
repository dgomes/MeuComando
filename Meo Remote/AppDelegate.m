//
//  AppDelegate.m
//  Meo Remote
//
//  Created by Diogo Gomes on 23/01/12.
//  Copyright (c) 2012 Diogo Gomes. All rights reserved.
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
    searchSTB();
}

- (void)applicationWillTerminate:(NSNotification *)notification {
    NSLog(@"Over and Out");
}

- (void) applicationDidBecomeActive:(NSNotification *)notification
{
//    [[_window standardWindowButton:NSWindowCloseButton] setHidden:YES];
//    [[_window standardWindowButton:NSWindowZoomButton] setHidden:YES];
//    [[_window standardWindowButton:NSWindowMiniaturizeButton] setFrame:[_window standardWindowButton:NSWindowCloseButton].frame];
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
    pressButton(BUTTON_NUMBER_0);
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

- (IBAction)Red:(NSButton *)sender {
    pressButton(BUTTON_RED);
}

- (IBAction)Green:(NSButton *)sender {
    pressButton(BUTTON_GREEN);
}

- (IBAction)Yellow:(NSButton *)sender {
    pressButton(BUTTON_YELLOW);
}

- (IBAction)Blue:(NSButton *)sender {
    pressButton(BUTTON_BLUE);
}

- (IBAction)Menu:(NSButton *)sender {
    pressButton(BUTTON_MENU);
}

- (IBAction)Back:(NSButton *)sender {
    pressButton(BUTTON_BACK);
}
- (IBAction)Output:(NSButton *)sender {
    pressButton(BUTTON_SCREEN);
}
- (IBAction)GuiaTV:(NSButton *)sender {
    pressButton(BUTTON_GUIA);
}
- (IBAction)VideoClube:(NSButton *)sender {
    pressButton(BUTTON_VOD);
}

- (IBAction)Info:(NSButton *)sender {
    pressButton(BUTTON_INFO);
}
- (IBAction)Switch:(NSButton *)sender {
    pressButton(BUTTON_SWITCH);
}
- (IBAction)Gravacoes:(NSButton *)sender {
    pressButton(BUTTON_GRAV);
}

- (IBAction)Stop:(NSButton *)sender {
    pressButton(BUTTON_STOP);
}
- (IBAction)PlayPause:(NSButton *)sender {
    pressButton(BUTTON_PLAYPAUSE);
}
- (IBAction)Rec:(NSButton *)sender{
    pressButton(BUTTON_REC);
}

- (IBAction)Prev:(NSButton *)sender{
    pressButton(BUTTON_PREV);
}
- (IBAction)Backward:(NSButton *)sender {
    pressButton(BUTTON_RWD);
}
- (IBAction)Forward:(NSButton *)sender {
    pressButton(BUTTON_FWD);
}
- (IBAction)Next:(NSButton *)sender {
    pressButton(BUTTON_NEXT);
}

- (IBAction)Mute:(NSButton *)sender {
    pressButton(BUTTON_MUTE);
}
- (IBAction)Options:(NSButton *)sender {
    pressButton(BUTTON_OPTS);
}
@end
