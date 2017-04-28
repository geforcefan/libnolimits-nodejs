#include "Terrain.h"
#include <iostream>
#include <algorithm>
#include <File/BufferFile.h>

namespace Library {
    namespace NL2Park {
        void Terrain::read(File::File *file) {
            file->readNull(8);

            file->readNull(8); // x y sizes in int, but don´t need these
            //setVertexDimX(file->readUnsignedInteger());
            //setVertexDimY(file->readUnsignedInteger());

            file->readNull(64);

            getWater()->setDiffuseTexture(file->readString());
            getWater()->setBumpMapTexture(file->readString());

            file->readNull(2);

            getWater()->setDensity(file->readFloat());
            getWater()->setDiffuseTextureRepeatsPerDistance(file->readFloat());

            getWater()->setWaves(file->readFloat());
            getWater()->setReflection(file->readFloat());

            getWater()->setBumpMapType((TerrainMap)file->readUnsigned8());
            getWater()->setBumpMapHeightMapScale(file->readFloat());
            getWater()->setBumpMapRepeatsPerDistance(file->readFloat());

            uint32_t numTextureRepeats = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numTextureRepeats; i++) {
                insertTextureRepeats(file->readFloat());
            }

            file->readNull(19);

            uint32_t numberOfLayers = file->readUnsignedInteger();
            for(uint32_t i = 0; i < numberOfLayers; i++) {
                Layer *l = new Layer();
                l->read(file);
                insertLayer(l);
            }

            file->readNull(64);

            File::File *terrainDataBufferFile = file->readFileCompressed();
            terrainDataBufferFile->openRB();

            setVertexDimX(terrainDataBufferFile->readUnsignedInteger());
            setVertexDimY(terrainDataBufferFile->readUnsignedInteger());

            uint16_t lastAbsoluteHeight = 0;
            for (uint32_t i = 0; i < getVertexDimX() * getVertexDimY(); i++) {
                uint16_t relativeHeight = terrainDataBufferFile->readUnsignedShort();
                uint16_t absoluteHeight = relativeHeight + lastAbsoluteHeight;

                terrainData[i] = ((int32_t)absoluteHeight - 8191) / 32.0;

                lastAbsoluteHeight = absoluteHeight;
            }
        }

        void Terrain::write(File::File *file) {
            file->writeNull(8);

            file->writeUnsignedInteger(getVertexDimX() - 1);
            file->writeUnsignedInteger(getVertexDimY() - 1);

            file->writeNull(64);

            file->writeString(getWater()->getDiffuseTexture());
            file->writeString(getWater()->getBumpMapTexture());

            file->writeNull(2);

            file->writeFloat(getWater()->getDensity());
            file->writeFloat(getWater()->getDiffuseTextureRepeatsPerDistance());

            file->writeFloat(getWater()->getWaves());
            file->writeFloat(getWater()->getReflection());

            file->writeUnsigned8(getWater()->getBumpMapType());
            file->writeFloat(getWater()->getBumpMapHeightMapScale());
            file->writeFloat(getWater()->getBumpMapRepeatsPerDistance());

            file->writeUnsignedInteger(textureRepeats.size());
            for(uint32_t i = 0; i < textureRepeats.size(); i++) {
                file->writeFloat(textureRepeats[i]);
            }

            file->writeNull(19);

            file->writeUnsignedInteger(layer.size());
            for(uint32_t i = 0; i < layer.size(); i++) {
                layer[i]->write(file);
            }

            file->writeNull(64);

            File::BufferFile *terrainDataBuffer = new File::BufferFile();
            terrainDataBuffer->openWB();
            terrainDataBuffer->writeUnsignedInteger(getVertexDimX());
            terrainDataBuffer->writeUnsignedInteger(getVertexDimY());

            uint16_t lastAbsoluteHeight = 0;
            for (uint32_t i = 0; i < getVertexDimX() * getVertexDimY(); i++) {
                uint16_t absoluteHeight = ((terrainData[i] * 32.0f) + 8191);
                uint16_t relativeHeight = absoluteHeight - lastAbsoluteHeight;

                terrainDataBuffer->writeUnsignedShort(relativeHeight);

                lastAbsoluteHeight = absoluteHeight;
            }
            terrainDataBuffer->close();

            file->writeFileCompressed(terrainDataBuffer);
        }

        float Terrain::getHeightAtVertex(int32_t x, int32_t y) {
            x = std::max(std::min(x, (int)vertexDimX), 0);
            y = std::max(std::min(y, (int)vertexDimY), 0);

            return terrainData[(vertexDimY * y) + x];
        }

        void Terrain::setHeightAtVertex(int32_t x, int32_t y, float height) {
            x = std::max(std::min(x, (int)vertexDimX), 0);
            y = std::max(std::min(y, (int)vertexDimY), 0);

            terrainData[(vertexDimY * y) + x] = height;
        }

        void Terrain::allocTerrainData() {
            terrainData = (float*) realloc(terrainData, (vertexDimX * vertexDimY * sizeof(float)));
        }

        Water *Terrain::getWater() const {
            return water;
        }

        void Terrain::setWater(Water *value) {
            water = value;
        }

        std::vector<float> Terrain::getTextureRepeats() const {
            return textureRepeats;
        }

        void Terrain::insertTextureRepeats(float value) {
            textureRepeats.push_back(value);
        }

        std::vector<Layer*> Terrain::getLayer() const {
            return layer;
        }

        Layer *Terrain::getLayer(std::string name) {
            if(!name.size())
                return NULL;

            for(uint32_t i = 0; i < layer.size(); i++) {
                if(layer[i]->getName() == name)
                    return layer[i];
            }

            return NULL;
        }

        void Terrain::insertLayer(Layer* value) {
            layer.push_back(value);
        }

        uint32_t Terrain::getVertexDimX() const {
            return vertexDimX;
        }

        void Terrain::setVertexDimX(const uint32_t &value) {
            vertexDimX = value;
            allocTerrainData();
        }

        uint32_t Terrain::getVertexDimY() const {
            return vertexDimY;
        }

        void Terrain::setVertexDimY(const uint32_t &value) {
            vertexDimY = value;
            allocTerrainData();
        }
    }
}
