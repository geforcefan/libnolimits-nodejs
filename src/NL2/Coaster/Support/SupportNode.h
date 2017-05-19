#ifndef BINDING_NL2PARK_SUPPORTNODE_H
#define BINDING_NL2PARK_SUPPORTNODE_H

#include "../../../Nolimits.h"
#include <libnolimits/NL2/Coaster/Support/SupportNode.h>

namespace Binding {
    namespace NoLimits2 {
        class SupportNodeColorMode {
        public:
            static BINDING_MODULE_INIT_ENUM(ColorMode,
                BINDING_MODULE_ENUM_FIELD(CustomColor, NoLimits::NoLimits2::SupportNode::ColorMode);
                BINDING_MODULE_ENUM_FIELD(SupportColor, NoLimits::NoLimits2::SupportNode::ColorMode);
                BINDING_MODULE_ENUM_FIELD(HandrailsColor, NoLimits::NoLimits2::SupportNode::ColorMode);
                BINDING_MODULE_ENUM_FIELD(CatwalkColor, NoLimits::NoLimits2::SupportNode::ColorMode);
                BINDING_MODULE_ENUM_FIELD(SpineColor, NoLimits::NoLimits2::SupportNode::ColorMode);
            );
        };
    }
}

#endif // BINDING_NL2PARK_RAILNODE_H
