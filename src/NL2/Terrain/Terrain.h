#ifndef BINDING_NL2PARK_TERRAIN_H
#define BINDING_NL2PARK_TERRAIN_H

#include "../../Nolimits.h"
#include "Water.h"
#include "Layer.h"

#include <libnolimits/NL2/Terrain/Terrain.h>

namespace Binding {
    namespace NL2Park {
        class Terrain : public Nan::ObjectWrap {
        public:
            class TerrainMap {
            public:
                static BINDING_MODULE_INIT_ENUM(TerrainMap,
                    BINDING_MODULE_ENUM_FIELD(Normal, NoLimits::NoLimits2::TerrainMap);
                    BINDING_MODULE_ENUM_FIELD(Height, NoLimits::NoLimits2::TerrainMap);
                );
            };

            explicit Terrain() : _terrain(new NoLimits::NoLimits2::Terrain) {}
            explicit Terrain(NoLimits::NoLimits2::Terrain *terrain) : _terrain(terrain) {}

            ~Terrain() {}

            NoLimits::NoLimits2::Terrain *getTerrain() { return _terrain; }

            static BINDING_MODULE_INIT("Terrain",
                BINDING_PROTOTYPE_METHOD_GETTER(VertexDimX);
                BINDING_PROTOTYPE_METHOD_GETTER(VertexDimY);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(TextureRepeats);
                BINDING_PROTOTYPE_METHOD_GETTER(Water);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Layer);
                BINDING_PROTOTYPE_METHOD_GETTER_BY_NAME_VECTOR(Layer);
                BINDING_PROTOTYPE_METHOD_GETTER(NumberOfIntensityLayers);

                Nan::SetPrototypeMethod(tpl, "getHeightAtVertex", getHeightAtVertex);
                Nan::SetPrototypeMethod(tpl, "setHeightAtVertex", setHeightAtVertex);

                Nan::SetPrototypeMethod(tpl, "getIntensityAtVertex", getIntensityAtVertex);
                Nan::SetPrototypeMethod(tpl, "setIntensityAtVertex", setIntensityAtVertex);

                BINDING_PROTOTYPE_ENUM_LIST(TerrainMap);
            );

            static BINDING_NEW_INSTANCE();
        private:

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Terrain);

            BINDING_METHOD_GETTER_UNSIGNED_INTEGER(VertexDimX, Terrain);
            BINDING_METHOD_GETTER_UNSIGNED_INTEGER(VertexDimY, Terrain);
            BINDING_METHOD_GETTER_UNSIGNED_INTEGER(NumberOfIntensityLayers, Terrain);
            BINDING_METHOD_SETTER_GETTER_FLOAT_VECTOR(TextureRepeats, Terrain);
            BINDING_METHOD_SETTER_GETTER_OBJECT(Water, Terrain);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Layer, Terrain);
            BINDING_METHOD_GETTER_BY_NAME_OBJECT_VECTOR(Layer, Terrain);

            static NAN_METHOD(getHeightAtVertex) {
                if(info.Length() != 2 || !info[0]->IsNumber() || !info[1]->IsNumber())
                    Nan::ThrowTypeError("Two arguments of type number must be provided");

                Terrain* obj = ObjectWrap::Unwrap<Terrain>(info.Holder());

                uint32_t x = (uint32_t)Nan::To<int>(info[0]).FromJust();
                uint32_t y = (uint32_t)Nan::To<int>(info[1]).FromJust();

                info.GetReturnValue().Set(obj->getTerrain()->getHeightAtVertex(x, y));
            }

            static NAN_METHOD(setHeightAtVertex) {
                if(info.Length() != 3 || !info[0]->IsNumber() || !info[1]->IsNumber() || !info[2]->IsNumber())
                    Nan::ThrowTypeError("Three arguments of type number must be provided");

                Terrain* obj = ObjectWrap::Unwrap<Terrain>(info.Holder());

                uint32_t x = (uint32_t)Nan::To<int>(info[0]).FromJust();
                uint32_t y = (uint32_t)Nan::To<int>(info[1]).FromJust();
                float height = (float)Nan::To<double>(info[2]).FromJust();

                obj->getTerrain()->setHeightAtVertex(x, y, height);
            }

            static NAN_METHOD(getIntensityAtVertex) {
                if(info.Length() != 3 || !info[0]->IsNumber() || !info[1]->IsNumber() || !info[2]->IsNumber())
                    Nan::ThrowTypeError("Three arguments of type number must be provided");

                Terrain* obj = ObjectWrap::Unwrap<Terrain>(info.Holder());

                uint32_t index = (uint32_t)Nan::To<int>(info[0]).FromJust();
                uint32_t x = (uint32_t)Nan::To<int>(info[1]).FromJust();
                uint32_t y = (uint32_t)Nan::To<int>(info[2]).FromJust();

                info.GetReturnValue().Set(obj->getTerrain()->getIntensityAtVertex(index, x, y));
            }

            static NAN_METHOD(setIntensityAtVertex) {
                if(info.Length() != 4 || !info[0]->IsNumber() || !info[1]->IsNumber() || !info[2]->IsNumber() || !info[3]->IsNumber())
                    Nan::ThrowTypeError("Four arguments of type number must be provided");

                Terrain* obj = ObjectWrap::Unwrap<Terrain>(info.Holder());

                uint32_t index = (uint32_t)Nan::To<int>(info[0]).FromJust();
                uint32_t x = (uint32_t)Nan::To<int>(info[1]).FromJust();
                uint32_t y = (uint32_t)Nan::To<int>(info[2]).FromJust();
                float intensity = (float)Nan::To<double>(info[3]).FromJust();

                obj->getTerrain()->setIntensityAtVertex(index, x, y, intensity);
            }

            NoLimits::NoLimits2::Terrain *_terrain;
        };
    }
}

#endif // BINDING_NL2PARK_TERRAIN_H
