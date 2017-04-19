#ifndef BINDING_NL2PARK_TRAIN_H
#define BINDING_NL2PARK_TRAIN_H

#include <binding/nolimits.h>
#include "Car.h"
#include "IndividualColor.h"
#include <lib/NL2Park/Coaster/Train.h>

namespace Binding {
    namespace NL2Park {
        class Train : public Nan::ObjectWrap {
        public:
            explicit Train(Library::NL2Park::Train *train) : _train(train) {}
            explicit Train() : _train(new Library::NL2Park::Train) {}
            ~Train() {}

            Library::NL2Park::Train *getTrain() { return _train; }

            static BINDING_MODULE_INIT("Train",
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

            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Car, Train);
            BINDING_METHOD_SETTER_GETTER_OBJECT(IndividualColor, Train);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(RunBackward, Train);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(RemovedFromTrack, Train);
            BINDING_METHOD_SETTER_GETTER_STRING(StartBlock, Train);

            Library::NL2Park::Train *_train;
        };
    }
}

#endif // BINDING_NL2PARK_TRAIN_H
