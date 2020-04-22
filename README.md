# Mati iOS SDK documentation 

![alt text](https://github.com/MatiFace/mati-global-id-sdk/blob/master/Group%2011-1.png)

## Xcode configurations

### Install Mati SDK using CocoaPods (recommended)

Install Mati (your App pod file)
  
    pod 'Mati-Global-ID-SDK'
    
Update your pods from the terminal

    pod install

### If you're not using CocoaPods (not recommended)

Download Mati framework from GitHub and add it to your project.

Note: Don't miss to add framework in Embedded Binaries.


## AppDelegate - Mati KYC Initialisation

Make the following changes in your AppDelegate file 

### Swift
    
    import MatiGlobalIDSDK
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions
                     launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
          
          MFKYC.register(clientId:"{custom_token}")
          
          return true
      }
      
      
      
### Objective-C
    
    #import <MatiGlobalIDSDK/MatiGlobalIDSDK.h>
    
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        
        [MFKYC registerWithClientId:@"{custom_token}"];

        return YES;
    }

## Mati KYC Button Placement (UI)

You now need to place the Mati KYC button inside your App. You have 2 options for that (interface builder vs. code):

You can include `MFKYCButton` into your view using XCode interface builder
Or
Add using Swift or Objective-C 

### Swift
    
    MFKYC.instance.metadata = ["key": "value"]
    let matiButton = MFKYCButton()
    matiButton.frame = CGRect(x: 0, y: 20, width: 320, height: 60)//you can change position, width and height
    matiButton.title = "Custom Title"
    view.addSubview(matiButton)
    
### Objective-C
    
    [MFKYC instance].metadata = @{"key": "value"};
    MFKYCButton *matiButton =[[MFKYCButton alloc] init];
    matiButton.frame = CGRectMake(0, 20, 320, 60);//you can change position,width and height
    matiButton.title = @"Custom Title";
    [self.view addSubview:matiButton];
    
## Mati KYC Delegate

Use the delegate functions below in order to handle the success / failure of each verification.

### Swift

    //Assign the controller of your choice to be the Mati button delegate
    MFKYC.instance.delegate = self

    func mfKYCLoginSuccess(identityId: String) {
      print("Mati Login Success")
    }
    
    func mfKYCLoginCancelled() {
      print("Mati Login Failed")
    }
    
### Objective-C
    
    //Assign the controller of your choice to be the Mati button delegate
    [MFKYC instance].delegate = self;

    - (void)mfKYCLoginSuccessWithIdentityId:(NSString *)identityId {
        NSLog(@"Mati Login Success");
    }
    
    - (void)mfKYCLoginCancelled {
        NSLog(@"Mati Login Failed");
    }
    
### Requirements 
    iOS 9.0
    Xcode 10.2
    Swift 5.0
   For Xcode 10.1 and below, use [Version 2.3.13](https://github.com/MatiFace/mati-global-id-sdk/releases/tag/2.3.13)


## Mati iOS SDK integration video    

[![Mati SDK integration demo video](https://img.youtube.com/vi/sPS7_QoFhpY/0.jpg)](https://www.youtube.com/watch?v=sPS7_QoFhpY)
