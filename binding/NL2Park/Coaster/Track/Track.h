#ifndef BINDING_NL2PARK_TRACK_H
#define BINDING_NL2PARK_TRACK_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/Track.h>

namespace Binding {
    namespace NL2Park {
        class Track : public Nan::ObjectWrap {
        public:
            explicit Track(Library::NL2Park::Track *track) : _track(track) {}
            explicit Track() : _track(new Library::NL2Park::Track) {}
            ~Track() {}

            Library::NL2Park::Track *getTrack() { return _track; }

            static BINDING_MODULE_INIT("Track",
                BINDING_PROTOTYPE_METHOD_GETTER(TrackType)
            );

            static BINDING_NEW_INSTANCE();

            static v8::Local<v8::Object> createFromType(Library::NL2Park::Track *track);
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Track);

            BINDING_METHOD_SETTER_GETTER_ENUM(TrackType, Track, Library::NL2Park::Track::TrackType);

        protected:
            Library::NL2Park::Track *_track;
        };
    }
}

#endif // BINDING_NL2PARK_CUSTOM_TRACK_H
