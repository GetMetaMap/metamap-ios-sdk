//
//  ViewController.swift
//  MatiKYCSDKDemoSwift
//
//  Created by Suren Poghosyan on 3/27/19.
//  Copyright © 2019 Suren Poghosyan. All rights reserved.
//

import UIKit
import MatiGlobalIDSDK

class ViewController: UIViewController, MFKYCDelegate {
    let matiButton = MFKYCButton()
   
    override func viewDidLoad() {
        super.viewDidLoad()

        view.addSubview(matiButton)
        MFKYC.instance.delegate = self
    }
    
    override func viewWillLayoutSubviews() {
         super .viewWillLayoutSubviews()
        
        matiButton.frame = CGRect(x: 20, y: self.view.frame.size.height/2 - 50, width: view.frame.size.width - 40, height: 68)

    }

    //MARK: MFKYCDelegate
    
    func mfKYCLoginSuccess(identityId: String) {
       print("Mati Login Success")
    }
    
    func mfKYCLoginCancelled() {
        print("Mati Login Cancelled")
    }

}

