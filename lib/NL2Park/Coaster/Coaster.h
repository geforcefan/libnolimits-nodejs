#ifndef LIB_NL2PARK_COASTER_H
#define LIB_NL2PARK_COASTER_H

#include <vector>

#include <Stream/NoLimitsStream.h>
#include <lib/NL2Park/Coaster/Colors.h>
#include <lib/NL2Park/Coaster/Style.h>
#include <lib/NL2Park/Coaster/Mode.h>
#include <lib/NL2Park/Coaster/Track/Track.h>
#include <lib/NL2Park/Coaster/Track/CustomTrack.h>

namespace Library {
    namespace NL2Park {
        class Coaster: public Stream::NoLimitsStream {
        public:
            Coaster();
            void read();

            std::string getName() const;
            void setName(const std::string &value);

            std::string getDescription() const;
            void setDescription(const std::string &value);

            uint32_t getNumberOfCarsPerTrain() const;
            void setNumberOfCarsPerTrain(const uint32_t &value);

            bool getHideWireframe() const;
            void setHideWireframe(bool value);

            bool getFreezed() const;
            void setFreezed(bool value);

            Colors *getColors() const;
            void setColors(Colors *value);

            Style *getStyle() const;
            void setStyle(Style *value);

            Mode *getMode() const;
            void setMode(Mode *value);

            std::vector<std::string> getFileScript() const;
            void insertFileScript(std::string value);

            std::vector<Track*> getTrack() const;
            void insertTrack(Track* value);

        private:
            std::string name;
            std::string description;

            uint32_t numberOfCarsPerTrain;

            bool hideWireframe;
            bool freezed;

            Colors *colors;
            Style *style;
            Mode *mode;

            std::vector<Track *> track;
            std::vector<std::string> fileScript;
        };
    }
}

#endif // LIB_NL2PARK_COASTER_H
