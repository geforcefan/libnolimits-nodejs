#include "Section.h"
#include "Storage.h"
#include "Lift.h"
#include "Transport.h"
#include "Brake.h"
#include "Station.h"

namespace Binding {
    namespace NL2Park {
        v8::Local<v8::Object> Section::createFromType(NoLimits::NoLimits2::Section *section) {
            v8::Local<v8::Value> argv[] = { v8::External::New(v8::Isolate::GetCurrent(), new Section(section)) };

            switch(section->getSectionType()) {
            case NoLimits::NoLimits2::Section::SectionType::Track:
                return Binding::NL2Park::Section::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Storage:
                return Binding::NL2Park::Storage::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Lift:
                return Binding::NL2Park::Lift::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Station:
                return Binding::NL2Park::Station::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Transport:
                return Binding::NL2Park::Transport::NewInstance(1, argv);
                break;
            case NoLimits::NoLimits2::Section::SectionType::Brake:
                return Binding::NL2Park::Brake::NewInstance(1, argv);
                break;
            default:
                return Binding::NL2Park::Section::NewInstance(1, argv);
                break;
            }
        }
    }
}
