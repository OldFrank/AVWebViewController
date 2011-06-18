//
//  AVWebViewController.h
//
//  Created by Abraham Vegh on 6/12/11.
//  Copyright 2011 Abraham Vegh. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>


@class AVWebViewController;
@protocol AVWebViewControllerDelegate

- (NSURLRequest *) webViewController:(AVWebViewController *)controller shouldStartLoadingURLRequest:(NSURLRequest *)aRequest navigationType:(UIWebViewNavigationType)navigationType;
//	Return aRequest to say yes
//	Return nil to cancel the operation
//	If a new request is returned, we’ll load something different from that request instead

- (void) webViewControllerDidStartLoading:(AVWebViewController *)controller;
- (void) webViewControllerDidFinishLoading:(AVWebViewController *)controller;
- (void) webViewControllerDidFailLoading:(AVWebViewController *)controller withError:(NSError *)anError;
//	These are just piped up stock methods

@end


@interface AVWebViewController : UIViewController <UIWebViewDelegate, UIActionSheetDelegate, MFMailComposeViewControllerDelegate>
{
	NSString *_URLString;
@private
	UIWebView *_webView;
	UIBarButtonItem *_backItem;
	UIBarButtonItem *_forwardItem;
	UIActivityIndicatorView *_indicatorView;
	UIBarButtonItem *_indicatorItem;
	UIBarButtonItem *_loadItem;
	UIBarButtonItem *_actionItem;
	UIBarButtonItem *_fixedSpaceItem;
	UIBarButtonItem *_flexibleSpaceItem;
}

@property (nonatomic, copy) NSString *URLString; // Set this to navigate the web view to a new URL

- (id) initWithURLString: (NSString *) URLString;
- (void) reload;

@end
