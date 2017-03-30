#ifndef BINDING_INFO_INFO_H
#define BINDING_INFO_INFO_H

#include <nolimits.h>

#include <string>

#include <File/BufferFile.h>
#include <Stream/NoLimitsStream.h>
#include <NL2Park/Park.h>

#include <binding/NL2Park/Info/Info.h>

namespace Binding {
    namespace NL2Park {
        class Info : public node::ObjectWrap {
        public:
            Info(Library::NL2Park::Info *_info) : info(_info) {}
            Info() : info(new Library::NL2Park::Info) {}

            static void Init(v8::Handle<v8::Object> exports);
            static v8::Persistent<v8::Function> getConstructor();

            Library::NL2Park::Info *getInfo() const { return info; }
            static void NewInstance(const v8::FunctionCallbackInfo<v8::Value> &args);
        private:
            static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
            static v8::Persistent<v8::Function> constructor;

            Library::NL2Park::Info *info;

            BINDING_METHOD_SETTER_GETTER_STRING(Author, info, Info)
            BINDING_METHOD_SETTER_GETTER_STRING(Description, info, Info)
            BINDING_METHOD_SETTER_GETTER_STRING(Preview, info, Info)
            BINDING_METHOD_SETTER_GETTER_STRING(Environment, info, Info)
        };
    }
}

#endif // INFO_H
