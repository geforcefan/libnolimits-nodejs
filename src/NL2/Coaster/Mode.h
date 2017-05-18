#ifndef BINDING_NL2PARK_MODE_H
#define BINDING_NL2PARK_MODE_H

#include "../../Nolimits.h"
#include "CustomFriction.h"
#include <libnolimits/NL2/Coaster/Mode.h>

namespace Binding {
    namespace NL2Park {
        class Operation {
        public:
            static BINDING_MODULE_INIT_ENUM(Operation,
                BINDING_MODULE_ENUM_FIELD(ClosedCircuit, NoLimits::NoLimits2::Mode::Operation);
                BINDING_MODULE_ENUM_FIELD(Shuttle, NoLimits::NoLimits2::Mode::Operation);
                BINDING_MODULE_ENUM_FIELD(Scripted, NoLimits::NoLimits2::Mode::Operation);
            );
        };

        class SplinePosition {
        public:
            static BINDING_MODULE_INIT_ENUM(SplinePosition,
                BINDING_MODULE_ENUM_FIELD(CenterOfRail, NoLimits::NoLimits2::Mode::SplinePosition);
                BINDING_MODULE_ENUM_FIELD(HeartLineCurrentStyle, NoLimits::NoLimits2::Mode::SplinePosition);
                BINDING_MODULE_ENUM_FIELD(Custom, NoLimits::NoLimits2::Mode::SplinePosition);
            );
        };

        class PhysicsModel {
        public:
            static BINDING_MODULE_INIT_ENUM(PhysicsModel,
                BINDING_MODULE_ENUM_FIELD(NoLimits2, NoLimits::NoLimits2::Mode::PhysicsModel);
                BINDING_MODULE_ENUM_FIELD(NoLimits2CustomFriction, NoLimits::NoLimits2::Mode::PhysicsModel);
                BINDING_MODULE_ENUM_FIELD(NoLimits22, NoLimits::NoLimits2::Mode::PhysicsModel);
                BINDING_MODULE_ENUM_FIELD(NoLimits16, NoLimits::NoLimits2::Mode::PhysicsModel);
                BINDING_MODULE_ENUM_FIELD(NoLimits1, NoLimits::NoLimits2::Mode::PhysicsModel);
            );
        };

        class Mode : public Nan::ObjectWrap {
        public:
            explicit Mode(NoLimits::NoLimits2::Mode *mode) : _mode(mode) {}
            explicit Mode() : _mode(new NoLimits::NoLimits2::Mode) {}
            ~Mode() {}

            NoLimits::NoLimits2::Mode *getMode() { return _mode; }

            static BINDING_MODULE_INIT("Mode",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(OperationMode);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SplinePosition);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(PhysicsModel);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SplinePositionOffset);

                BINDING_PROTOTYPE_METHOD_GETTER(CustomFriction);

                BINDING_PROTOTYPE_ENUM_LIST(Operation);
                BINDING_PROTOTYPE_ENUM_LIST(SplinePosition);
                BINDING_PROTOTYPE_ENUM_LIST(PhysicsModel);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Mode);

            BINDING_METHOD_SETTER_GETTER_ENUM(OperationMode, Mode, NoLimits::NoLimits2::Mode::Operation);
            BINDING_METHOD_SETTER_GETTER_ENUM(SplinePosition, Mode, NoLimits::NoLimits2::Mode::SplinePosition);
            BINDING_METHOD_SETTER_GETTER_ENUM(PhysicsModel, Mode, NoLimits::NoLimits2::Mode::PhysicsModel);
            BINDING_METHOD_SETTER_GETTER_VEC2(SplinePositionOffset, Mode);
            BINDING_METHOD_GETTER_OBJECT(CustomFriction, Mode);

            NoLimits::NoLimits2::Mode *_mode;
        };
    }
}

#endif // BINDING_NL2PARK_MODE_H
