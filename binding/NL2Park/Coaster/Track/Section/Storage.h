#ifndef BINDING_NL2PARK_STORAGE_H
#define BINDING_NL2PARK_STORAGE_H

#include <binding/nolimits.h>
#include "Section.h"
#include "TransportDevice.h"
#include <lib/NL2Park/Coaster/Track/Section/Storage.h>

namespace Binding {
    namespace NL2Park {
        class Building {
        public:
            static BINDING_MODULE_INIT_ENUM(Building,
                BINDING_MODULE_ENUM_FIELD(None, Library::NL2Park::Storage::Building);
                BINDING_MODULE_ENUM_FIELD(Simple, Library::NL2Park::Storage::Building);
            );
        };

        class Storage : public Section {
        public:
            Storage(Library::NL2Park::Storage *storage) : Section(storage) {}
            Storage() : Section(new Library::NL2Park::Storage) {}

            Library::NL2Park::Storage *getStorage() { return (Library::NL2Park::Storage*)getSection(); }

            static BINDING_MODULE_INIT("Storage",
                BINDING_INHERIT(Binding::NL2Park::Section);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(EnableTransportDevice);
                BINDING_PROTOTYPE_METHOD_GETTER(TransportDevice);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(TransportType);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Building);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SideColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RoofColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(FrameColor);

                BINDING_PROTOTYPE_ENUM_LIST(Building);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Storage);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(EnableTransportDevice, Storage);
            BINDING_METHOD_GETTER_OBJECT(TransportDevice, Storage);
            BINDING_METHOD_SETTER_GETTER_ENUM(TransportType, Storage, Library::NL2Park::Transport::TransportType);
            BINDING_METHOD_SETTER_GETTER_ENUM(Building, Storage, Library::NL2Park::Storage::Building);
            BINDING_METHOD_SETTER_GETTER_VEC3(SideColor, Storage);
            BINDING_METHOD_SETTER_GETTER_VEC3(RoofColor, Storage);
            BINDING_METHOD_SETTER_GETTER_VEC3(FrameColor, Storage);
        };
    }
}

#endif // BINDING_NL2PARK_STORAGE_H
