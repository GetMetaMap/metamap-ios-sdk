---
title: "iOS"
excerpt: "Add the MetaMap button to your iOS app."
slug: "ios"
category: 61ae8e8dba577a0010791480
---
# MetaMap iOS Usage Guide

The following describes how to install and use the MetaMap iOS SDK for your application.

## iOS Demo App

You can go to GitHub and download the [MetaMap iOS demo app](https://github.com/GetMati/mati-mobile-examples/tree/main/swiftDemoApp(native))

## Requirements and size
   iOS 12+  
   Xcode 12.0  
   Swift 5.0  
   
SDK compiled size: ~10MB

Source (in project files): 55MB

## Add the MetaMap SDK
<!--
There are two ways to add the MetaMap SDK for iOS:
* [Using CocoaPods](#install-using-cocoapods)
* [Using the Swift Package Manager](#install-using-spm)
-->

### Install Using CocoaPods

Create a Podfile and add the pod `MetaMap-Global-ID-SDK`:

    pod 'MetaMap-Global-ID-SDK'

Update your pods from the terminal

    pod install

_**Note**_ The following dependencies will be automatically installed with the pod `MetaMap-Global-ID-SDK`:

* Starscream
* SocketIO

<!-- ### Download from GitHub

Download the MetaMap framework directly from GitHub and add it to your project with all necessary dependencies.

_**IMPORTANT**_ The `MetaMap-Global-ID-SDK` requires the following dependencies:

* Starscream
* SocketIO

_**Note**_ Check that you've added the [MetaMap framework](https://github.com/GetMati/mati-ios-sdk/tree/master/MetaMapSDK.xcframework).



### Install Using Swift Package Manager
-->


## Implement MetaMap in Your App

Add the MetaMap button to your App.

* [Swift](#metaMap-button-swift)
* [Objective-C](#metaMap-button-objc)

_**IMPORTANT**_ **`Info.plist`**
Add the following permissions to capture video, access the photo gallery, and access the microphone for the voiceliveness feature.

```xml
<key>NSCameraUsageDescription</key>
<string>MetaMap needs access to your Camera</string>
<key>NSPhotoLibraryUsageDescription</key>
<string>MetaMap needs access to your media library</string>
<key>NSMicrophoneUsageDescription</key>
<string>MetaMap needs access to your Microphone</string>
```


Set the following parameters for your application:

| Parameter                  | Type       | Required | Example                            |
|----------------------------|------------|----------|------------------------------------|
| `metaMapButton.title`         | string     | Required | `metaMapButton.title = "Verify Me" ` |
| `metaMapButton.textColor`     | UIColor    | Optional | `metaMapButton.textColor = .white`     |
| `metaMapButton.buttonColor`   | UIColor    | Optional | `metaMapButton.buttonColor = .black` |
| Metadata <br /> _**Note**_ Go to the [Metadata section](#metadata-usage) <br />to learn more about using metadata   | @Nullable Metadata   | Optional |



_**Note**_ Be sure to initialize the MetaMap button before use.

<a id="metaMap-button-swift"></a> **Swift**

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

<a id="metaMap-button-objc"></a>**SwiftUI**
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

<a id="metaMap-button-objc"></a>**Objective-C**
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
