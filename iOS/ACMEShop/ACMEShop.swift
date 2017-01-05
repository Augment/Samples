//
//  ACMEShop.swift
//  ACMEShop
//
//  Copyright © 2016-present Augment. All rights reserved.
//

import Foundation

/**
 * Config file for the App
 * Please change the AppId / AppSecret and Vuforia keys to match yours
 */
struct ACMEShop {

    /**
     * Augment Player SDK can also be configured with entries in your Info.plist if you want
     * <key>AugmentPlayerSDKKeys</key>
     *   <dict>
     *   <key>VuforiaKey</key>
     *   <string>your-Vuforia-key</string>
     *   <key>clientID</key>
     *   <string>your-client-id</string>
     *   <key>clientSecret</key>
     *   <string>your-client-secret</string>
     * </dict>
     */
    struct Augment {
        static let AppId     = "Please replace this with your own Augment App Id"
        static let AppSecret = "Please replace this with your own Augment App Secret"
        static let Vuforia   = "Please replace this with your own Augment Vuforia Key"
    }
}
