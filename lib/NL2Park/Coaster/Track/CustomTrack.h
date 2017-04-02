#ifndef LIB_NL2PARK_CUSTOM_TRACK_H
#define LIB_NL2PARK_CUSTOM_TRACK_H

#include <vector>

#include <Stream/NoLimitsStream.h>
#include <lib/NL2Park/Coaster/Track/Track.h>
#include <lib/NL2Park/Coaster/Track/RollPoint.h>
#include <lib/NL2Park/Coaster/Track/Vertex.h>
#include <lib/NL2Park/Coaster/Track/Trigger.h>
#include <lib/NL2Park/Coaster/Track/Support/RailNode.h>

namespace Library {
    namespace NL2Park {
        class CustomTrack: public Stream::NoLimitsStream, public Track  {
        public:
            CustomTrack();
            void read();

            RollPoint *getFirstRollPoint() const;
            RollPoint *getLastRollPoint() const;

            std::vector<Vertex*> getVertex() const;
            void insertVertex(Vertex *value);

            std::vector<RollPoint*> getRollPoint() const;
            void insertRollPoint(RollPoint* value);

            std::vector<Trigger*> getTrigger() const;
            void insertTrigger(Trigger* value);

            std::vector<RailNode*> getRailNode() const;
            void insertRailNode(RailNode* value);

        private:
            std::vector<Vertex*> vertex;
            std::vector<RollPoint*> rollPoint;
            std::vector<Trigger*> trigger;
            std::vector<RailNode*> railNode;

            RollPoint *firstRollPoint;
            RollPoint *lastRollPoint;
        };
    }
}

#endif // LIB_NL2PARK_CUSTOM_TRACK_H
