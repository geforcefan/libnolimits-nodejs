#ifndef BINDING_NL2PARK_PARAMETER4D_H
#define BINDING_NL2PARK_PARAMETER4D_H

#include "../../../Nolimits.h"
#include <libnolimits/NL2/Coaster/Track/Parameter4D.h>

namespace Binding {
    namespace NoLimits2 {
        class Parameter4D : public Nan::ObjectWrap {
        public:
            explicit Parameter4D(NoLimits::NoLimits2::Parameter4D *parameter4D) : _parameter4D(parameter4D) {}
            explicit Parameter4D() : _parameter4D(new NoLimits::NoLimits2::Parameter4D) {}
            ~Parameter4D() {}

            NoLimits::NoLimits2::Parameter4D *getParameter4D() { return _parameter4D; }

            static BINDING_MODULE_INIT("Parameter4D",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Position);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Angle);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Parameter4D);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(Position, Parameter4D);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Angle, Parameter4D);

            NoLimits::NoLimits2::Parameter4D *_parameter4D;
        };
    }
}

#endif // BINDING_NL2PARK_PARAMETER4D_H
