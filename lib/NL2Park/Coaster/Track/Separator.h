#ifndef LIB_NL2PARK_SEPARATOR_H
#define LIB_NL2PARK_SEPARATOR_H

#include "Section/Section.h"
#include "Segment.h"
#include <Stream/NoLimitsStream.h>

namespace Library {
    namespace NL2Park {
        class Separator : public Stream::NoLimitsStream {
        public:
            Separator() {
                section = new Section();
                segment = new Segment();
            }
            void read();

            Section *getSection() const;
            void setSection(Section *value);

            Segment *getSegment() const;
            void setSegment(Segment *value);

            double getPosition() const;
            void setPosition(double value);

        private:
            Section *section;
            Segment *segment;

            double position;
        };
    }
}

#endif // LIB_NL2PARK_SEPARATOR_H
