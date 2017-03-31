#include <NL2Park/Info/Weather.h>
#include <iostream>

namespace Library {
    namespace NL2Park {

        void Weather::read() {
           setOverwriteDefaultWeather(readBoolean());
           setRainIntensity(readFloat());
           setSnowIntensity(readFloat());
           setWindIntensity(Weather::convertWindIntensity(readFloat(), true));
           setFogIntensity(Weather::convertFogIntensity(readFloat(), true));
           setCloudsIntensity(readFloat());
           setOvercastIntensity(readFloat());
           setThunderIntensity(readFloat());
        }

        bool Weather::getOverwriteDefaultWeather() const {
            return overwriteDefaultWeather;
        }

        void Weather::setOverwriteDefaultWeather(bool value) {
            overwriteDefaultWeather = value;
        }

        float Weather::getThunderIntensity() const {
            return thunderIntensity;
        }

        void Weather::setThunderIntensity(float value) {
            thunderIntensity = value;
        }

        float Weather::getCloudsIntensity() const {
            return cloudsIntensity;
        }

        void Weather::setCloudsIntensity(float value) {
            cloudsIntensity = value;
        }

        float Weather::getOvercastIntensity() const {
            return overcastIntensity;
        }

        void Weather::setOvercastIntensity(float value) {
            overcastIntensity = value;
        }

        float Weather::getWindIntensity() const {
            return windIntensity;
        }

        void Weather::setWindIntensity(float value) {
            windIntensity = value;
        }

        float Weather::getFogIntensity() const {
            return fogIntensity;
        }

        void Weather::setFogIntensity(float value) {
            fogIntensity = value;
        }

        float Weather::getSnowIntensity() const {
            return snowIntensity;
        }

        void Weather::setSnowIntensity(float value) {
            snowIntensity = value;
        }

        float Weather::getRainIntensity() const {
            return rainIntensity;
        }

        void Weather::setRainIntensity(float value) {
            rainIntensity = value;
        }


        float Weather::convertWindIntensity(float value, bool fromWindIntensity) {
            if (fromWindIntensity) {
                return (1 * value) / 34.75186920166;
            } else {
                return (34.75186920166 * value) / 1;
            }
        }

        float Weather::convertFogIntensity(float value, bool fromFogIntensity) {
            if (fromFogIntensity) {
                return (1.0 * value) / 0.05;
            } else {
                return (0.050000000745058 * value) / 1;
            }
        }
    }
}
