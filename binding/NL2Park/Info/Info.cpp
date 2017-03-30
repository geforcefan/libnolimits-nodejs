#include "Info.h"

#include <File/BufferFile.h>
#include <Stream/NoLimitsStream.h>
#include <NL2Park/Park.h>

#include <iostream>

namespace Binding {
    namespace NL2Park {
        v8::Persistent<v8::Function> Info::constructor;

        void Info::Init(v8::Handle<v8::Object> exports) {
            v8::Isolate* isolate = v8::Isolate::GetCurrent();

            // Prepare constructor template
            v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
            tpl->SetClassName(v8::String::NewFromUtf8(isolate, "Info"));
            tpl->InstanceTemplate()->SetInternalFieldCount(1);

            // Prototype
            BINDING_PROTOTYPE_METHOD_SETTER_GETTER(tpl, Author);
            BINDING_PROTOTYPE_METHOD_SETTER_GETTER(tpl, Description)
            BINDING_PROTOTYPE_METHOD_SETTER_GETTER(tpl, Preview)
            BINDING_PROTOTYPE_METHOD_SETTER_GETTER(tpl, Environment)

            constructor.Reset(isolate, tpl->GetFunction());
            exports->Set(v8::String::NewFromUtf8(isolate, "Info"), tpl->GetFunction());
        }

        void Info::NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args) {
            v8::Isolate* isolate = v8::Isolate::GetCurrent();
            v8::HandleScope scope(isolate);

            const unsigned argc = 1;
            v8::Handle<v8::Value> argv[argc] = { args[0] };
            v8::Local<v8::Function> cons = v8::Local<v8::Function>::New(isolate, constructor);

            Nan::MaybeLocal<v8::Object> maybeInstance = Nan::NewInstance(cons, argc, argv);
            v8::Local<v8::Object> instance;

            if (maybeInstance.IsEmpty()) {
                Nan::ThrowError("Could not create new instance");
            } else {
                instance = maybeInstance.ToLocalChecked();
                args.GetReturnValue().Set(instance);
            }
        }

        void Info::New(const v8::FunctionCallbackInfo<v8::Value> &args) {
            v8::Isolate* isolate = v8::Isolate::GetCurrent();
            v8::HandleScope scope(isolate);

            if (args.IsConstructCall()) {
                Info* obj;

                if(args[0]->IsUndefined()) {
                    obj = new Info();
                } else {
                    obj = new Info(ObjectWrap::Unwrap<Info>(args[0]->ToObject())->getInfo());
                }

                obj->Wrap(args.This());
                args.GetReturnValue().Set(args.This());
            }
        }
    }
}
