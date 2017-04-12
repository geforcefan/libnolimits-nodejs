#include <binding/nolimits.h>

#include <binding/NL2Park/Park.h>
#include <binding/NL2Park/Info/Info.h>
#include <binding/NL2Park/Info/Weather.h>
#include <binding/NL2Park/Info/Sky.h>
#include <binding/NL2Park/Coaster/Coaster.h>
#include <binding/NL2Park/Coaster/Colors.h>
#include <binding/NL2Park/Coaster/Style.h>
#include <binding/NL2Park/Coaster/Mode.h>
#include <binding/NL2Park/Coaster/CustomFriction.h>
#include <binding/NL2Park/Coaster/Track/CustomTrack.h>
#include <binding/NL2Park/Coaster/Track/Track.h>
#include <binding/NL2Park/Coaster/Track/RollPoint.h>
#include <binding/NL2Park/Coaster/Track/Vertex.h>
#include <binding/NL2Park/Coaster/Track/Trigger.h>
#include <binding/NL2Park/Coaster/Track/Separator.h>
#include <binding/NL2Park/Coaster/Track/Segment.h>
#include <binding/NL2Park/Coaster/Track/WoodenSupportGenerator.h>
#include <binding/NL2Park/Coaster/Track/Parameter4D.h>
#include <binding/NL2Park/Coaster/Track/Support/RailNode.h>
#include <binding/NL2Park/Coaster/Track/Section/Section.h>
#include <binding/NL2Park/Coaster/Track/Section/TransportDevice.h>
#include <binding/NL2Park/Coaster/Track/Section/Lift.h>
#include <binding/NL2Park/Coaster/Track/Section/Storage.h>
#include <binding/NL2Park/Coaster/Track/Section/Station.h>
#include <binding/NL2Park/Coaster/Track/Section/Transport.h>
#include <binding/NL2Park/Coaster/Track/Section/WaitTime.h>
#include <binding/NL2Park/Coaster/Track/Section/Brake.h>
#include <binding/NL2Park/Coaster/Track/Section/BrakeDevice.h>

void NL2Functions(const v8::FunctionCallbackInfo<v8::Value>& args) {
}

void InitAll(v8::Handle<v8::Object> exports) {
    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    Binding::NL2Park::Park::Init(obj);
    Binding::NL2Park::Info::Init(obj);
    Binding::NL2Park::Weather::Init(obj);
    Binding::NL2Park::Sky::Init(obj);
    Binding::NL2Park::Coaster::Init(obj);
    Binding::NL2Park::Colors::Init(obj);
    Binding::NL2Park::Style::Init(obj);
    Binding::NL2Park::Mode::Init(obj);
    Binding::NL2Park::CustomFriction::Init(obj);
    Binding::NL2Park::CustomTrack::Init(obj);
    Binding::NL2Park::Track::Init(obj);
    Binding::NL2Park::Vertex::Init(obj);
    Binding::NL2Park::RollPoint::Init(obj);
    Binding::NL2Park::Trigger::Init(obj);
    Binding::NL2Park::RailNode::Init(obj);
    Binding::NL2Park::Segment::Init(obj);
    Binding::NL2Park::Parameter4D::Init(obj);
    Binding::NL2Park::WoodenSupportGenerator::Init(obj);
    Binding::NL2Park::Section::Init(obj);
    Binding::NL2Park::Storage::Init(obj);
    Binding::NL2Park::TransportDevice::Init(obj);
    Binding::NL2Park::Lift::Init(obj);
    Binding::NL2Park::Separator::Init(obj);
    Binding::NL2Park::Station::Init(obj);
    Binding::NL2Park::Brake::Init(obj);
    Binding::NL2Park::WaitTime::Init(obj);
    Binding::NL2Park::Transport::Init(obj);
    Binding::NL2Park::BrakeDevice::Init(obj);

    Nan::Set(exports, Nan::New("NL2").ToLocalChecked(), obj);
}

NODE_MODULE(nolimits, InitAll)
