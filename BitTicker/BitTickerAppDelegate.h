/*
 BitTicker is Copyright 2011 Stephen Oliver
 http://github.com/mrsteveman1
 
 This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation; either version 2 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA 
 */

#import <Cocoa/Cocoa.h>

@class Ticker;
@class StatusItemView;
@class RequestHandler;

@class MtGoxMarket;

#import "BitcoinMarketDelegate.h"

@interface BitTickerAppDelegate : NSObject <NSApplicationDelegate, BitcoinMarketDelegate> {
    MtGoxMarket *market;
    
    NSTimer *tickerTimer;
	NSTimer *walletTimer;
    
    NSMutableArray *stats;
    NSMutableArray *highArray;
    NSMutableArray *lowArray;
	StatusItemView *statusItemView;
	NSStatusItem *_statusItem;

	//fields for each stat
	NSTextField *highValue;
	NSTextField *lowValue;
	NSTextField *volValue;
	NSTextField *buyValue;
	NSTextField *sellValue;
	NSTextField *lastValue;
    
    NSTextField *spreadValue;
    
	NSNumber *high;
    NSNumber *low;
    NSNumber *vol;
    NSNumber *buy;
    NSNumber *sell;
    NSNumber *last;
    
    NSNumber *spread;

	NSView *statsView;
	NSMenuItem *statsItem;
    
    NSView *technicalsView;
    NSMenuItem *technicalsItem;
	
	// below the line
	NSMenuItem *quitItem;
    NSMenuItem *aboutItem;
	NSMenuItem *settingsItem;
    NSMenuItem *refreshItem;
	NSMenuItem *preferenceItem;
	
	NSMenu *trayMenu;
    
    NSNumberFormatter *currencyFormatter;
	
	//Settings
	NSString *username;
	NSString *password;
	NSString *selected_market;
	
	//User interface stuff
	IBOutlet NSWindow *settings_window;
	IBOutlet NSTextField *username_field;
	IBOutlet NSSecureTextField *password_field;
	IBOutlet NSComboBox *market_selector;
}

- (void) quitProgram:(id)sender;
- (void)refreshTicker:(id)sender;
- (IBAction)showSettings:(id)sender;
- (IBAction)showAbout:(id)sender;
@property (retain) NSString *username;
@property (retain) NSString *password;
@property (retain) NSString *selected_market;
@property (retain, nonatomic) NSNumber *tickerValue;
@property (retain) NSMutableArray *stats;
@property (nonatomic) NSInteger cancelThread;

@end
