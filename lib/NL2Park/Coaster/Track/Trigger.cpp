#include "Trigger.h"

namespace Library {
    namespace NL2Park {
        void Trigger::read() {
            setPosition(readDouble());
            setName(readString());
            readNull(3);
            setTrainEvent((Trigger::TrainEvent)readUnsigned8());
            readNull(23);
        }

        double Trigger::getPosition() const {
            return position;
        }

        void Trigger::setPosition(double value) {
            position = value;
        }

        std::string Trigger::getName() const {
            return name;
        }

        void Trigger::setName(const std::string &value) {
            name = value;
        }

        Trigger::TrainEvent Trigger::getTrainEvent() const {
            return trainEvent;
        }

        void Trigger::setTrainEvent(const Trigger::TrainEvent &value) {
            trainEvent = value;
        }
    }

}
