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
        static let AppId     = "357fee36746668573ceb2f5957c4869ee1a62a112639bac9b0fae43c7c431692"
        static let AppSecret = "80ae1420e164e0440d5329067bcdd953e9fa6c63b75c001c06d169a4f11268c5"
        static let Vuforia   = "ATQqCM7/////AAAAGXLs+GRi0UwXh0X+/qQL49dbZGym8kKo+iRtgC95tbJoCWjXXZihDl5pzxoca2JxLcYxBJ2pIeIE4dNcK0etMeb1746L7lq6vSFen43cS7P1P/HXjwHtUouV5Xus2U0F7WHUTKuO629jKFO13fBQczuY52UJcSEhsu9jHPMaupo5CpqQT3TFTQjlhzHhVXiVMEqq7RI+Edwh8TCSfGAbNRdbIELTfK+8YDYqwEHDbp62mFrs68YnCEQZDrpcLyC8WzFCVZtnUq3Cj3YBUfQ6gNnENYiuLf06gAAF/FcaF65VYveGRBbp3hpkqolX28bxPiUYNVknCSFXICPHciVntxF+rcHW5rrX7Cg/IVFGdNRF"
    }
}
