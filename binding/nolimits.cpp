#include <binding/nolimits.h>

#include <binding/NL2Park/Park.h>
#include <binding/NL2Park/Terrain/Terrain.h>
#include <binding/NL2Park/Terrain/Water.h>
#include <binding/NL2Park/Terrain/Layer.h>
#include <binding/NL2Park/Terrain/AutoPaint.h>
#include <binding/NL2Park/Terrain/BaseMap.h>
#include <binding/NL2Park/Terrain/DetailMap.h>
#include <binding/NL2Park/Terrain/BumpMap.h>
#include <binding/NL2Park/Terrain/Extras.h>
#include <binding/NL2Park/Info/Info.h>
#include <binding/NL2Park/Info/Weather.h>
#include <binding/NL2Park/Info/Sky.h>
#include <binding/NL2Park/Coaster/Coaster.h>
#include <binding/NL2Park/Coaster/Colors.h>
#include <binding/NL2Park/Coaster/Style.h>
#include <binding/NL2Park/Coaster/Mode.h>
#include <binding/NL2Park/Coaster/Train.h>
#include <binding/NL2Park/Coaster/Car.h>
#include <binding/NL2Park/Coaster/IndividualColor.h>
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
#include <binding/NL2Park/Coaster/Support/RailNode.h>
#include <binding/NL2Park/Coaster/Track/Section/Section.h>
#include <binding/NL2Park/Coaster/Track/Section/TransportDevice.h>
#include <binding/NL2Park/Coaster/Track/Section/Lift.h>
#include <binding/NL2Park/Coaster/Track/Section/Storage.h>
#include <binding/NL2Park/Coaster/Track/Section/Station.h>
#include <binding/NL2Park/Coaster/Track/Section/Transport.h>
#include <binding/NL2Park/Coaster/Track/Section/WaitTime.h>
#include <binding/NL2Park/Coaster/Track/Section/Brake.h>
#include <binding/NL2Park/Coaster/Track/Section/BrakeDevice.h>

void InitAll(v8::Handle<v8::Object> exports) {
    v8::Local<v8::Object> NL2Binding = Nan::New<v8::Object>();
    Binding::NL2Park::Park::Init(NL2Binding);
    Binding::NL2Park::Info::Init(NL2Binding);
    Binding::NL2Park::Weather::Init(NL2Binding);
    Binding::NL2Park::Sky::Init(NL2Binding);
    Binding::NL2Park::Coaster::Init(NL2Binding);
    Binding::NL2Park::Colors::Init(NL2Binding);
    Binding::NL2Park::Style::Init(NL2Binding);
    Binding::NL2Park::Mode::Init(NL2Binding);
    Binding::NL2Park::CustomFriction::Init(NL2Binding);
    Binding::NL2Park::CustomTrack::Init(NL2Binding);
    Binding::NL2Park::Track::Init(NL2Binding);
    Binding::NL2Park::Vertex::Init(NL2Binding);
    Binding::NL2Park::RollPoint::Init(NL2Binding);
    Binding::NL2Park::Trigger::Init(NL2Binding);
    Binding::NL2Park::RailNode::Init(NL2Binding);
    Binding::NL2Park::Segment::Init(NL2Binding);
    Binding::NL2Park::Parameter4D::Init(NL2Binding);
    Binding::NL2Park::WoodenSupportGenerator::Init(NL2Binding);
    Binding::NL2Park::Section::Init(NL2Binding);
    Binding::NL2Park::Storage::Init(NL2Binding);
    Binding::NL2Park::TransportDevice::Init(NL2Binding);
    Binding::NL2Park::Lift::Init(NL2Binding);
    Binding::NL2Park::Separator::Init(NL2Binding);
    Binding::NL2Park::Station::Init(NL2Binding);
    Binding::NL2Park::Brake::Init(NL2Binding);
    Binding::NL2Park::WaitTime::Init(NL2Binding);
    Binding::NL2Park::Transport::Init(NL2Binding);
    Binding::NL2Park::BrakeDevice::Init(NL2Binding);
    Binding::NL2Park::Train::Init(NL2Binding);
    Binding::NL2Park::Car::Init(NL2Binding);
    Binding::NL2Park::IndividualColor::Init(NL2Binding);
    Binding::NL2Park::Terrain::Init(NL2Binding);
    Binding::NL2Park::Water::Init(NL2Binding);
    Binding::NL2Park::Layer::Init(NL2Binding);
    Binding::NL2Park::AutoPaint::Init(NL2Binding);
    Binding::NL2Park::BaseMap::Init(NL2Binding);
    Binding::NL2Park::DetailMap::Init(NL2Binding);
    Binding::NL2Park::BumpMap::Init(NL2Binding);
    Binding::NL2Park::Extras::Init(NL2Binding);

    Nan::Set(exports, Nan::New("NL2").ToLocalChecked(), NL2Binding);
}

NODE_MODULE(nolimits, InitAll)
