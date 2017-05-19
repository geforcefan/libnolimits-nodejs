#ifndef BINDING_NL2PARK_TRANSPORT_H
#define BINDING_NL2PARK_TRANSPORT_H

#include "../../../../Nolimits.h"
#include "Section.h"
#include <libnolimits/NL2/Coaster/Track/Section/Transport.h>

namespace Binding {
    namespace NoLimits2 {
        class TransportType {
        public:
            static BINDING_MODULE_INIT_ENUM(TransportType,
                BINDING_MODULE_ENUM_FIELD(FrictionWheels, NoLimits::NoLimits2::Transport::TransportType);
                BINDING_MODULE_ENUM_FIELD(LinearMotor, NoLimits::NoLimits2::Transport::TransportType);
                BINDING_MODULE_ENUM_FIELD(HideDevice, NoLimits::NoLimits2::Transport::TransportType);
            );
        };

        class Transport : public Section {
        public:
            Transport(NoLimits::NoLimits2::Transport *transport) : Section(transport) {}
            Transport() : Section(new NoLimits::NoLimits2::Transport) {}

            NoLimits::NoLimits2::Transport *getTransport() { return (NoLimits::NoLimits2::Transport*)getSection(); }

            static BINDING_MODULE_INIT("Transport",
                BINDING_INHERIT(Binding::NoLimits2::Section);

                BINDING_PROTOTYPE_ENUM_LIST(TransportType);

                BINDING_PROTOTYPE_METHOD_GETTER(Speed);
                BINDING_PROTOTYPE_METHOD_GETTER(Acceleration);
                BINDING_PROTOTYPE_METHOD_GETTER(Deceleration);
                BINDING_PROTOTYPE_METHOD_GETTER(SpeedingUpPasses);
                BINDING_PROTOTYPE_METHOD_GETTER(SpeedingDown);
                BINDING_PROTOTYPE_METHOD_GETTER(MinSpeed);
                BINDING_PROTOTYPE_METHOD_GETTER(TransportType);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Transport);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(Speed, Transport);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Acceleration, Transport);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Deceleration, Transport);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER(SpeedingUpPasses, Transport);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(SpeedingDown, Transport);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(MinSpeed, Transport);
            BINDING_METHOD_SETTER_GETTER_ENUM(TransportType, Transport, NoLimits::NoLimits2::Transport::TransportType);
        };
    }
}

#endif // BINDING_NL2PARK_TRANSPORT_H
