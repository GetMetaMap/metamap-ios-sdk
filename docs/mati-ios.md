---
title: "iOS"
excerpt: "Add the Mati button to your iOS app."
slug: "mobile-sdks"
category: 61141a8437375100442f3d20
hidden: true
---
# Mati iOS Usage Guide

The following describes how to install and use the Mati iOS SDK for your application.

## iOS Demo App

You can go to GitHub and download the [Mati iOS demo app](https://github.com/GetMati/mati-mobile-examples/tree/main/swiftDemoApp(native))

## Requirements and size
   iOS 12+  
   Xcode 12.0  
   Swift 5.0  
   
SDK compiled size: ~10MB

Source (in project files): 55MB

## Add the Mati SDK
<!--
There are two ways to add the Mati SDK for iOS:
* [Using CocoaPods](#install-using-cocoapods)
* [Using the Swift Package Manager](#install-using-spm)
-->

### Install Using CocoaPods

Create a Podfile and add the pod `Mati-Global-ID-SDK`:

    pod 'Mati-Global-ID-SDK'

Update your pods from the terminal

    pod install

_**Note**_ The following dependencies will be automatically installed with the pod `Mati-Global-ID-SDK`:

* Starscream
* SocketIO

<!-- ### Download from GitHub

Download the Mati framework directly from GitHub and add it to your project with all necessary dependencies.

_**IMPORTANT**_ The `Mati-Global-ID-SDK` requires the following dependencies:

* Starscream
* SocketIO

_**Note**_ Check that you've added the [Mati framework](https://github.com/GetMati/mati-ios-sdk/tree/master/MatiSDK.xcframework).



### Install Using Swift Package Manager
-->


## Implement Mati in Your App

Add the Mati button to your App.

* [Swift](#mati-button-swift)
* [Objective-C](#mati-button-objc)

_**IMPORTANT**_ **`Info.plist`**
Add the following permissions to capture video, access the photo gallery, and access the microphone for the voiceliveness feature.

```xml
<key>NSCameraUsageDescription</key>
<string>Mati needs access to your Camera</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>Mati needs access to your media library</string>
<key>NSMicrophoneUsageDescription</key>
<string>Mati needs access to your Microphone</string>
```


Set the following parameters for your application:

| Parameter                  | Type       | Required | Example                            |
|----------------------------|------------|----------|------------------------------------|
| `matiButton.title`         | string     | Required | `matiButton.title = "Verify Me" ` |
| `matiButton.textColor`     | UIColor    | Optional | `matiButton.textColor = .white`     |
| `matiButton.buttonColor`   | UIColor    | Optional | `matiButton.buttonColor = .black` |
| Metadata <br /> _**Note**_ Go to the [Metadata section](#metadata-usage) <br />to learn more about using metadata   | @Nullable Metadata   | Optional |



_**Note**_ Be sure to initialize the Mati button before use.

<a id="mati-button-swift"></a> **Swift**

```swift
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

      //add button action
      matiButton.addTarget(self, action: #selector(self.matiButtonAction), for: .touchUpInside)

      //set view of button
      matiButton.frame = CGRect(x: 20, y: self.view.frame.size.height/2 - 50, width: view.frame.size.width - 40, height: 50)

      //add button to yours view
      view.addSubview(matiButton)

      //set delegate to get result
      MatiButtonResult.shared.delegate = self

    }

      @objc private func matiButtonAction() {
	//set params to showMatiFlow
	Mati.shared.showMatiFlow(clientId: "YOUR_CLIENT_ID",
				flowId: "YOUR_FLOW_ID",
				metadata: ["key1": "value1", "key2": 123])
	}
}

//MARK: MatiButtonResultDelegate
extension ViewController: MatiButtonResultDelegate {

    func verificationSuccess(identityId: String?, verificationID: String?) {
		print("Mati Verification Success \(identityId)")
	}

	func verificationCancelled() {
		print("Mati Verification Cancelled")
	}
}
```

<a id="mati-button-objc"></a>**SwiftUI**
```swift

import SwiftUI
import MatiSDK
import UIKit

struct ContentView: View {
    var body: some View {
        VStack {
            ZStack {
//MARK: MatiDelegateObserver
                MatiDelegateObserver { identityId, verificationId in
                    print("\(identityId), \(verificationId)")
                } cancelled: {
                    print("cancelled")
                }
                HStack {
                    Button(action: {
                        Mati.shared.showMatiFlow(clientId: "YOUR_CLIENT_ID", flowId: "YOUR_FLOW_ID", metadata: ["key1": "value1", "key2": 123])
                    }) {
                        Text("press me")
                    }
                }
            }
        }
    }
}

struct MatiDelegateObserver: UIViewControllerRepresentable {
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
    
    public  class Coordinator: NSObject, MatiButtonResultDelegate {
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
            MatiButtonResult.shared.delegate = self
        }
    }
}

class MatiViewController: UIViewController {}
```

<a id="mati-button-objc"></a>**Objective-C**
```objc


    #import "ViewController.h"
    #import <MatiSDK/MatiSDK.h>

    @interface ViewController () <MatiButtonResultDelegate>

    @property (nonatomic, strong) MatiButton *matiButton;

    @end

    @implementation ViewController

      - (void)viewDidLoad {
          [super viewDidLoad];

          //init button
          self.matiButton = [[MatiButton alloc] init];

          //add action to yours button
            [self.matiButton addTarget:self action:@selector(matiButtonAction:) forControlEvents:UIControlEventTouchUpInside];

          //set view of button
          self.matiButton.frame = CGRectMake(20, self.view.frame.size.height/2 - 25, self.view.frame.size.width - 40, 50);
          self.matiButton.center = self.view.center;

           //add button to yours view
          [self.view addSubview:self.matiButton];

          //set delegate to get result
          [MatiButtonResult shared].delegate = self;
      }

      //add showMatiFlow function with YOURS parameters
      -(void)matiButtonAction:(UIButton *) sender{
          [Mati.shared showMatiFlowWithClientId:@"YOUR_CLIENT_ID" flowId:@"YOUR_FLOW_ID"  metadata:@{@"key1":@"value"}];
    }

    #pragma mark - MatiButtonResultDelegate
    
      -(void)verificationSuccessWithIdentityId:(NSString *)identityId, verificationID(NSString *) {
          NSLog(@"Success: $@", identityId);
      }

      - (void)verificationCancelled {
          NSLog(@"Cancelled");
      }

    @end;
```


## Metadata Usage

Metadata is an additional optional parameter that you can receive using a webhook after passing verification. The metadata is also displayed in the verification on the [Dashboard](https://dashboard.getmati.com/).

### Metadata: Set the Language

You can use metadata to set specific parameters, including setting your default language and to hide language settings from users.

key: `fixedLanguage`
value: locale code of language

For instance, to set the language code for Spain to Spanish, we would set the `fixedLanguage` parameter to `es" `

#### Example: Set the Language Code for Spain

**Swift, SwiftUI**
```swift
metadata: ["fixedLanguage": "es"]
```
### Metadata: Set the Button Color

You can use metadata to set the color of the main buttons in your flow.

To set the background color of the button, use the following parameter:

key: `buttonColor`
value: hexColor


### Example

**Swift, SwiftUI**
```swift
metadata: ["buttonColor": "#C0C8D1"]
```
To set the title color of the button:

key: `buttonTextColor`
value: hexColor


### Example 

**Swift, SwiftUI**
```swift
metadata: ["buttonTextColor": "#C0C8D1"]
```
