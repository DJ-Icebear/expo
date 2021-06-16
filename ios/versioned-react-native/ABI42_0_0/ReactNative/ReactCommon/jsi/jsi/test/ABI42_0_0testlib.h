/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <functional>
#include <memory>
#include <vector>

#include <gtest/gtest.h>
#include <ABI42_0_0jsi/ABI42_0_0jsi.h>

namespace ABI42_0_0facebook {
namespace jsi {

class Runtime;

using RuntimeFactory = std::function<std::unique_ptr<Runtime>()>;

std::vector<RuntimeFactory> runtimeGenerators();

class JSITestBase : public ::testing::TestWithParam<RuntimeFactory> {
 public:
  JSITestBase() : factory(GetParam()), runtime(factory()), rt(*runtime) {}

  Value eval(const char* code) {
    return rt.global().getPropertyAsFunction(rt, "eval").call(rt, code);
  }

  Function function(const std::string& code) {
    return eval(("(" + code + ")").c_str()).getObject(rt).getFunction(rt);
  }

  bool checkValue(const Value& value, const std::string& jsValue) {
    return function("function(value) { return value == " + jsValue + "; }")
        .call(rt, std::move(value))
        .getBool();
  }

  RuntimeFactory factory;
  std::unique_ptr<Runtime> runtime;
  Runtime& rt;
};
} // namespace jsi
} // namespace ABI42_0_0facebook
