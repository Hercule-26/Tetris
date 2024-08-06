#ifndef SHAPES_H
#define SHAPES_H
// #include "Shape.h"   // rnvs : comm

namespace model::shape
{
class Shape;    // rnvs : ajout
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
