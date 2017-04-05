#ifndef BINDING_NL2PARK_SECTION_H
#define BINDING_NL2PARK_SECTION_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/Section/Section.h>

namespace Binding {
    namespace NL2Park {
        class Section : public Nan::ObjectWrap {
        public:
            explicit Section(Library::NL2Park::Section *section) : _section(section) {}
            explicit Section() : _section(new Library::NL2Park::Section) {}
            ~Section() {}

            Library::NL2Park::Section *getSection() { return _section; }

            static BINDING_MODULE_INIT("Section",
                BINDING_PROTOTYPE_METHOD_GETTER(SectionType)
            );

            static BINDING_NEW_INSTANCE();

            static v8::Local<v8::Object> createFromType(Library::NL2Park::Section *track);
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Section);

            BINDING_METHOD_SETTER_GETTER_ENUM(SectionType, Section, Library::NL2Park::Section::SectionType);

        protected:
            Library::NL2Park::Section *_section;
        };
    }
}

#endif // BINDING_NL2PARK_SECTION_H
