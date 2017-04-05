#include "Transport.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        void Transport::read() {
            setTransportType((Transport::TransportType)readUnsigned8());
            setSpeed(readDouble());
            setAcceleration(readDouble());
            setDeceleration(readDouble());
            setSpeedingUpPasses(readUnsignedInteger());
            setSpeedingDown(readBoolean());
            setMinSpeed(readDouble());
        }

        double Transport::getSpeed() const {
            return speed;
        }

        void Transport::setSpeed(double value) {
            speed = value;
        }

        double Transport::getAcceleration() const {
            return acceleration;
        }

        void Transport::setAcceleration(double value) {
            acceleration = value;
        }

        double Transport::getDeceleration() const {
            return deceleration;
        }

        void Transport::setDeceleration(double value) {
            deceleration = value;
        }

        uint32_t Transport::getSpeedingUpPasses() const {
            return speedingUpPasses;
        }

        void Transport::setSpeedingUpPasses(const uint32_t &value) {
            speedingUpPasses = value;
        }

        bool Transport::getSpeedingDown() const {
            return speedingDown;
        }

        void Transport::setSpeedingDown(bool value) {
            speedingDown = value;
        }

        double Transport::getMinSpeed() const {
            return minSpeed;
        }

        void Transport::setMinSpeed(double value) {
            minSpeed = value;
        }

        Transport::TransportType Transport::getTransportType() const {
            return transportType;
        }

        void Transport::setTransportType(const Transport::TransportType &value) {
            transportType = value;
        }
    }
}
