#ifndef BINDING_NOLIMITS_H
#define BINDING_NOLIMITS_H

#include <iostream>
#include <nan.h>
#include <node.h>
#include <node_object_wrap.h>

#include <glm/common.hpp>

#define BINDING_QUOTE(name) #name

#define BINDING_NEW_INSTANCE() \
    v8::Local<v8::Object> NewInstance(int argc, v8::Local<v8::Value> argv[]) { \
      v8::Local<v8::Function> cons = Nan::New(constructor()); \
      return Nan::NewInstance(cons, argc, argv).ToLocalChecked(); \
    }

#define BINDING_MODULE_INIT(moduleName, prototypeDeclaration) \
    NAN_MODULE_INIT(Init) { \
        v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New); \
        tpl->SetClassName(Nan::New(moduleName).ToLocalChecked()); \
        tpl->InstanceTemplate()->SetInternalFieldCount(1); \
        v8::Local<v8::ObjectTemplate> itpl = tpl->InstanceTemplate(); \
        prototypeDeclaration \
        constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked()); \
        Nan::Set(target, Nan::New(moduleName).ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked()); \
    } \

#define BINDING_PERSISTENT_CONSTRUCTOR() \
    inline Nan::Persistent<v8::Function> & constructor() { \
      static Nan::Persistent<v8::Function> cons; \
      return cons; \
    }

#define BINDING_METHOD_NEW(init) \
    NAN_METHOD(New) { \
        if (info.IsConstructCall()) { \
            init \
            obj->Wrap(info.This()); \
            info.GetReturnValue().Set(info.This()); \
        } else { \
            const int argc = 1; \
            v8::Local<v8::Value> argv[argc] = {info[0]}; \
            v8::Local<v8::Function> cons = Nan::New(constructor()); \
            \
            Nan::MaybeLocal<v8::Object> maybeInstance = Nan::NewInstance(cons, argc, argv); \
            v8::Local<v8::Object> instance; \
            \
            if (maybeInstance.IsEmpty()) { \
                Nan::ThrowError("Could not create new instance"); \
            } else { \
                instance = maybeInstance.ToLocalChecked(); \
                info.GetReturnValue().Set(instance); \
            } \
        } \
    } \


#define BINDING_METHOD_NEW_CAST_EXTERNAL(className) \
    BINDING_METHOD_NEW( \
        className *obj; \
        if(!info[0]->IsUndefined() && info[0]->IsExternal()) { \
          v8::Local<v8::External> ext = info[0].As<v8::External>(); \
          obj = static_cast<className*>(ext->Value()); \
        } else { \
          obj = new className(); \
        } \
    )

#define BINDING_PROTOTYPE_METHOD(name) \
    Nan::SetPrototypeMethod(tpl, BINDING_QUOTE(name), name);

#define BINDING_PROTOTYPE_STATIC_METHOD(name) \
    tpl->Set(Nan::New(BINDING_QUOTE(name)).ToLocalChecked(), Nan::New<v8::FunctionTemplate>(name));

#define BINDING_PROTOTYPE_METHOD_SETTER_GETTER(name) \
    Nan::SetAccessor(itpl, Nan::New<v8::String>(BINDING_QUOTE(name)).ToLocalChecked(), get##name, set##name);

#define BINDING_PROTOTYPE_METHOD_GETTER(name) \
    Nan::SetAccessor(itpl, Nan::New<v8::String>(BINDING_QUOTE(name)).ToLocalChecked(), get##name);

#define BINDING_METHOD_GETTER_OBJECT(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = Nan::ObjectWrap::Unwrap<className>(info.Holder()); \
        Library::NL2Park::method *lib = obj->get##className()->get##method(); \
        Binding::NL2Park::method *binding = new Binding::NL2Park::method(lib); \
        const int argc = 1; \
        v8::Local<v8::Value> argv[] = { v8::External::New(info.GetIsolate(), binding) }; \
        info.GetReturnValue().Set(Binding::NL2Park::method::NewInstance(argc, argv)); \
    }

#define BINDING_METHOD_SETTER_GETTER_STRING(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(Nan::New<v8::String>(obj->get##className()->get##method().c_str()).ToLocalChecked()); \
    } \
    \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsString()) \
            Nan::ThrowTypeError("First argument must be of type string"); \
        obj->get##className()->set##method(std::string(*Nan::Utf8String(value))); \
    } \

#define BINDING_METHOD_SETTER_GETTER_FLOAT(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsNumber()) \
            Nan::ThrowTypeError("First argument must be of type number"); \
        obj->get##className()->set##method((float)Nan::To<double>(value).FromJust()); \
    } \


#define BINDING_METHOD_SETTER_GETTER_BOOLEAN(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsBoolean()) \
            Nan::ThrowTypeError("First argument must be of type boolen"); \
        obj->get##className()->set##method(Nan::To<bool>(value).FromJust()); \
    } \


#endif // BINDING_NOLIMITS_H
