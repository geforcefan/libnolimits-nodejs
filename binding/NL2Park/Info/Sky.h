#ifndef BINDING_NL2PARK_SKY_H
#define BINDING_NL2PARK_SKY_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Info/Sky.h>

namespace Binding {
    namespace NL2Park {
        class Sky : public Nan::ObjectWrap {
        public:
            explicit Sky(Library::NL2Park::Sky *sky) : _sky(sky) {}
            explicit Sky() : _sky(new Library::NL2Park::Sky) {}
            ~Sky() {}

            Library::NL2Park::Sky *getSky() { return _sky; }

            static BINDING_MODULE_INIT("Sky",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(OverrideDefaultDateTime);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(CurrentDate);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(CurrentTime);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Sky);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(OverrideDefaultDateTime, Sky);
            BINDING_METHOD_SETTER_GETTER_VEC2(CurrentDate, Sky);
            BINDING_METHOD_SETTER_GETTER_VEC2(CurrentTime, Sky);

            Library::NL2Park::Sky *_sky;
        };
    }
}

#endif // BINDING_NL2PARK_SKY_H
