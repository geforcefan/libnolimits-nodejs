#ifndef BINDING_NL2PARK_SCRIPT_H
#define BINDING_NL2PARK_SCRIPT_H

#include "../../Nolimits.h"
#include "ResourceFile.h"
#include <libnolimits/NL2/Coaster/Script.h>

namespace Binding {
    namespace NoLimits2 {
        class Script : public Nan::ObjectWrap {
        public:
            explicit Script(NoLimits::NoLimits2::Script *script) : _script(script) {}
            explicit Script() : _script(new NoLimits::NoLimits2::Script) {}
            ~Script() {}

            NoLimits::NoLimits2::Script *getScript() { return _script; }

            static BINDING_MODULE_INIT("Script",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(ResourceFile);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ScriptClass);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ClassPath);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(PrivateVirtualMachine);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Script);

            BINDING_METHOD_SETTER_GETTER_OBJECT_VECTOR(ResourceFile, Script);
            BINDING_METHOD_SETTER_GETTER_STRING(ScriptClass, Script);
            BINDING_METHOD_SETTER_GETTER_STRING(ClassPath, Script);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(PrivateVirtualMachine, Script);

            NoLimits::NoLimits2::Script *_script;
        };
    }
}

#endif // BINDING_NL2PARK_SCRIPT_H
