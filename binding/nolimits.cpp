#include <binding/nolimits.h>

#include <binding/NL2Park/Park.h>
#include <binding/NL2Park/Info.h>
#include <binding/NL2Park/Weather.h>

void NL2Functions(const v8::FunctionCallbackInfo<v8::Value>& args) {
}

void InitAll(v8::Handle<v8::Object> exports) {
    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    Binding::NL2Park::Park::Init(obj);
    Binding::NL2Park::Info::Init(obj);
    Binding::NL2Park::Weather::Init(obj);

    Nan::Set(exports, Nan::New("NL2").ToLocalChecked(), obj);
}

NODE_MODULE(nolimits, InitAll)
