//
//  ViewController.swift
//  MatiKYCSDKDemoSwift
//
//  Created by Suren Poghosyan on 3/27/19.
//  Copyright © 2019 Suren Poghosyan. All rights reserved.
//

import UIKit
import MatiSDK

class ViewController: UIViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        self.setupMatiButton()
    }
    
    private func setupMatiButton() {
        //init button
        let matiButton = MatiButton()
        
        //set params to your button
        matiButton.setParams(clientId: "YOUR_CLIENT_ID", flowId: "YOUR_FLOW_ID", metadata: ["key1": "value1"])
        
        //set view of button
        matiButton.frame = CGRect(x: 20, y: self.view.frame.size.height/2 - 50, width: view.frame.size.width - 40, height: 50)
        
        //add button to yours view
        view.addSubview(matiButton)
        
        //set delegate to get result
        MatiButtonResult.shared.delegate = self
    }

}

//MARK: MatiButtonResultDelegate
extension ViewController: MatiButtonResultDelegate {
    func verificationSuccess(identityId: String) {
        print("Mati Verification Success \(identityId)")
    }
    
    func verificationCancelled() {
        print("Mati Verification Cancelled")
    }
}

