#ifndef BINDING_NL2PARK_PARK_H
#define BINDING_NL2PARK_PARK_H

#include "../Nolimits.h"
#include "Info/Info.h"
#include "Terrain/Terrain.h"
#include "Coaster/Coaster.h"
#include "Scenery/Scenery.h"

#include <libnolimits/NL2/Park.h>
#include <libnolimits/File/MemoryFile.h>

namespace Binding {
    namespace NoLimits2 {
        class Park : public Nan::ObjectWrap {
        public:
            explicit Park(std::string filepath) {
                _park = new NoLimits::NoLimits2::Park(filepath);
            }

            explicit Park() {
                _park = new NoLimits::NoLimits2::Park();
            }

            ~Park() {}

            NoLimits::NoLimits2::Park *getPark() { return _park; }

            static BINDING_MODULE_INIT("Park",
                BINDING_PROTOTYPE_METHOD_GETTER(Info);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Coaster);
                BINDING_PROTOTYPE_METHOD_GETTER_BY_NAME_VECTOR(Coaster);
                BINDING_PROTOTYPE_METHOD_GETTER(Terrain);
                BINDING_PROTOTYPE_METHOD_GETTER(Scenery);
                Nan::SetPrototypeMethod(tpl, "save", save);
            );
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW(
                Park *obj;

                if(info[0]->IsString())
                    obj = new Park(std::string(*Nan::Utf8String(info[0])));
                else
                    obj = new Park();
            );

            BINDING_METHOD_GETTER_OBJECT(Info, Park);
            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(Coaster, Park);
            BINDING_METHOD_GETTER_BY_NAME_OBJECT_VECTOR(Coaster, Park);
            BINDING_METHOD_GETTER_OBJECT(Terrain, Park);
            BINDING_METHOD_GETTER_OBJECT(Scenery, Park);

            static NAN_METHOD(save) {
                Park* obj = ObjectWrap::Unwrap<Park>(info.Holder());

                if(!info[0]->IsString())
                    Nan::ThrowTypeError("First argument must be of type string");

                obj->getPark()->save(std::string(*Nan::Utf8String(info[0])));
            }

            NoLimits::NoLimits2::Park *_park;
        };
    }
}

#endif // BINDING_NL2PARK_PARK_H
