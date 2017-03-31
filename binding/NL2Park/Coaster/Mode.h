#ifndef BINDING_NL2PARK_MODE_H
#define BINDING_NL2PARK_MODE_H

#include <binding/nolimits.h>
#include <binding/NL2Park/Coaster/CustomFriction.h>
#include <lib/NL2Park/Coaster/Mode.h>

namespace Binding {
    namespace NL2Park {
        class Operation {
        public:
            static BINDING_MODULE_INIT_ENUM(Operation,
                BINDING_MODULE_ENUM_FIELD(ClosedCircuit, Library::NL2Park::Mode::Operation);
                BINDING_MODULE_ENUM_FIELD(Shuttle, Library::NL2Park::Mode::Operation);
                BINDING_MODULE_ENUM_FIELD(Scripted, Library::NL2Park::Mode::Operation);
            );
        };

        class SplinePosition {
        public:
            static BINDING_MODULE_INIT_ENUM(SplinePosition,
                BINDING_MODULE_ENUM_FIELD(CenterOfRail, Library::NL2Park::Mode::SplinePosition);
                BINDING_MODULE_ENUM_FIELD(HeartLineCurrentStyle, Library::NL2Park::Mode::SplinePosition);
                BINDING_MODULE_ENUM_FIELD(Custom, Library::NL2Park::Mode::SplinePosition);
            );
        };

        class PhysicsModel {
        public:
            static BINDING_MODULE_INIT_ENUM(PhysicsModel,
                BINDING_MODULE_ENUM_FIELD(NoLimits2, Library::NL2Park::Mode::PhysicsModel);
                BINDING_MODULE_ENUM_FIELD(NoLimits2CustomFriction, Library::NL2Park::Mode::PhysicsModel);
                BINDING_MODULE_ENUM_FIELD(NoLimits22, Library::NL2Park::Mode::PhysicsModel);
                BINDING_MODULE_ENUM_FIELD(NoLimits16, Library::NL2Park::Mode::PhysicsModel);
                BINDING_MODULE_ENUM_FIELD(NoLimits1, Library::NL2Park::Mode::PhysicsModel);
            );
        };

        class Mode : public Nan::ObjectWrap {
        public:
            explicit Mode(Library::NL2Park::Mode *mode) : _mode(mode) {}
            explicit Mode() : _mode(new Library::NL2Park::Mode) {}
            ~Mode() {}

            Library::NL2Park::Mode *getMode() { return _mode; }

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

            BINDING_METHOD_SETTER_GETTER_ENUM(OperationMode, Mode, Library::NL2Park::Mode::Operation);
            BINDING_METHOD_SETTER_GETTER_ENUM(SplinePosition, Mode, Library::NL2Park::Mode::SplinePosition);
            BINDING_METHOD_SETTER_GETTER_ENUM(PhysicsModel, Mode, Library::NL2Park::Mode::PhysicsModel);
            BINDING_METHOD_SETTER_GETTER_VEC2(SplinePositionOffset, Mode);
            BINDING_METHOD_GETTER_OBJECT(CustomFriction, Mode);

            Library::NL2Park::Mode *_mode;
        };
    }
}

#endif // BINDING_NL2PARK_MODE_H
