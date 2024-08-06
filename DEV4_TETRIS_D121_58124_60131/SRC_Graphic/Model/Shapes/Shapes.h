#ifndef SHAPES_H
#define SHAPES_H
#include "Shape.h"

namespace model::shape {
    /**
     * @brief createShape
     *  * Creates a shape by providing its identifier.
     * If the identifier is not recognized, an exception is thrown.
     * @param id
     * @return Shape
     */
    Shape createShape(int id);
}
#endif // SHAPES_H
