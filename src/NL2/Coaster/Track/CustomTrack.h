#ifndef BINDING_NL2PARK_CUSTOM_TRACK_H
#define BINDING_NL2PARK_CUSTOM_TRACK_H

#include "../../../Nolimits.h"
#include "Track.h"
#include "RollPoint.h"
#include "Vertex.h"
#include "Trigger.h"
#include "Parameter4D.h"
#include "Separator.h"
#include "Segment.h"
#include "../Support/RailNode.h"
#include "Section/Section.h"
#include <libnolimits/NL2/Coaster/Track/CustomTrack.h>

namespace Binding {
    namespace NoLimits2 {
        class CustomTrack : public Track {
        public:
            CustomTrack(NoLimits::NoLimits2::Track *track) : Track(track) {}
            CustomTrack() : Track(new NoLimits::NoLimits2::CustomTrack) {}

            NoLimits::NoLimits2::CustomTrack *getCustomTrack() { return (NoLimits::NoLimits2::CustomTrack*)getTrack(); }

            static BINDING_MODULE_INIT("CustomTrack",
                BINDING_INHERIT(Binding::NoLimits2::Track);

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
