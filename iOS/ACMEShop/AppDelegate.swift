//
//  AppDelegate.swift
//  ACMEShop
//
//  Created by jerome on 13/10/2016.
//  Copyright © 2016 Augment. All rights reserved.
//

import UIKit

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
        /**
         * Init Augment SDK with our AppId / AppSecret keys
         */
        AGTAugmentSDK.setSharedClientID(ACMEShop.Augment.AppId, sharedClientSecret: ACMEShop.Augment.AppSecret, sharedVuforiaKey: ACMEShop.Augment.Vuforia)
        
        return true
    }
}

