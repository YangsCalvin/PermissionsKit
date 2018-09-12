//
//  MPPermissionsKit.h
//  PermissionsKit
//
//  Created by Sergii Kryvoblotskyi on 9/12/18.
//  Copyright © 2018 MacPaw. All rights reserved.
//

@import Foundation;

#import "MPPermissionType.h"
#import "MPAuthorizationStatus.h"

NS_ASSUME_NONNULL_BEGIN

@interface MPPermissionsKit : NSObject

/**
 Requests current authorization status for a given type.

 @param permissionType MPPermissionType
 @return MPAuthorizationStatus
 */
+ (MPAuthorizationStatus)authorizationStatusForPermissionType:(MPPermissionType)permissionType;

/**
 Requests user authorization for a given permission. Completion will be invoked with a user decision. Completion queue is undefined.
 Important Note: The will be no completion when requesting MPPermissionTypeFullDiskAccess, because its status is unknown. You should implement your own callback mechanism, for example - polling authorization.

 @param permissionType MPPermissionType
 @param completionHandler void (^)(MPAuthorizationStatus status)
 */
+ (void)requestAuthorizationForPermissionType:(MPPermissionType)permissionType withCompletion:(void (^)(MPAuthorizationStatus status))completionHandler;

@end

NS_ASSUME_NONNULL_END
