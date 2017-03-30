#ifndef NOLIMITS_H
#define NOLIMITS_H

#include <nan.h>
#include <node.h>
#include <node_object_wrap.h>

#include <glm/common.hpp>

#define BINDING_QUOTE(name) #name

#define BINDING_PROTOTYPE_METHOD_SETTER_GETTER(recv, name) \
    NODE_SET_PROTOTYPE_METHOD(recv, BINDING_QUOTE(get##name), get##name); \
    NODE_SET_PROTOTYPE_METHOD(recv, BINDING_QUOTE(set##name), set##name);

#define BINDING_METHOD_SETTER_GETTER_STRING(getterMethod, object, className) \
    static void get##getterMethod(const v8::FunctionCallbackInfo<v8::Value>& args) { \
        v8::Isolate* isolate = v8::Isolate::GetCurrent(); \
        v8::HandleScope scope(isolate); \
        className* obj = ObjectWrap::Unwrap<className>(args.Holder()); \
        std::string val = obj->get##className()->get##getterMethod(); \
        args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, val.c_str())); \
    } \
    \
    static void set##getterMethod(const v8::FunctionCallbackInfo<v8::Value>& args) { \
        v8::Isolate* isolate = v8::Isolate::GetCurrent(); \
        v8::HandleScope scope(isolate); \
        className* obj = ObjectWrap::Unwrap<className>(args.Holder()); \
        if(args[0]->IsUndefined() || !args[0]->IsString()) \
            Nan::ThrowTypeError("First argument must be of type string"); \
        std::string val(*v8::String::Utf8Value(args[0]->ToString())); \
        obj->get##className()->set##getterMethod(val); \
        args.GetReturnValue().Set(v8::Boolean::New(isolate, true)); \
    } \

#endif // NOLIMITS_H
