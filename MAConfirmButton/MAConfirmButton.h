//  
//  MAConfirmButton.h
//  
//  Created by Mike on 11-03-28.
//  Copyright 2011 Mike Ahmarani. All rights reserved.
//  
//  Additions and improvements:
//  Copyright 2012 Wolter Group New York, Inc., All rights reserved.
//  

#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

@class MAConfirmButtonOverlayView;
@protocol MAConfirmButtonDelegate;

typedef enum {
  MAConfirmButtonToggleAnimationLeft = 0,
  MAConfirmButtonToggleAnimationRight = 1
} MAConfirmButtonToggleAnimation;

@interface MAConfirmButton : UIButton {

@private
	BOOL selected;
	BOOL confirmed;
	CALayer *colorLayer;
	CALayer *darkenLayer;
	MAConfirmButtonOverlayView *cancelOverlay;
	id representedObject;
	id <MAConfirmButtonDelegate> delegate;
	
}

@property (nonatomic, assign) MAConfirmButtonToggleAnimation toggleAnimation;
@property (nonatomic, retain) id representedObject;
@property (nonatomic, assign) id <MAConfirmButtonDelegate> delegate;

+ (MAConfirmButton *)buttonWithTitle:(NSString *)titleString confirm:(NSString *)confirmString;
+ (MAConfirmButton *)buttonWithDisabledTitle:(NSString *)disabledString;

- (id)initWithTitle:(NSString *)titleString confirm:(NSString *)confirmString;
- (id)initWithDisabledTitle:(NSString *)disabledString;
- (void)disableWithTitle:(NSString *)disabledString;
- (void)setAnchor:(CGPoint)anchor;
- (void)setTintColor:(UIColor *)color;

@end

@protocol MAConfirmButtonDelegate <NSObject>
@optional

-(UIView *)confirmButtonSuperviewForCancelOverlay:(MAConfirmButton *)confirmButton;

@end


