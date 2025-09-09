Pod::Spec.new do |s|
s.name                = "MetaMapSDK"
s.version             = "3.23.13"
s.summary             = "MetaMap SDK"
s.description         = "MetaMap SDK for iOS"
s.homepage            = "https://github.com/GetMati/mati-ios-sdk"
s.license             = { type: 'MIT', file: 'LICENSE' }
s.authors             = "MetaMap"
s.homepage	      = "https://getmati.com"
s.platform            = :ios, "13.0"
s.source = {
    :http => "https://github.com/GetMetaMap/metamap-ios-sdk/releases/download/3.23.13/MetaMapSDK-3.23.13.zip",
    :checksum => "PUT_SHA256_HERE"
  }
s.vendored_frameworks = ["MetaMapSDK.xcframework", "IncdOnboarding.xcframework", "opencv2.xcframework"]
s.frameworks = %w[UIKit Foundation AVFoundation]
s.requires_arc = true
end