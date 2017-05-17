#ifndef BINDING_NL2PARK_TRAIN_H
#define BINDING_NL2PARK_TRAIN_H

#include <binding/nolimits.h>
#include "Car.h"
#include "IndividualColor.h"
#include <NL2/Coaster/Train.h>

namespace Binding {
    namespace NL2Park {
        class Train : public Nan::ObjectWrap {
        public:
            explicit Train(NoLimits::NoLimits2::Train *train) : _train(train) {}
            explicit Train() : _train(new NoLimits::NoLimits2::Train) {}
            ~Train() {}

            NoLimits::NoLimits2::Train *getTrain() { return _train; }

            static BINDING_MODULE_INIT("Train",
               //BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ZeroCar);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Car);
               BINDING_PROTOTYPE_METHOD_GETTER(IndividualColor);
               BINDING_PROTOTYPE_METHOD_GETTER(RunBackward);
               BINDING_PROTOTYPE_METHOD_GETTER(RemovedFromTrack);
               BINDING_PROTOTYPE_METHOD_GETTER(StartBlock);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Train);

            // @TODO: make this great again
            //BINDING_METHOD_SETTER_GETTER_OBJECT(ZeroCar, Train);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Car, Train);
            BINDING_METHOD_SETTER_GETTER_OBJECT(IndividualColor, Train);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(RunBackward, Train);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(RemovedFromTrack, Train);
            BINDING_METHOD_SETTER_GETTER_STRING(StartBlock, Train);

            NoLimits::NoLimits2::Train *_train;
        };
    }
}

#endif // BINDING_NL2PARK_TRAIN_H
