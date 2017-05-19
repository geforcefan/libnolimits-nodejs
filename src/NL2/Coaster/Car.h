#ifndef BINDING_NL2PARK_CAR_H
#define BINDING_NL2PARK_CAR_H

#include "../../Nolimits.h"
#include "IndividualColor.h"
#include <libnolimits/NL2/Coaster/Car.h>

namespace Binding {
    namespace NoLimits2 {
        class Car : public Nan::ObjectWrap {
        public:
            explicit Car(NoLimits::NoLimits2::Car *car) : _car(car) {}
            explicit Car() : _car(new NoLimits::NoLimits2::Car) {}
            ~Car() {}

            NoLimits::NoLimits2::Car *getCar() { return _car; }

            static BINDING_MODULE_INIT("Car",
                BINDING_PROTOTYPE_METHOD_GETTER(IndividualColor);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Car);

            BINDING_METHOD_SETTER_GETTER_OBJECT(IndividualColor, Car);

            NoLimits::NoLimits2::Car *_car;
        };
    }
}

#endif // BINDING_NL2PARK_CAR_H
