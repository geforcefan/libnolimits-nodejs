#include <NL2Park/Park.h>
#include <iostream>
#include <File/BufferFile.h>

namespace Library {
    namespace NL2Park {
        Park::Park(std::string filepath) {
            info = new Info();
            terrain = new Terrain();

            readChunk(Library::File::BufferFile::createFromFilePath(filepath));
        }

        void Park::save(std::string filepath) {
            Library::File::File *chunkFile = writeChunk();

            chunkFile->openRB();
            char *oBuffer = (char*) malloc(chunkFile->getFilesize());
            chunkFile->read(&oBuffer[0], 1, chunkFile->getFilesize());

            FILE *oFile = fopen(filepath.c_str(), "wb");
            fwrite(&oBuffer[0], 1, chunkFile->getFilesize(), oFile);
            fclose(oFile);
        }

        void Park::write(File::File *file) {
            file->writeNull(4); // propably version?

            file->writeFile(getInfo()->writeChunk());
            file->writeFile(getUspk()->writeChunk());
            //file->writeFile(getCoaster()->writeChunk()); // n amount of coasters
            file->writeFile(getTerrain()->writeChunk());
        }

        void Park::read(File::File *file) {
            file->readNull(4); // propably version?

            for(int i = file->tell(); i <= file->getFilesize(); i++) {
                file->seek(i, SEEK_SET);

                std::string chunk = file->readChunkName();

                if(chunk == "INFO") {
                    getInfo()->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                if(chunk == "COAS") {
                    Coaster *_coaster = new Coaster();
                    _coaster->readChunk(file->getChunkBufferFile());

                    insertCoaster(_coaster);
                    i = file->tell() - 1;
                }

                if(chunk == "TERC") {
                    getTerrain()->readChunk(file->getChunkBufferFile());
                    i = file->tell() - 1;
                }

                // @TODO: Implement scenery
                if(chunk == "SCEN") {
                    file->getChunkBufferFile();
                    i = file->tell() - 1;
                }

                // @TODO: Implement uspk
                if(chunk == "USPK") {
                    file->getChunkBufferFile();
                    i = file->tell() - 1;
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

        Terrain *Park::getTerrain() const {
            return terrain;
        }

        void Park::setTerrain(Terrain *value) {
            terrain = value;
        }

        Uspk *Park::getUspk() const {
            return uspk;
        }

        void Park::setUspk(Uspk *value) {
            uspk = value;
        }
    }
}
