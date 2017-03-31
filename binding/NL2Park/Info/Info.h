#ifndef BINDING_NL2PARK_INFO_H
#define BINDING_NL2PARK_INFO_H

#include <binding/nolimits.h>
#include <binding/NL2Park/Info/Weather.h>
#include <binding/NL2Park/Info/Sky.h>
#include <lib/NL2Park/Info/Info.h>

namespace Binding {
    namespace NL2Park {
        class RideView {
        public:
            static BINDING_MODULE_INIT_ENUM(RideView,
                BINDING_MODULE_ENUM_FIELD(ClosestCoasterFirstTrain, Library::NL2Park::Info::RideView);
                BINDING_MODULE_ENUM_FIELD(ClosestCoasterClosestTrain, Library::NL2Park::Info::RideView);
                BINDING_MODULE_ENUM_FIELD(FlyView, Library::NL2Park::Info::RideView);
                BINDING_MODULE_ENUM_FIELD(WalkView, Library::NL2Park::Info::RideView);
            );
        };

        class Info : public Nan::ObjectWrap {
        public:
            explicit Info() : _info(new Library::NL2Park::Info) {}
            explicit Info(Library::NL2Park::Info *info) : _info(info) {}

            ~Info() {}

            Library::NL2Park::Info *getInfo() { return _info; }

            static BINDING_MODULE_INIT("Info",
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Author);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Description);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Preview);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Environment);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(InitialPosition);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(InitialRotation);
               BINDING_PROTOTYPE_METHOD_SETTER_GETTER(InitialView);
               BINDING_PROTOTYPE_METHOD_GETTER(Weather);
               BINDING_PROTOTYPE_METHOD_GETTER(Sky);
               BINDING_PROTOTYPE_ENUM_LIST(RideView);
            );

            static BINDING_NEW_INSTANCE();
        private:
            BINDING_METHOD_SETTER_GETTER_STRING(Author, Info);
            BINDING_METHOD_SETTER_GETTER_STRING(Description, Info);
            BINDING_METHOD_SETTER_GETTER_STRING(Preview, Info);
            BINDING_METHOD_SETTER_GETTER_STRING(Environment, Info);
            BINDING_METHOD_SETTER_GETTER_VEC3(InitialPosition, Info);
            BINDING_METHOD_SETTER_GETTER_VEC2(InitialRotation, Info);
            BINDING_METHOD_SETTER_GETTER_ENUM(InitialView, Info, Library::NL2Park::Info::RideView);
            BINDING_METHOD_GETTER_OBJECT(Weather, Info);
            BINDING_METHOD_GETTER_OBJECT(Sky, Info);

            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Info);

            Library::NL2Park::Info *_info;
        };
    }
}

#endif // BINDING_NL2PARK_INFO_H
