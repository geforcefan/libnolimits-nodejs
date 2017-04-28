#ifndef BINDING_NL2PARK_BUMPMAP_H
#define BINDING_NL2PARK_BUMPMAP_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Terrain/BumpMap.h>

namespace Binding {
    namespace NL2Park {
        class BumpMap : public Nan::ObjectWrap {
        public:
            explicit BumpMap() : _bumpMap(new Library::NL2Park::BumpMap) {}
            explicit BumpMap(Library::NL2Park::BumpMap *bumpMap) : _bumpMap(bumpMap) {}

            ~BumpMap() {}

            Library::NL2Park::BumpMap *getBumpMap() { return _bumpMap; }

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
            BINDING_METHOD_SETTER_GETTER_ENUM(MapType, BumpMap, Library::NL2Park::TerrainMap);
            BINDING_METHOD_SETTER_GETTER_FLOAT(HeightMapScale, BumpMap);
            BINDING_METHOD_SETTER_GETTER_STRING(SpecularMapTexture, BumpMap);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER(RepeatIndex, BumpMap);

            Library::NL2Park::BumpMap *_bumpMap;
        };
    }
}

#endif // BINDING_NL2PARK_BUMPMAP_H
