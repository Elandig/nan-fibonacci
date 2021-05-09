/*
 * MIT License. Copyright (c) 2021 Elandig
 */

#ifndef NANFIBONACCI_H
#define NANFIBONACCI_H

#include <nan.h>
#include "../lib/infint/InfInt.h"
#include "nan_fibonacci_base.hpp"

class NanFibonacci : public Nan::ObjectWrap, public NanFibonacciBase
{
public:
  static void Init(v8::Local<v8::Object> exports);

private:
  // Constructor/Destructor
  explicit NanFibonacci();
  ~NanFibonacci();
  static Nan::Persistent<v8::Function> constructor;

  // Exposed methods
  static void New(const Nan::FunctionCallbackInfo<v8::Value> &info);
  static void GetValue(const Nan::FunctionCallbackInfo<v8::Value> &info);
  static void NextValue(const Nan::FunctionCallbackInfo<v8::Value> &info);
  static void ResetValue(const Nan::FunctionCallbackInfo<v8::Value> &info);
  static void IsFibo(const Nan::FunctionCallbackInfo<v8::Value> &info);
};

#endif