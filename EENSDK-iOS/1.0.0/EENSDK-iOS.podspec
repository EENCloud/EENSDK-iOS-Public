#
# Be sure to run `pod lib lint EENSDK-iOS.podspec' to ensure this is a
# valid spec before submitting.

Pod::Spec.new do |s|
  s.name             = 'EENSDK-iOS'
  s.version          = '2.0.0'
  s.summary          = 'An FLV player designed specifically to play files from EagleEye Networks.'
  s.license = { :type => 'Proprietary', :text => 'This binary is is not openly licensed to any individual without prior written permission and remains the property of EagleEye Networks, Inc.' }

  s.description      = 'An FLV player designed specifically to play files from EagleEye Networks .'
  s.homepage         = 'https://github.com/EENCloud/EENSDK-iOS-Public/'
  s.author           = { 'Greg Slomin' => 'gslomin@eagleeyenetworks.com' }
  s.ios.deployment_target = '11.0'

  s.source = {
  	:http => 'https://github.com/EENCloud/EENSDK-iOS-Public/blob/master/EENSDK-iOS/1.0.0/EENSDK_iOS.zip?raw=true'
  }
  s.vendored_frameworks = 'EENSDK_iOS.framework'
end