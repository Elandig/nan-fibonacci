
// MIT License. Copyright (c) 2021 Elandig
#ifndef NANFIBONACCI_H
#define NANFIBONACCI_H

class NanFibonacci : public Nan::ObjectWrap
{
public:
  static void Init(v8::Local<v8::Object> exports);

private:
  explicit NanFibonacci();
  ~NanFibonacci();

  static void New(const Nan::FunctionCallbackInfo<v8::Value> &info);
  static void GetValue(const Nan::FunctionCallbackInfo<v8::Value> &info);
  static void ResetValue(const Nan::FunctionCallbackInfo<v8::Value> &info);
  static Nan::Persistent<v8::Function> constructor;
  unsigned long long value_[3];
};

#endif