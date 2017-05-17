#ifndef BINDING_NL2PARK_WAITTIME_H
#define BINDING_NL2PARK_WAITTIME_H

#include <binding/nolimits.h>
#include <NL2/Coaster/Track/Section/WaitTime.h>

namespace Binding {
    namespace NL2Park {
        class WaitTime : public Nan::ObjectWrap {
        public:
            explicit WaitTime(NoLimits::NoLimits2::WaitTime *waitTime) : _waitTime(waitTime) {}
            explicit WaitTime() : _waitTime(new NoLimits::NoLimits2::WaitTime) {}
            ~WaitTime() {}

            NoLimits::NoLimits2::WaitTime *getWaitTime() { return _waitTime; }

            static BINDING_MODULE_INIT("WaitTime",
                BINDING_PROTOTYPE_METHOD_GETTER(Avarage);
                BINDING_PROTOTYPE_METHOD_GETTER(Minimum);
                BINDING_PROTOTYPE_METHOD_GETTER(Maximum);
                BINDING_PROTOTYPE_METHOD_GETTER(Deviation);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER_VECTOR(SynchronizeDispatchWith);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(WaitTime);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(Avarage, WaitTime);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Minimum, WaitTime);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Maximum, WaitTime);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(Deviation, WaitTime);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER_VECTOR(SynchronizeDispatchWith, WaitTime);

            NoLimits::NoLimits2::WaitTime *_waitTime;
        };
    }
}

#endif // BINDING_NL2PARK_WAITTIME_H
