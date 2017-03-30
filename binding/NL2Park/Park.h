#ifndef PARK_H
#define PARK_H

#include <nan.h>
#include <node.h>
#include <node_object_wrap.h>

#include <string>

#include <File/BufferFile.h>
#include <Stream/NoLimitsStream.h>
#include <NL2Park/Park.h>

#include <binding/NL2Park/Info/Info.h>

namespace Binding {
    namespace NL2Park {
        class Park : public node::ObjectWrap {
        public:
            static void Init(v8::Handle<v8::Object> exports);

            static v8::Persistent<v8::Function> getConstructor();

            Library::NL2Park::Park *getPark() const;
        private:
            explicit Park(std::string filepath);
            explicit Park();

            static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void getInfo(const v8::FunctionCallbackInfo<v8::Value> &args);

            static v8::Persistent<v8::Function> constructor;

            Library::NL2Park::Park *park;
        };
    }
}

#endif // PARK_H
