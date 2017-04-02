#ifndef LIB_NL2PARK_PARAMETER4d_H
#define LIB_NL2PARK_PARAMETER4d_H

#include <Stream/NoLimitsStream.h>

namespace Library {
    namespace NL2Park {
        class Parameter4D : public Stream::NoLimitsStream {
        public:
            Parameter4D() {}
            void read();

            double getPosition() const;
            void setPosition(double value);

            double getAngle() const;
            void setAngle(double value);

        private:
            double position;
            double angle;
        };
    }
}

#endif // LIB_NL2PARK_PARAMETER4d_H
