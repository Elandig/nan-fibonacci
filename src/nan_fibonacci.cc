/*
 * MIT License. Copyright (c) 2021 Elandig
 */

#include "nan_fibonacci.hpp"

NanFibonacci::NanFibonacci()
{
  CreateArray();
}

NanFibonacci::~NanFibonacci()
{
  delete[] value_;
}

Nan::Persistent<v8::Function> NanFibonacci::constructor;

/*
 * Purpose: Initializes the v8 class
 */
void NanFibonacci::Init(v8::Local<v8::Object> exports)
{
  v8::Local<v8::Context> context = exports->CreationContext();
  Nan::HandleScope scope;

  // Constructor template
  v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New);
  tpl->SetClassName(Nan::New("NanFibonacci").ToLocalChecked());
  tpl->InstanceTemplate()->SetInternalFieldCount(1);

  // Prototype
  Nan::SetPrototypeMethod(tpl, "get", GetValue);
  Nan::SetPrototypeMethod(tpl, "next", NextValue);
  Nan::SetPrototypeMethod(tpl, "reset", ResetValue);
  Nan::SetPrototypeMethod(tpl, "isFibo", IsFibo);
  Nan::SetPrototypeMethod(tpl, "genFibo", GenFibo);

  constructor.Reset(tpl->GetFunction(context).ToLocalChecked());
  exports->Set(context, Nan::New("NanFibonacci").ToLocalChecked(), tpl->GetFunction(context).ToLocalChecked());
}

/*
 * Purpose: Creates NanFibonacci() instances depending on passed context
 */
void NanFibonacci::New(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();

  if (info.IsConstructCall())
  {
    NanFibonacci *obj = new NanFibonacci();
    obj->Wrap(info.This());
    info.GetReturnValue().Set(info.This());
  }
  else
  {
    v8::Local<v8::Function> cons = Nan::New<v8::Function>(constructor);
    info.GetReturnValue().Set(cons->NewInstance(context).ToLocalChecked());
  }
}

/*
 * Purpose: Generates and returns the next value of the fibonacci sequence
 */
void NanFibonacci::GetValue(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  NanFibonacci *obj = ObjectWrap::Unwrap<NanFibonacci>(info.Holder());
  obj->GenNextValue();
  info.GetReturnValue().Set(Nan::New(obj->GetFormattedArray()).ToLocalChecked());
}

/*
 * Purpose: Generates the next value of the fibonacci sequence
 */
void NanFibonacci::NextValue(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  NanFibonacci *obj = ObjectWrap::Unwrap<NanFibonacci>(info.Holder());
  obj->GenNextValue();
  info.GetReturnValue().Set(Nan::New(true));
}

/*
 * Purpose: Resets the instance state
 */
void NanFibonacci::ResetValue(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  NanFibonacci *obj = ObjectWrap::Unwrap<NanFibonacci>(info.Holder());
  obj->Reset();
  info.GetReturnValue().Set(Nan::New(true));
}

/*
 * Purpose: Checks if the given value is a part of the fibonacci sequence
 */
void NanFibonacci::IsFibo(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
  NanFibonacci *obj = ObjectWrap::Unwrap<NanFibonacci>(info.Holder());
  if (info.Length() < 1)
  {
    Nan::ThrowTypeError("Wrong amount of arguments");
    return;
  }
  if (info[0]->IsUndefined() || (!info[0]->IsString() && !info[0]->IsNumber()))
  {
    Nan::ThrowTypeError("Wrong argument");
    return;
  }
  info.GetReturnValue().Set(Nan::New(NanFibonacciBase::isFibonacci(InfInt(*Nan::Utf8String(info[0])))));
}

/*
 * Purpose: Generates specified amount of numbers of the fibonacci sequence 
 */
void NanFibonacci::GenFibo(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  v8::Local<v8::Context> context = info.GetIsolate()->GetCurrentContext();
  NanFibonacci *obj = ObjectWrap::Unwrap<NanFibonacci>(info.Holder());
  if (info.Length() < 1)
  {
    Nan::ThrowTypeError("Wrong amount of arguments");
    return;
  }
  if (info[0]->IsUndefined() || !info[0]->IsNumber())
  {
    Nan::ThrowTypeError("Wrong argument");
    return;
  }
  int64_t length = info[0]->NumberValue(context).FromJust();
  if (length <= 0)
  {
    Nan::ThrowTypeError("Value must be greater than zero");
    return;
  }
  info.GetReturnValue().Set(Nan::New(NanFibonacciBase::GenFibonacci(length)).ToLocalChecked());
}