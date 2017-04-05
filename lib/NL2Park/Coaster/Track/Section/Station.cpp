#include "Station.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        void Station::read() {
            setUseTransportDevice(readBoolean());
            getTransportDevice()->setTransportType((Transport::TransportType)readUnsigned8());
            getTransportDevice()->setSpeed(readDouble());
            getTransportDevice()->setAcceleration(readDouble());
            getTransportDevice()->setDeceleration(readDouble());

            getBrakeDevice()->setDeceleration(readDouble());
            getWaitTime()->setAvarage(readDouble());
            getWaitTime()->setMinimum(readDouble());
            getWaitTime()->setMaximum(readDouble());
            getWaitTime()->setDeviation(readDouble());

            getTransportDevice()->setLaunch(readBoolean());
            getTransportDevice()->setLaunchAcceleration(readDouble());
            getTransportDevice()->setLaunchMaxSpeed(readDouble());

            setUnloadingOnly(readBoolean());

            readNull(3);

            setPasses(readUnsigned8());
            setShuttleBackwardsStart(readBoolean());
            setStationNumber(readUnsignedInteger());

            readNull(3);

            uint8_t numSynchronizeDispatchWith = readUnsigned8();

            for(uint8_t i = 0; i < numSynchronizeDispatchWith; i++) {
                getWaitTime()->insertSynchronizeDispatchWith(readUnsignedInteger());
            }

            setExtraBlockLength(readDouble());

            getBrakeDevice()->setBrakeType((Brake::BrakeType)readUnsigned8());
            setGateDirection((Station::GateDirection)readUnsigned8());
            setDisplay((Station::Display)readUnsigned8());
            setEntranceStairs((Station::Stairs)readUnsigned8());
            setExitStairs((Station::Stairs)readUnsigned8());

            readNull(1);

            setGatesColor(readColor());
            setRailingsColor(readColor());
            setStructureColor(readColor());

            readNull(137);
        }

        double Station::getExtraBlockLength() const {
            return extraBlockLength;
        }

        void Station::setExtraBlockLength(double value) {
            extraBlockLength = value;
        }

        bool Station::getUnloadingOnly() const {
            return unloadingOnly;
        }

        void Station::setUnloadingOnly(bool value) {
            unloadingOnly = value;
        }

        Station::Display Station::getDisplay() const {
            return display;
        }

        void Station::setDisplay(const Station::Display &value) {
            display = value;
        }

        Station::GateDirection Station::getGateDirection() const {
            return gateDirection;
        }

        void Station::setGateDirection(const Station::GateDirection &value) {
            gateDirection = value;
        }

        Station::Stairs Station::getEntranceStairs() const {
            return entranceStairs;
        }

        void Station::setEntranceStairs(const Station::Stairs &value) {
            entranceStairs = value;
        }

        Station::Stairs Station::getExitStairs() const {
            return exitStairs;
        }

        void Station::setExitStairs(const Station::Stairs &value) {
            exitStairs = value;
        }

        uint8_t Station::getPasses() const {
            return passes;
        }

        void Station::setPasses(const uint8_t &value) {
            passes = value;
        }

        bool Station::getShuttleBackwardsStart() const {
            return shuttleBackwardsStart;
        }

        void Station::setShuttleBackwardsStart(bool value) {
            shuttleBackwardsStart = value;
        }

        glm::vec3 Station::getStructureColor() const {
            return structureColor;
        }

        void Station::setStructureColor(const glm::vec3 &value) {
            structureColor = value;
        }

        glm::vec3 Station::getRailingsColor() const {
            return railingsColor;
        }

        void Station::setRailingsColor(const glm::vec3 &value) {
            railingsColor = value;
        }

        glm::vec3 Station::getGatesColor() const {
            return gatesColor;
        }

        void Station::setGatesColor(const glm::vec3 &value) {
            gatesColor = value;
        }

        WaitTime *Station::getWaitTime() const {
            return waitTime;
        }

        void Station::setWaitTime(WaitTime *value) {
            waitTime = value;
        }

        BrakeDevice *Station::getBrakeDevice() const {
            return brakeDevice;
        }

        void Station::setBrakeDevice(BrakeDevice *value) {
            brakeDevice = value;
        }

        bool Station::getUseTransportDevice() const {
            return useTransportDevice;
        }

        void Station::setUseTransportDevice(bool value) {
            useTransportDevice = value;
        }

        TransportDevice *Station::getTransportDevice() const {
            return transportDevice;
        }

        void Station::setTransportDevice(TransportDevice *value) {
            transportDevice = value;
        }

        uint32_t Station::getStationNumber() const {
            return stationNumber;
        }

        void Station::setStationNumber(const uint32_t &value) {
            stationNumber = value;
        }
    }
}
