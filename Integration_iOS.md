# This document explains how to integrate the Mati button into your iOS app

# LOGIN

## Xcode configurations

1. PODFILE

    [//install Mati (your App pod file)
    pod 'Mati-Global-ID-SDK'](//install)

    //update your pods from the terminal
    pod install

2. XCODE PROJECT BUILD SETTINGS

In your XCode project Build Settings, please set

    "Enable Bitcode" to "No".

## AppDelegate - Mati KYC Initialisation

Make the following changes in your AppDelegate file (swift on the left, Obj-C on the right)

    import MatiGlobalIDSDK
    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions
                     launchOptions: [UIApplicationLaunchOptionsKey: Any]?) -> Bool {
          MFKYC.register(clientId:"{custom_token}")
    			//or
    			MFKYC.register(clientId:"{custom_token}" identityId:"{identity_id}")
    			
    			//optional
    			MFKYC.instance.icon = UIImage(named:"custom_image")
    	    MFKYC.instance.buttonColor = UIColor.blue		
    			MFKYC.instance.mainTitle = "Custom title."
    	    MFKYC.instance.mainDescription = "Custom description."
    	    MFKYC.instance.mainStepsTitle = "Custom 2 steps"
    	    MFKYC.instance.mainStep1Text = "Custom step 1"
    	    MFKYC.instance.mainStep2Text = "Custom step 2"
    	    MFKYC.instance.mainButtonTitle = "Custom button title"
     	    
          return true
      }

    #import <MatiGlobalIDSDK/MatiGlobalIDSDK.h>
    
    - (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
        [MFKYC registerWithClientId:@"{custom_token}"];
    		//or
    		[MFKYC registerWithClientId:@"{custom_token}" identityId:@"{identity_id}"];
    		
    		//optional
    		MFKYC.instance.icon = [UIImage imageNamed:@"custom_image"];
        MFKYC.instance.buttonColor = [UIColor blueColor];
    		MFKYC.instance.mainTitle = @"Custom title.";
        MFKYC.instance.mainDescription = @"Custom description.";
        MFKYC.instance.mainStepsTitle = @"Custom 2 steps";
        MFKYC.instance.mainStep1Text = @"Custom step 1";
        MFKYC.instance.mainStep2Text = @"Custom step 2";
        MFKYC.instance.mainButtonTitle = @"Custom button title";
        
        return YES;
    }

## Mati KYC Button Placement (UI)

You now need to place the Mati KYC button inside your App. You have 2 options for that (interface builder / code):

- OPTION 1: You can include `MFKYCButton` into your view using XCode interface builder
- OPTION 2: Add using Swift (left) or Objective-C (right)

    MFKYC.instance.metadata = ["key": "value"]
    let matiButton = MFKYCButton()
    matiButton.frame = CGRect(x: 0, y: 20, width: 320, height: 60)//you can change position, width and height :)
    matiButton.title = "Custom"
    view.addSubview(matiButton)

    [MFKYC instance].metadata = @{"key": "value"};
    MFKYCButton *matiButton =[[MFKYCButton alloc] init];
    matiButton.frame = CGRectMake(0, 20, 320, 60);//you can change position,width and height :)
    matiButton.title = "Custom";
    [self.view addSubview:matiButton];

## Mati KYC Delegate

Use the delegate functions below in order to handle the success / failure of login

    //as always, assign the controller of your choice to be the Mati button delegate
    MFKYC.instance.delegate = self

    //as always, assign the controller of your choice to be the Mati button delegate
    [MFKYC instance].delegate = self;

    func mfKYCLoginSuccess(identityId: String) {
      print("Mati Login Success")
    }
    
    func mfKYCLoginCancelled() {
        print("Mati Login Failed")
    }

    - (void)mfKYCLoginSuccessWithIdentityId:(NSString *)identityId {
      NSLog(@"Mati Login Success");
    }
    
    - (void)mfKYCLoginCancelled {
      NSLog(@"Mati Login Failed");
    }