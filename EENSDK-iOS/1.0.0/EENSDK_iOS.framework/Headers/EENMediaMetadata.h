//
//  EENMediaMetadata.h
//  EENSDK-iOS
//
//  Created by D. Ianchyk on 19/11/2018.
//  Copyright © 2018 Eagle Eye Networks. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 @interface
    EENMediaMetadata
 @abstract
    Class which holds loaded metadata for currently played media item.
 */
@interface EENMediaMetadata : NSObject

/*!
 @property
    header
 @abstract
    Indicates header of media item.
 */
@property (readonly) NSData *header;

/*!
 @property
    startDate
 @abstract
    Indicates start date of media item.
 */
@property (readonly) NSDate *startDate;

/*!
 @property
    duration
 @abstract
    Indicates duration of media item.
 */
@property (readonly) NSTimeInterval duration;

@end

NS_ASSUME_NONNULL_END
