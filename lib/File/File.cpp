#include <File/File.h>

namespace Library {
    namespace File {
        File::File() {
            openedWB = false;
            openedRB = false;
        }
        bool File::isOpenedRB() const {
            return openedRB;
        }

        bool File::isOpenedWB() const {
            return openedWB;
        }
    }
}
