//
//  TXScrollLabelView.h
//
//  Created by tingxins on 2/23/16.
//  Copyright © 2016 tingxins. All rights reserved.
//  滚动视图

#define TX_DEPRECATED(explain) __attribute__((deprecated(explain)))

#import <UIKit/UIKit.h>
#import "UIView+TXFrame.h"

@interface TXScrollLabelView : UIScrollView

typedef NS_ENUM(NSInteger, TXScrollLabelViewType) {
    TXScrollLabelViewTypeLeftRight = 0, //not supports scrollInset.top\bottom\right
    TXScrollLabelViewTypeUpDown,        //not supports scrollInset.top\bottom
    TXScrollLabelViewTypeFlipRepeat,    //not supports scrollInset.top\bottom
    TXScrollLabelViewTypeFlipNoRepeat   //not supports scrollInset.top\bottom
};

/*************WILL BE REMOVED IN FUTURE.********************/
#pragma mark - Deprecated Property
/** Deprecated, please Use `scrollTitle` */
@property (copy, nonatomic) NSString *tx_scrollTitle TX_DEPRECATED("Deprecated, please Use `scrollTitle`");
/** Deprecated, please Use `scrollType` */
@property (assign, nonatomic) TXScrollLabelViewType tx_scrollType TX_DEPRECATED("Deprecated, please Use `scrollType`");
/** Deprecated, please Use `scrollVelocity` */
@property (assign, nonatomic) NSTimeInterval tx_scrollVelocity TX_DEPRECATED("Deprecated, please Use `scrollVelocity`");
/** Deprecated, please Use `frame` */
@property (assign, nonatomic) CGRect tx_scrollContentSize TX_DEPRECATED("Deprecated, please Use `frame`");
/** Deprecated, please Use `scrollTitleColor` */
@property (strong, nonatomic) UIColor *tx_scrollTitleColor TX_DEPRECATED("Deprecated, please Use `scrollTitleColor`");
/*************ALL ABOVE.***********************************/

#pragma mark - On Used Property
/** 滚动文字 */
@property (copy, nonatomic) NSString *scrollTitle;
/** 滚动类型 */
@property (assign, nonatomic) TXScrollLabelViewType scrollType;
/** 滚动速率([1, 10])，单位秒s */
@property (assign, nonatomic) NSTimeInterval scrollVelocity;
/** 文本颜色 */
@property (strong, nonatomic) UIColor *scrollTitleColor;
/** 滚动内部inset */
@property (assign, nonatomic) UIEdgeInsets scrollInset;
/** 每次循环滚动的间距 */
@property (assign, nonatomic) CGFloat scrollSpace;
/** 文字排版 */
@property (assign, nonatomic) NSTextAlignment textAlignment;
/** 字体大小 */
@property (strong, nonatomic) UIFont *font;
//根据内容自适应宽度 Pending!!
@property (assign, nonatomic) BOOL autoWidth;


#pragma mark - Class Methods

- (instancetype)initWithTitle:(NSString *)scrollTitle
                         scrollType:(TXScrollLabelViewType)scrollType
                     scrollVelocity:(NSTimeInterval)scrollVelocity
                            options:(UIViewAnimationOptions)options
                              inset:(UIEdgeInsets)inset;

+ (instancetype)tx_setScrollTitle:(NSString *)scrollTitle;

+ (instancetype)tx_setScrollTitle:(NSString *)scrollTitle
                       scrollType:(TXScrollLabelViewType)scrollType;

+ (instancetype)tx_setScrollTitle:(NSString *)scrollTitle
                       scrollType:(TXScrollLabelViewType)scrollType
                   scrollVelocity:(NSTimeInterval)scrollVelocity;

+ (instancetype)tx_setScrollTitle:(NSString *)scrollTitle
                       scrollType:(TXScrollLabelViewType)scrollType
                   scrollVelocity:(NSTimeInterval)scrollVelocity
                          options:(UIViewAnimationOptions)options;


/**
 类初始化方法
 @param scrollTitle 滚动文本
 @param scrollType 滚动类型
 @param scrollVelocity 滚动速率
 @param options Now, supports the types of TXScrollLabelViewTypeFlipRepeat\NoRepeat only.
 @param inset just edgeInset.
 */
+ (instancetype)tx_setScrollTitle:(NSString *)scrollTitle
                       scrollType:(TXScrollLabelViewType)scrollType
                   scrollVelocity:(NSTimeInterval)scrollVelocity
                          options:(UIViewAnimationOptions)options
                            inset:(UIEdgeInsets)inset;

#pragma mark - Operation Methods
/**
 *  开始滚动
 */
- (void) beginScrolling;
/**
 *  停止滚动
 */
- (void) endScrolling;

/**
 *  暂停滚动(暂不支持恢复)
 */
- (void) pauseScrolling;

@end
