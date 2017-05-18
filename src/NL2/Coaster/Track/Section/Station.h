#ifndef BINDING_NL2PARK_STATION_H
#define BINDING_NL2PARK_STATION_H

#include "../../../../Nolimits.h"
#include "Section.h"
#include "BrakeDevice.h"
#include "WaitTime.h"
#include <libnolimits/NL2/Coaster/Track/Section/Station.h>

namespace Binding {
    namespace NL2Park {
        class Display {
        public:
            static BINDING_MODULE_INIT_ENUM(Display,
                BINDING_MODULE_ENUM_FIELD(FullBuilding, NoLimits::NoLimits2::Station::Display);
                BINDING_MODULE_ENUM_FIELD(NoRoof, NoLimits::NoLimits2::Station::Display);
                BINDING_MODULE_ENUM_FIELD(GatesOnly, NoLimits::NoLimits2::Station::Display);
                BINDING_MODULE_ENUM_FIELD(HideAll, NoLimits::NoLimits2::Station::Display);
            );
        };

        class GateDirection {
        public:
            static BINDING_MODULE_INIT_ENUM(GateDirection,
                BINDING_MODULE_ENUM_FIELD(Left, NoLimits::NoLimits2::Station::GateDirection);
                BINDING_MODULE_ENUM_FIELD(Right, NoLimits::NoLimits2::Station::GateDirection);
            );
        };

        class Stairs {
        public:
            static BINDING_MODULE_INIT_ENUM(Stairs,
                BINDING_MODULE_ENUM_FIELD(None, NoLimits::NoLimits2::Station::Stairs);
                BINDING_MODULE_ENUM_FIELD(BeginFront, NoLimits::NoLimits2::Station::Stairs);
                BINDING_MODULE_ENUM_FIELD(BeginSide, NoLimits::NoLimits2::Station::Stairs);
                BINDING_MODULE_ENUM_FIELD(EndFront, NoLimits::NoLimits2::Station::Stairs);
                BINDING_MODULE_ENUM_FIELD(EndSide, NoLimits::NoLimits2::Station::Stairs);
            );
        };

        class Station : public Section {
        public:
            Station(NoLimits::NoLimits2::Station *station) : Section(station) {}
            Station() : Section(new NoLimits::NoLimits2::Station) {}

            NoLimits::NoLimits2::Station *getStation() { return (NoLimits::NoLimits2::Station*)getSection(); }

            static BINDING_MODULE_INIT("Station",
                BINDING_INHERIT(Binding::NL2Park::Section);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ExtraBlockLength);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(UnloadingOnly);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Display);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(GateDirection);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(EntranceStairs);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ExitStairs);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Passes);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ShuttleBackwardsStart);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(StructureColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(RailingsColor);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(GatesColor);

                BINDING_PROTOTYPE_METHOD_GETTER(WaitTime);
                BINDING_PROTOTYPE_METHOD_GETTER(BrakeDevice);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(UseTransportDevice);
                BINDING_PROTOTYPE_METHOD_GETTER(TransportDevice);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(StationNumber);

                BINDING_PROTOTYPE_ENUM_LIST(Display);
                BINDING_PROTOTYPE_ENUM_LIST(GateDirection);
                BINDING_PROTOTYPE_ENUM_LIST(Stairs);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Station);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(ExtraBlockLength, Station);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UnloadingOnly, Station);

            BINDING_METHOD_SETTER_GETTER_ENUM(Display, Station, NoLimits::NoLimits2::Station::Display);
            BINDING_METHOD_SETTER_GETTER_ENUM(GateDirection, Station, NoLimits::NoLimits2::Station::GateDirection);

            BINDING_METHOD_SETTER_GETTER_ENUM(EntranceStairs, Station, NoLimits::NoLimits2::Station::Stairs);
            BINDING_METHOD_SETTER_GETTER_ENUM(ExitStairs, Station, NoLimits::NoLimits2::Station::Stairs);

            BINDING_METHOD_SETTER_GETTER_UNSIGNED_8(Passes, Station);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(ShuttleBackwardsStart, Station);

            BINDING_METHOD_SETTER_GETTER_VEC3(StructureColor, Station);
            BINDING_METHOD_SETTER_GETTER_VEC3(RailingsColor, Station);
            BINDING_METHOD_SETTER_GETTER_VEC3(GatesColor, Station);

            BINDING_METHOD_GETTER_OBJECT(WaitTime, Station);
            BINDING_METHOD_GETTER_OBJECT(BrakeDevice, Station);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseTransportDevice, Station);
            BINDING_METHOD_GETTER_OBJECT(TransportDevice, Station);

            BINDING_METHOD_SETTER_GETTER_UNSIGNED_INTEGER(StationNumber, Station);
        };
    }
}

#endif // BINDING_NL2PARK_STATION_H
