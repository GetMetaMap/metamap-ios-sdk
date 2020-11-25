//
//  AppDelegate.swift
//  MatiKYCSDKDemoSwift
//
//  Created by Suren Poghosyan on 3/27/19.
//  Copyright © 2019 Suren Poghosyan. All rights reserved.
//

import UIKit
import MatiGlobalIDSDK

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {

    var window: UIWindow?

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        // You can put your client id here instead
        MFKYC.register(clientId:"5c7f82b7407f0e21e74ac043")
        
        
        
        return true
    }

}

