#ifndef LIB_NL2PARK_SKY_H
#define LIB_NL2PARK_SKY_H

#include <Stream/NoLimitsStream.h>
#include <nolimits.h>

namespace Library {
    namespace NL2Park {
        class Sky: public Stream::NoLimitsStream {
            using Stream::NoLimitsStream::NoLimitsStream;
        public:
            void read();
            bool getOverrideDefaultDateTime() const;
            void setOverrideDefaultDateTime(bool value);

            glm::vec2 getCurrentDate() const;
            void setCurrentDate(const glm::vec2 &value);

            glm::vec2 getCurrentTime() const;
            void setCurrentTime(const glm::vec2 &value);

        private:
            bool overrideDefaultDateTime;
            glm::vec2 currentDate;
            glm::vec2 currentTime;
        };
    }
}

#endif // SKY_H
