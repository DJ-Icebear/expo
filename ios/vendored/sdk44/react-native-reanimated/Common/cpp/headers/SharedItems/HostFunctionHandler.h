#pragma once

#include <ABI44_0_0jsi/ABI44_0_0jsi.h>

namespace ABI44_0_0reanimated {

struct HostFunctionHandler : jsi::HostObject {
  std::shared_ptr<jsi::Function> pureFunction;
  std::string functionName;
  jsi::Runtime *hostRuntime;
    jsi::HostObject a;
    
  HostFunctionHandler(std::shared_ptr<jsi::Function> f, jsi::Runtime &rt) {
    pureFunction = f;
    functionName = f->getProperty(rt, "name").asString(rt).utf8(rt);
    hostRuntime = &rt;
  }
  
  std::shared_ptr<jsi::Function> getPureFunction() {
    return pureFunction;
  }
};

}
