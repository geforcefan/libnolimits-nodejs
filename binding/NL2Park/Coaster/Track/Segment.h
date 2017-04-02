#ifndef BINDING_NL2PARK_SEGMENT_H
#define BINDING_NL2PARK_SEGMENT_H

#include <binding/nolimits.h>
#include <binding/NL2Park/Coaster/Track/WoodenSupportGenerator.h>
#include <lib/NL2Park/Coaster/Track/Segment.h>

namespace Binding {
    namespace NL2Park {
        class Tunnel {
        public:
            static BINDING_MODULE_INIT_ENUM(Tunnel,
                BINDING_MODULE_ENUM_FIELD(None, Library::NL2Park::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(Steel, Library::NL2Park::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(Wooden, Library::NL2Park::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(RoundConcrete, Library::NL2Park::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(RectangularConcrete, Library::NL2Park::Segment::Tunnel);
                BINDING_MODULE_ENUM_FIELD(Virtual, Library::NL2Park::Segment::Tunnel);
            );
        };

        class TieSpacing {
        public:
            static BINDING_MODULE_INIT_ENUM(TieSpacing,
                BINDING_MODULE_ENUM_FIELD(LowestStress, Library::NL2Park::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(LowerStress, Library::NL2Park::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(LowStress, Library::NL2Park::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(Normal, Library::NL2Park::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(HighStress, Library::NL2Park::Segment::TieSpacing);
                BINDING_MODULE_ENUM_FIELD(HighestStress, Library::NL2Park::Segment::TieSpacing);
            );
        };

        class Segment : public Nan::ObjectWrap {
        public:
            explicit Segment(Library::NL2Park::Segment *segment) : _segment(segment) {}
            explicit Segment() : _segment(new Library::NL2Park::Segment) {}
            ~Segment() {}

            Library::NL2Park::Segment *getSegment() { return _segment; }

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
            BINDING_METHOD_SETTER_GETTER_ENUM(SpineColorScheme, Segment, Library::NL2Park::Colors::SpineColorScheme);

            BINDING_METHOD_SETTER_GETTER_ENUM(Tunnel, Segment, Library::NL2Park::Segment::Tunnel);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_8(SpineType, Segment);
            BINDING_METHOD_SETTER_GETTER_ENUM(TieSpacing, Segment, Library::NL2Park::Segment::TieSpacing);

            Library::NL2Park::Segment *_segment;
        };
    }
}

#endif // BINDING_NL2PARK_SEGMENT_H
