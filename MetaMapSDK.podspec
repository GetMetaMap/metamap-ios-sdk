Pod::Spec.new do |s|
  s.name    = "MetaMapSDK"
  s.version = "3.23.14"
  s.summary = "MetaMap SDK"
  s.description = "MetaMap SDK for iOS"
  s.homepage = "https://getmati.com"
  s.license  = { :type => 'MIT', :file => 'LICENSE' }
  s.authors  = { "MetaMap" => "sdk@getmati.com" }
  s.platform = :ios, "13.0"

  s.source  = { :git => "https://github.com/GetMetaMap/metamap-ios-sdk.git",
                :tag => s.version.to_s }

  # Keep only your own frameworks here
  s.vendored_frameworks = ["MetaMapSDK.xcframework", "IncdOnboarding.xcframework"]

  # Pull OpenCV via CocoaPods
  s.dependency 'OpenCV2', '~> 4.12'   # adjust as needed

  s.pod_target_xcconfig = { 'OTHER_LDFLAGS' => '-ObjC' }
  s.frameworks = ['AVFoundation','Vision','UIKit','Foundation']
  s.libraries  = ['c++']
end
