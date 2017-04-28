#ifndef BINDING_NL2PARK_AUTOPAINT_H
#define BINDING_NL2PARK_AUTOPAINT_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Terrain/AutoPaint.h>

namespace Binding {
    namespace NL2Park {
        class AutoPaint : public Nan::ObjectWrap {
        public:
            explicit AutoPaint() : _autoPaint(new Library::NL2Park::AutoPaint) {}
            explicit AutoPaint(Library::NL2Park::AutoPaint *autoPaint) : _autoPaint(autoPaint) {}

            ~AutoPaint() {}

            Library::NL2Park::AutoPaint *getAutoPaint() { return _autoPaint; }

            static BINDING_MODULE_INIT("AutoPaint",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Enabled);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Covarage);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(MaxHeight);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(MinHeight);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(MinSlope);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(MaxSlope);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Noise);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(NoiseDetail);
            );

            static BINDING_NEW_INSTANCE();
        private:

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(AutoPaint);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Enabled, AutoPaint);
            BINDING_METHOD_SETTER_GETTER_FLOAT(Covarage, AutoPaint);
            BINDING_METHOD_SETTER_GETTER_FLOAT(MaxHeight, AutoPaint);
            BINDING_METHOD_SETTER_GETTER_FLOAT(MinHeight, AutoPaint);
            BINDING_METHOD_SETTER_GETTER_FLOAT(MinSlope, AutoPaint);
            BINDING_METHOD_SETTER_GETTER_FLOAT(MaxSlope, AutoPaint);
            BINDING_METHOD_SETTER_GETTER_FLOAT(Noise, AutoPaint);
            BINDING_METHOD_SETTER_GETTER_FLOAT(NoiseDetail, AutoPaint);

            Library::NL2Park::AutoPaint *_autoPaint;
        };
    }
}

#endif // BINDING_NL2PARK_AUTOPAINT_H
