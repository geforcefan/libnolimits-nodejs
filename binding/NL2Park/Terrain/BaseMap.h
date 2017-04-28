#ifndef BINDING_NL2PARK_BASEMAP_H
#define BINDING_NL2PARK_BASEMAP_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Terrain/BaseMap.h>

namespace Binding {
    namespace NL2Park {
        class BaseMap : public Nan::ObjectWrap {
        public:
            explicit BaseMap() : _baseMap(new Library::NL2Park::BaseMap) {}
            explicit BaseMap(Library::NL2Park::BaseMap *baseMap) : _baseMap(baseMap) {}

            ~BaseMap() {}

            Library::NL2Park::BaseMap *getBaseMap() { return _baseMap; }

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

            Library::NL2Park::BaseMap *_baseMap;
        };
    }
}

#endif // BINDING_NL2PARK_BASEMAP_H
