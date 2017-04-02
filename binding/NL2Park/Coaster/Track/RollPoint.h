#ifndef BINDING_NL2PARK_ROLLPOINT_H
#define BINDING_NL2PARK_ROLLPOINT_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/RollPoint.h>

namespace Binding {
    namespace NL2Park {
        class RollPoint : public Nan::ObjectWrap {
        public:
            explicit RollPoint(Library::NL2Park::RollPoint *rollPoint) : _rollPoint(rollPoint) {}
            explicit RollPoint() : _rollPoint(new Library::NL2Park::RollPoint) {}
            ~RollPoint() {}

            Library::NL2Park::RollPoint *getRollPoint() { return _rollPoint; }

            static BINDING_MODULE_INIT("RollPoint",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Position);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Roll);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Vertical);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Strict);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(RollPoint);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(Position, RollPoint);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Roll, RollPoint);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Vertical, RollPoint);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Strict, RollPoint);

            Library::NL2Park::RollPoint *_rollPoint;
        };
    }
}

#endif // BINDING_NL2PARK_ROLLPOINT_H
