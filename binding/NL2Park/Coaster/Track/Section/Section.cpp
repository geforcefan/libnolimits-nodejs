#include <binding/NL2Park/Coaster/Track/Section/Section.h>
#include <binding/NL2Park/Coaster/Track/Section/Storage.h>

namespace Binding {
    namespace NL2Park {
        v8::Local<v8::Object> Section::createFromType(Library::NL2Park::Section *section) {
            v8::Local<v8::Value> argv[] = { v8::External::New(v8::Isolate::GetCurrent(), new Section(section)) };

            switch(section->getSectionType()) {
            case Library::NL2Park::Section::SectionType::Track:
                return Binding::NL2Park::Section::NewInstance(1, argv);
                break;
            case Library::NL2Park::Section::SectionType::Storage:
                return Binding::NL2Park::Storage::NewInstance(1, argv);
                break;
            default:
                return Binding::NL2Park::Section::NewInstance(1, argv);
                break;
            }
        }
    }
}
