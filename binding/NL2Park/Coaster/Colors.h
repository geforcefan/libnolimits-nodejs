#ifndef BINDING_NL2PARK_COLORS_H
#define BINDING_NL2PARK_COLORS_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Colors.h>

namespace Binding {
    namespace NL2Park {
        class SpineColorScheme {
        public:
            static BINDING_MODULE_INIT_ENUM(SpineColorScheme,
                BINDING_MODULE_ENUM_FIELD(Plain, Library::NL2Park::Colors::SpineColorScheme);
                BINDING_MODULE_ENUM_FIELD(TopAccented, Library::NL2Park::Colors::SpineColorScheme);
                BINDING_MODULE_ENUM_FIELD(BottomAccented, Library::NL2Park::Colors::SpineColorScheme);
                BINDING_MODULE_ENUM_FIELD(Stripe, Library::NL2Park::Colors::SpineColorScheme);
            );
        };

        class Colors : public Nan::ObjectWrap {
        public:
            explicit Colors(Library::NL2Park::Colors *colors) : _colors(colors) {}
            explicit Colors() : _colors(new Library::NL2Park::Colors) {}
            ~Colors() {}

            Library::NL2Park::Colors *getColors() { return _colors; }

            static BINDING_MODULE_INIT("Colors",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(WireframeTrack);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Rails);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(CrossTies);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(MainSpine);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Car);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Seat);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Harness);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Bogie);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Chasiss);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Supports);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Tunnel);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Handrails);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Catwalks);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SpineColorScheme);

                BINDING_PROTOTYPE_ENUM_LIST(SpineColorScheme);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Colors);

            BINDING_METHOD_SETTER_GETTER_VEC3(WireframeTrack, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Rails, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(CrossTies, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(MainSpine, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Car, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Seat, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Harness, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Bogie, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Chasiss, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Supports, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Tunnel, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Handrails, Colors);
            BINDING_METHOD_SETTER_GETTER_VEC3(Catwalks, Colors);
            BINDING_METHOD_SETTER_GETTER_ENUM(SpineColorScheme, Colors, Library::NL2Park::Colors::SpineColorScheme);

            Library::NL2Park::Colors *_colors;
        };
    }
}

#endif // BINDING_NL2PARK_COLORS_H
