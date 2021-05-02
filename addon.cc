// MIT License. Copyright (c) 2021 Elandig
#include <nan.h>
#include "nan_fibonacci.h"  // NOLINT(build/include)

void InitAll(v8::Local<v8::Object> exports) {
  NanFibonacci::Init(exports);
}

NODE_MODULE(addon, InitAll)