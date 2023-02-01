//
//  EENMediaItem.h
//  EENSDK-iOS
//
//  Created by D. Ianchyk on 19/11/2018.
//  Copyright © 2018 Eagle Eye Networks. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EENMediaItemBuilder.h"

NS_ASSUME_NONNULL_BEGIN

/*!
 @interface
    EENMediaItem
 @abstract
    Class which represents media item to be played.
 */
@interface EENMediaItem : NSObject

/*!
 @property
 	cameraId
 @abstract
 	Represents the camera ID.
 */
@property (readonly) NSString *cameraId;

/*!
 @property
 	baseUrl
 @abstract
 	Represents the base URL of the video stream.
 */
@property (readonly) NSString *baseUrl;

/*!
 @property
 	apiKey
 @abstract
 	Represents the API key of the authorized user.
 */
@property (readonly) NSString *apiKey;

/*!
 @property
    title
 @abstract
    Represents the title being shown in navigation bar.
 */
@property (readonly) NSString *title;

/*!
 @property
    startDate
 @abstract
    Represents the start date of the stream in Greenwich time (GMT+0). Will be nil for the item representing live stream.
 */
@property (readonly) NSDate *startDate;

/*!
 @property
    endDate
 @abstract
    Represents the end date of the stream in Greenwich time (GMT+0). Will be nil for the item representing live stream.
 */
@property (readonly) NSDate *endDate;

/*!
 @property
 	dateFormat
 @abstract
 	Represents the date format of the current playback time being shown in navigation bar.
 */
@property (readonly) NSString *dateFormat;

/*!
 @property
    timeZone
 @abstract
    Represents the time zone of the current playback time being shown in navigation bar.
 */
@property (readonly) NSTimeZone *timeZone;

/*!
 @property
 isLiveItem
 @abstract
	Tells if the played item is a live item
 */
@property (nonatomic, assign) BOOL isLiveItem;

@end

NS_ASSUME_NONNULL_END
