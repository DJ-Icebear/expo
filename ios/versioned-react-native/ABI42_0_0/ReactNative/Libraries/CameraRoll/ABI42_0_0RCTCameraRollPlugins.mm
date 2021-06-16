/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 *
 * @generated by an internal plugin build system
 */

#ifndef ABI42_0_0RN_DISABLE_OSS_PLUGIN_HEADER

// OSS-compatibility layer

#import "ABI42_0_0RCTCameraRollPlugins.h"

#import <string>
#import <unordered_map>

Class ABI42_0_0RCTCameraRollClassProvider(const char *name) {
  static std::unordered_map<std::string, Class (*)(void)> sCoreModuleClassMap = {
    {"AssetsLibraryRequestHandler", ABI42_0_0RCTAssetsLibraryRequestHandlerCls},
    {"CameraRollManager", ABI42_0_0RCTCameraRollManagerCls},
    {"ImagePickerIOS", ABI42_0_0RCTImagePickerManagerCls},
    {"PhotoLibraryImageLoader", ABI42_0_0RCTPhotoLibraryImageLoaderCls},
  };

  auto p = sCoreModuleClassMap.find(name);
  if (p != sCoreModuleClassMap.end()) {
    auto classFunc = p->second;
    return classFunc();
  }
  return nil;
}

#endif // ABI42_0_0RN_DISABLE_OSS_PLUGIN_HEADER
