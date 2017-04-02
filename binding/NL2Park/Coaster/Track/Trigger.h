#ifndef BINDING_NL2PARK_TRIGGER_H
#define BINDING_NL2PARK_TRIGGER_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/Trigger.h>

namespace Binding {
    namespace NL2Park {
        class Trigger : public Nan::ObjectWrap {
        public:
            explicit Trigger(Library::NL2Park::Trigger *trigger) : _trigger(trigger) {}
            explicit Trigger() : _trigger(new Library::NL2Park::Trigger) {}
            ~Trigger() {}

            Library::NL2Park::Trigger *getTrigger() { return _trigger; }

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
            BINDING_METHOD_SETTER_GETTER_ENUM(TrainEvent, Trigger, Library::NL2Park::Trigger::TrainEvent);

            Library::NL2Park::Trigger *_trigger;
        };
    }
}

#endif // BINDING_NL2PARK_TRIGGER_H
