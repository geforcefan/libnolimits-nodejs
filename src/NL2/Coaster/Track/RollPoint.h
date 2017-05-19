#ifndef BINDING_NL2PARK_ROLLPOINT_H
#define BINDING_NL2PARK_ROLLPOINT_H

#include "../../../Nolimits.h"
#include <libnolimits/NL2/Coaster/Track/RollPoint.h>

namespace Binding {
    namespace NoLimits2 {
        class RollPoint : public Nan::ObjectWrap {
        public:
            explicit RollPoint(NoLimits::NoLimits2::RollPoint *rollPoint) : _rollPoint(rollPoint) {}
            explicit RollPoint() : _rollPoint(new NoLimits::NoLimits2::RollPoint) {}
            ~RollPoint() {}

            NoLimits::NoLimits2::RollPoint *getRollPoint() { return _rollPoint; }

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

            NoLimits::NoLimits2::RollPoint *_rollPoint;
        };
    }
}

#endif // BINDING_NL2PARK_ROLLPOINT_H
