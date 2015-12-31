//
//   Copyright 2012 Square Inc.
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//

#import <Foundation/Foundation.h>
#import <Security/SecCertificate.h>

typedef NS_ENUM(NSInteger, InteageSRReadyState) {
    INTEAGE_SR_CONNECTING   = 0,
    INTEAGE_SR_OPEN         = 1,
    INTEAGE_SR_CLOSING      = 2,
    INTEAGE_SR_CLOSED       = 3,
};

typedef enum InteageSRStatusCode : NSInteger {
    InteageSRStatusCodeNormal = 1000,
    InteageSRStatusCodeGoingAway = 1001,
    InteageSRStatusCodeProtocolError = 1002,
    InteageSRStatusCodeUnhandledType = 1003,
    // 1004 reserved.
    InteageSRStatusNoStatusReceived = 1005,
    // 1004-1006 reserved.
    InteageSRStatusCodeInvalidUTF8 = 1007,
    InteageSRStatusCodePolicyViolated = 1008,
    InteageSRStatusCodeMessageTooBig = 1009,
} InteageSRStatusCode;

@class InteageSRWebSocket;

extern NSString *const InteageSRWebSocketErrorDomain;
extern NSString *const InteageSRHTTPResponseErrorKey;

#pragma mark - InteageSRWebSocketDelegate

@protocol InteageSRWebSocketDelegate;

#pragma mark - InteageSRWebSocket

@interface InteageSRWebSocket : NSObject <NSStreamDelegate>

@property (nonatomic, weak) id <InteageSRWebSocketDelegate> delegate;

@property (nonatomic, readonly) InteageSRReadyState readyState;
@property (nonatomic, readonly, retain) NSURL *url;


@property (nonatomic, readonly) CFHTTPMessageRef receivedHTTPHeaders;

// Optional array of cookies (NSHTTPCookie objects) to apply to the connections
@property (nonatomic, readwrite) NSArray * requestCookies;

// This returns the negotiated protocol.
// It will be nil until after the handshake completes.
@property (nonatomic, readonly, copy) NSString *protocol;

// Protocols should be an array of strings that turn into Sec-WebSocket-Protocol.
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURLRequest:(NSURLRequest *)request protocols:(NSArray *)protocols;
- (id)initWithURLRequest:(NSURLRequest *)request;

// Some helper constructors.
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols allowsUntrustedSSLCertificates:(BOOL)allowsUntrustedSSLCertificates;
- (id)initWithURL:(NSURL *)url protocols:(NSArray *)protocols;
- (id)initWithURL:(NSURL *)url;

// Delegate queue will be dispatch_main_queue by default.
// You cannot set both OperationQueue and dispatch_queue.
- (void)setDelegateOperationQueue:(NSOperationQueue*) queue;
- (void)setDelegateDispatchQueue:(dispatch_queue_t) queue;

// By default, it will schedule itself on +[NSRunLoop SR_networkRunLoop] using defaultModes.
- (void)scheduleInRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;
- (void)unscheduleFromRunLoop:(NSRunLoop *)aRunLoop forMode:(NSString *)mode;

// InteageSRWebSockets are intended for one-time-use only.  Open should be called once and only once.
- (void)open;

- (void)close;
- (void)closeWithCode:(NSInteger)code reason:(NSString *)reason;

// Send a UTF8 String or Data.
- (void)send:(id)data;

// Send Data (can be nil) in a ping message.
- (void)sendPing:(NSData *)data;

@end

#pragma mark - InteageSRWebSocketDelegate

@protocol InteageSRWebSocketDelegate <NSObject>

// message will either be an NSString if the server is using text
// or NSData if the server is using binary.
- (void)webSocket:(InteageSRWebSocket *)webSocket didReceiveMessage:(id)message;

@optional

- (void)webSocketDidOpen:(InteageSRWebSocket *)webSocket;
- (void)webSocket:(InteageSRWebSocket *)webSocket didFailWithError:(NSError *)error;
- (void)webSocket:(InteageSRWebSocket *)webSocket didCloseWithCode:(NSInteger)code reason:(NSString *)reason wasClean:(BOOL)wasClean;
- (void)webSocket:(InteageSRWebSocket *)webSocket didReceivePong:(NSData *)pongPayload;

@end

#pragma mark - NSURLRequest (InteageCertificateAdditions)

@interface NSURLRequest (InteageCertificateAdditions)

@property (nonatomic, retain, readonly) NSArray *SR_SSLPinnedCertificates;

@end

#pragma mark - NSMutableURLRequest (InteageCertificateAdditions)

@interface NSMutableURLRequest (InteageCertificateAdditions)

@property (nonatomic, retain) NSArray *SR_SSLPinnedCertificates;

@end

#pragma mark - NSRunLoop (InteageSRWebSocket)

@interface NSRunLoop (InteageSRWebSocket)

+ (NSRunLoop *)SR_networkRunLoop;

@end
