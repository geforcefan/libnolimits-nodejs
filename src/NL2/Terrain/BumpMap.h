#ifndef BINDING_NL2PARK_DETAILMAP_H
#define BINDING_NL2PARK_DETAILMAP_H

#include "../../Nolimits.h"
#include <libnolimits/NL2/Terrain/DetailMap.h>

namespace Binding {
    namespace NL2Park {
        class DetailMap : public Nan::ObjectWrap {
        public:
            explicit DetailMap() : _detailMap(new NoLimits::NoLimits2::DetailMap) {}
            explicit DetailMap(NoLimits::NoLimits2::DetailMap *detailMap) : _detailMap(detailMap) {}

            ~DetailMap() {}

            NoLimits::NoLimits2::DetailMap *getDetailMap() { return _detailMap; }

            static BINDING_MODULE_INIT("DetailMap",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Texture);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RepeatIndex);
            );

            static BINDING_NEW_INSTANCE();
        private:

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(DetailMap);

            BINDING_METHOD_SETTER_GETTER_STRING(Texture, DetailMap);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER(RepeatIndex, DetailMap);

            NoLimits::NoLimits2::DetailMap *_detailMap;
        };
    }
}

#endif // BINDING_NL2PARK_DETAILMAP_H
