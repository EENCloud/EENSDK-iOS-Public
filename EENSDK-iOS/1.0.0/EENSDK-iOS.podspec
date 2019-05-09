#
# Be sure to run `pod lib lint EENSDK-iOS.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'EENSDK-iOS'
  s.version          = '1.0.0'
  s.summary          = 'An FLV player designed specifically to play files from EagleEye Networks.'
  s.license = { :type => 'Proprietary', :text => 'This binary is is not openly licensed to any individual without prior written permission and remains the property of EagleEye Networks, Inc.' }
# This description is used to generate tags and improve search results.
#   * Think: What does it do? Why did you write it? What is the focus?
#   * Try to keep it short, snappy and to the point.
#   * Write the description between the DESC delimiters below.
#   * Finally, don't worry about the indent, CocoaPods strips it!

  s.description      = 'An FLV player designed specifically to play files from EagleEye Networks .'
  s.homepage         = 'https://github.com/EENCloud/EENSDK-iOS-Public/'
  s.author           = { 'Greg Slomin' => 'gslomin@eagleeyenetworks.com' }
  s.ios.deployment_target = '10.0'

  s.source = {
    :http => 'https://github.com/EENCloud/EENSDK-iOS-Public/blob/master/EENSDK-iOS/1.0.0/EENSDK_iOS.zip?raw=true'
  }
  s.vendored_frameworks = 'EENSDK_iOS.framework'
end