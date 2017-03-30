#include <cmath>
#include <iostream>
#include <nan.h>

#include <binding/NL2Park/Park.h>
#include <binding/NL2Park/Info/Info.h>

void Init(v8::Handle<v8::Object> exports) {
    Binding::NL2Park::Park::Init(exports);
    Binding::NL2Park::Info::Init(exports);
}


NODE_MODULE(nolimits, Init)
