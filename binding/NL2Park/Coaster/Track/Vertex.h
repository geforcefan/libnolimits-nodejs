#ifndef BINDING_NL2PARK_VERTEX_H
#define BINDING_NL2PARK_VERTEX_H

#include <binding/nolimits.h>
#include <lib/NL2Park/Coaster/Track/Vertex.h>

namespace Binding {
    namespace NL2Park {
        class Vertex : public Nan::ObjectWrap {
        public:
            explicit Vertex(Library::NL2Park::Vertex *vertex) : _vertex(vertex) {}
            explicit Vertex() : _vertex(new Library::NL2Park::Vertex) {}
            ~Vertex() {}

            Library::NL2Park::Vertex *getVertex() { return _vertex; }

            static BINDING_MODULE_INIT("Vertex",
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Position);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Locked);
                BINDING_PROTOTYPE_METHOD_SETTER_GETTER(Strict);
            );

            static BINDING_NEW_INSTANCE();
        private:
            static BINDING_PERSISTENT_CONSTRUCTOR();
            static BINDING_METHOD_NEW_CAST_EXTERNAL(Vertex);

            BINDING_METHOD_SETTER_GETTER_VEC4(Position, Vertex);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Locked, Vertex);
            BINDING_METHOD_SETTER_GETTER_BOOLEAN(Strict, Vertex);

            Library::NL2Park::Vertex *_vertex;
        };
    }
}

#endif // BINDING_NL2PARK_VERTEX_H
