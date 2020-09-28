//
//  ViewController.swift
//  MatiKYCSDKDemoSwift
//
//  Created by Suren Poghosyan on 3/27/19.
//  Copyright © 2019 Suren Poghosyan. All rights reserved.
//

import UIKit
import MatiGlobalIDSDK

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.setupMatiButton()
    }
    
    private func setupMatiButton() {
        //init button
        let matiButton = MFKYCButton()
       
        // If you want to work with specific flow, please add "flowId" parameter.
       // matiButton.flowId = "7e8zf446aa5b5e001a7769d0"
        
        //view button
        matiButton.frame = CGRect(x: 20, y: self.view.frame.size.height/2 - 50, width: view.frame.size.width - 40, height: 50)
        
        //add button to yours view
        view.addSubview(matiButton)
        
        //set delegate
        MFKYC.instance.delegate = self
    }

}

//MARK: MFKYCDelegate
extension ViewController: MFKYCDelegate {
    func mfKYCLoginSuccess(identityId: String) {
       print("Mati Login Success")
    }
    
    func mfKYCLoginCancelled() {
        print("Mati Login Cancelled")
    }
}
