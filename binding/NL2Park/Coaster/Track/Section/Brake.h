#ifndef BINDING_NL2PARK_BRAKE_H
#define BINDING_NL2PARK_BRAKE_H

#include <binding/nolimits.h>
#include "Section.h"
#include "TransportDevice.h"
#include <NL2/Coaster/Track/Section/Brake.h>

namespace Binding {
    namespace NL2Park {
        class BrakeType {
        public:
            static BINDING_MODULE_INIT_ENUM(BrakeType,
                BINDING_MODULE_ENUM_FIELD(FrictionBrake, NoLimits::NoLimits2::Brake::BrakeType);
                BINDING_MODULE_ENUM_FIELD(MagneticBrake, NoLimits::NoLimits2::Brake::BrakeType);
                BINDING_MODULE_ENUM_FIELD(HideBrakeDevice, NoLimits::NoLimits2::Brake::BrakeType);
            );
        };

        class BrakeMode {
        public:
            static BINDING_MODULE_INIT_ENUM(BrakeMode,
                BINDING_MODULE_ENUM_FIELD(TrimBrake, NoLimits::NoLimits2::Brake::BrakeMode);
                BINDING_MODULE_ENUM_FIELD(BlockBrake, NoLimits::NoLimits2::Brake::BrakeMode);
            );
        };

        class Position {
        public:
            static BINDING_MODULE_INIT_ENUM(Position,
                BINDING_MODULE_ENUM_FIELD(FirstCar, NoLimits::NoLimits2::Brake::Position);
                BINDING_MODULE_ENUM_FIELD(MiddleCar, NoLimits::NoLimits2::Brake::Position);
            );
        };

        class Brake : public Section {
        public:
            Brake(NoLimits::NoLimits2::Brake *brake) : Section(brake) {}
            Brake() : Section(new NoLimits::NoLimits2::Brake) {}

            NoLimits::NoLimits2::Brake *getBrake() { return (NoLimits::NoLimits2::Brake*)getSection(); }

            static BINDING_MODULE_INIT("Brake",
                BINDING_INHERIT(Binding::NL2Park::Section);

                BINDING_PROTOTYPE_METHOD_GETTER(ExtraBlockLength);

                BINDING_PROTOTYPE_METHOD_GETTER(Mode);

                BINDING_PROTOTYPE_METHOD_GETTER(CompleteStop);
                BINDING_PROTOTYPE_METHOD_GETTER(WaitTime);

                BINDING_PROTOTYPE_METHOD_GETTER(BrakeType);

                BINDING_PROTOTYPE_METHOD_GETTER(SpeedLimit);
                BINDING_PROTOTYPE_METHOD_GETTER(Hysteresis);
                BINDING_PROTOTYPE_METHOD_GETTER(Deceleration);

                BINDING_PROTOTYPE_METHOD_GETTER(PositionOnTrain);
                BINDING_PROTOTYPE_METHOD_GETTER(PositionOnSection);

                BINDING_PROTOTYPE_METHOD_GETTER(EnableTransport);
                BINDING_PROTOTYPE_METHOD_GETTER(TransportDevice);

                BINDING_PROTOTYPE_ENUM_LIST(BrakeType);
                BINDING_PROTOTYPE_ENUM_LIST(BrakeMode);
                BINDING_PROTOTYPE_ENUM_LIST(Position);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Brake);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(ExtraBlockLength, Brake);

            BINDING_METHOD_SETTER_GETTER_ENUM(Mode, Brake, NoLimits::NoLimits2::Brake::BrakeMode);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(CompleteStop, Brake);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(WaitTime, Brake);

            BINDING_METHOD_SETTER_GETTER_ENUM(BrakeType, Brake, NoLimits::NoLimits2::Brake::BrakeType);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(SpeedLimit, Brake);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Hysteresis, Brake);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Deceleration, Brake);

            BINDING_METHOD_SETTER_GETTER_ENUM(PositionOnTrain, Brake, NoLimits::NoLimits2::Brake::Position);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(PositionOnSection, Brake);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(EnableTransport, Brake);
            BINDING_METHOD_GETTER_OBJECT(TransportDevice, Brake);
        };
    }
}

#endif // BINDING_NL2PARK_BRAKE_H
