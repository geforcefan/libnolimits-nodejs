#ifndef BINDING_NL2PARK_SUPPORTNODE_H
#define BINDING_NL2PARK_SUPPORTNODE_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/Support/SupportNode.h>

namespace Binding {
    namespace NL2Park {
        class SupportNodeColorMode {
        public:
            static BINDING_MODULE_INIT_ENUM(ColorMode,
                BINDING_MODULE_ENUM_FIELD(CustomColor, Library::NL2Park::SupportNode::ColorMode);
                BINDING_MODULE_ENUM_FIELD(SupportColor, Library::NL2Park::SupportNode::ColorMode);
                BINDING_MODULE_ENUM_FIELD(HandrailsColor, Library::NL2Park::SupportNode::ColorMode);
                BINDING_MODULE_ENUM_FIELD(CatwalkColor, Library::NL2Park::SupportNode::ColorMode);
                BINDING_MODULE_ENUM_FIELD(SpineColor, Library::NL2Park::SupportNode::ColorMode);
            );
        };
    }
}

#endif // BINDING_NL2PARK_RAILNODE_H
