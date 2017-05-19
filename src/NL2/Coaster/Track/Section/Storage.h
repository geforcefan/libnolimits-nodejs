#ifndef BINDING_NL2PARK_STORAGE_H
#define BINDING_NL2PARK_STORAGE_H

#include "../../../../Nolimits.h"
#include "Section.h"
#include "TransportDevice.h"
#include <libnolimits/NL2/Coaster/Track/Section/Storage.h>

namespace Binding {
    namespace NoLimits2 {
        class Building {
        public:
            static BINDING_MODULE_INIT_ENUM(Building,
                BINDING_MODULE_ENUM_FIELD(None, NoLimits::NoLimits2::Storage::Building);
                BINDING_MODULE_ENUM_FIELD(Simple, NoLimits::NoLimits2::Storage::Building);
            );
        };

        class Storage : public Section {
        public:
            Storage(NoLimits::NoLimits2::Storage *storage) : Section(storage) {}
            Storage() : Section(new NoLimits::NoLimits2::Storage) {}

            NoLimits::NoLimits2::Storage *getStorage() { return (NoLimits::NoLimits2::Storage*)getSection(); }

            static BINDING_MODULE_INIT("Storage",
                BINDING_INHERIT(Binding::NoLimits2::Section);
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
            BINDING_METHOD_SETTER_GETTER_ENUM(TransportType, Storage, NoLimits::NoLimits2::Transport::TransportType);
            BINDING_METHOD_SETTER_GETTER_ENUM(Building, Storage, NoLimits::NoLimits2::Storage::Building);
            BINDING_METHOD_SETTER_GETTER_VEC3(SideColor, Storage);
            BINDING_METHOD_SETTER_GETTER_VEC3(RoofColor, Storage);
            BINDING_METHOD_SETTER_GETTER_VEC3(FrameColor, Storage);
        };
    }
}

#endif // BINDING_NL2PARK_STORAGE_H
