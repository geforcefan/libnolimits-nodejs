#ifndef BINDING_NL2PARK_SEPARATOR_H
#define BINDING_NL2PARK_SEPARATOR_H

#include <binding/nolimits.h>
#include <binding/NL2Park/Coaster/Track/Section/Section.h>
#include <binding/NL2Park/Coaster/Track/Segment.h>
#include <lib/NL2Park/Coaster/Track/Separator.h>

namespace Binding {
    namespace NL2Park {
        class Separator : public Nan::ObjectWrap {
        public:
            explicit Separator(Library::NL2Park::Separator *separator) : _separator(separator) {}
            explicit Separator() : _separator(new Library::NL2Park::Separator) {}
            ~Separator() {}

            Library::NL2Park::Separator *getSeparator() { return _separator; }

            static BINDING_MODULE_INIT("Separator",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Position);
                BINDING_PROTOTYPE_METHOD_GETTER(Section);
                BINDING_PROTOTYPE_METHOD_GETTER(Segment);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Separator);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(Position, Separator);
            BINDING_METHOD_SETTER_GETTER_INHERITED_OBJECT(Section, Separator);
            BINDING_METHOD_SETTER_GETTER_OBJECT(Segment, Separator);

            Library::NL2Park::Separator *_separator;
        };
    }
}

#endif // BINDING_NL2PARK_SEPARATOR_H
