#include <NL2Park/Coaster/Track/CustomTrack.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        CustomTrack::CustomTrack() : Track(TrackType::Custom) {
            firstRollPoint = new RollPoint();
            lastRollPoint = new RollPoint();
        }

        void CustomTrack::read() {
            readNull(1);

            getFirstRollPoint()->setPosition(0.0);
            getFirstRollPoint()->setRoll(readDouble());
            getFirstRollPoint()->setVertical(readBoolean());
            getFirstRollPoint()->setStrict(true);

            getLastRollPoint()->setRoll(readDouble());
            getLastRollPoint()->setVertical(readBoolean());
            getLastRollPoint()->setStrict(true);

            readNull(53);

            uint32_t numberOfControlPoints = readUnsignedInteger();
            getLastRollPoint()->setPosition(numberOfControlPoints - 1);

            for (uint32_t i = 0; i < numberOfControlPoints; i++) {
                Vertex *vertex = new Vertex();

                vertex->readStream(this);
                insertVertex(vertex);
            }

            readNull(60);

            for(int i=0; i <= getFileSize(); i++) {
                setStreamPosition(i);

                std::string chunk = readChunkName();

                if(chunk == "ROLL") {
                    RollPoint *_rollPoint = new RollPoint();
                    insertRollPoint(_rollPoint);

                    _rollPoint->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }

                if(chunk == "TTRG") {
                    Trigger *_trigger = new Trigger();
                    insertTrigger(_trigger);

                    _trigger->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }
            }
        }

        RollPoint *CustomTrack::getFirstRollPoint() const {
            return firstRollPoint;
        }

        RollPoint *CustomTrack::getLastRollPoint() const {
            return lastRollPoint;
        }

        std::vector<Vertex*> CustomTrack::getVertex() const {
            return vertex;
        }

        void CustomTrack::insertVertex(Vertex *value) {
            vertex.push_back(value);
        }

        std::vector<RollPoint *> CustomTrack::getRollPoint() const {
            return rollPoint;
        }

        void CustomTrack::insertRollPoint(RollPoint *value) {
            rollPoint.push_back(value);
        }

        std::vector<Trigger *> CustomTrack::getTrigger() const {
            return trigger;
        }

        void CustomTrack::insertTrigger(Trigger* value) {
            trigger.push_back(value);
        }
    }
}