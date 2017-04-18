#include <NL2Park/Coaster/Train.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        void Train::read() {
            readNull(1);

            setStartBlock(readString());
            readNull(1);

            readNull(7);
            setRunBackward(readBoolean());
            setRemovedFromTrack(readBoolean());

            for(int i=0; i <= getFileSize(); i++) {
                setStreamPosition(i);
                std::string chunk = readChunkName();

                if(chunk == "CAR") {
                    Car *_car = new Car();
                    insertCar(_car);

                    _car->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }

                if (chunk == "INDC") {
                    getIndividualColor()->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }
            }
        }

        std::vector<Car*> Train::getCar() const {
            return car;
        }

        void Train::insertCar(Car* value) {
            car.push_back(value);
        }

        IndividualColor *Train::getIndividualColor() const {
            return individualColor;
        }

        void Train::setIndividualColor(IndividualColor *value) {
            individualColor = value;
        }

        bool Train::getRunBackward() const {
            return runBackward;
        }

        void Train::setRunBackward(bool value) {
            runBackward = value;
        }

        bool Train::getRemovedFromTrack() const {
            return removedFromTrack;
        }

        void Train::setRemovedFromTrack(bool value) {
            removedFromTrack = value;
        }

        std::string Train::getStartBlock() const {
            return startBlock;
        }

        void Train::setStartBlock(const std::string &value) {
            startBlock = value;
        }
    }
}
