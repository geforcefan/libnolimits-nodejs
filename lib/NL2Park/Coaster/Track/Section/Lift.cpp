#include "Lift.h"

#include <iostream>

namespace Library {
    namespace NL2Park {
        void Lift::read() {
            readNull(3);
            setLiftType((LiftType)readUnsigned8());

            readNull(3);
            setMotorLocation((MotorLocation)readUnsigned8());
            setSpeed(readDouble());
            setAcceleration(readDouble());
            setDeceleration(readDouble());

            setHasAntiRollbackDevice(readBoolean());
            setShuttleModeGentle2ndPassRelease(readBoolean());
            setExtraBlockLength(readDouble());

            setDiveCoasterDropReleaseMode(readBoolean());
        }

        double Lift::getSpeed() const {
            return speed;
        }

        void Lift::setSpeed(double value) {
            speed = value;
        }

        double Lift::getAcceleration() const {
            return acceleration;
        }

        void Lift::setAcceleration(double value) {
            acceleration = value;
        }

        double Lift::getDeceleration() const {
            return deceleration;
        }

        void Lift::setDeceleration(double value) {
            deceleration = value;
        }

        Lift::LiftType Lift::getLiftType() const {
            return liftType;
        }

        void Lift::setLiftType(const Lift::LiftType &value) {
            liftType = value;
        }

        Lift::MotorLocation Lift::getMotorLocation() const {
            return motorLocation;
        }

        void Lift::setMotorLocation(const Lift::MotorLocation &value) {
            motorLocation = value;
        }

        bool Lift::getHasAntiRollbackDevice() const {
            return hasAntiRollbackDevice;
        }

        void Lift::setHasAntiRollbackDevice(bool value) {
            hasAntiRollbackDevice = value;
        }

        bool Lift::getShuttleModeGentle2ndPassRelease() const {
            return shuttleModeGentle2ndPassRelease;
        }

        void Lift::setShuttleModeGentle2ndPassRelease(bool value) {
            shuttleModeGentle2ndPassRelease = value;
        }

        bool Lift::getDiveCoasterDropReleaseMode() const {
            return diveCoasterDropReleaseMode;
        }

        void Lift::setDiveCoasterDropReleaseMode(bool value) {
            diveCoasterDropReleaseMode = value;
        }

        double Lift::getExtraBlockLength() const {
            return extraBlockLength;
        }

        void Lift::setExtraBlockLength(double value) {
            extraBlockLength = value;
        }
    }
}
