//
//  PixelBufferDelegate.h
//  EENSDK-iOS
//
//  Created by Greg Slomin on 2/3/20.
//  Copyright © 2020 D. Ianchyk. All rights reserved.
//

#ifndef PixelBufferDelegate_h
#define PixelBufferDelegate_h
#import <CoreMedia/CoreMedia.h>

@class EENMediaPlayer;

@protocol  EENMediaPlayerPixelBufferDelegate <NSObject>

-(CVPixelBufferRef)mediaPlayer:(EENMediaPlayer*)mediaPlayer didOutputPixelBuffer:(CVImageBufferRef)pixelBuffer atTimestamp:(CMTime)pts withClock:(CMTimebaseRef)timebase usingESN:(NSString*)esn;

@end
#endif /* PixelBufferDelegate_h */
