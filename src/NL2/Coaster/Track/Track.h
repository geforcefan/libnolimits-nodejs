#ifndef BINDING_NL2PARK_TRACK_H
#define BINDING_NL2PARK_TRACK_H

#include "../../../Nolimits.h"
#include <libnolimits/NL2/Coaster/Track/Track.h>

namespace Binding {
    namespace NL2Park {
        class Track : public Nan::ObjectWrap {
        public:
            explicit Track(NoLimits::NoLimits2::Track *track) : _track(track) {}
            explicit Track() : _track(new NoLimits::NoLimits2::Track) {}
            ~Track() {}

            NoLimits::NoLimits2::Track *getTrack() { return _track; }

            static BINDING_MODULE_INIT("Track",
                BINDING_PROTOTYPE_METHOD_GETTER(TrackType)
            );

            static BINDING_NEW_INSTANCE();

            static v8::Local<v8::Object> createFromType(NoLimits::NoLimits2::Track *track);
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Track);

            BINDING_METHOD_SETTER_GETTER_ENUM(TrackType, Track, NoLimits::NoLimits2::Track::TrackType);

        protected:
            NoLimits::NoLimits2::Track *_track;
        };
    }
}

#endif // BINDING_NL2PARK_CUSTOM_TRACK_H
