#ifndef BINDING_NL2PARK_CAR_H
#define BINDING_NL2PARK_CAR_H

#include <binding/nolimits.h>
#include "IndividualColor.h"
#include <lib/NL2Park/Coaster/Car.h>

namespace Binding {
    namespace NL2Park {
        class Car : public Nan::ObjectWrap {
        public:
            explicit Car(Library::NL2Park::Car *car) : _car(car) {}
            explicit Car() : _car(new Library::NL2Park::Car) {}
            ~Car() {}

            Library::NL2Park::Car *getCar() { return _car; }

            static BINDING_MODULE_INIT("Car",
                BINDING_PROTOTYPE_METHOD_GETTER(IndividualColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(IsZeroCar);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Car);

            BINDING_METHOD_SETTER_GETTER_OBJECT(IndividualColor, Car);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(IsZeroCar, Car);

            Library::NL2Park::Car *_car;
        };
    }
}

#endif // BINDING_NL2PARK_CAR_H
