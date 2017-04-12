#ifndef BINDING_NL2PARK_CUSTOM_TRACK_H
#define BINDING_NL2PARK_CUSTOM_TRACK_H

#include <binding/nolimits.h>
#include <binding/NL2Park/Coaster/Track/Track.h>
#include <binding/NL2Park/Coaster/Track/RollPoint.h>
#include <binding/NL2Park/Coaster/Track/Vertex.h>
#include <binding/NL2Park/Coaster/Track/Trigger.h>
#include <binding/NL2Park/Coaster/Track/Parameter4D.h>
#include <binding/NL2Park/Coaster/Track/Separator.h>
#include <binding/NL2Park/Coaster/Track/Segment.h>
#include <binding/NL2Park/Coaster/Track/Support/RailNode.h>
#include <binding/NL2Park/Coaster/Track/Section/Section.h>
#include <lib/NL2Park/Coaster/Track/CustomTrack.h>

namespace Binding {
    namespace NL2Park {
        class CustomTrack : public Track {
        public:
            CustomTrack(Library::NL2Park::Track *track) : Track(track) {}
            CustomTrack() : Track(new Library::NL2Park::CustomTrack) {}

            Library::NL2Park::CustomTrack *getCustomTrack() { return (Library::NL2Park::CustomTrack*)getTrack(); }

            static BINDING_MODULE_INIT("CustomTrack",
                BINDING_INHERIT(Binding::NL2Park::Track);

                BINDING_PROTOTYPE_METHOD_GETTER(FirstRollPoint);
                BINDING_PROTOTYPE_METHOD_GETTER(LastRollPoint);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Vertex);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(RollPoint);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Trigger);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(RailNode);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Parameter4D);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Separator);
                BINDING_PROTOTYPE_METHOD_GETTER(Segment);
                BINDING_PROTOTYPE_METHOD_GETTER(Section);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(CustomTrack);

            BINDING_METHOD_GETTER_OBJECT_WITH_VARNAME(FirstRollPoint, RollPoint, CustomTrack);
            BINDING_METHOD_GETTER_OBJECT_WITH_VARNAME(LastRollPoint, RollPoint, CustomTrack);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Vertex, CustomTrack);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(RollPoint, CustomTrack);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Trigger, CustomTrack);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(RailNode, CustomTrack);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Parameter4D, CustomTrack);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Separator, CustomTrack);

            BINDING_METHOD_SETTER_GETTER_OBJECT(Segment, CustomTrack);
            BINDING_METHOD_SETTER_GETTER_INHERITED_OBJECT(Section, CustomTrack);
        };
    }
}

#endif // BINDING_NL2PARK_CUSTOM_TRACK_H
