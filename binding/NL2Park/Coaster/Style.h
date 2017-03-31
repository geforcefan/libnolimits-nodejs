#ifndef BINDING_NL2PARK_STYLE_H
#define BINDING_NL2PARK_STYLE_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Style.h>

namespace Binding {
    namespace NL2Park {
        class StyleType {
        public:
            static BINDING_MODULE_INIT_ENUM(StyleType,
                BINDING_MODULE_ENUM_FIELD(Coaster4D, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(ClassicSteelLoopingCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(ClassicSteelLoopingCoasterModern, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(CorkscrewCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GerstlauerBobsledCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GerstlauerEuroFighter, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GerstlauerEuroFighter2, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GerstlauerSpinningCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GravityGroupTimberliner, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(HyperCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(HyperCoaster4SeatsAcross, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(HyperCoaster4SeatsStaggeredWithScoops, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(HyperCoaster4SeatsStaggered, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(InvertedCoaster2Seats, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(InvertedCoaster4Seats, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(InvertedFaceToFaceCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(InvertedImpulseCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(LimLaunchedCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(MackLaunchedCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(MaurerSoehneSpinningCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(MaurerSoehneXCarCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(RocketCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(SuspendedCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedDiveCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedFloorlessCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedFlyingCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedSitdownCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedStandUpCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedWingCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(VekomaFlyingDutchman, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(VekomaMinetrainCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(VekomaMinetrainCoasterWithLocomotive, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(VekomaMotorbikeCoaster, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(WoodenCoasterClassic4, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(WoodenCoasterClassic6, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(WoodenCoasterTrailered2, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(WoodenCoasterTrailered4, Library::NL2Park::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(ZamperlaTwisterCoaster, Library::NL2Park::Style::StyleType);
            );
        };

        class WornType {
        public:
            static BINDING_MODULE_INIT_ENUM(WornType,
                BINDING_MODULE_ENUM_FIELD(New, Library::NL2Park::Style::WornType);
                BINDING_MODULE_ENUM_FIELD(Worn, Library::NL2Park::Style::WornType);
                BINDING_MODULE_ENUM_FIELD(Rusted, Library::NL2Park::Style::WornType);
            );
        };

        class RailType {
        public:
            static BINDING_MODULE_INIT_ENUM(RailType,
                BINDING_MODULE_ENUM_FIELD(Standard, Library::NL2Park::Style::RailType);
                BINDING_MODULE_ENUM_FIELD(Striped, Library::NL2Park::Style::RailType);
            );
        };

        class Style : public Nan::ObjectWrap {
        public:
            explicit Style(Library::NL2Park::Style *style) : _style(style) {}
            explicit Style() : _style(new Library::NL2Park::Style) {}
            ~Style() {}

            Library::NL2Park::Style *getStyle() { return _style; }

            static BINDING_MODULE_INIT("Style",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(StyleType);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(WornType);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RailType);

                BINDING_PROTOTYPE_ENUM_LIST(StyleType);
                BINDING_PROTOTYPE_ENUM_LIST(WornType);
                BINDING_PROTOTYPE_ENUM_LIST(RailType);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Style);

            BINDING_METHOD_SETTER_GETTER_ENUM(StyleType, Style, Library::NL2Park::Style::StyleType);
            BINDING_METHOD_SETTER_GETTER_ENUM(WornType, Style, Library::NL2Park::Style::WornType);
            BINDING_METHOD_SETTER_GETTER_ENUM(RailType, Style, Library::NL2Park::Style::RailType);

            Library::NL2Park::Style *_style;
        };
    }
}

#endif // BINDING_NL2PARK_STYLE_H
