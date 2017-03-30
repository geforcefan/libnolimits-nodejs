#ifndef LIB_STREAM_NOLIMITSSTREAM_H
#define LIB_STREAM_NOLIMITSSTREAM_H

#include <File/File.h>
#include <File/BufferFile.h>

#include <stdint.h>
#include <nolimits.h>

namespace Library {
    namespace Stream {
        class NoLimitsStream {
        public:
            NoLimitsStream() {}

            void readChunk(File::File *_file);
            void readStream(NoLimitsStream *stream);

            int getChunkSize() const;
            int getFileSize() const;

            File::File *getFile() const;

        protected:
            virtual void read() = 0;

            uint16_t readUnsignedShort();
            uint32_t readUnsignedInteger();
            uint8_t readUnsigned8();

            int readInteger();
            void readNull(long count);
            float readFloat();
            bool readBoolean();

            glm::vec2 readIntVec2();
            glm::vec2 readFloatVec2();
            glm::vec3 readFloatVec3();

            std::string readString();

            std::string readChunkName();
            File::BufferFile *getChunkBufferFile();

            File::File *file;
            void setStreamPosition(int streamPosition);
            int getStreamPosition();

            template <typename T> T bswap(T val);
            template <typename T> T be2Host(T val);
            template <typename T> T host2Be(T val);
            template <typename T> T le2Host(T val);
            template <typename T> T host2Le(T val);
        private:
            int chunkSize;
        };
    }
}

#endif // NOLIMITSSTREAM_H
