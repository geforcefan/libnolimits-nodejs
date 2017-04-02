#include "NoLimitsStream.h"
#include <iostream>

namespace Library {
    namespace Stream {
        void NoLimitsStream::readChunk(File::File *_file) {
            file = _file;
            file->openRB();

            chunkSize = readUnsignedInteger();
            read();
        }

        void NoLimitsStream::readStream(NoLimitsStream *stream) {
            file = stream->getFile();
            read();
        }

        bool NoLimitsStream::readBoolean() {
            bool buffer;
            file->read(&buffer, 1, 1);

            return buffer;
        }

        void NoLimitsStream::readNull(long count) {
            file->seek(count, SEEK_CUR);
        }

        float NoLimitsStream::readFloat() {
            float floatBuffer;
            file->read(&floatBuffer, 4, 1);
            floatBuffer = be2Host(floatBuffer);

            return floatBuffer;
        }

        double NoLimitsStream::readDouble() {
            double doubleBuffer;
            file->read(&doubleBuffer, 8, 1);
            doubleBuffer = be2Host(doubleBuffer);

            return doubleBuffer;
        }

        uint16_t NoLimitsStream::readUnsignedShort() {
            uint16_t shortBuffer;
            file->read(&shortBuffer, 2, 1);
            shortBuffer = le2Host(shortBuffer);

            return shortBuffer;
        }

        uint32_t NoLimitsStream::readUnsignedInteger() {
            uint32_t intBuffer;
            file->read(&intBuffer, 4, 1);
            intBuffer = be2Host(intBuffer);

            return intBuffer;
        }

        uint8_t NoLimitsStream::readUnsigned8() {
            uint8_t u8Buffer;
            file->read(&u8Buffer, 1, 1);

            return u8Buffer;
        }

        int NoLimitsStream::readInteger() {
            int intBuffer;
            file->read(&intBuffer, 4, 1);
            intBuffer = le2Host(intBuffer);

            return intBuffer;
        }

        glm::vec3 NoLimitsStream::readColor() {
            return readUnsigned8Vec3();
        }

        glm::vec2 NoLimitsStream::readIntVec2() {
            return glm::vec2(readInteger(), readInteger());
        }

        glm::vec2 NoLimitsStream::readFloatVec2() {
            return glm::vec2(readFloat(), readFloat());
        }

        glm::vec3 NoLimitsStream::readFloatVec3() {
            return glm::vec3(readFloat(), readFloat(), readFloat());
        }

        glm::vec3 NoLimitsStream::readUnsigned8Vec3() {
            return glm::vec3(readUnsigned8(), readUnsigned8(), readUnsigned8());
        }

        glm::vec2 NoLimitsStream::readDoubleVec2() {
            return glm::vec2(readDouble(), readDouble());
        }

        glm::vec4 NoLimitsStream::readDoubleVec4() {
            return glm::vec4(readDouble(), readDouble(), readDouble(), readDouble());
        }

        std::string NoLimitsStream::readChunkName() {
            std::string chunkName(4, '\0');
            file->read(&chunkName[0], sizeof(char), 4);

            return chunkName;
        }

        std::string NoLimitsStream::readString() {
            bool terminated = false;
            std::string str;

            while (!terminated) {
                char buffer[2];
                file->read(&buffer[0], 1, 2);
                char c = buffer[1];

                if (c == 0) {
                    terminated = true;
                } else {
                    str.append(1, c);
                }
            }

            return str;
        }

        int NoLimitsStream::getChunkSize() const {
            return chunkSize;
        }

        int NoLimitsStream::getFileSize() const {
            return file->getFilesize();
        }

        void NoLimitsStream::setStreamPosition(int streamPosition) {
            file->seek(streamPosition, SEEK_SET);
        }

        int NoLimitsStream::getStreamPosition() {
            return file->tell();
        }

        File::BufferFile *NoLimitsStream::getChunkBufferFile() {
            uint32_t chunkSize = readUnsignedInteger();

            char *chunkBuffer = (char*) malloc(chunkSize + 4);

            file->seek(-4, SEEK_CUR);
            file->read(&chunkBuffer[0], chunkSize + 4, 1);

            File::BufferFile *bufferFile = new File::BufferFile();
            bufferFile->setBuffer(chunkBuffer, chunkSize + 4);

            return bufferFile;
        }

        File::File *NoLimitsStream::getFile() const {
            return file;
        }

        template <typename T>
        T NoLimitsStream::bswap(T val) {
            T retVal;
            char *pVal = (char*) &val;
            char *pRetVal = (char*)&retVal;
            int size = sizeof(T);
            for(int i=0; i<size; i++) {
                pRetVal[size-1-i] = pVal[i];
            }

            return retVal;
        }

        template <typename T>
        T NoLimitsStream::be2Host(T val) {
        #ifdef __BIG_ENDIAN__
            return val;
        #else
            return bswap(val);
        #endif
        }

        template <typename T>
        T NoLimitsStream::host2Be(T val) {
        #ifdef __BIG_ENDIAN__
            return val;
        #else
            return bswap(val);
        #endif
        }

        template <typename T>
        T NoLimitsStream::le2Host(T val) {
        #ifdef __BIG_ENDIAN__
            return bswap(val);
        #else
            return val;
        #endif
        }
        template <typename T>
        T NoLimitsStream::host2Le(T val) {
        #ifdef __BIG_ENDIAN__
            return bswap(val);
        #else
            return val;
        #endif
        }
    }
}
