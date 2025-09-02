Pod::Spec.new do |s|
  s.name          = 'MetaMapSDK'
  s.version       = '3.23.12'
  s.summary       = 'MetaMap SDK'
  s.description   = 'MetaMap SDK for iOS'
  s.homepage      = 'https://github.com/GetMati/mati-ios-sdk'
  s.license       = { :type => 'MIT', :file => 'LICENSE' }
  s.authors       = { 'MetaMap' => 'support@getmati.com' }

  s.platform      = :ios, '13.0'
  s.swift_version = '5.9'
  s.source = {
    :git => 'https://github.com/GetMetaMap/metamap-ios-sdk.git',
    :tag => s.version.to_s
  }
  s.vendored_frameworks = [
    'MetaMapSDK.xcframework',
    'IncdOnboarding.xcframework',
    'opencv2.xcframework'
  ]
  s.frameworks = %w[
    Accelerate AVFoundation CoreMedia CoreVideo CoreImage CoreGraphics
    QuartzCore CoreAudio AudioToolbox UIKit Foundation
  ]
  s.libraries = 'z', 'c++'
end