#ifndef BINDING_NL2PARK_RAILNODE_H
#define BINDING_NL2PARK_RAILNODE_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/Support/RailNode.h>
#include <binding/NL2Park/Coaster/Track/Support/SupportNode.h>

namespace Binding {
    namespace NL2Park {
        class ConnectionStyle {
        public:
            static BINDING_MODULE_INIT_ENUM(ConnectionStyle,
                BINDING_MODULE_ENUM_FIELD(TrackDefault, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(Simple, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(CorkscrewStraightDown, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(TwistedStraightDown, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(TwistedHorizontal, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(TwistedVertical, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(Horizontal4D, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(Vertical4D, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(Aligned4D, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(Special4D, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(SuspendedHorizontal, Library::NL2Park::RailNode::ConnectionStyle);
                BINDING_MODULE_ENUM_FIELD(SuspendedVertical, Library::NL2Park::RailNode::ConnectionStyle);
            );
        };

        class RailNode : public Nan::ObjectWrap {
        public:
            explicit RailNode(Library::NL2Park::RailNode *railNode) : _railNode(railNode) {}
            explicit RailNode() : _railNode(new Library::NL2Park::RailNode) {}
            ~RailNode() {}

            Library::NL2Park::RailNode *getRailNode() { return _railNode; }

            static BINDING_MODULE_INIT("RailNode",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Position);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ConnectionStyle);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(SizeParameter);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(TrackIndex);

                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Color);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(ColorMode);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HasNoCapsForLODsHint);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HasDimAsIfItWasInATunnel);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HasNoStartCapHint);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HasNoEndCapHint);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(HasRotationModeAzimuth);

                BINDING_PROTOTYPE_ENUM_LIST(ConnectionStyle);
                BINDING_PROTOTYPE_ENUM_LIST(Binding::NL2Park::SupportNodeColorMode);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(RailNode);

            BINDING_METHOD_SETTER_GETTER_DOUBLE(Position, RailNode);
            BINDING_METHOD_SETTER_GETTER_ENUM(ConnectionStyle, RailNode, Library::NL2Park::RailNode::ConnectionStyle);
            BINDING_METHOD_SETTER_GETTER_DOUBLE(SizeParameter, RailNode);
            BINDING_METHOD_SETTER_GETTER_UNSIGNED_8(TrackIndex, RailNode);

            BINDING_METHOD_SETTER_GETTER_VEC3(Color, RailNode);
            BINDING_METHOD_SETTER_GETTER_ENUM(ColorMode, RailNode, Library::NL2Park::SupportNode::ColorMode);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(HasNoCapsForLODsHint, RailNode);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(HasDimAsIfItWasInATunnel, RailNode);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(HasNoStartCapHint, RailNode);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(HasNoEndCapHint, RailNode);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(HasRotationModeAzimuth, RailNode);

            Library::NL2Park::RailNode *_railNode;
        };
    }
}

#endif // BINDING_NL2PARK_RAILNODE_H
