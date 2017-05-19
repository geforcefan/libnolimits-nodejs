#ifndef BINDING_NL2PARK_SEGMENT_H
#define BINDING_NL2PARK_SEGMENT_H

#include "../../../Nolimits.h"
#include "WoodenSupportGenerator.h"
#include <libnolimits/NL2/Coaster/Track/Segment.h>

namespace Binding {
    namespace NoLimits2 {
        class Tunnel {
        public:
            static BINDING_MODULE_INIT_ENUM(Tunnel,
                BINDING_MODULE_ENUM_FIELD(None, NoLimits::NoLimits2::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(Steel, NoLimits::NoLimits2::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(Wooden, NoLimits::NoLimits2::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(RoundConcrete, NoLimits::NoLimits2::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(RectangularConcrete, NoLimits::NoLimits2::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(Virtual, NoLimits::NoLimits2::Segment::Tunnel);
            );
        };

        class TieSpacing {
        public:
            static BINDING_MODULE_INIT_ENUM(TieSpacing,
                BINDING_MODULE_ENUM_FIELD(LowestStress, NoLimits::NoLimits2::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(LowerStress, NoLimits::NoLimits2::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(LowStress, NoLimits::NoLimits2::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(Normal, NoLimits::NoLimits2::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(HighStress, NoLimits::NoLimits2::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(HighestStress, NoLimits::NoLimits2::Segment::TieSpacing);
            );
        };

        class Segment : public Nan::ObjectWrap {
        public:
            explicit Segment(NoLimits::NoLimits2::Segment *segment) : _segment(segment) {}
            explicit Segment() : _segment(new NoLimits::NoLimits2::Segment) {}
            ~Segment() {}

            NoLimits::NoLimits2::Segment *getSegment() { return _segment; }

            static BINDING_MODULE_INIT("Segment",
                BINDING_PROTOTYPE_METHOD_GETTER(WoodenSupportGenerator);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(InvisibleSegment);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(LeftRailingAndCatwalk);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(LeftRailingLights);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(LeftRailingLightsColor);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RightRailingAndCatwalk);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RightRailingLights);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RightRailingLightsColor);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(TransparentCatwalks);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(UseRailsColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(UseCrossTiesColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(UseMainSpineColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(UseHandrailsColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(UseCatwalksColor);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RailColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(CrossTiesColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(MainSpineColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HandrailsColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(CatwalksColor);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(UseSpineColorScheme);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SpineColorScheme);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Tunnel);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SpineType);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(TieSpacing);

                BINDING_PROTOTYPE_ENUM_LIST(Tunnel);
                BINDING_PROTOTYPE_ENUM_LIST(TieSpacing);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Segment);

            BINDING_METHOD_GETTER_OBJECT(WoodenSupportGenerator, Segment);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(InvisibleSegment, Segment);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(LeftRailingAndCatwalk, Segment);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(LeftRailingLights, Segment);
            BINDING_METHOD_SETTER_GETTER_VEC3(LeftRailingLightsColor, Segment);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(RightRailingAndCatwalk, Segment);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(RightRailingLights, Segment);
            BINDING_METHOD_SETTER_GETTER_VEC3(RightRailingLightsColor, Segment);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(TransparentCatwalks, Segment);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseRailsColor, Segment);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseCrossTiesColor, Segment);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseMainSpineColor, Segment);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseHandrailsColor, Segment);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseCatwalksColor, Segment);

            BINDING_METHOD_SETTER_GETTER_VEC3(RailColor, Segment);
            BINDING_METHOD_SETTER_GETTER_VEC3(CrossTiesColor, Segment);
            BINDING_METHOD_SETTER_GETTER_VEC3(MainSpineColor, Segment);
            BINDING_METHOD_SETTER_GETTER_VEC3(HandrailsColor, Segment);
            BINDING_METHOD_SETTER_GETTER_VEC3(CatwalksColor, Segment);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseSpineColorScheme, Segment);
            BINDING_METHOD_SETTER_GETTER_ENUM(SpineColorScheme, Segment, NoLimits::NoLimits2::Colors::SpineColorScheme);

            BINDING_METHOD_SETTER_GETTER_ENUM(Tunnel, Segment, NoLimits::NoLimits2::Segment::Tunnel);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_8(SpineType, Segment);
            BINDING_METHOD_SETTER_GETTER_ENUM(TieSpacing, Segment, NoLimits::NoLimits2::Segment::TieSpacing);

            NoLimits::NoLimits2::Segment *_segment;
        };
    }
}

#endif // BINDING_NL2PARK_SEGMENT_H
