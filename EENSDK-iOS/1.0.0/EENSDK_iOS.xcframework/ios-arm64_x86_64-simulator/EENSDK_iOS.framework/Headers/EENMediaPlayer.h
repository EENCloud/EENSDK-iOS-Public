//
//  EENMediaPlayer.h
//  EENSDK-iOS
//
//  Created by D. Ianchyk on 19/11/2018.
//  Copyright © 2018 Eagle Eye Networks. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>


#import "EENMediaItem.h"
#import "EENMediaMetadata.h"

@class EENSDKError;

NS_ASSUME_NONNULL_BEGIN

/*!
 @enum
    EENMediaPlayerStatus
 @abstract
    Indicates status of EENMediaPlayer.
 @constant
    EENMediaPlayerStatusUnknown
    Indicates that the status of the player is not yet known because it has not tried to load or currently loading media resources for playback.
 @constant
    EENMediaPlayerStatusReadyToPlay
    Indicates that the player is ready to play MediaItem instance. Loaded data is described by the fields of the metadata property.
 @constant
    EENMediaPlayerStatusFailed
    Indicates that the player can no longer play MediaItem instance because of an error. The error is described by the value of the failureReason property.
 */
typedef NS_ENUM(NSInteger) {
    EENMediaPlayerStatusUnknown,
    EENMediaPlayerStatusReadyToPlay,
    EENMediaPlayerStatusFailed,
} EENMediaPlayerStatus;

/*!
 @enum
    EENMediaPlayerPlaybackState
 @abstract
    Indicates playback state of EENMediaPlayer.
 @constant
    EENMediaPlayerPlaybackStatePaused
    This state is entered when user pressed pause button. In this state, playback is paused indefinitely and will not resume until user presses play button.
 @constant
    EENMediaPlayerPlaybackStateBuffering
    This state is entered when when sufficient media data has been buffered for playback to proceed.
 @constant
    EENMediaPlayerPlaybackStatePlaying
    In this state, playback is currently progressing. Should playback stall because of insufficient media data, playbackState will change to buffering.
 @constant
 	EENMediaPlayerPlaybackStateStopped
 	In this state playback has ended and the player is paused. Calling play() or toggle the play button will restart the stream.
 */
typedef NS_ENUM(NSInteger) {
    EENMediaPlayerPlaybackStatePaused,
    EENMediaPlayerPlaybackStateBuffering,
    EENMediaPlayerPlaybackStatePlaying,
	EENMediaPlayerPlaybackStateStopped
} EENMediaPlayerPlaybackState;

@class EENMediaPlayer;
/*!
 @protocol
    EENMediaPlayerDelegate
 @abstract
    Interface of object which will receive and process callbacks.
 */
@protocol EENMediaPlayerDelegate <NSObject>

@optional

- (void)mediaPlayer:(EENMediaPlayer*)mediaPlayer onTimeChanged:(NSString*)newTime rawTime:(NSDate*)rawTime;

- (void)mediaPlayer:(EENMediaPlayer*)mediaPlayer onAspectRatioChanged:(CGFloat)aspectRatio;

- (void)mediaPlayer:(EENMediaPlayer*)mediaPlayer onLayerChanged:(CALayer*)newLayer;

/*!
 @method
    mediaPlayer:onStatusChanged:
 @abstract
    Will be called on status change.
 @param
    mediaPlayer
    Instance of EENMediaPlayer which triggered callback.
 @param
    newStatus
    New status of EENMediaPlayer instance.
 @discussion
    For possible values and discussion, see EENMediaPlayerStatus.
 */
- (void)mediaPlayer:(EENMediaPlayer *)mediaPlayer onStatusChanged:(EENMediaPlayerStatus)newStatus;

/*!
 @method
    mediaPlayer:onPlaybackStateChanged:
 @abstract
    Will be called on playback state change.
 @param
    mediaPlayer
    Instance of EENMediaPlayer which triggered callback.
 @param
    newPlaybackState
    New playback state of EENMediaPlayer instance.
 @discussion
    For possible values and discussion, see EENMediaPlayerPlaybackState.
 */
- (void)mediaPlayer:(EENMediaPlayer *)mediaPlayer onPlaybackStateChanged:(EENMediaPlayerPlaybackState)newPlaybackState;

/*!
 @method
    mediaPlayerDonePressed:
 @abstract
    Will be called after done button was pressed.
 @param
    mediaPlayer
    Instance of EENMediaPlayer which triggered callback.
 @discussion
    UI-related interfaces will be separated from EENMediaPlayer class in future versions.
 */
- (void)mediaPlayerDonePressed:(EENMediaPlayer *)mediaPlayer;

@end

/*!
 @interface
    EENMediaPlayer
 @abstract
    Class designed for media playback.
 @discussion
    EENMediaPlayer is responsible for both playback, rendering and controls management, UI-related interfaces will be separated from EENMediaPlayer class in future versions.
    To ensure safe access to EENMediaPlayer instance's nonatomic properties while dynamic changes in playback state may be reported, clients must serialize their access with the receiver's notification queue.
    In the common case, such serialization is naturally achieved by invoking EENMediaPlayer instance's various methods on the main thread or queue.
 */
@interface EENMediaPlayer : UIView

/*!
 @method
    startWithMediaItem:
 @abstract
    Starts stream with provided media item.
 @param
    item
    MediaItem instance to be played by MediaPlayer.
 @discussion
    Use EENMediaItem instance can e created with help of EENMediaItemBuilder class.
 */
- (void)startWithMediaItem:(EENMediaItem *)item;

/*!
 @method
    showControlBar
 @abstract
    Shows control bar.
 @discussion
    UI-related interfaces will be separated from EENMediaPlayer class in future versions.
 */
- (void)showControlBar;

/*!
 @method
    hideControlBar
 @abstract
    Hides control bar.
 @discussion
    UI-related interfaces will be separated from EENMediaPlayer class in future versions.
 */
- (void)hideControlBar;


- (void)enableClipToBounds:(BOOL)isClipped;

- (void)changeVideoGravity:(AVLayerVideoGravity)videoGravity;

- (void)resetZoomLevel;

/*!
 @method
 	play
 @abstract
 	Resumes the stream that is in paused state.
 @discussion
 	The playback state will be changed to either buffering or playing.
 */
- (void)play;

/*!
 @method
 	pause
 @abstract
 	Pauses the stream that is in playing state.
 @discussion
 	The playback state will be changed to paused.
 */
- (void)pause;


/*!
 @method
 	destroy
 @abstract
 	Disposes the resources that were used for streaming video.
 @discussion
 	Player state changes to unknown, playback state changes to paused.
 */
- (void)destroy;

- (void)setColor:(UIColor *)color;

/*!
 @property
     delegate
 @abstract
     Indicates object which will receive and process callbacks.
 */
@property (nonatomic, weak) id<EENMediaPlayerDelegate> delegate;


/*!
 @property
    currentItem
 @abstract
    Indicates currently played item.
 */
@property (readonly) EENMediaItem *currentItem;

/*!
 @property
    metadata
 @abstract
    If status is readyToPlay, this property indicates loaded metadata for current media item.
 */
@property (readonly) EENMediaMetadata *metadata;

/*!
 @property
    status
 @abstract
    Indicates current status of media player.
 */
@property (readonly) EENMediaPlayerStatus status;

/*!
 @property
    failureReason
 @abstract
    If status is failed, this property indicates the error that caused the failure.
 */
@property (readonly) EENSDKError *failureReason;

/*!
 @property
    playbackState
 @abstract
    Indicates current playback state of media item.
 */
@property (readonly) EENMediaPlayerPlaybackState playbackState;

@property (nonatomic, retain) AVSampleBufferDisplayLayer *videoLayer;

@property (nonatomic, assign) AVLayerVideoGravity videoGravity;
@property (nonatomic, assign) BOOL isFullscreen;

@end

NS_ASSUME_NONNULL_END
