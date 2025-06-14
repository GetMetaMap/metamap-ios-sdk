---
title: "iOS"
excerpt: "Add the MetaMap button to your iOS app."
slug: "ios"
category: 61ae8e8dba577a0010791480
---


| LTS version (Recommended for most users): |Current Version(Latest features)|
|---|---|
| 3.22.8 | 3.22.8 |


# MetaMap iOS Usage Guide

### Requirments
* iOS support min version 13 
* support Swift version 5.7
* SDK download size 30 MB

The following describes how to install and use the MetaMap iOS SDK for your application.

### Install Using CocoaPods

1. Create a Podfile and add the pod `MetaMapSDK`:
```bash
pod 'MetaMapSDK', '3.22.8'
```

2. Update your pods from the terminal
```bash
pod install
```

3. Add the MetaMap button to your App.

Implementation MetaMap button for Swift

```swift
import UIKit
import MetaMapSDK

class ViewController: UIViewController {

	override func viewDidLoad() {
		super.viewDidLoad()
		self.setupMetaMapButton()
	}

    private func setupMetaMapButton() {

      //init button
      let metaMapButton = MetaMapButton()

      //add button action
            metaMapButton.addTarget(self, action: #selector(self.metaMapButtonAction), for: .touchUpInside)

      //set view of button
            metaMapButton.frame = CGRect(x: 20, y: self.view.frame.size.height/2 - 50, width: view.frame.size.width - 40, height: 50)

      //add button to yours view
      view.addSubview(metaMapButton)

      //set delegate to get result
      MetaMapButtonResult.shared.delegate = self

    }

      @objc private func metaMapButtonAction() {
	//set params to showMetaMapFlow
	MetaMap.shared.showMetaMapFlow(clientId: "YOUR_CLIENT_ID",
				flowId: "YOUR_FLOW_ID",
				metadata: ["key1": "value1", "key2": 123])
	}
}

//MARK: MetaMapButtonResultDelegate
extension ViewController: MetaMapButtonResultDelegate {

    func verificationSuccess(identityId: String?, verificationID: String?) {
		print("MetaMap Verification Success \(identityId)")
	}

	func verificationCancelled() {
		print("MetaMap Verification Cancelled")
	}
}
```

Implementation MetaMap button for SwiftUI

```swift

import SwiftUI
import MetaMapSDK
import UIKit

struct ContentView: View {
    var body: some View {
        VStack {
            ZStack {
//MARK: MetaMapDelegateObserver
                MetaMapDelegateObserver { identityId, verificationId in
                    print("\(identityId), \(verificationId)")
                } cancelled: {
                    print("cancelled")
                }
                HStack {
                    Button(action: {
                        MetaMap.shared.showMetaMapFlow(clientId: "YOUR_CLIENT_ID", flowId: "YOUR_FLOW_ID", metadata: ["key1": "value1", "key2": 123])
                    }) {
                        Text("press me")
                    }
                }
            }
        }
    }
}

struct MetaMapDelegateObserver: UIViewControllerRepresentable {
    let vc = MatiViewController()
    public func makeUIViewController(context: Context) -> MatiViewController {
        return vc
    }
    
    public func updateUIViewController(_ uiViewController: MatiViewController, context: Context) {}
    
    var success: (_ identityId: String?, _ verificationId: String?) -> Void
    var cancelled: () -> Void
    
    public func makeCoordinator() -> Coordinator {
        Coordinator(success: success, cancelled: cancelled)
    }
    
    public  class Coordinator: NSObject, MetaMapButtonResultDelegate {
        public  func verificationSuccess(identityId: String?, verificationID: String?) {
            success(identityId, verificationID)
        }
        
        public  func verificationCancelled() {
            cancelled()
        }
        
        var success: (_ identityId: String?, _ verificationId: String?) -> Void
        var cancelled: () -> Void
        
        init(success: @escaping (_ identityId: String?, _ verificationId: String?) -> Void, cancelled: @escaping () -> Void) {
            self.success = success
            self.cancelled = cancelled
            super.init()
            MetaMapButtonResult.shared.delegate = self
        }
    }
}

class MetaMapViewController: UIViewController {}
```

Implementation MetaMap button for Objective-C

```objc
    #import "ViewController.h"
    #import <MetaMapSDK/MetaMapSDK.h>

    @interface ViewController () <MetaMapButtonResultDelegate>

    @property (nonatomic, strong) MetaMapButton *metaMapButton;

    @end

    @implementation ViewController

      - (void)viewDidLoad {
          [super viewDidLoad];

          //init button
          self.metaMapButton = [[MetaMapButton alloc] init];

          //add action to yours button
            [self.metaMapButton addTarget:self action:@selector(metaMapButtonAction:) forControlEvents:UIControlEventTouchUpInside];

          //set view of button
          self.metaMapButton.frame = CGRectMake(20, self.view.frame.size.height/2 - 25, self.view.frame.size.width - 40, 50);
          self.metaMapButton.center = self.view.center;

           //add button to yours view
          [self.view addSubview:self.metaMapButton];

          //set delegate to get result
          [MetaMapButtonResult shared].delegate = self;
      }

      //add showMetaMapFlow function with YOURS parameters
      -(void)metaMapButtonAction:(UIButton *) sender{
          [MetaMap.shared showMetaMapFlowWithClientId:@"YOUR_CLIENT_ID" flowId:@"YOUR_FLOW_ID"  metadata:@{@"key1":@"value"}];
    }

    #pragma mark - MetaMapButtonResultDelegate
    
      -(void)verificationSuccessWithIdentityId:(NSString *)identityId, verificationID(NSString *) {
          NSLog(@"Success: $@", identityId);
      }

      - (void)verificationCancelled {
          NSLog(@"Cancelled");
      }

    @end;
```

_**IMPORTANT**_ **`Info.plist`**
4. Add the following permissions to capture video, access the photo gallery, access the microphone and access to the location

```xml
<key>NSCameraUsageDescription</key>
<string>MetaMap needs access to your Camera</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>MetaMap needs access to your media library</string>
<key>NSMicrophoneUsageDescription</key>
<string>MetaMap needs access to your Microphone</string>
<key>NSLocationWhenInUseUsageDescription</key>
<string>MetaMap will use your location information to provide best possible verification experience.</string>
<key>NSLocationAlwaysAndWhenInUseUsageDescription</key>
<string>MetaMap will use your location information to provide best possible verification experience.</string>
<key>NSLocationAlwaysUsageDescription</key>
<string>MetaMap will use your location information to provide best possible verification experience.</string>
```

## Metadata is an additional optional parameter:

### Set the Language: 
By default the SDK language is set to "en" but it is editable to the language from the list: "es", "fr", "pt", "ru", "tr", "de", "it", "pl", "th".

```bash
metadata: ["fixedLanguage": "value"]
```
### Set the Button Color:
By default main button color is white but it is editable by using hex Color format "hexColor".
```bash
metadata: ["buttonColor": "value"]
   ```

### Set the Title color of the button:
By default main button title color is black but it is editable by using hex Color format "hexColor".

```bash
metadata: ["buttonTextColor": "value"]
   ```

### Set identity Id as parameter for re-verification:
```bash
metadata: ["identityId": "value"]
   ```

### Set encryption Configuration Id as parameter for encrypting data.
```bash
metaData: ["encryptionConfigurationId": "value"]
   ```

### Set customization fonts as parameter.
to add custom fonts, the project needs to have these font files, otherwise SDK will use default fonts: 
```bash
metadata: ["regularFont": "REGULAR_FONT_NAME.ttf", "boldFont":  "BOLD_FONT_NAME.ttf"]
   ```

