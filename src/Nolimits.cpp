#include "Nolimits.h"

#include "NL2/Park.h"
#include "NL2/Terrain/Terrain.h"
#include "NL2/Terrain/Water.h"
#include "NL2/Terrain/Layer.h"
#include "NL2/Terrain/AutoPaint.h"
#include "NL2/Terrain/BaseMap.h"
#include "NL2/Terrain/DetailMap.h"
#include "NL2/Terrain/BumpMap.h"
#include "NL2/Terrain/Extras.h"
#include "NL2/Info/Info.h"
#include "NL2/Info/Weather.h"
#include "NL2/Info/Sky.h"
#include "NL2/Coaster/Coaster.h"
#include "NL2/Coaster/Colors.h"
#include "NL2/Coaster/Style.h"
#include "NL2/Coaster/Mode.h"
#include "NL2/Coaster/Train.h"
#include "NL2/Coaster/Car.h"
#include "NL2/Coaster/IndividualColor.h"
#include "NL2/Coaster/CustomFriction.h"
#include "NL2/Coaster/Track/CustomTrack.h"
#include "NL2/Coaster/Track/Track.h"
#include "NL2/Coaster/Track/RollPoint.h"
#include "NL2/Coaster/Track/Vertex.h"
#include "NL2/Coaster/Track/Trigger.h"
#include "NL2/Coaster/Track/Separator.h"
#include "NL2/Coaster/Track/Segment.h"
#include "NL2/Coaster/Track/WoodenSupportGenerator.h"
#include "NL2/Coaster/Track/Parameter4D.h"
#include "NL2/Coaster/Support/RailNode.h"
#include "NL2/Coaster/Track/Section/Section.h"
#include "NL2/Coaster/Track/Section/TransportDevice.h"
#include "NL2/Coaster/Track/Section/Lift.h"
#include "NL2/Coaster/Track/Section/Storage.h"
#include "NL2/Coaster/Track/Section/Station.h"
#include "NL2/Coaster/Track/Section/Transport.h"
#include "NL2/Coaster/Track/Section/WaitTime.h"
#include "NL2/Coaster/Track/Section/Brake.h"
#include "NL2/Coaster/Track/Section/BrakeDevice.h"

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
