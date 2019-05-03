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
    esn
    Esn of camera in system.
 @param
    baseUrl
    Base url of end point.
 @result
    EENMediaItemBuilder instance to be used for EENMediaItem instance building.
 */
+ (EENMediaItemBuilder *)builderForLiveItem:(NSString *)esn baseUrl:(NSString *)baseUrl;

/*!
 @method
    builderForHistoricalItem:baseUrl:startTime:endTime:
 @abstract
    Creates builder instance for hostorical item.
 @param
    esn
    Esn of camera in system.
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
+ (EENMediaItemBuilder *)builderForHistoricalItem:(NSString *)esn baseUrl:(NSString *)baseUrl startDate:(NSDate *)startDate endDate:(NSDate *)endDate;

/*!
 @method
    addTitle:
 @abstract
    Configures builder with custom title. Will override previously added title.
 @param
    title
    Title to set at MediaItem instance while building it.
 @result
    Reference to EENMediaItemBuilder instance itself (to be used for message chaining).
 */
- (EENMediaItemBuilder *)addTitle:(NSString *)title;

/*!
 @method
    addDateFormat:
 @abstract
    Configures builder with custom date format. Will override previously added data format.
 @param
    dateFormat
    Date format to set at MediaItem instance while building it.
 @result
    Reference to EENMediaItemBuilder instance itself (to be used for message chaining).
 */
- (EENMediaItemBuilder *)addDateFormat:(NSString *)dateFormat;

/*!
 @method
    addTimeZone:
 @abstract
    Configures builder with custom time zone. Will override previously added time zone.
 @param
    timeZone
    Time zone to set at MediaItem instance while building it.
 @result
    Reference to EENMediaItemBuilder instance itself (to be used for message chaining).
 */
- (EENMediaItemBuilder *)addTimeZone:(NSTimeZone *)timeZone;

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
