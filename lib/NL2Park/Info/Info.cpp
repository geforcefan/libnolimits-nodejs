#include <NL2Park/Info/Info.h>
#include <iostream>

namespace Library {
    namespace NL2Park {
        Info::Info() {
            weather = new Weather();
            sky = new Sky();

            author = std::string("Ercan Yeah");
        }

        void Info::read() {
            readNull(31);

            getWeather()->readStream(this);

            readNull(6);

            setAuthor(readString());
            setDescription(readString());
            setPreview(readString());
            setEnvironment(readString());

            readNull(9);

            getSky()->readStream(this);

            readNull(1);

            setInitialPosition(readFloatVec3());
            setInitialRotation(readFloatVec2());

            setInitialView((Info::RideView)readUnsigned8());
        }

        Sky *Info::getSky() const {
            return sky;
        }

        Info::RideView Info::getInitialView() {
            return initialView;
        }

        void Info::setInitialView(Info::RideView value) {
            initialView = value;
        }

        glm::vec2 Info::getInitialRotation() const {
            return initialRotation;
        }

        void Info::setInitialRotation(const glm::vec2 &value) {
            initialRotation = value;
        }

        glm::vec3 Info::getInitialPosition() const {
            return initialPosition;
        }

        void Info::setInitialPosition(const glm::vec3 &value) {
            initialPosition = value;
        }

        std::string Info::getEnvironment() const {
            return environment;
        }

        void Info::setEnvironment(const std::string &value) {
            environment = value;
        }

        std::string Info::getPreview() const {
            return preview;
        }

        void Info::setPreview(const std::string &value) {
            preview = value;
        }

        std::string Info::getDescription() const {
            return description;
        }

        void Info::setDescription(const std::string &value) {
            description = value;
        }

        std::string Info::getAuthor() const {
            return author;
        }

        void Info::setAuthor(const std::string &value) {
            author = value;
        }

        Weather *Info::getWeather() const {
            return weather;
        }
    }
}
