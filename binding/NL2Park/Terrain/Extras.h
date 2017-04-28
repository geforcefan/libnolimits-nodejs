#ifndef BINDING_NL2PARK_EXTRAS_H
#define BINDING_NL2PARK_EXTRAS_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Terrain/Extras.h>

namespace Binding {
    namespace NL2Park {
        class Extras : public Nan::ObjectWrap {
        public:
            explicit Extras() : _extras(new Library::NL2Park::Extras) {}
            explicit Extras(Library::NL2Park::Extras *extras) : _extras(extras) {}

            ~Extras() {}

            Library::NL2Park::Extras *getExtras() { return _extras; }

            static BINDING_MODULE_INIT("Extras",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(FootstepSounds);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(AutoplantObject);
            );

            static BINDING_NEW_INSTANCE();
        private:

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Extras);

            BINDING_METHOD_SETTER_GETTER_STRING(FootstepSounds, Extras);
            BINDING_METHOD_SETTER_GETTER_STRING(AutoplantObject, Extras);

            Library::NL2Park::Extras *_extras;
        };
    }
}

#endif // BINDING_NL2PARK_EXTRAS_H
