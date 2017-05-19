#include "Section.h"
#include "Storage.h"
#include "Lift.h"
#include "Transport.h"
#include "Brake.h"
#include "Station.h"

namespace Binding {
    namespace NoLimits2 {
        v8::Local<v8::Object> Section::createFromType(NoLimits::NoLimits2::Section *section) {
            v8::Local<v8::Value> argv[] = { v8::External::New(v8::Isolate::GetCurrent(), new Section(section)) };

            switch(section->getSectionType()) {
            case NoLimits::NoLimits2::Section::SectionType::Track:
                return Binding::NoLimits2::Section::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Storage:
                return Binding::NoLimits2::Storage::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Lift:
                return Binding::NoLimits2::Lift::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Station:
                return Binding::NoLimits2::Station::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Transport:
                return Binding::NoLimits2::Transport::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Brake:
                return Binding::NoLimits2::Brake::NewInstance(1, argv);
                break;
            default:
                return Binding::NoLimits2::Section::NewInstance(1, argv);
                break;
            }
        }
    }
}
