#include "Track.h"
#include "CustomTrack.h"

namespace Binding {
    namespace NoLimits2 {
        v8::Local<v8::Object> Track::createFromType(NoLimits::NoLimits2::Track *track) {
            v8::Local<v8::Value> argv[] = { v8::External::New(v8::Isolate::GetCurrent(), new Track(track)) };

            switch(track->getTrackType()) {
            case NoLimits::NoLimits2::Track::TrackType::Custom:
                return Binding::NoLimits2::CustomTrack::NewInstance(1, argv);
                break;
            default:
                return Binding::NoLimits2::Track::NewInstance(1, argv);
                break;
            }
        }
    }
}
