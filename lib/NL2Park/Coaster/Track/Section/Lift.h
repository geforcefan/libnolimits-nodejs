#ifndef LIB_NL2PARK_LIFT_H
#define LIB_NL2PARK_LIFT_H

#include "Section.h"
#include <Stream/NoLimitsStream.h>

namespace Library {
    namespace NL2Park {
        class Lift : public Section {
            enum LiftType {
                Chain,
                FrictionWheels
            };

            enum MotorLocation {
                AtStart,
                AtEnd,
                Silent
            };
        public:
            Lift() : Section(Section::SectionType::Lift) {}
            void read();

            double getSpeed() const;
            void setSpeed(double value);

            double getAcceleration() const;
            void setAcceleration(double value);

            double getDeceleration() const;
            void setDeceleration(double value);

            LiftType getLiftType() const;
            void setLiftType(const LiftType &value);

            MotorLocation getMotorLocation() const;
            void setMotorLocation(const MotorLocation &value);

            bool getHasAntiRollbackDevice() const;
            void setHasAntiRollbackDevice(bool value);

            bool getShuttleModeGentle2ndPassRelease() const;
            void setShuttleModeGentle2ndPassRelease(bool value);

            bool getDiveCoasterDropReleaseMode() const;
            void setDiveCoasterDropReleaseMode(bool value);

            double getExtraBlockLength() const;
            void setExtraBlockLength(double value);

        private:
            double speed;
            double acceleration;
            double deceleration;

            LiftType liftType;
            MotorLocation motorLocation;

            bool hasAntiRollbackDevice;
            bool shuttleModeGentle2ndPassRelease;
            bool diveCoasterDropReleaseMode;

            double extraBlockLength;
        };
    }
}

#endif // LIB_NL2PARK_LIFT_H
