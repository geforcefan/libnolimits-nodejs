#ifndef LIB_NL2PARK_FRICTION_H
#define LIB_NL2PARK_FRICTION_H

#include <Stream/NoLimitsStream.h>

namespace Library {
    namespace NL2Park {
        class CustomFriction: public Stream::NoLimitsStream {
        public:
            CustomFriction();
            void read();

            double getConstFrictionParameter() const;
            void setConstFrictionParameter(double value);

            double getAirResistanceParameter() const;
            void setAirResistanceParameter(double value);

        private:
            double constFrictionParameter;
            double airResistanceParameter;
        };
    }
}

#endif // LIB_NL2PARK_FRICTION_H
