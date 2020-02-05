
Pod::Spec.new do |s|
s.name                = "Mati-Global-ID-SDK"
s.version             = "2.5.2"
s.summary             = "Use Mati for login"
s.description         = "User Mati for login"
s.homepage            = "https://github.com/MatiFace/mati-global-id-sdk"
s.license             = { type: 'MIT', file: 'LICENSE' }
s.authors             = "Mati Face"
s.platform            = :ios, "9.0"
s.source              = { :git => "https://github.com/MatiFace/mati-global-id-sdk.git",  :tag => "2.5.2"  }
s.frameworks          = 'UIKit'
s.source_files        = "MatiGlobalIDSDK.framework/Headers/*.h"
s.vendored_frameworks = "MatiGlobalIDSDK.framework"
s.public_header_files = "MatiGlobalIDSDK.framework/Headers/*.h"
end

