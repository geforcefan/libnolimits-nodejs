#ifndef BINDING_NL2PARK_CUSTOMFRICTION_H
#define BINDING_NL2PARK_CUSTOMFRICTION_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/CustomFriction.h>

namespace Binding {
    namespace NL2Park {
        class CustomFriction : public Nan::ObjectWrap {
        public:
            explicit CustomFriction(Library::NL2Park::CustomFriction *customFriction) : _customFriction(customFriction) {}
            explicit CustomFriction() : _customFriction(new Library::NL2Park::CustomFriction) {}
            ~CustomFriction() {}

            Library::NL2Park::CustomFriction *getCustomFriction() { return _customFriction; }

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

            Library::NL2Park::CustomFriction *_customFriction;
        };
    }
}

#endif // BINDING_NL2PARK_CUSTOMFRICTION_H
