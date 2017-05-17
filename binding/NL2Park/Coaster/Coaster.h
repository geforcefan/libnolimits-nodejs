#ifndef BINDING_NL2PARK_COASTER_H
#define BINDING_NL2PARK_COASTER_H

#include <binding/nolimits.h>
#include <NL2/Coaster/Coaster.h>
#include <NL2/Coaster/Track/Track.h>
#include <NL2/Coaster/Track/CustomTrack.h>

#include <binding/NL2Park/Coaster/Colors.h>
#include <binding/NL2Park/Coaster/Style.h>
#include <binding/NL2Park/Coaster/Mode.h>
#include <binding/NL2Park/Coaster/Train.h>

#include <binding/NL2Park/Coaster/Track/CustomTrack.h>

namespace Binding {
    namespace NL2Park {
        class Coaster : public Nan::ObjectWrap {
        public:
            explicit Coaster(NoLimits::NoLimits2::Coaster *coaster) : _coaster(coaster) {}
            explicit Coaster() : _coaster(new NoLimits::NoLimits2::Coaster) {}
            ~Coaster() {}

            NoLimits::NoLimits2::Coaster *getCoaster() { return _coaster; }

            static BINDING_MODULE_INIT("Coaster",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Name);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Description);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HideWireframe);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Freezed);
                //BINDING_PROTOTYPE_METHOD_SETTER_GETTER(NumberOfCarsPerTrain);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Track);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Train);

                BINDING_PROTOTYPE_METHOD_GETTER(Colors);
                BINDING_PROTOTYPE_METHOD_GETTER(Style);
                BINDING_PROTOTYPE_METHOD_GETTER(Mode);
                BINDING_PROTOTYPE_METHOD_GETTER_BY_NAME_VECTOR(Section);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Coaster);

            BINDING_METHOD_SETTER_GETTER_STRING(Name, Coaster);
            BINDING_METHOD_SETTER_GETTER_STRING(Description, Coaster);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(HideWireframe, Coaster);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Freezed, Coaster);
            //BINDING_METHOD_SETTER_GETTER_INTEGER(NumberOfCarsPerTrain, Coaster);

            BINDING_METHOD_GETTER_OBJECT(Colors, Coaster);
            BINDING_METHOD_GETTER_OBJECT(Style, Coaster);
            BINDING_METHOD_GETTER_OBJECT(Mode, Coaster);

            BINDING_METHOD_SETTER_GETTER_INHERITED_OBJECT_VECTOR(Track, Coaster);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Train, Coaster);
            BINDING_METHOD_GETTER_BY_NAME_INHERITED_OBJECT_VECTOR(Section, Coaster);

            NoLimits::NoLimits2::Coaster *_coaster;
        };
    }
}

#endif // BINDING_NL2PARK_COASTER_H
