#ifndef BINDING_NOLIMITS_H
#define BINDING_NOLIMITS_H

#include <vector>
#include <iostream>
#include <nan.h>
#include <node.h>
#include <node_object_wrap.h>

#include <glm/common.hpp>

#define BINDING_QUOTE(name) #name

#define BINDING_MODULE_INIT_ENUM(enumName, initList) \
    NAN_MODULE_INIT(Init) { \
        v8::Local<v8::Object> enums = Nan::New<v8::Object>(); \
        initList \
        Nan::Set(target, Nan::New(BINDING_QUOTE(enumName)).ToLocalChecked(), enums); \
    }

#define BINDING_PROTOTYPE_ENUM_LIST(bindingEnumClass) \
    bindingEnumClass::Init(Nan::GetFunction(tpl).ToLocalChecked());

#define BINDING_MODULE_ENUM_FIELD(enumField, className) \
    enums->Set(Nan::New(BINDING_QUOTE(enumField)).ToLocalChecked(), Nan::New(className::enumField));

#define BINDING_NEW_INSTANCE() \
    v8::Local<v8::Object> NewInstance(int argc, v8::Local<v8::Value> argv[]) { \
      v8::Local<v8::Function> cons = Nan::New(constructor()); \
      return Nan::NewInstance(cons, argc, argv).ToLocalChecked(); \
    }

#define BINDING_MODULE_INIT(moduleName, prototypeDeclaration) \
    v8::Local<v8::FunctionTemplate> Init(v8::Local<v8::Object> target) { \
        v8::Local<v8::FunctionTemplate> tpl = Nan::New<v8::FunctionTemplate>(New); \
        tpl->SetClassName(Nan::New(moduleName).ToLocalChecked()); \
        tpl->InstanceTemplate()->SetInternalFieldCount(1); \
        v8::Local<v8::ObjectTemplate> itpl = tpl->InstanceTemplate(); \
        prototypeDeclaration \
        constructor().Reset(Nan::GetFunction(tpl).ToLocalChecked()); \
        Nan::Set(target, Nan::New(moduleName).ToLocalChecked(), Nan::GetFunction(tpl).ToLocalChecked()); \
        return tpl; \
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

#define BINDING_INHERIT(className) \
    tpl->Inherit(className::Init(Nan::New<v8::Object>()));

#define BINDING_PROTOTYPE_METHOD(name) \
    Nan::SetPrototypeMethod(tpl, BINDING_QUOTE(name), name);

#define BINDING_PROTOTYPE_STATIC_METHOD(name) \
    tpl->Set(Nan::New(BINDING_QUOTE(name)).ToLocalChecked(), Nan::New<v8::FunctionTemplate>(name));

#define BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(name) \
    Nan::SetAccessor(itpl, Nan::New<v8::String>(BINDING_QUOTE(name)).ToLocalChecked(), get##name); \
    Nan::SetPrototypeMethod(tpl, BINDING_QUOTE(insert##name), insert##name);

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

#define BINDING_METHOD_SETTER_GETTER_OBJECT(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = Nan::ObjectWrap::Unwrap<className>(info.Holder()); \
        Library::NL2Park::method *lib = obj->get##className()->get##method(); \
        Binding::NL2Park::method *binding = new Binding::NL2Park::method(lib); \
        const int argc = 1; \
        v8::Local<v8::Value> argv[] = { v8::External::New(info.GetIsolate(), binding) }; \
        info.GetReturnValue().Set(Binding::NL2Park::method::NewInstance(argc, argv)); \
    } \
    static NAN_METHOD(set##method) { \
        className* self = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(info[0]->IsUndefined()) \
            return Nan::ThrowSyntaxError("1 argument must be provided"); \
        Nan::MaybeLocal<v8::Object> maybe1 = Nan::To<v8::Object>(info[0]); \
        Binding::NL2Park::method* _lib = ObjectWrap::Unwrap<Binding::NL2Park::method>(maybe1.ToLocalChecked()); \
        self->get##className()->set##method(_lib->get##method()); \
    }

#define BINDING_METHOD_GETTER_OBJECT_WITH_VARNAME(varName, method, className) \
    static NAN_GETTER(get##varName) { \
    className* obj = Nan::ObjectWrap::Unwrap<className>(info.Holder()); \
    Library::NL2Park::method *lib = obj->get##className()->get##varName(); \
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
    }

#define BINDING_METHOD_SETTER_GETTER_FLOAT(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsNumber()) \
            Nan::ThrowTypeError("First argument must be of type number"); \
        obj->get##className()->set##method((float)Nan::To<double>(value).FromJust()); \
    }

#define BINDING_METHOD_SETTER_GETTER_DOUBLE(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsNumber()) \
            Nan::ThrowTypeError("First argument must be of type number"); \
        obj->get##className()->set##method(Nan::To<double>(value).FromJust()); \
    }

#define BINDING_METHOD_SETTER_GETTER_INTEGER(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsNumber()) \
            Nan::ThrowTypeError("First argument must be of type number"); \
        obj->get##className()->set##method(Nan::To<int>(value).FromJust()); \
    }

#define BINDING_METHOD_SETTER_GETTER_UNSIGNED_8(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsNumber()) \
            Nan::ThrowTypeError("First argument must be of type number"); \
        obj->get##className()->set##method((uint8_t)Nan::To<int>(value).FromJust()); \
    }

#define BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsNumber()) \
            Nan::ThrowTypeError("First argument must be of type number"); \
        obj->get##className()->set##method((uint32_t)Nan::To<int>(value).FromJust()); \
    }

#define BINDING_METHOD_SETTER_GETTER_ENUM(method, className, cast) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsNumber()) \
            Nan::ThrowTypeError("First argument must be of type number"); \
        obj->get##className()->set##method((cast)Nan::To<int>(value).FromJust()); \
    }

#define BINDING_METHOD_SETTER_GETTER_VEC3(method, className)\
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        glm::vec3 val = obj->get##className()->get##method(); \
        v8::Local<v8::Array> aVal = Nan::New<v8::Array>(3); \
        aVal->Set(0, Nan::New(val.x)); \
        aVal->Set(1, Nan::New(val.y)); \
        aVal->Set(2, Nan::New(val.z)); \
        info.GetReturnValue().Set(aVal); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsArray()) \
            return Nan::ThrowSyntaxError("First argument must be of type array"); \
        v8::Local<v8::Array> aVal = v8::Local<v8::Array>::Cast(value); \
        if(aVal->Length() != 3) \
            return Nan::ThrowSyntaxError("3 argument must be provided of type number"); \
        obj->get##className()->set##method(glm::vec3( \
            aVal->Get(0)->IsNumber() ? Nan::To<double>(aVal->Get(0)).FromJust() : 0, \
            aVal->Get(1)->IsNumber() ? Nan::To<double>(aVal->Get(1)).FromJust() : 0, \
            aVal->Get(2)->IsNumber() ? Nan::To<double>(aVal->Get(2)).FromJust() : 0 \
        )); \
    }


#define BINDING_METHOD_SETTER_GETTER_VEC4(method, className)\
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        glm::vec4 val = obj->get##className()->get##method(); \
        v8::Local<v8::Array> aVal = Nan::New<v8::Array>(3); \
        aVal->Set(0, Nan::New(val.x)); \
        aVal->Set(1, Nan::New(val.y)); \
        aVal->Set(2, Nan::New(val.z)); \
        aVal->Set(3, Nan::New(val.w)); \
        info.GetReturnValue().Set(aVal); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsArray()) \
            return Nan::ThrowSyntaxError("First argument must be of type array"); \
        v8::Local<v8::Array> aVal = v8::Local<v8::Array>::Cast(value); \
        if(aVal->Length() != 4) \
            return Nan::ThrowSyntaxError("4 argument must be provided of type number"); \
        obj->get##className()->set##method(glm::vec4( \
            aVal->Get(0)->IsNumber() ? Nan::To<double>(aVal->Get(0)).FromJust() : 0, \
            aVal->Get(1)->IsNumber() ? Nan::To<double>(aVal->Get(1)).FromJust() : 0, \
            aVal->Get(2)->IsNumber() ? Nan::To<double>(aVal->Get(2)).FromJust() : 0, \
            aVal->Get(3)->IsNumber() ? Nan::To<double>(aVal->Get(3)).FromJust() : 0 \
        )); \
    }

#define BINDING_METHOD_SETTER_GETTER_VEC2(method, className)\
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        glm::vec2 val = obj->get##className()->get##method(); \
        v8::Local<v8::Array> aVal = Nan::New<v8::Array>(2); \
        aVal->Set(0, Nan::New(val.x)); \
        aVal->Set(1, Nan::New(val.y)); \
        info.GetReturnValue().Set(aVal); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsArray()) \
            return Nan::ThrowSyntaxError("First argument must be of type array"); \
        v8::Local<v8::Array> aVal = v8::Local<v8::Array>::Cast(value); \
        if(aVal->Length() != 2) \
            return Nan::ThrowSyntaxError("2 argument must be provided of type number"); \
        obj->get##className()->set##method(glm::vec2( \
            aVal->Get(0)->IsNumber() ? Nan::To<double>(aVal->Get(0)).FromJust() : 0, \
            aVal->Get(1)->IsNumber() ? Nan::To<double>(aVal->Get(1)).FromJust() : 0 \
        )); \
    }

#define BINDING_METHOD_SETTER_GETTER_BOOLEAN(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        info.GetReturnValue().Set(obj->get##className()->get##method()); \
    } \
    static NAN_SETTER(set##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!value->IsBoolean()) \
            Nan::ThrowTypeError("First argument must be of type boolean"); \
        obj->get##className()->set##method(Nan::To<bool>(value).FromJust()); \
    }

#define BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER_VECTOR(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        std::vector<uint32_t> vec = obj->get##className()->get##method(); \
        v8::Local<v8::Array> arr = Nan::New<v8::Array>(vec.size()); \
        for(unsigned long i = 0; i < vec.size(); i++) {\
            uint32_t val = vec[i]; \
            arr->Set(i, Nan::New(val)); \
        } \
        info.GetReturnValue().Set(arr);\
    } \
    static NAN_METHOD(insert##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(!info[0]->IsNumber()) \
            return Nan::ThrowSyntaxError("1 argument must be of type number"); \
        obj->get##className()->insert##method((uint32_t)Nan::To<int>(info[0]).FromJust()); \
    }


#define BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(method, className) \
    static NAN_GETTER(get##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        std::vector<Library::NL2Park::method*> vec = obj->get##className()->get##method(); \
        v8::Local<v8::Array> arr = Nan::New<v8::Array>(vec.size()); \
        for(unsigned long i = 0; i < vec.size(); i++) {\
            Library::NL2Park::method *lib = vec[i]; \
            Binding::NL2Park::method *binding = new Binding::NL2Park::method(lib); \
            const int argc = 1; \
            v8::Local<v8::Value> argv[] = { v8::External::New(info.GetIsolate(), binding) }; \
            arr->Set(i, Binding::NL2Park::method::NewInstance(argc, argv)); \
        } \
        info.GetReturnValue().Set(arr);\
    } \
    static NAN_METHOD(insert##method) { \
        className* obj = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(info[0]->IsUndefined()) \
            return Nan::ThrowSyntaxError("1 argument must be provided"); \
        Nan::MaybeLocal<v8::Object> maybe1 = Nan::To<v8::Object>(info[0]); \
        Binding::NL2Park::method* argObj = ObjectWrap::Unwrap<Binding::NL2Park::method>(maybe1.ToLocalChecked()); \
        obj->get##className()->insert##method(argObj->get##method()); \
    }


#define BINDING_METHOD_SETTER_GETTER_INHERITED_OBJECT_VECTOR(method, className) \
    static NAN_GETTER(get##method) { \
        className* self = ObjectWrap::Unwrap<className>(info.Holder()); \
        std::vector<Library::NL2Park::method*> vec = self->get##className()->get##method(); \
        v8::Local<v8::Array> arr = Nan::New<v8::Array>(vec.size()); \
        for(unsigned long i = 0; i < vec.size(); i++) { \
            Library::NL2Park::method *_lib = vec[i]; \
            arr->Set(i, Binding::NL2Park::method::createFromType(_lib)); \
        } \
        info.GetReturnValue().Set(arr); \
    } \
    static NAN_METHOD(insert##method) { \
        className* self = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(info[0]->IsUndefined()) \
            return Nan::ThrowSyntaxError("1 argument must be provided"); \
        Nan::MaybeLocal<v8::Object> maybe1 = Nan::To<v8::Object>(info[0]); \
        Binding::NL2Park::method* _lib = ObjectWrap::Unwrap<Binding::NL2Park::method>(maybe1.ToLocalChecked()); \
        self->get##className()->insert##method(_lib->get##method()); \
    }

#define BINDING_METHOD_SETTER_GETTER_INHERITED_OBJECT(method, className) \
    static NAN_GETTER(get##method) { \
        className* self = ObjectWrap::Unwrap<className>(info.Holder()); \
        Library::NL2Park::method *_lib = self->get##className()->get##method(); \
        info.GetReturnValue().Set(Binding::NL2Park::method::createFromType(_lib)); \
    } \
    static NAN_METHOD(set##method) { \
        className* self = ObjectWrap::Unwrap<className>(info.Holder()); \
        if(info[0]->IsUndefined()) \
            return Nan::ThrowSyntaxError("1 argument must be provided"); \
        Nan::MaybeLocal<v8::Object> maybe1 = Nan::To<v8::Object>(info[0]); \
        Binding::NL2Park::method* _lib = ObjectWrap::Unwrap<Binding::NL2Park::method>(maybe1.ToLocalChecked()); \
        self->get##className()->set##method(_lib->get##method()); \
    }

#endif // BINDING_NOLIMITS_H
