
Pod::Spec.new do |s|
s.name                = "Mati-Global-ID-SDK"
s.version             = "3.0.0"
s.summary             = "Mati SDK"
s.description         = "Mati SDK"
s.homepage            = "https://github.com/GetMati/mati-ios-sdk"
s.license             = { type: 'MIT', file: 'LICENSE' }
s.authors             = "Mati Face"
s.platform            = :ios, "11.4"
s.source              = { :git => "https://github.com/GetMati/mati-ios-sdk.git",  :tag => "3.0.0"  }
s.frameworks          = 'UIKit'
s.source_files        = "MatiSDK.framework/Headers/*.h"
s.vendored_frameworks = "MatiSDK.framework"
s.public_header_files = "MatiSDK.framework/Headers/*.h"
end

