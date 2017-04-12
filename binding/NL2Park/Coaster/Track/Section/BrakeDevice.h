#ifndef BINDING_NL2PARK_BRAKEDEVICE_H
#define BINDING_NL2PARK_BRAKEDEVICE_H

#include "Brake.h"
#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/Section/BrakeDevice.h>

namespace Binding {
    namespace NL2Park {
        class BrakeDevice : public Nan::ObjectWrap {
        public:
            explicit BrakeDevice(Library::NL2Park::BrakeDevice *brakeDevice) : _brakeDevice(brakeDevice) {}
            explicit BrakeDevice() : _brakeDevice(new Library::NL2Park::BrakeDevice) {}
            ~BrakeDevice() {}

            Library::NL2Park::BrakeDevice *getBrakeDevice() { return _brakeDevice; }

            static BINDING_MODULE_INIT("BrakeDevice",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Deceleration);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(BrakeType);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(BrakeDevice);

            BINDING_METHOD_SETTER_GETTER_ENUM(BrakeType, BrakeDevice, Library::NL2Park::Brake::BrakeType);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Deceleration, BrakeDevice);

            Library::NL2Park::BrakeDevice *_brakeDevice;
        };
    }
}

#endif // BINDING_NL2PARK_BRAKEDEVICE_H
