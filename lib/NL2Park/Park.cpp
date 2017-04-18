#include <NL2Park/Park.h>
#include <iostream>


namespace Library {
    namespace NL2Park {
        Park::Park() {
            info = new Info();
        }

        void Park::read() {
            for(int i=0; i <= getFileSize(); i++) {
                setStreamPosition(i);

                std::string chunk = readChunkName();

                if(chunk == "INFO") {
                    getInfo()->readChunk(getChunkBufferFile());
                    i = getStreamPosition() - 1;
                }

                if(chunk == "COAS") {
                    Coaster *_coaster = new Coaster();
                    _coaster->readChunk(getChunkBufferFile());

                    insertCoaster(_coaster);
                    i = getStreamPosition() - 1;
                }

                // @TODO: Implement terrain
                if(chunk == "TERC") {
                    getChunkBufferFile();
                    i = getStreamPosition() - 1;
                }

                // @TODO: Implement scenery
                if(chunk == "SCEN") {
                    getChunkBufferFile();
                    i = getStreamPosition() - 1;
                }

                // @TODO: Implement uspk
                if(chunk == "USPK") {
                    getChunkBufferFile();
                    i = getStreamPosition() - 1;
                }
            }
        }

        Info *Park::getInfo() const {
            return info;
        }

        std::vector<Coaster*> Park::getCoaster() const {
            return coaster;
        }

        Coaster *Park::getCoaster(std::string name) const {
            if(coasterMapping.find(name) != coasterMapping.end())
                return coaster.at(coasterMapping.at(name));
            else
                return NULL;
        }

        void Park::insertCoaster(Coaster* value) {
            coasterMapping[value->getName()] = coaster.size();
            coaster.push_back(value);
        }
    }
}
