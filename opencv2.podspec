Pod::Spec.new do |s|
  s.name             = 'opencv2'
  s.version          = '4.5.0'
  s.summary          = 'OpenCV (Open Source Computer Vision Library)'

  s.description      = <<-DESC
  OpenCV is an open source computer vision and machine learning software library.
  DESC

  s.homepage         = 'https://opencv.org/'
  s.license          = { :type => 'BSD', :file => 'LICENSE' }
  s.author           = { 'OpenCV Team' => 'info@opencv.org' }
  s.source           = { :path => '.' }

  s.platform     = :ios, '13.0'
  s.vendored_frameworks = 'opencv2.framework'
  s.frameworks   = ['Accelerate', 'CoreGraphics', 'Foundation', 'QuartzCore', 'UIKit']
  s.requires_arc = true
  s.static_framework = false
  s.pod_target_xcconfig = {
    'OTHER_LDFLAGS' => '-lObjC'
  }
end