Pod::Spec.new do |s|
s.name                = "MetaMapSDK"
s.version             = "3.22.4"
s.summary             = "MetaMap SDK"
s.description         = "MetaMap SDK for iOS"
s.homepage            = "https://github.com/GetMati/mati-ios-sdk"
s.license             = { type: 'MIT', file: 'LICENSE' }
s.authors             = "MetaMap"
s.homepage	      = "https://getmati.com"
s.platform            = :ios, "13.0"
s.source              = { :git => "https://github.com/GetMetaMap/metamap-ios-sdk.git",  :tag => "3.22.4"}
s.vendored_frameworks = ["MetaMapSDK.xcframework", "IncdOnboarding.xcframework", "opencv2.xcframework"]
end


