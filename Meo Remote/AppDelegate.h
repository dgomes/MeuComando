//
//  AppDelegate.h
//  Meo Remote
//
//  Created by Diogo Gomes on 23/01/12.
//  Copyright (c) 2012 Diogo Gomes. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#include "IRproxy.h"

@interface AppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;

- (IBAction)min:(id)sender;

void pressButton(int button);

- (IBAction)Power:(NSButton *)sender;

- (IBAction)Number1:(NSButton *)sender;
- (IBAction)Number2:(NSButton *)sender;
- (IBAction)Number3:(NSButton *)sender;
- (IBAction)Number4:(NSButton *)sender;
- (IBAction)Number5:(NSButton *)sender;
- (IBAction)Number6:(NSButton *)sender;
- (IBAction)Number7:(NSButton *)sender;
- (IBAction)Number8:(NSButton *)sender;
- (IBAction)Number9:(NSButton *)sender;

- (IBAction)Number0:(NSButton *)sender;

- (IBAction)VolUp:(NSButton *)sender;
- (IBAction)VolDown:(NSButton *)sender;

- (IBAction)ProgUp:(NSButton *)sender;
- (IBAction)ProgDown:(NSButton *)sender;

- (IBAction)Left:(NSButton *)sender;
- (IBAction)Right:(NSButton *)sender;
- (IBAction)Up:(NSButton *)sender;
- (IBAction)Down:(NSButton *)sender;
- (IBAction)Ok:(NSButton *)sender;

- (IBAction)Menu:(NSButton *)sender;

- (IBAction)Back:(NSButton *)sender;
- (IBAction)Output:(NSButton *)sender;
- (IBAction)GuiaTV:(NSButton *)sender;
- (IBAction)VideoClube:(NSButton *)sender;

- (IBAction)Info:(NSButton *)sender;
- (IBAction)Switch:(NSButton *)sender;
- (IBAction)Gravacoes:(NSButton *)sender;

- (IBAction)Stop:(NSButton *)sender;
- (IBAction)PlayPause:(NSButton *)sender;
- (IBAction)Rec:(NSButton *)sender;

- (IBAction)Prev:(NSButton *)sender;
- (IBAction)Backward:(NSButton *)sender;
- (IBAction)Forward:(NSButton *)sender;
- (IBAction)Next:(NSButton *)sender;

- (IBAction)Red:(NSButton *)sender;
- (IBAction)Green:(NSButton *)sender;
- (IBAction)Yellow:(NSButton *)sender;
- (IBAction)Blue:(NSButton *)sender;

- (IBAction)Mute:(NSButton *)sender;
- (IBAction)Options:(NSButton *)sender;
@end
