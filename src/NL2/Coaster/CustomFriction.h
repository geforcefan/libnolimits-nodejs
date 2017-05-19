#ifndef BINDING_NL2PARK_CUSTOMFRICTION_H
#define BINDING_NL2PARK_CUSTOMFRICTION_H

#include "../../Nolimits.h"
#include <libnolimits/NL2/Coaster/CustomFriction.h>

namespace Binding {
    namespace NoLimits2 {
        class CustomFriction : public Nan::ObjectWrap {
        public:
            explicit CustomFriction(NoLimits::NoLimits2::CustomFriction *customFriction) : _customFriction(customFriction) {}
            explicit CustomFriction() : _customFriction(new NoLimits::NoLimits2::CustomFriction) {}
            ~CustomFriction() {}

            NoLimits::NoLimits2::CustomFriction *getCustomFriction() { return _customFriction; }

            static BINDING_MODULE_INIT("CustomFriction",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ConstFrictionParameter);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(AirResistanceParameter);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(CustomFriction);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(ConstFrictionParameter, CustomFriction);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(AirResistanceParameter, CustomFriction);

            NoLimits::NoLimits2::CustomFriction *_customFriction;
        };
    }
}

#endif // BINDING_NL2PARK_CUSTOMFRICTION_H
