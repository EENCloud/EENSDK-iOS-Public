//
//  EENMediaItemBuilder.h
//  EENSDK-iOS
//
//  Created by D. Ianchyk on 19/11/2018.
//  Copyright © 2018 Eagle Eye Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class EENMediaItem;

/*!
 @interface
    EENMediaItemBuilder
 @abstract
    Class which helps to configure and create MediaItem instance.
 */
@interface EENMediaItemBuilder : NSObject

/*!
 @method
    builderForLiveItem:baseUrl:
 @abstract
    Creates builder instance for live item.
 @param
    cameraId
    Camera Id of camera in system.
 @param
    baseUrl
    Base url of end point.
 @result
    EENMediaItemBuilder instance to be used for EENMediaItem instance building.
 */
+ (EENMediaItemBuilder *)builderForLiveItem:(NSString *)cameraId baseUrl:(NSString *)baseUrl;

/*!
 @method
    builderForHistoricalItem:baseUrl:startTime:endTime:
 @abstract
    Creates builder instance for hostorical item.
 @param
 	cameraId
 	Camera Id of camera in system.
 @param
    baseUrl
    Base url of end point.
 @param
    startDate
    Date from which playback should start.
 @param
    endDate
    Date at which playback should end.
 @result
    EENMediaItemBuilder instance to be used for EENMediaItem instance building.
 */
+ (EENMediaItemBuilder *)builderForHistoricalItem:(NSString *)cameraId baseUrl:(NSString *)baseUrl startDate:(NSDate *)startDate endDate:(NSDate *)endDate;

/*!
 @method
 	setApiKey:
 @abstract
 	Configures the builder with a provided API key. Will override previously set value.
 @param
 	apiKey
 	Api key to set at MediaItem instance while building it.
 @result
 	Reference to EENMediaItemBuilder instance itself (to be used for message chaining).
 */
- (EENMediaItemBuilder *)setApiKey:(NSString *)apiKey;

/*!
 @method
    setTitle:
 @abstract
    Configures builder with custom title. Will override previously added title.
 @param
    title
    Title to set at MediaItem instance while building it.
 @result
    Reference to EENMediaItemBuilder instance itself (to be used for message chaining).
 */
- (EENMediaItemBuilder *)setTitle:(NSString *)title;

/*!
 @method
    setDateFormat:
 @abstract
    Configures builder with custom date format. Will override previously added data format.
 @param
    dateFormat
    Date format to set at MediaItem instance while building it.
 @result
    Reference to EENMediaItemBuilder instance itself (to be used for message chaining).
 */
- (EENMediaItemBuilder *)setDateFormat:(NSString *)dateFormat;

/*!
 @method
    setTimeZone:
 @abstract
    Configures builder with custom time zone. Will override previously added time zone.
 @param
    timeZone
    Time zone to set at MediaItem instance while building it.
 @result
    Reference to EENMediaItemBuilder instance itself (to be used for message chaining).
 */
- (EENMediaItemBuilder *)setTimeZone:(NSTimeZone *)timeZone;

/*!
 @method
    build:
 @abstract
    Builds EENMediaItem instance.
 @result
    Returns configuted instanse of EENMediaItem.
 */
- (EENMediaItem *)build;

@end

NS_ASSUME_NONNULL_END
