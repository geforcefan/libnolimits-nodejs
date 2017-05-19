#ifndef BINDING_NL2PARK_SCENERY_H
#define BINDING_NL2PARK_SCENERY_H

#include "../../Nolimits.h"
#include "SceneObjectInstance.h"
#include <libnolimits/NL2/Scenery/Scenery.h>

namespace Binding {
    namespace NoLimits2 {
        class Scenery : public Nan::ObjectWrap {
        public:
            explicit Scenery() : _scenery(new NoLimits::NoLimits2::Scenery) {}
            explicit Scenery(NoLimits::NoLimits2::Scenery *scenery) : _scenery(scenery) {}

            ~Scenery() {}

            NoLimits::NoLimits2::Scenery *getScenery() { return _scenery; }

            static BINDING_MODULE_INIT("Scenery",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(SceneObject);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(SceneObjectInstance);
            );

            static BINDING_NEW_INSTANCE();
        private:

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Scenery);

            BINDING_METHOD_SETTER_GETTER_STRING_VECTOR(SceneObject, Scenery);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(SceneObjectInstance, Scenery);

            NoLimits::NoLimits2::Scenery *_scenery;
        };
    }
}

#endif // BINDING_NL2PARK_SCENERY_H
