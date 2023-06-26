---
title: "iOS Changelog"
excerpt: "MetaMap's iOS SDK Changelog"
slug: "ios-changelog"
category: 61ae8e8dba577a0010791480
---

# Feedback

If you have an issue or ideas to improve MetaMap's iOS SDK, please look at our [issues](https://github.com/GetMetaMap/metamap-ios-sdk/issues) page to see if your issue has been reported or to add your own.


# Version 3.15.4

### Bug Fixes
    * fixed crash on the iOS 12, 14.0.1 versions
    * fixed minor UI issue on the document verification step


# Version 3.15.3


### Bug Fixes
    * fixed UI minor issues
    * fixing issue related to the MetaMap button/title colors
    * did UX correctionsd


### Updated Features  
    * added error screen for unexpected error



# Version 3.15.2

### Bug Fixes
    * fixed the issue related to creating verification twice
    * fixed UI issues
    * correction passport title
    
### Updated Features  
    * updated Sentry and fix conflicts between our SDK's Sentry and merchant's Sentry




# Version 3.15.1

### Bug Fixes
    * fixed analytic event title


# Version 3.15.0

### Updated Features  
    * updated Sentry
    * idemia improvement
    * changed start screen flow's item logic
    
### New Features
    *  support reusage for Idemia
    
### Bug Fixes
    * fixed encryption configuration id error case
    


# Version 3.14.2

### Bug Fixes
    * fixed User-Agent's crash 

# Version 3.14.1

### New Features
    * Idemia SDK in webView
    * Added encryptionConfigurationId param


# Version 3.14.0

### New Features
    * added PRS support
    * added smart capture feature (Vision) 
    * added configuration Id as params
    * added re-usage feature 
    * added revision support feature 


### Updated Features  
    * added E-Sign touch sign support
    * updated Sentry
    * added credit check support for Columbia

### Bug Fixes
    * fixed issue related to the document subtype list



# Version 3.13.2

### Updated Features   
    * reduced SDK download size to 3.66 MB


# Version 3.13.1

### Bug Fixes
    * fixed crash on the document verification step



# Version 3.13.0

### New Features
    * added video agreement feature support

### Bug Fixes
    * fixed issue on the Brazilian driver license back side skip request
    * corrected VPN try again button behavior
    
    
### Updated Features   
    * redesigned Document, Biometric verification, Phone/Email, E-signature, verification steps
    * redesigned errors, permissions, exit screens
    * updated to the latest version of Socket.io (.three)
    * IP restriction shows before start screen


# Version 3.12.1
#### Bug Fixes
    * fixes UI issue in shimmering screen
    * fixed crash on the backside document upload 
    * fixing issue on the email/phone verification step

### Updated Features
    * replaced MetaMap-ID-SDK.podspec to MetaMapSDK.podspec

# Version 3.12.0
###### 25 November 2022

#### Bug Fixes
    * fixed crash on the credit check verification Flow
    * corrected close button image
    * fixed Search bar logic on countries list screen
    * fixed issue on IP restriction part

### Updated Features
    * redesign Location Intelligence flow
    * added cancel event on the loading close action 




# Version 3.11.3
###### 28 October 2022

#### Bug Fixes
    * fixed issue on the Error screen
    * fixed socket connection ping-pong issue
    * fixed crash on the voice liveness step
    * fixed issue on the biometric step 
    * fixed resend code timer
    * fixed minor UI issues

### New Features
    * added Skeleton loader for Start screen
    
    
    

# Version 3.11.2
###### 11 October 2022

#### Bug Fixes
  * fixed Country restriction is limiting document upload error
      


# Version 3.11.0
###### 06 October 2022

#### Bug Fixes
  * fixed issue on the upload document error type
  
    
### Updated Features
       * Liveness and VoiceLiveness videos recording will automatically stop on the time limit of 20 seconds
       * Show a meaningful error screen when the initialization of the SDK fails


# Version 3.10.1
###### 19 September 2022

#### Bug Fixes
    * fixed issue on the CPF screen
    * fixed issue on the selfie photo screen
    * fixed verifications completed status for Brazilian Driving License verification
    * corrected text/Title on the Main screen
    
### Updated Features
        * support dark mode
        * support country restriction enable mode 
        

# Version 3.10.0
###### 1 September 2022

#### Bug Fixes
    * fixed crash on document upload screen
    * fixed server error issue
    * fixed issue related to the country selection when supported country is one 
    
### Updated Features
    * refactored flows list screen (Main screen)
    * replaced upload document screen to loading spinner
    * removed RootViewController 
    * fixed minor layout issues
    * refactored video/voice liveness screen 
    * added error code/id to the error screens
    * refactored verification phone/E_mail flow

### New Features
    * added support 402/403 errors code
    * added id to all UI elements



# Version 3.9.11
###### 22 July 2022

#### Bug Fixes
    * fixed issue on the stop video at recording liveness button
    * corrected no face document leads error
    * fixed issue on the start screen financial icons
    * corrected key of localization string on the e-sign screen 
    * changed the Reachability public class to private
    * fixed crash, on the cancel action on the country list screen
    * fixed crash after verification finishes
    
#### Updated Features
    * "metaMap_" prefix to string resources in localize
    * server message of error for incorrect CPF code
    * documentation of the plugins: added location permission information


# Version 3.9.10
###### 28 June 2022

#### Bug Fixes
    * corrected IP address

# Version 3.9.9
###### 27 June 2022

#### New Features
    *  add "metamap_" prefix to string

#### Updated Features
    * new Start screen style
    

#### Bug Fixes
    * added the right error code to the Analytic
    * fixed issue on the document country restriction


# Version 3.9.8
###### 10 June 2022

#### New Features
    * replaced metaData dictionary with the object

#### Updated Features
    * event queue for analytics
    * identity Id to analytic events

#### Bug Fixes
    * fixed issue on the E-sign flow
    * fixed issue related to the camera permission


# Version 3.9.6
###### 18 May 2022

#### New Features
    * integration with Geo Location will continue, but with the new architecture
    * new error for selfie validation
    * support dark mode for iOS SDK
    * dynamic Terms and Privacy link
    * permissions basic coordinator
    * flow management refactor
    * Input data manager refactor

#### Updated Features
    * updated the subtypes for LATAM and Africa
    * subtypes translations from WS
    * reduced time resend SMS to 30 seconds
    * new data structure for the web container

#### Bug Fixes
    * fixed issue related to the document upload
    * fixed issue on the MetaMap button
    * fixed issue on the proof of residency verification flow
    * fixed the issue on the self-verification flow
    * fixed minor issues after refactoring


# Version 3.9.5
###### 15 April 2022

#### New Features
    * document skip back
    * document subtypes

#### Bug Fixes
    * server error & no internet connection screens
    * fixed minor issue related to the back button
    * fixed issue on the e-sign step
    * fixed minor issue in the verification done screen
    * fixed issue related to the sending CPF typed to the document
    * fixed issue on the Cordova plugin related to [ iOS podFile] replacing
    * corrected done button title in Spanish


# Version 3.9.4
###### 25 March 2022

#### Bug Fixes
    * fixed issue on update document
    * fixed issue related to the country restrictions
    * fixed issue related to the detecting and auto-correcting whitespace characters in Email ID input
    * changed text on the success screen
    * fixed Sentry error on the React-Native plugin
    * fixed incorrect verificationId and identityId response on the Flutter plugin

#### Updated Features
    * changed all things related to Mati on the plugins


# Version 3.9.3
###### 14 March 2022

#### New Features
    * rebranding to MetaMap
    * updated Flutter & Capacitor plugins for support iOS and Android latest version
    * updated documentation about deprecated methods


# Version 3.9.1
###### 23 Febrary 2022

#### New Features
    * added face detection
    * document subType selection

#### Bug Fixes
    * fixed minor issues related to the e-sign step
    * fixed retry button issue on the liveness screen
    * fixed translation issues for Spanish

#### Updated Features
    * corrected credit check contents feature
    * fixed start button issue on several screens
    * fixed minor issues on the Brazil CPF screen


# Version 3.9.0
###### 9 Febrary 2022

#### New Features
    * support CPF for Brazil NID
    * support credit check
    * support dynamic start screen
    * replaced Mati logo to MetaMap

#### Bug Fixes
    * fixed crash on the iPad 
    * fixed minor issue related to the mic. permission
    * fixed layout issues related to the document scan and document previewers screens
    * corrected ordering of verificationId and IdentityId - [ issue was in Flutter plugin ]


# Version 3.8.9
###### 25 January 2022

#### New Features
    * support error case for face mask detection
    * dynamic web containers
    * support device language by default
    * support internet disconnect case for all project

#### Bug Fixes
    * fixed issue related to the SMS resend timer freezes







