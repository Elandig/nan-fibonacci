// MIT License. Copyright (c) 2021 Elandig
#include <nan.h>
#include "nan_fibonacci.h" // NOLINT(build/include)

Nan::Persistent<v8::Function> NanFibonacci::constructor;

// Variable for initialization & reset
const unsigned int initialValues[] = {0, 1, 0};

NanFibonacci::NanFibonacci()
{
  memcpy(value_, initialValues, sizeof(initialValues));
}

NanFibonacci::~NanFibonacci() {}

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
  Nan::SetPrototypeMethod(tpl, "reset", ResetValue);

  constructor.Reset(tpl->GetFunction(context).ToLocalChecked());
  exports->Set(context, Nan::New("NanFibonacci").ToLocalChecked(), tpl->GetFunction(context).ToLocalChecked());
}

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

void NanFibonacci::GetValue(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  NanFibonacci *obj = ObjectWrap::Unwrap<NanFibonacci>(info.Holder());

  info.GetReturnValue().Set(Nan::New(obj->value_[2]));

  // Not the ideal solution but it's good enough for the task I'm given
  obj->value_[0] = obj->value_[1];
  obj->value_[1] = obj->value_[2];
  obj->value_[2] = obj->value_[0] + obj->value_[1];
}

void NanFibonacci::ResetValue(const Nan::FunctionCallbackInfo<v8::Value> &info)
{
  NanFibonacci *obj = ObjectWrap::Unwrap<NanFibonacci>(info.Holder());
  memcpy(obj->value_, initialValues, sizeof(initialValues));
  info.GetReturnValue().Set(Nan::New(obj->value_[2]));
}