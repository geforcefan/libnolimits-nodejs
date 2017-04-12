#ifndef BINDING_NL2PARK_TRANSPORT_H
#define BINDING_NL2PARK_TRANSPORT_H

#include <binding/nolimits.h>
#include "Section.h"
#include <lib/NL2Park/Coaster/Track/Section/Transport.h>

namespace Binding {
    namespace NL2Park {
        class TransportType {
        public:
            static BINDING_MODULE_INIT_ENUM(TransportType,
                BINDING_MODULE_ENUM_FIELD(FrictionWheels, Library::NL2Park::Transport::TransportType);
                BINDING_MODULE_ENUM_FIELD(LinearMotor, Library::NL2Park::Transport::TransportType);
                BINDING_MODULE_ENUM_FIELD(HideDevice, Library::NL2Park::Transport::TransportType);
            );
        };

        class Transport : public Section {
        public:
            Transport(Library::NL2Park::Transport *transport) : Section(transport) {}
            Transport() : Section(new Library::NL2Park::Transport) {}

            Library::NL2Park::Transport *getTransport() { return (Library::NL2Park::Transport*)getSection(); }

            static BINDING_MODULE_INIT("Transport",
                BINDING_INHERIT(Binding::NL2Park::Section);

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
            BINDING_METHOD_SETTER_GETTER_ENUM(TransportType, Transport, Library::NL2Park::Transport::TransportType);
        };
    }
}

#endif // BINDING_NL2PARK_TRANSPORT_H
