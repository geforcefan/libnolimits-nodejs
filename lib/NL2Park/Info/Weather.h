#ifndef LIB_NL2PARK_WEATHER_H
#define LIB_NL2PARK_WEATHER_H

#include <Stream/Chunk.h>

namespace Library {
    namespace NL2Park {
        class Weather: public Stream::Chunk {
        public:
            Weather() : Stream::Chunk::Chunk() {
                rainIntensity = 0;
                snowIntensity = 0;
                fogIntensity = 0;
                windIntensity = 0;
                overcastIntensity = 0;
                cloudsIntensity = 0;
                thunderIntensity = 0;
                overwriteDefaultWeather = false;
            }

            void read(File::File *file);
            void write(File::File *file);

            float getRainIntensity() const;
            void setRainIntensity(float value);

            float getSnowIntensity() const;
            void setSnowIntensity(float value);

            float getFogIntensity() const;
            void setFogIntensity(float value);

            float getWindIntensity() const;
            void setWindIntensity(float value);

            float getOvercastIntensity() const;
            void setOvercastIntensity(float value);

            float getCloudsIntensity() const;
            void setCloudsIntensity(float value);

            float getThunderIntensity() const;
            void setThunderIntensity(float value);

            bool getOverwriteDefaultWeather() const;
            void setOverwriteDefaultWeather(bool value);

            static float convertWindIntensity(float value, bool fromWindIntensity);
            static float convertFogIntensity(float value, bool fromFogIntensity);
        private:
            float rainIntensity;
            float snowIntensity;
            float fogIntensity;
            float windIntensity;
            float overcastIntensity;
            float cloudsIntensity;
            float thunderIntensity;
            bool overwriteDefaultWeather;
        };
    }
}

#endif // WEATHER_H
