#ifndef POSITION_H
#define POSITION_H
// #include "../Direction.h"    // rnvs : comm
#include <utility>  // rnvs : ajout

namespace model // rnvs : ajout
{
// rnvs : ajout
using Direction2D = std::pair<int, int>;    // rnvs : ajout
struct Direction;   // rnvs : ajout
}   // rnvs : ajout

namespace model::shape
{


/**
 * @brief The Position Class
 * The position represents the position of a brick in the game,
 * a brick can have its position manipulated.
 */
class Position
{

    /**
     * @brief pos an x y coordinate
     */
    std::pair<int, int> pos;

  public:
    /**
     * @brief Position
     * The default position constructor initializes a position with a std::pair of <0,0>.
     * @param x
     * @param y
     */
    Position(int x = 0, int y = 0);

    /**
     * @brief get_x
     * @return value of x
     */
    const int & get_x() const;

    /**
     * @brief get_y
     * @return value of y
     */
    const int & get_y() const;
};

/**
 * ==================================
 *         OPERATOR
 * ==================================
 */
Position operator+(const Position & pos, const Direction2D & dir);
Position operator+(const Direction2D & dir, const Position & pos);
Position operator+(const Position & pos1, const Position & pos2);
bool operator==(const Position & pos1, const Position & pos2);
}

#endif
