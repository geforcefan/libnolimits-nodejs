#include <binding/NL2Park/Coaster/Track/Track.h>
#include <binding/NL2Park/Coaster/Track/CustomTrack.h>

namespace Binding {
    namespace NL2Park {
        v8::Local<v8::Object> Track::createFromType(NoLimits::NoLimits2::Track *track) {
            v8::Local<v8::Value> argv[] = { v8::External::New(v8::Isolate::GetCurrent(), new Track(track)) };

            switch(track->getTrackType()) {
            case NoLimits::NoLimits2::Track::TrackType::Custom:
                return Binding::NL2Park::CustomTrack::NewInstance(1, argv);
                break;
            default:
                return Binding::NL2Park::Track::NewInstance(1, argv);
                break;
            }
        }
    }
}
