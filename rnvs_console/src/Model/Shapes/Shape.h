#ifndef SHAPE_H
#define SHAPE_H
#include <map>
#include <vector>
#include "Position.h"
#include "../Rotation.h"
namespace model::shape
{

/**
 * @brief The Shape class
 * The Shape class represents a geometric shape made up of several bricks.
 * The shape can move around the board and collide with other shapes.
 */
class Shape
{

    /**
     * @brief id : A unique identifier associated with each shape (e.g., 1 for the L shape).
     */
    int id;

    /**
     * @brief rotation_state : four saved rotation states.
     */
    int rotation_state;

    /**
     * @brief cell_status : A list of positions for its four bricks.
     */
    std::map<int, std::vector<shape::Position>> cell_status;

    /**
     * @brief offset : Offset from its central position.
     */
    Position offset;

  public:
    Shape();
    /**
    * @brief Rotates the shape.
    * This function rotates the shape either left or right based on the given rotation direction.
    * @param rotation The direction of rotation (`model::Rotation::LEFT` for left rotation, `model::Rotation::RIGHT` for right rotation).
    */
    void rotate(model::Rotation rotation);

    /**
     * @brief move
     * Move all brick of the shape with a offset
     * @param row
     * @param column
     */
    void move(int row, int column);


    /**
     * @brief move
     * Moves the shape in a specified direction.
     * Use the enumeration Direction to specify the direction.
     * For example, `model::Direction::DOWN` corresponds to the position `(1,0)`.
     * @param d The direction to move the shape.
     */
    void move(Direction2D d);

    /**
     * @brief get_id
     * Get the unique identifier of the shape.
     * @return The id of the shape as an integer.
     */
    const int & get_id() const;
    /**
     * @brief get_cell_status
     * Get a vector containing the positions of each brick in the shape.
     * @return A vector of Position objects representing the positions of the bricks.
     */
    const std::vector<Position> & get_cell_status() const;
    /**
     * @brief get_offset
     * Get the offset of the shape from its central position.
     * @return The offset as a Position object.
     */
    const Position & get_offset() const;
    /**
     * @brief set_cell_status
     * Set a new rotation status for the shape.
     * @param cell_status
     */
    void set_cell_status(std::map<int, std::vector<shape::Position>>
                         cell_status);
    /**
     * @brief set_id
     * Set unique id for the shape.
     * @param id
     */
    void set_id(int id);
};

/**
 * ==================================
 *         OPERATOR
 * ==================================
 */

bool operator ==(const Shape & s, const Position & pos);
bool operator ==(const Position & pos, const Shape & s);
}
#endif // SHAPE_H
