#ifndef LIB_FILE_FILE_H
#define LIB_FILE_FILE_H

#include <cstddef>
#include <cstring>
#include <fstream>

namespace Library {
    namespace File {
        class File
        {
        public:
            File();

            virtual bool openWB() { return false; }
            virtual bool openRB() { return false; }

            virtual std::streamsize write(const void * ptr, std::streamsize size, std::streamsize count) { return 0; }
            virtual std::streamsize read (void * ptr, std::streamsize size, std::streamsize count) { return 0; }

            virtual bool close() { return false; }

            virtual bool isEof() { return false; }
            virtual int seek(long offset, int origin) { return 0; }
            virtual long tell() { return false; }
            virtual int flush() { return false; }

            bool isOpenedWB() const;
            bool isOpenedRB() const;

            virtual bool canWrite() { return false; }
            virtual bool canSeekInFile() { return false; }

            virtual long getFilesize() { return 0; }
        protected:
            bool openedWB;
            bool openedRB;
        };
    }
}

#endif
