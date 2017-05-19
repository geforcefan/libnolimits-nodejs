#ifndef BINDING_NL2PARK_SCENEOBJECTINSTANCE_H
#define BINDING_NL2PARK_SCENEOBJECTINSTANCE_H

#include "../../Nolimits.h"
#include <libnolimits/NL2/Scenery/SceneObjectInstance.h>

namespace Binding {
    namespace NoLimits2 {
        class SceneObjectInstance : public Nan::ObjectWrap {
        public:
            explicit SceneObjectInstance() : _sceneObjectInstance(new NoLimits::NoLimits2::SceneObjectInstance) {}
            explicit SceneObjectInstance(NoLimits::NoLimits2::SceneObjectInstance *sceneObjectInstance) : _sceneObjectInstance(sceneObjectInstance) {}

            ~SceneObjectInstance() {}

            NoLimits::NoLimits2::SceneObjectInstance *getSceneObjectInstance() { return _sceneObjectInstance; }

            static BINDING_MODULE_INIT("SceneObjectInstance",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Name);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SceneObjectIndex);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Position);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Scale);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Rotation);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Lock);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(LockOnTerrain);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(DimObject);
            );

            static BINDING_NEW_INSTANCE();
        private:

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(SceneObjectInstance);

            BINDING_METHOD_SETTER_GETTER_STRING(Name, SceneObjectInstance);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER(SceneObjectIndex, SceneObjectInstance);
            BINDING_METHOD_SETTER_GETTER_VEC3(Position, SceneObjectInstance);
            BINDING_METHOD_SETTER_GETTER_VEC3(Scale, SceneObjectInstance);
            BINDING_METHOD_SETTER_GETTER_VEC3(Rotation, SceneObjectInstance);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Lock, SceneObjectInstance);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(LockOnTerrain, SceneObjectInstance);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(DimObject, SceneObjectInstance);

            NoLimits::NoLimits2::SceneObjectInstance *_sceneObjectInstance;
        };
    }
}

#endif // BINDING_NL2PARK_SCENEOBJECTINSTANCE_H
