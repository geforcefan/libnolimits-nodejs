#ifndef BINDING_NL2PARK_COASTER_H
#define BINDING_NL2PARK_COASTER_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Coaster.h>
#include <lib/NL2Park/Coaster/Track/Track.h>
#include <lib/NL2Park/Coaster/Track/CustomTrack.h>

#include <binding/NL2Park/Coaster/Colors.h>
#include <binding/NL2Park/Coaster/Style.h>
#include <binding/NL2Park/Coaster/Mode.h>

#include <binding/NL2Park/Coaster/Track/CustomTrack.h>

namespace Binding {
    namespace NL2Park {
        class Coaster : public Nan::ObjectWrap {
        public:
            explicit Coaster(Library::NL2Park::Coaster *coaster) : _coaster(coaster) {}
            explicit Coaster() : _coaster(new Library::NL2Park::Coaster) {}
            ~Coaster() {}

            Library::NL2Park::Coaster *getCoaster() { return _coaster; }

            static BINDING_MODULE_INIT("Coaster",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Name);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Description);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HideWireframe);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Freezed);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(NumberOfCarsPerTrain);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Track);

                BINDING_PROTOTYPE_METHOD_GETTER(Colors);
                BINDING_PROTOTYPE_METHOD_GETTER(Style);
                BINDING_PROTOTYPE_METHOD_GETTER(Mode);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Coaster);

            BINDING_METHOD_SETTER_GETTER_STRING(Name, Coaster);
            BINDING_METHOD_SETTER_GETTER_STRING(Description, Coaster);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(HideWireframe, Coaster);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Freezed, Coaster);
            BINDING_METHOD_SETTER_GETTER_INTEGER(NumberOfCarsPerTrain, Coaster);

            BINDING_METHOD_GETTER_OBJECT(Colors, Coaster);
            BINDING_METHOD_GETTER_OBJECT(Style, Coaster);
            BINDING_METHOD_GETTER_OBJECT(Mode, Coaster);


            BINDING_METHOD_SETTER_GETTER_INHERITED_OBJECT_VECTOR(Track, Coaster);

            Library::NL2Park::Coaster *_coaster;
        };
    }
}

#endif // BINDING_NL2PARK_COASTER_H
