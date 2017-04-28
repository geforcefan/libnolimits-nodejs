#ifndef LIB_NL2PARK_INFO_H
#define LIB_NL2PARK_INFO_H

#include <Stream/Chunk.h>
#include <NL2Park/Info/Weather.h>
#include <NL2Park/Info/Sky.h>
#include "Version.h"

namespace Library {
    namespace NL2Park {
        class Info: public Stream::Chunk {
        public:
            enum RideView {
                ClosestCoasterFirstTrain = 0,
                ClosestCoasterClosestTrain = 1,
                FlyView = 2,
                WalkView = 3
            };

            Info();

            void read(File::File *file);
            void write(File::File *file);

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

            Version *getVersion() const;
            void setVersion(Version *value);

        private:
            Weather *weather;
            Sky *sky;
            Version *version;

            std::string author;
            std::string description;
            std::string preview;
            std::string environment;

            glm::vec3 initialPosition;
            glm::vec2 initialRotation;
            RideView initialView;

        protected:
            std::string getChunkName() { return "INFO"; }
        };
    }
}

#endif // LIB_NL2PARK_INFO_H
