# Mati iOS SDK documentation 

![alt text](https://github.com/MatiFace/mati-global-id-sdk/blob/master/readme_pic.png)

## Xcode configurations

### Install MetaMap SDK using CocoaPods (recommended)

Install MetaMap (your App pod file)
  
    pod 'MetaMapSDK'
    
Update your pods from the terminal

    pod install

### If you're not using CocoaPods (not recommended)

Download MetaMap framework from GitHub and add it to your project.

Note: Don't miss to add framework in Embedded Binaries.


## AppDelegate - MetaMap KYC Initialization

Make the following changes in your AppDelegate file 

### Swift
    
    import MetaMapGlobalIDSDK
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions
                     launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
          
          MFKYC.register(clientId:"{custom_token}")
          
          return true
      }
      
      
      
### Objective-C
    
    #import <MetaMapGlobalIDSDK/MetaMapGlobalIDSDK.h>
    
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        
        [MFKYC registerWithClientId:@"{custom_token}"];

        return YES;
    }

## MetaMap KYC Button Placement (UI)

You now need to place the MetaMap KYC button inside your App. You have 2 options for that (interface builder vs. code):

You can include `MFKYCButton` into your view using XCode interface builder
Or
Add using Swift or Objective-C 

### Swift
    
    MFKYC.instance.metadata = ["key": "value"]
    let metaMapButton = MFKYCButton()
    metaMapButton.frame = CGRect(x: 0, y: 20, width: 320, height: 60)//you can change position, width and height
    metaMapButton.title = "Custom Title"
    view.addSubview(metaMapButton)
    
### Objective-C
    
    [MFKYC instance].metadata = @{"key": "value"};
    MFKYCButton *metaMapButton =[[MFKYCButton alloc] init];
    metaMapButton.frame = CGRectMake(0, 20, 320, 60);//you can change position,width and height
    metaMapButton.title = @"Custom Title";
    [self.view addSubview: metaMapButton];
    
## MetaMap KYC Button Multiflow Support

If you want to work with specific flow, please add "flowId" parameter.
Add using Swift or Objective-C 

### Swift
    
    MFKYC.instance.metadata = ["key": "value"]
    let metaMapButton = MFKYCButton()
    metaMapButton.frame = CGRect(x: 0, y: 20, width: 320, height: 60)//you can change position, width and height
    metaMapButton.title = "Custom Title"
    metaMapButton.flowId = "SPECIFIC_FLOW_ID" // like "7e8zf446aa5b5e001a7769d0"
    view.addSubview(metaMapButton)
    
### Objective-C
    
    [MFKYC instance].metadata = @{"key": "value"};
    MFKYCButton *metaMapButton =[[MFKYCButton alloc] init];
    metaMapButton.frame = CGRectMake(0, 20, 320, 60);//you can change position,width and height
    metaMapButton.title = @"Custom Title";
    metaMapButton.flowId = @"SPECIFIC_FLOW_ID"; // like "7e8zf446aa5b5e001a7769d0"
    [self.view addSubview:metaMapButton];
    
## MetaMap KYC Delegate

Use the delegate functions below in order to handle the success / failure of each verification.

### Swift

    //Assign the controller of your choice to be the MetaMap button delegate
    MFKYC.instance.delegate = self

    func mfKYCLoginSuccess(identityId: String) {
      print("MetaMap Login Success")
    }
    
    func mfKYCLoginCancelled() {
      print("MetaMap Login Failed")
    }
    
### Objective-C
    
    //Assign the controller of your choice to be the MetaMap button delegate
    [MFKYC instance].delegate = self;

    - (void)mfKYCLoginSuccessWithIdentityId:(NSString *)identityId {
        NSLog(@"MetaMap Login Success");
    }
    
    - (void)mfKYCLoginCancelled {
        NSLog(@"MetaMap Login Failed");
    }
    
### Requirements 
   iOS 12+ 
   Xcode 12.0  
   Swift 5.0  
   For Xcode 10 and below, use [Version 2.3.13](https://github.com/MatiFace/mati-global-id-sdk/releases/tag/2.3.13)  
   For Xcode 11 and below, use [Version 2.8.0](https://github.com/MatiFace/mati-global-id-sdk/releases/tag/2.8.0)  


## MetaMap iOS SDK integration video    

[![MetaMap SDK integration demo video](https://img.youtube.com/vi/sPS7_QoFhpY/0.jpg)](https://www.youtube.com/watch?v=sPS7_QoFhpY)
