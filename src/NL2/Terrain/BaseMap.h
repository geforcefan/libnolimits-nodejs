#ifndef BINDING_NL2PARK_BASEMAP_H
#define BINDING_NL2PARK_BASEMAP_H

#include "../../Nolimits.h"
#include <libnolimits/NL2/Terrain/BaseMap.h>

namespace Binding {
    namespace NoLimits2 {
        class BaseMap : public Nan::ObjectWrap {
        public:
            explicit BaseMap() : _baseMap(new NoLimits::NoLimits2::BaseMap) {}
            explicit BaseMap(NoLimits::NoLimits2::BaseMap *baseMap) : _baseMap(baseMap) {}

            ~BaseMap() {}

            NoLimits::NoLimits2::BaseMap *getBaseMap() { return _baseMap; }

            static BINDING_MODULE_INIT("BaseMap",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Texture);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RepeatIndex);
            );

            static BINDING_NEW_INSTANCE();
        private:

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(BaseMap);

            BINDING_METHOD_SETTER_GETTER_STRING(Texture, BaseMap);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER(RepeatIndex, BaseMap);

            NoLimits::NoLimits2::BaseMap *_baseMap;
        };
    }
}

#endif // BINDING_NL2PARK_BASEMAP_H
