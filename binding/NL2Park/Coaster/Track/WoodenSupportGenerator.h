#ifndef BINDING_NL2PARK_WOODENSUPPORTGENERATOR_H
#define BINDING_NL2PARK_WOODENSUPPORTGENERATOR_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/WoodenSupportGenerator.h>

namespace Binding {
    namespace NL2Park {
        class BentSpacing {
        public:
            static BINDING_MODULE_INIT_ENUM(BentSpacing,
                BINDING_MODULE_ENUM_FIELD(Spacing9Ft, Library::NL2Park::WoodenSupportGenerator::BentSpacing);
                BINDING_MODULE_ENUM_FIELD(Spacing625Ft, Library::NL2Park::WoodenSupportGenerator::BentSpacing);
                BINDING_MODULE_ENUM_FIELD(Spacing45Ft, Library::NL2Park::WoodenSupportGenerator::BentSpacing);
            );
        };

        class WoodenSupportGenerator : public Nan::ObjectWrap {
        public:
            explicit WoodenSupportGenerator(Library::NL2Park::WoodenSupportGenerator *woodenSupportGenerator) : _woodenSupportGenerator(woodenSupportGenerator) {}
            explicit WoodenSupportGenerator() : _woodenSupportGenerator(new Library::NL2Park::WoodenSupportGenerator) {}
            ~WoodenSupportGenerator() {}

            Library::NL2Park::WoodenSupportGenerator *getWoodenSupportGenerator() { return _woodenSupportGenerator; }

            static BINDING_MODULE_INIT("WoodenSupportGenerator",
                BINDING_PROTOTYPE_METHOD_GETTER(UseIndividualSettings);
                BINDING_PROTOTYPE_METHOD_GETTER(UseLeftWideSupports);
                BINDING_PROTOTYPE_METHOD_GETTER(UseRightWideSupports);
                BINDING_PROTOTYPE_METHOD_GETTER(UseLeftCatwalks);
                BINDING_PROTOTYPE_METHOD_GETTER(UseRightCatwalks);
                BINDING_PROTOTYPE_METHOD_GETTER(UseLeftHandrails);
                BINDING_PROTOTYPE_METHOD_GETTER(UseRightHandrails);
                BINDING_PROTOTYPE_METHOD_GETTER(CollisionDetection);
                BINDING_PROTOTYPE_METHOD_GETTER(EnableSupports);
                BINDING_PROTOTYPE_METHOD_GETTER(BentSpacing);

                BINDING_PROTOTYPE_ENUM_LIST(BentSpacing);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(WoodenSupportGenerator);

            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseIndividualSettings, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseLeftWideSupports, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseRightWideSupports, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseLeftCatwalks, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseRightCatwalks, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseLeftHandrails, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(UseRightHandrails, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(CollisionDetection, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(EnableSupports, WoodenSupportGenerator);
            BINDING_METHOD_SETTER_GETTER_ENUM(BentSpacing, WoodenSupportGenerator, Library::NL2Park::WoodenSupportGenerator::BentSpacing);

            Library::NL2Park::WoodenSupportGenerator *_woodenSupportGenerator;
        };
    }
}

#endif // BINDING_NL2PARK_WOODENSUPPORTGENERATOR_H
