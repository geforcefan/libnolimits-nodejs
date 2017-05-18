#ifndef BINDING_NL2PARK_TRIGGER_H
#define BINDING_NL2PARK_TRIGGER_H

#include "../../../Nolimits.h"
#include <libnolimits/NL2/Coaster/Track/Trigger.h>

namespace Binding {
    namespace NL2Park {
        class Trigger : public Nan::ObjectWrap {
        public:
            explicit Trigger(NoLimits::NoLimits2::Trigger *trigger) : _trigger(trigger) {}
            explicit Trigger() : _trigger(new NoLimits::NoLimits2::Trigger) {}
            ~Trigger() {}

            NoLimits::NoLimits2::Trigger *getTrigger() { return _trigger; }

            static BINDING_MODULE_INIT("Trigger",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Position);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Name);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(TrainEvent);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Trigger);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(Position, Trigger);
            BINDING_METHOD_SETTER_GETTER_STRING(Name, Trigger);
            BINDING_METHOD_SETTER_GETTER_ENUM(TrainEvent, Trigger, NoLimits::NoLimits2::Trigger::TrainEvent);

            NoLimits::NoLimits2::Trigger *_trigger;
        };
    }
}

#endif // BINDING_NL2PARK_TRIGGER_H
