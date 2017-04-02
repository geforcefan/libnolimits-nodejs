#include <NL2Park/Coaster/Coaster.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        Coaster::Coaster() {
            colors = new Colors();
            style = new Style();
            mode = new Mode();
        }

        void Coaster::read() {
            setName(readString());

            getColors()->setWireframeTrack(readColor());
            getMode()->setSplinePosition((Mode::SplinePosition)readUnsigned8());

            getMode()->setSplinePositionOffset(readDoubleVec2());

            setDescription(readString());

            readNull(3);
            getStyle()->setStyleType((Style::StyleType)readUnsigned8());

            getColors()->setRails(readColor());
            getColors()->setCrossTies(readColor());
            getColors()->setMainSpine(readColor());
            getColors()->setCar(readColor());
            getColors()->setSeat(readColor());
            getColors()->setHarness(readColor());
            getColors()->setBogie(readColor());

            setFreezed(readBoolean());
            getColors()->setSpineColorScheme((Colors::SpineColorScheme)readUnsigned8());
            getColors()->setSupports(readColor());
            getColors()->setTunnel(readColor());

            getStyle()->setWornType((Style::WornType)readUnsigned8());
            getColors()->setChasiss(readColor());

            getMode()->setOperationMode((Mode::Operation)readUnsigned8());
            getStyle()->setRailType((Style::RailType)readUnsigned8());

            getColors()->setHandrails(readColor());
            getColors()->setCatwalks(readColor());

            getMode()->setPhysicsModel((Mode::PhysicsModel)readUnsigned8());
            setHideWireframe(readBoolean());

            setNumberOfCarsPerTrain(readUnsigned8());

            for(int i=0; i <= getFileSize(); i++) {
                setStreamPosition(i);
                std::string chunk = readChunkName();

                if(chunk == "CUTK") {
                    CustomTrack *_track = new CustomTrack();
                    insertTrack(_track);

                    _track->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }

                if(chunk == "CUFR") {
                    getMode()->getCustomFriction()->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }

                if(chunk == "FSCR") {
                    readNull(4);

                    uint32_t numScripts = readUnsignedInteger();

                    for(uint32_t i = 0; i < numScripts; i++) {
                        insertFileScript(readString());
                        readNull(8);
                    }
                }
            }
        }

        std::string Coaster::getName() const {
            return name;
        }

        void Coaster::setName(const std::string &value) {
            name = value;
        }

        std::string Coaster::getDescription() const {
            return description;
        }

        void Coaster::setDescription(const std::string &value) {
            description = value;
        }

        uint32_t Coaster::getNumberOfCarsPerTrain() const {
            return numberOfCarsPerTrain;
        }

        void Coaster::setNumberOfCarsPerTrain(const uint32_t &value) {
            numberOfCarsPerTrain = value;
        }

        bool Coaster::getHideWireframe() const {
            return hideWireframe;
        }

        void Coaster::setHideWireframe(bool value) {
            hideWireframe = value;
        }

        bool Coaster::getFreezed() const {
            return freezed;
        }

        void Coaster::setFreezed(bool value) {
            freezed = value;
        }

        Colors *Coaster::getColors() const {
            return colors;
        }

        void Coaster::setColors(Colors *value) {
            colors = value;
        }

        Style *Coaster::getStyle() const {
            return style;
        }

        void Coaster::setStyle(Style *value) {
            style = value;
        }

        Mode *Coaster::getMode() const {
            return mode;
        }

        void Coaster::setMode(Mode *value) {
            mode = value;
        }

        std::vector<std::string> Coaster::getFileScript() const {
            return fileScript;
        }

        void Coaster::insertFileScript(std::string value) {
            fileScript.push_back(value);
        }

        std::vector<Track*> Coaster::getTrack() const {
            return track;
        }

        void Coaster::insertTrack(Track* value) {
            track.push_back(value);
        }
    }
}
