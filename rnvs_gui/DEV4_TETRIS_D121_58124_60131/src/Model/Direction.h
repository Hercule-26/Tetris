#ifndef DIRECTION_H
#define DIRECTION_H
#include <utility>

/**
 * @brief The Direction struct
 * Contains predefined 2-dimensional direction vectors for common directions:
 * UP, DOWN, LEFT, RIGHT, for move Position.
 */
namespace model {
using Direction2D = std::pair<int, int>;

struct Direction
{
    static const Direction2D UP;
    static const Direction2D DOWN;
    static const Direction2D LEFT;
    static const Direction2D RIGHT;
};

inline const Direction2D Direction::UP = std::pair(-1, 0);
inline const Direction2D Direction::DOWN = std::pair(1, 0);
inline const Direction2D Direction::LEFT = std::pair(0, -1);
inline const Direction2D Direction::RIGHT = std::pair(0, 1);

}
#endif // DIRECTION_H
