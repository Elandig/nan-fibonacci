/*
 * MIT License. Copyright (c) 2021 Elandig
 */

#include "nan_fibonacci.hpp"

/*
 * Purpose: Initializes the addon modules
 */
void InitializeAll(v8::Local<v8::Object> exports)
{
  NanFibonacci::Init(exports);
}

NODE_MODULE(addon, InitializeAll)