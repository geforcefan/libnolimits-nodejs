#ifndef LIB_NL2PARK_INFO_H
#define LIB_NL2PARK_INFO_H

#include <Stream/NoLimitsStream.h>
#include <NL2Park/Info/Weather.h>
#include <NL2Park/Info/Sky.h>

namespace Library {
    namespace NL2Park {
        class Info: public Stream::NoLimitsStream {
        public:
            enum RideView {
                ClosestCoasterFirstTrain = 0,
                ClosestCoasterClosestTrain = 1,
                FlyView = 2,
                WalkView = 3
            };

            Info();
            void read();

            Weather *getWeather() const;
            Sky *getSky() const;

            std::string getAuthor() const;
            void setAuthor(const std::string &value);

            std::string getDescription() const;
            void setDescription(const std::string &value);

            std::string getPreview() const;
            void setPreview(const std::string &value);

            std::string getEnvironment() const;
            void setEnvironment(const std::string &value);

            glm::vec3 getInitialPosition() const;
            void setInitialPosition(const glm::vec3 &value);

            glm::vec2 getInitialRotation() const;
            void setInitialRotation(const glm::vec2 &value);

            RideView getInitialView();
            void setInitialView(RideView value);

        private:
            Weather *weather;
            Sky *sky;

            std::string author;
            std::string description;
            std::string preview;
            std::string environment;

            glm::vec3 initialPosition;
            glm::vec2 initialRotation;
            RideView initialView;
        };
    }
}

#endif // INFO_H
