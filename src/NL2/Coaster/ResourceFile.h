#ifndef BINDING_NL2PARK_RESOURCEFILE_H
#define BINDING_NL2PARK_RESOURCEFILE_H

#include "../../Nolimits.h"
#include <libnolimits/NL2/Coaster/ResourceFile.h>

namespace Binding {
    namespace NoLimits2 {
        class ResourceFile : public Nan::ObjectWrap {
        public:
            explicit ResourceFile(NoLimits::NoLimits2::ResourceFile *resourceFile) : _resourceFile(resourceFile) {}
            explicit ResourceFile() : _resourceFile(new NoLimits::NoLimits2::ResourceFile) {}
            ~ResourceFile() {}

            NoLimits::NoLimits2::ResourceFile *getResourceFile() { return _resourceFile; }

            static BINDING_MODULE_INIT("ResourceFile",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Id);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Path);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(ResourceFile);

            BINDING_METHOD_SETTER_GETTER_STRING(Id, ResourceFile);
            BINDING_METHOD_SETTER_GETTER_STRING(Path, ResourceFile);

            NoLimits::NoLimits2::ResourceFile *_resourceFile;
        };
    }
}

#endif // BINDING_NL2PARK_RESOURCEFILE_H
