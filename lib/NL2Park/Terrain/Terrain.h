#ifndef LIB_NL2PARK_TERRAIN_H
#define LIB_NL2PARK_TERRAIN_H

#include <string>
#include <Stream/Chunk.h>

#include <vector>
#include <map>

#include "Water.h"
#include "Layer.h"

namespace Library {
    namespace NL2Park {
        class Terrain: public Stream::Chunk {
        public:
            Terrain() {
                water = new Water();
                terrainData = (float *)malloc(0);

                vertexDimX = 0;
                vertexDimY = 0;
            }

            void read(File::File *file);
            void write(File::File *file);

            Water *getWater() const;
            void setWater(Water *value);

            std::vector<float> getTextureRepeats() const;
            void insertTextureRepeats(float value);

            std::vector<Layer*> getLayer() const;
            Layer *getLayer(std::string name);
            void insertLayer(Layer* value);

            uint32_t getVertexDimX() const;
            void setVertexDimX(const uint32_t &value);

            uint32_t getVertexDimY() const;
            void setVertexDimY(const uint32_t &value);

            float getHeightAtVertex(int32_t x, int32_t y);
            void setHeightAtVertex(int32_t x, int32_t y, float height);
        private:
            uint32_t vertexDimX;
            uint32_t vertexDimY;

            Water *water;
            std::vector<float> textureRepeats;
            std::vector<Layer*> layer;

            float *terrainData;

            void allocTerrainData();

        protected:
            std::string getChunkName() { return "TERC"; }
        };
    }
}

#endif
