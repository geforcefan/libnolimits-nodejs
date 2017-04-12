#ifndef BINDING_NL2PARK_LIFT_H
#define BINDING_NL2PARK_LIFT_H

#include <binding/nolimits.h>
#include "Section.h"
#include <lib/NL2Park/Coaster/Track/Section/Lift.h>

namespace Binding {
    namespace NL2Park {
        class LiftType {
        public:
            static BINDING_MODULE_INIT_ENUM(LiftType,
                BINDING_MODULE_ENUM_FIELD(Chain, Library::NL2Park::Lift::LiftType);
                BINDING_MODULE_ENUM_FIELD(FrictionWheels, Library::NL2Park::Lift::LiftType);
            );
        };

        class MotorLocation {
        public:
            static BINDING_MODULE_INIT_ENUM(MotorLocation,
                BINDING_MODULE_ENUM_FIELD(AtStart, Library::NL2Park::Lift::MotorLocation);
                BINDING_MODULE_ENUM_FIELD(AtEnd, Library::NL2Park::Lift::MotorLocation);
                BINDING_MODULE_ENUM_FIELD(Silent, Library::NL2Park::Lift::MotorLocation);
            );
        };

        class Lift : public Section {
        public:
            Lift(Library::NL2Park::Lift *lift) : Section(lift) {}
            Lift() : Section(new Library::NL2Park::Lift) {}

            Library::NL2Park::Lift *getLift() { return (Library::NL2Park::Lift*)getSection(); }

            static BINDING_MODULE_INIT("Lift",
                BINDING_INHERIT(Binding::NL2Park::Section);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Speed);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Acceleration);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Deceleration);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(LiftType);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(MotorLocation);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HasAntiRollbackDevice);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ShuttleModeGentle2ndPassRelease);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(DiveCoasterDropReleaseMode);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ExtraBlockLength);

                BINDING_PROTOTYPE_ENUM_LIST(LiftType);
                BINDING_PROTOTYPE_ENUM_LIST(MotorLocation);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Lift);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(Speed, Lift);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Acceleration, Lift);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Deceleration, Lift);
            BINDING_METHOD_SETTER_GETTER_ENUM(LiftType, Lift, Library::NL2Park::Lift::LiftType);
            BINDING_METHOD_SETTER_GETTER_ENUM(MotorLocation, Lift, Library::NL2Park::Lift::MotorLocation);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(HasAntiRollbackDevice, Lift);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(ShuttleModeGentle2ndPassRelease, Lift);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(DiveCoasterDropReleaseMode, Lift);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(ExtraBlockLength, Lift);
        };
    }
}

#endif // BINDING_NL2PARK_LIFT_H
