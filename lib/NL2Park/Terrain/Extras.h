#ifndef EXTRAS_H
#define EXTRAS_H

#include <string>

namespace Library {
    namespace NL2Park {
        class Extras
        {
        public:
            Extras() {}

            std::string getFootstepSounds() const;
            void setFootstepSounds(const std::string &value);

            std::string getAutoplantObject() const;
            void setAutoplantObject(const std::string &value);

        private:
            std::string footstepSounds;
            std::string autoplantObject;
        };
    }
}

#endif // EXTRAS_H
