#ifndef BINDING_NL2PARK_PARK_H
#define BINDING_NL2PARK_PARK_H

#include <binding/nolimits.h>
#include <binding/NL2Park/Info.h>

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
            );
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW(
                Park *obj;

                if(info[0]->IsUndefined() || !info[0]->IsString())
                    obj = new Park();
                else
                    obj = new Park(std::string(*Nan::Utf8String(info[0])));
            );

            BINDING_METHOD_GETTER_OBJECT(Info, Park);

            Library::NL2Park::Park *_park;
        };
    }
}

#endif // BINDING_NL2PARK_PARK_H
