#ifndef BINDING_NL2PARK_SECTION_H
#define BINDING_NL2PARK_SECTION_H

#include "../../../../Nolimits.h"
#include <libnolimits/NL2/Coaster/Track/Section/Section.h>

namespace Binding {
    namespace NoLimits2 {
        class Section : public Nan::ObjectWrap {
        public:
            explicit Section(NoLimits::NoLimits2::Section *section) : _section(section) {}
            explicit Section() : _section(new NoLimits::NoLimits2::Section) {}
            ~Section() {}

            NoLimits::NoLimits2::Section *getSection() { return _section; }

            static BINDING_MODULE_INIT("Section",
                BINDING_PROTOTYPE_METHOD_GETTER(SectionType)
            );

            static BINDING_NEW_INSTANCE();

            static v8::Local<v8::Object> createFromType(NoLimits::NoLimits2::Section *track);
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Section);

            BINDING_METHOD_SETTER_GETTER_ENUM(SectionType, Section, NoLimits::NoLimits2::Section::SectionType);

        protected:
            NoLimits::NoLimits2::Section *_section;
        };
    }
}

#endif // BINDING_NL2PARK_SECTION_H
