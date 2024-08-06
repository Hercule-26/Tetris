#ifndef BAG_H
#define BAG_H
#include <vector>
#include "Shapes/Shape.h"


namespace model {

/**
 * @brief The Bag class
 * Tetris shapes are generated from a bag of bricks, i.e. from a set of bricks.
 */
class Bag {

    /**
     * @brief shapes : Vector containing shapes in the bag.
     */
    std::vector<shape::Shape> shapes;

    /**
     * @brief cpt : Counter for tracking the number of shapes retrieved.
     */
    int cpt;

public:

    /**
     * @brief Bag
     * Constructor of the bag
     */
    Bag();

    /**
    * @brief Retrieves the next shape from the bag.
    *
    * If the bag is empty, it will be refilled and reshuffled.
    *
    * @return A reference to the next shape in the bag.
    */
   const shape::Shape &get_shape();

private:
   /**
    * @brief Refills the bag with shapes and shuffles them.
    */
    void reorder();
};

}
#endif // BAG_H
