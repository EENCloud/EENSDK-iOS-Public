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
    esn
 @abstract
    Indicates esn of media item.
 */
@property (readonly) NSString *esn;

/*!
 @property
    baseUrl
 @abstract
    Indicates base url of media item.
 */
@property (readonly) NSString *baseUrl;

/*!
 @property
    title
 @abstract
    Indicates title being presented at navigation bar.
 */
@property (readonly) NSString *title;

/*!
 @property
    startDate
 @abstract
    Indicates start date of media item in Greenwich time (GMT+0). Will be nil for item representing live stream.
 */
@property (readonly) NSDate *startDate;

/*!
 @property
    endDate
 @abstract
    Indicates end date of media item in Greenwich time (GMT+0). Will be nil for item representing live stream.
 */
@property (readonly) NSDate *endDate;

/*!
 @property
    dateFormat
 @abstract
    Indicates date format of current playback time being presented at navigation bar.
 */
@property (readonly) NSString *dateFormat;

/*!
 @property
    timeZone
 @abstract
    Indicates time zone of current playback time being presented at navigation bar.
 */
@property (readonly) NSTimeZone *timeZone;

@end

NS_ASSUME_NONNULL_END
