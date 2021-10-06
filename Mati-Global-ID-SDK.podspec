
Pod::Spec.new do |s|
s.name                = "Mati-Global-ID-SDK"
s.version             = "3.6.2"
s.summary             = "Mati SDK"
s.description         = "Mati SDK for iOS"
s.homepage            = "https://github.com/GetMati/mati-ios-sdk"
s.license             = { type: 'MIT', file: 'LICENSE' }
s.authors             = "Mati"
s.homepage 			  = "https://getmati.com"
s.platform            = :ios, "11.4"
s.source              = { :git => "https://github.com/GetMati/mati-ios-sdk.git",  :tag => "3.6.2"  }
s.vendored_frameworks = "MatiSDK.xcframework"
end