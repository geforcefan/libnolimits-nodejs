#ifndef WATER_H
#define WATER_H

#include <string>
#include "TerrainMap.h"

namespace Library {
    namespace NL2Park {
        class Water
        {
        public:
            Water() {}

            float getDensity() const;
            void setDensity(float value);

            std::string getDiffuseTexture() const;
            void setDiffuseTexture(const std::string &value);

            float getDiffuseTextureRepeatsPerDistance() const;
            void setDiffuseTextureRepeatsPerDistance(float value);

            std::string getBumpMapTexture() const;
            void setBumpMapTexture(const std::string &value);

            float getBumpMapRepeatsPerDistance() const;
            void setBumpMapRepeatsPerDistance(float value);

            TerrainMap getBumpMapType() const;
            void setBumpMapType(const TerrainMap &value);

            float getBumpMapHeightMapScale() const;
            void setBumpMapHeightMapScale(float value);

            float getReflection() const;
            void setReflection(float value);

            float getWaves() const;
            void setWaves(float value);

        private:
            float density;

            std::string diffuseTexture;
            float diffuseTextureRepeatsPerDistance;

            std::string bumpMapTexture;
            float bumpMapRepeatsPerDistance;

            TerrainMap bumpMapType;
            float bumpMapHeightMapScale;

            float reflection;
            float waves;
        };
    }
}

#endif // WATER_H
