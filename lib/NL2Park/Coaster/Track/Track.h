#ifndef LIB_NL2PARK_TRACK_H
#define LIB_NL2PARK_TRACK_H

#include <Stream/NoLimitsStream.h>

namespace Library {
    namespace NL2Park {
        class Track {
        public:
            enum TrackType {
                None,
                Custom,
                SpecialTrack
            };

            Track(TrackType trackType) : _trackType(trackType) {}
            Track() : _trackType(TrackType::None) {}
            TrackType getTrackType() const;
            void setTrackType(const TrackType &value);

        private:
            TrackType _trackType;
        };
    }
}

#endif // TRACK_H
