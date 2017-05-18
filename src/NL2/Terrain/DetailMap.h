#ifndef BINDING_NL2PARK_BUMPMAP_H
#define BINDING_NL2PARK_BUMPMAP_H

#include "../../Nolimits.h"
#include <libnolimits/NL2/Terrain/BumpMap.h>

namespace Binding {
    namespace NL2Park {
        class BumpMap : public Nan::ObjectWrap {
        public:
            explicit BumpMap() : _bumpMap(new NoLimits::NoLimits2::BumpMap) {}
            explicit BumpMap(NoLimits::NoLimits2::BumpMap *bumpMap) : _bumpMap(bumpMap) {}

            ~BumpMap() {}

            NoLimits::NoLimits2::BumpMap *getBumpMap() { return _bumpMap; }

            static BINDING_MODULE_INIT("BumpMap",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Texture);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(MapType);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HeightMapScale);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SpecularMapTexture);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RepeatIndex);
            );

            static BINDING_NEW_INSTANCE();
        private:

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(BumpMap);

            BINDING_METHOD_SETTER_GETTER_STRING(Texture, BumpMap);
            BINDING_METHOD_SETTER_GETTER_ENUM(MapType, BumpMap, NoLimits::NoLimits2::TerrainMap);
            BINDING_METHOD_SETTER_GETTER_FLOAT(HeightMapScale, BumpMap);
            BINDING_METHOD_SETTER_GETTER_STRING(SpecularMapTexture, BumpMap);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER(RepeatIndex, BumpMap);

            NoLimits::NoLimits2::BumpMap *_bumpMap;
        };
    }
}

#endif // BINDING_NL2PARK_BUMPMAP_H
