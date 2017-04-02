#include "Vertex.h"

namespace Library {
    namespace NL2Park {
        void Vertex::read() {
            setPosition(readDoubleVec4());
            setLocked(readBoolean());
            setStrict(readBoolean());

            readNull(22);
        }

        glm::vec4 Vertex::getPosition() const {
            return position;
        }

        void Vertex::setPosition(const glm::vec4 &value) {
            position = value;
        }

        bool Vertex::getLocked() const {
            return locked;
        }

        void Vertex::setLocked(bool value) {
            locked = value;
        }

        bool Vertex::getStrict() const {
            return strict;
        }

        void Vertex::setStrict(bool value) {
            strict = value;
        }
    }

}
