#ifndef BINDING_NL2PARK_SEPARATOR_H
#define BINDING_NL2PARK_SEPARATOR_H

#include "../../../Nolimits.h"
#include "Section/Section.h"
#include "Segment.h"
#include <libnolimits/NL2/Coaster/Track/Separator.h>

namespace Binding {
    namespace NoLimits2 {
        class Separator : public Nan::ObjectWrap {
        public:
            explicit Separator(NoLimits::NoLimits2::Separator *separator) : _separator(separator) {}
            explicit Separator() : _separator(new NoLimits::NoLimits2::Separator) {}
            ~Separator() {}

            NoLimits::NoLimits2::Separator *getSeparator() { return _separator; }

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

            NoLimits::NoLimits2::Separator *_separator;
        };
    }
}

#endif // BINDING_NL2PARK_SEPARATOR_H
