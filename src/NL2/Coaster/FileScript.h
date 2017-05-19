#ifndef BINDING_NL2PARK_FILESCRIPT_H
#define BINDING_NL2PARK_FILESCRIPT_H

#include "../../Nolimits.h"
#include <libnolimits/NL2/Coaster/FileScript.h>

namespace Binding {
    namespace NoLimits2 {
        class FileScript : public Nan::ObjectWrap {
        public:
            explicit FileScript(NoLimits::NoLimits2::FileScript *fileScript) : _fileScript(fileScript) {}
            explicit FileScript() : _fileScript(new NoLimits::NoLimits2::FileScript) {}
            ~FileScript() {}

            NoLimits::NoLimits2::FileScript *getFileScript() { return _fileScript; }

            static BINDING_MODULE_INIT("FileScript",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(Path);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(FileScript);

            BINDING_METHOD_SETTER_GETTER_STRING_VECTOR(Path, FileScript);

            NoLimits::NoLimits2::FileScript *_fileScript;
        };
    }
}

#endif // BINDING_NL2PARK_FILESCRIPT_H
