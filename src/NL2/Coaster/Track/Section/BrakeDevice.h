#ifndef BINDING_NL2PARK_BRAKEDEVICE_H
#define BINDING_NL2PARK_BRAKEDEVICE_H

#include "../../../../Nolimits.h"
#include "Brake.h"
#include <libnolimits/NL2/Coaster/Track/Section/BrakeDevice.h>

namespace Binding {
    namespace NoLimits2 {
        class BrakeDevice : public Nan::ObjectWrap {
        public:
            explicit BrakeDevice(NoLimits::NoLimits2::BrakeDevice *brakeDevice) : _brakeDevice(brakeDevice) {}
            explicit BrakeDevice() : _brakeDevice(new NoLimits::NoLimits2::BrakeDevice) {}
            ~BrakeDevice() {}

            NoLimits::NoLimits2::BrakeDevice *getBrakeDevice() { return _brakeDevice; }

            static BINDING_MODULE_INIT("BrakeDevice",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Deceleration);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(BrakeType);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(BrakeDevice);

            BINDING_METHOD_SETTER_GETTER_ENUM(BrakeType, BrakeDevice, NoLimits::NoLimits2::Brake::BrakeType);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Deceleration, BrakeDevice);

            NoLimits::NoLimits2::BrakeDevice *_brakeDevice;
        };
    }
}

#endif // BINDING_NL2PARK_BRAKEDEVICE_H
