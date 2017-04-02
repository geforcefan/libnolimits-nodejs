#ifndef LIB_NL2PARK_VERTEX_H
#define LIB_NL2PARK_VERTEX_H

#include <Stream/NoLimitsStream.h>

namespace Library {
    namespace NL2Park {
        class Vertex : public Stream::NoLimitsStream {
        public:
            Vertex() {}
            void read();

            glm::vec4 getPosition() const;
            void setPosition(const glm::vec4 &value);

            bool getLocked() const;
            void setLocked(bool value);

            bool getStrict() const;
            void setStrict(bool value);

        private:
            glm::vec4 position;
            bool locked;
            bool strict;
        };
    }
}

#endif // LIB_NL2PARK_VERTEX_H
