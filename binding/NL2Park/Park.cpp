#include "Park.h"

#include <File/BufferFile.h>
#include <Stream/NoLimitsStream.h>
#include <NL2Park/Park.h>

#include <iostream>

namespace Binding {
    namespace NL2Park {
        v8::Persistent<v8::Function> Park::constructor;

        Park::Park(std::string filepath) {
            park = new Library::NL2Park::Park();
            park->readChunk(Library::File::BufferFile::createFromFilePath(filepath));
        }

        Park::Park() {
            park = new Library::NL2Park::Park();
        }

        void Park::Init(v8::Handle<v8::Object> exports) {
            v8::Isolate* isolate = v8::Isolate::GetCurrent();

            // Prepare constructor template
            v8::Local<v8::FunctionTemplate> tpl = v8::FunctionTemplate::New(isolate, New);
            tpl->SetClassName(v8::String::NewFromUtf8(isolate, "NL2Park"));
            tpl->InstanceTemplate()->SetInternalFieldCount(1);

            // Prototype
            NODE_SET_PROTOTYPE_METHOD(tpl, "getInfo", getInfo);

            constructor.Reset(isolate, tpl->GetFunction());
            exports->Set(v8::String::NewFromUtf8(isolate, "NL2Park"), tpl->GetFunction());
        }

        void Park::getInfo(const v8::FunctionCallbackInfo<v8::Value> &args) {
            v8::Isolate* isolate = v8::Isolate::GetCurrent();
            v8::HandleScope scope(isolate);

            Park* parkBinding = ObjectWrap::Unwrap<Park>(args.Holder()); // this
            Binding::NL2Park::Info *info = new Binding::NL2Park::Info(parkBinding->getPark()->getInfo());

            Binding::NL2Park::Info::NewInstance(args);
        }

        void Park::New(const v8::FunctionCallbackInfo<v8::Value> &args) {
            v8::Isolate* isolate = v8::Isolate::GetCurrent();
            v8::HandleScope scope(isolate);

            if (args.IsConstructCall()) {
                Park* obj;

                if(args[0]->IsUndefined()) {
                    obj = new Park();
                } else {
                    std::string filepath(*v8::String::Utf8Value(args[0]->ToString()));
                    obj = new Park(filepath);
                }

                obj->Wrap(args.This());
                args.GetReturnValue().Set(args.This());
            } else {
                const int argc = 1;
                v8::Local<v8::Value> argv[argc] = { args[0] };
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
        }

        Library::NL2Park::Park *Park::getPark() const {
            return park;
        }
    }
}
