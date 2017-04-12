#include "Separator.h"

namespace Library {
    namespace NL2Park {
        void Separator::read() {
            setPosition(readDouble());

            for(int i=0; i <= getFileSize(); i++) {
                setStreamPosition(i);

                std::string chunk = readChunkName();

                if(chunk == "SEGM") {
                    Segment *_segment = new Segment();
                    setSegment(_segment);

                    _segment->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }

                if(chunk == "SECT") {
                    Section *_section = new Section();
                    _section->readChunk(getChunkBufferFile());

                    setSection(_section->getSection());
                    i = getStreamPosition() - 1;
                }
            }
        }

        Section *Separator::getSection() const {
            return section;
        }

        void Separator::setSection(Section *value) {
            section = value;
        }

        Segment *Separator::getSegment() const {
            return segment;
        }

        void Separator::setSegment(Segment *value) {
            segment = value;
        }

        double Separator::getPosition() const {
            return position;
        }

        void Separator::setPosition(double value) {
            position = value;
        }
    }

}
