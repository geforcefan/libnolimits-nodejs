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
#include "NL2/Coaster/ResourceFile.h"
#include "NL2/Coaster/Script.h"
#include "NL2/Coaster/FileScript.h"
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
#include "NL2/Scenery/Scenery.h"
#include "NL2/Scenery/SceneObjectInstance.h"

void InitAll(v8::Handle<v8::Object> exports) {
    v8::Local<v8::Object> NL2Binding = Nan::New<v8::Object>();
    Binding::NoLimits2::Park::Init(NL2Binding);
    Binding::NoLimits2::Info::Init(NL2Binding);
    Binding::NoLimits2::Weather::Init(NL2Binding);
    Binding::NoLimits2::Sky::Init(NL2Binding);
    Binding::NoLimits2::Coaster::Init(NL2Binding);
    Binding::NoLimits2::Colors::Init(NL2Binding);
    Binding::NoLimits2::Style::Init(NL2Binding);
    Binding::NoLimits2::Mode::Init(NL2Binding);
    Binding::NoLimits2::CustomFriction::Init(NL2Binding);
    Binding::NoLimits2::CustomTrack::Init(NL2Binding);
    Binding::NoLimits2::Track::Init(NL2Binding);
    Binding::NoLimits2::Vertex::Init(NL2Binding);
    Binding::NoLimits2::RollPoint::Init(NL2Binding);
    Binding::NoLimits2::Trigger::Init(NL2Binding);
    Binding::NoLimits2::RailNode::Init(NL2Binding);
    Binding::NoLimits2::Segment::Init(NL2Binding);
    Binding::NoLimits2::Parameter4D::Init(NL2Binding);
    Binding::NoLimits2::WoodenSupportGenerator::Init(NL2Binding);
    Binding::NoLimits2::Section::Init(NL2Binding);
    Binding::NoLimits2::Storage::Init(NL2Binding);
    Binding::NoLimits2::TransportDevice::Init(NL2Binding);
    Binding::NoLimits2::Lift::Init(NL2Binding);
    Binding::NoLimits2::Separator::Init(NL2Binding);
    Binding::NoLimits2::Station::Init(NL2Binding);
    Binding::NoLimits2::Brake::Init(NL2Binding);
    Binding::NoLimits2::WaitTime::Init(NL2Binding);
    Binding::NoLimits2::Transport::Init(NL2Binding);
    Binding::NoLimits2::BrakeDevice::Init(NL2Binding);
    Binding::NoLimits2::Train::Init(NL2Binding);
    Binding::NoLimits2::Car::Init(NL2Binding);
    Binding::NoLimits2::IndividualColor::Init(NL2Binding);
    Binding::NoLimits2::Terrain::Init(NL2Binding);
    Binding::NoLimits2::Water::Init(NL2Binding);
    Binding::NoLimits2::Layer::Init(NL2Binding);
    Binding::NoLimits2::AutoPaint::Init(NL2Binding);
    Binding::NoLimits2::BaseMap::Init(NL2Binding);
    Binding::NoLimits2::DetailMap::Init(NL2Binding);
    Binding::NoLimits2::BumpMap::Init(NL2Binding);
    Binding::NoLimits2::Extras::Init(NL2Binding);
    Binding::NoLimits2::Scenery::Init(NL2Binding);
    Binding::NoLimits2::SceneObjectInstance::Init(NL2Binding);
    Binding::NoLimits2::ResourceFile::Init(NL2Binding);
    Binding::NoLimits2::Script::Init(NL2Binding);
    Binding::NoLimits2::FileScript::Init(NL2Binding);

    Nan::Set(exports, Nan::New("NoLimits2").ToLocalChecked(), NL2Binding);
}

NODE_MODULE(nolimits, InitAll)
