#ifndef LIB_NL2PARK_PARK_H
#define LIB_NL2PARK_PARK_H

#include <string>
#include <Stream/NoLimitsStream.h>
#include <NL2Park/Info/Info.h>
#include <NL2Park/Coaster/Coaster.h>

#include <vector>

namespace Library {
    namespace NL2Park {
        class Park: public Stream::NoLimitsStream {
        public:
            Park();

            void read();

            Info *getInfo() const;

            std::vector<Coaster*> getCoaster() const;
            void insertCoaster(Coaster* value);

        private:
            Info *info;

            std::vector<Coaster*> coaster;
        };
    }
}

#endif
