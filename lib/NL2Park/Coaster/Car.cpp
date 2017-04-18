#include <NL2Park/Coaster/Car.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        void Car::read() {
            for(int i=0; i <= getFileSize(); i++) {
                setStreamPosition(i);
                std::string chunk = readChunkName();

                if (chunk == "INDC") {
                    getIndividualColor()->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }
            }
        }

        IndividualColor *Car::getIndividualColor() const {
            return individualColor;
        }

        void Car::setIndividualColor(IndividualColor *value) {
            individualColor = value;
        }

        bool Car::getIsZeroCar() const {
            return isZeroCar;
        }

        void Car::setIsZeroCar(bool value) {
            isZeroCar = value;
        }
    }
}
