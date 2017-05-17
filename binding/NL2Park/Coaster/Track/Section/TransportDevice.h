#ifndef BINDING_NL2PARK_TRANSPORTDEVICE_H
#define BINDING_NL2PARK_TRANSPORTDEVICE_H

#include <binding/nolimits.h>
#include <NL2/Coaster/Track/Section/TransportDevice.h>

namespace Binding {
    namespace NL2Park {
        class TransportDevice : public Nan::ObjectWrap {
        public:
            explicit TransportDevice(NoLimits::NoLimits2::TransportDevice *transportDevice) : _transportDevice(transportDevice) {}
            explicit TransportDevice() : _transportDevice(new NoLimits::NoLimits2::TransportDevice) {}
            ~TransportDevice() {}

            NoLimits::NoLimits2::TransportDevice *getTransportDevice() { return _transportDevice; }

            static BINDING_MODULE_INIT("TransportDevice",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(TransportType);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Speed);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Acceleration);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Deceleration);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Launch);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(LaunchAcceleration);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(LaunchMaxSpeed);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(TransportDevice);

            BINDING_METHOD_SETTER_GETTER_ENUM(TransportType, TransportDevice, NoLimits::NoLimits2::Transport::TransportType);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Speed, TransportDevice);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Acceleration, TransportDevice);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Deceleration, TransportDevice);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Launch, TransportDevice);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(LaunchAcceleration, TransportDevice);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(LaunchMaxSpeed, TransportDevice);

            NoLimits::NoLimits2::TransportDevice *_transportDevice;
        };
    }
}

#endif // BINDING_NL2PARK_TRANSPORTDEVICE_H
