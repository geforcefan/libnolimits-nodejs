#include <NL2Park/Info/Sky.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        void Sky::read() {
            setOverrideDefaultDateTime(readBoolean());
            setCurrentDate(readIntVec2());
            setCurrentTime(readIntVec2());
        }

        glm::vec2 Sky::getCurrentTime() const {
            return currentTime;
        }

        void Sky::setCurrentTime(const glm::vec2 &value) {
            currentTime = value;
        }

        glm::vec2 Sky::getCurrentDate() const {
            return currentDate;
        }

        void Sky::setCurrentDate(const glm::vec2 &value) {
            currentDate = value;
        }

        bool Sky::getOverrideDefaultDateTime() const {
            return overrideDefaultDateTime;
        }

        void Sky::setOverrideDefaultDateTime(bool value) {
            overrideDefaultDateTime = value;
        }
    }
}
