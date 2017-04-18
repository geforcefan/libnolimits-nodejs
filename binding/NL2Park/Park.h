#ifndef BINDING_NL2PARK_PARK_H
#define BINDING_NL2PARK_PARK_H

#include <binding/nolimits.h>
#include <binding/NL2Park/Info/Info.h>
#include <binding/NL2Park/Coaster/Coaster.h>

#include <lib/NL2Park/Park.h>
#include <lib/File/BufferFile.h>

namespace Binding {
    namespace NL2Park {
        class Park : public Nan::ObjectWrap {
        public:
            explicit Park(std::string filepath) {
                _park = new Library::NL2Park::Park();
                _park->readChunk(Library::File::BufferFile::createFromFilePath(filepath));
            }

            explicit Park() {}
            ~Park() {}

            Library::NL2Park::Park *getPark() { return _park; }

            static BINDING_MODULE_INIT("Park",
                BINDING_PROTOTYPE_METHOD_GETTER(Info);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Coaster);
                BINDING_PROTOTYPE_METHOD_GETTER_BY_NAME_VECTOR(Coaster);
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

            Library::NL2Park::Park *_park;
        };
    }
}

#endif // BINDING_NL2PARK_PARK_H
