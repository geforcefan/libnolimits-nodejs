#ifndef BINDING_NL2PARK_STYLE_H
#define BINDING_NL2PARK_STYLE_H

#include "../../Nolimits.h"
#include <libnolimits/NL2/Coaster/Style.h>

namespace Binding {
    namespace NL2Park {
        class StyleType {
        public:
            static BINDING_MODULE_INIT_ENUM(StyleType,
                BINDING_MODULE_ENUM_FIELD(Coaster4D, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(ClassicSteelLoopingCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(ClassicSteelLoopingCoasterModern, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(CorkscrewCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GerstlauerBobsledCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GerstlauerEuroFighter, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GerstlauerEuroFighter2, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GerstlauerSpinningCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(GravityGroupTimberliner, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(HyperCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(HyperCoaster4SeatsAcross, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(HyperCoaster4SeatsStaggeredWithScoops, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(HyperCoaster4SeatsStaggered, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(InvertedCoaster2Seats, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(InvertedCoaster4Seats, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(InvertedFaceToFaceCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(InvertedImpulseCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(LimLaunchedCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(MackLaunchedCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(MaurerSoehneSpinningCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(MaurerSoehneXCarCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(RocketCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(SuspendedCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedDiveCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedFloorlessCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedFlyingCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedSitdownCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedStandUpCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(TwistedWingCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(VekomaFlyingDutchman, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(VekomaMinetrainCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(VekomaMinetrainCoasterWithLocomotive, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(VekomaMotorbikeCoaster, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(WoodenCoasterClassic4, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(WoodenCoasterClassic6, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(WoodenCoasterTrailered2, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(WoodenCoasterTrailered4, NoLimits::NoLimits2::Style::StyleType);
                BINDING_MODULE_ENUM_FIELD(ZamperlaTwisterCoaster, NoLimits::NoLimits2::Style::StyleType);
            );
        };

        class WornType {
        public:
            static BINDING_MODULE_INIT_ENUM(WornType,
                BINDING_MODULE_ENUM_FIELD(New, NoLimits::NoLimits2::Style::WornType);
                BINDING_MODULE_ENUM_FIELD(Worn, NoLimits::NoLimits2::Style::WornType);
                BINDING_MODULE_ENUM_FIELD(Rusted, NoLimits::NoLimits2::Style::WornType);
            );
        };

        class RailType {
        public:
            static BINDING_MODULE_INIT_ENUM(RailType,
                BINDING_MODULE_ENUM_FIELD(Standard, NoLimits::NoLimits2::Style::RailType);
                BINDING_MODULE_ENUM_FIELD(Striped, NoLimits::NoLimits2::Style::RailType);
            );
        };

        class Style : public Nan::ObjectWrap {
        public:
            explicit Style(NoLimits::NoLimits2::Style *style) : _style(style) {}
            explicit Style() : _style(new NoLimits::NoLimits2::Style) {}
            ~Style() {}

            NoLimits::NoLimits2::Style *getStyle() { return _style; }

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

            BINDING_METHOD_SETTER_GETTER_ENUM(StyleType, Style, NoLimits::NoLimits2::Style::StyleType);
            BINDING_METHOD_SETTER_GETTER_ENUM(WornType, Style, NoLimits::NoLimits2::Style::WornType);
            BINDING_METHOD_SETTER_GETTER_ENUM(RailType, Style, NoLimits::NoLimits2::Style::RailType);

            NoLimits::NoLimits2::Style *_style;
        };
    }
}

#endif // BINDING_NL2PARK_STYLE_H
