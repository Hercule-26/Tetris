#ifndef TETRISINTERFACE_H
#define TETRISINTERFACE_H
// #include "./Direction.h"     // rnvs : comm
// #include "../Util/Observer.h"    // rnvs : comm
#include "../Util/Observable.h"
// #include "./Shapes/Shape.h"  // rnvs : comm
#include "Rotation.h"
#include <vector>

namespace model
{
using Direction2D = std::pair<int, int>;    // rnvs : ajout
namespace shape // rnvs : ajout
{
class Shape;    // rnvs : ajout
}

struct TetrisInterface : public  util::Observable
{
    /**
     * @brief get_score
     * @return current score
     */
    virtual const int & get_score() const = 0;
    /**
     * @brief get_level
     * @return current level (1,2,3,..)
     */
    virtual const int & get_level() const = 0;
    /**
     * @brief speed value of the game
     * @return duration convert into double (1,0.83,0.76,...)
     */
    virtual const double get_tick() const = 0;
    /**
     * @brief get_board class
     * @return 2D arrow
     */
    virtual const std::vector<std::vector<int>> & get_board() const = 0;
    /**
     * @brief get_curr_shape
     * @return shape currently played
     */
    virtual const shape::Shape & get_curr_shape() const = 0;
    /**
     * @brief get_next_shape
     * @return next shape to be played
     */
    virtual const shape::Shape & get_next_shape() const = 0;

    /**
    * @brief move_shape_down Moves the shape downwards.
    *
    * This function attempts to move the shape downwards in the game.
    *
    * @return true if the shape can be successfully moved downwards, false if the shape cannot be moved further down and needs to be placed on the game board.
    */
    virtual bool move_shape_down() = 0;
    /**
     * @brief move shape to te left of right
     * @param dir
     */
    virtual void move_shape_l_r(Direction2D dir) = 0;

    /**
     * @brief rotate_shape to te left or right if rotation is possible
     * @param dir
     */
    virtual void rotate_shape(Rotation dir) = 0;

    /**
     * @brief drop_shape directly to bottom of the board
     */
    virtual void drop_shape() = 0;

    /**
     * @brief Register observer
     * @param obs
     */
    virtual void Register(util::Observer * obs) = 0;

    /**
     * @brief Unregister observer
     * @param obs
     */
    virtual void Unregister(util::Observer * obs) = 0;

    /**
     * @brief game is over if is not possible to place a shape up board
     * @return
     */
    virtual bool is_game_over() = 0;

    /**
     * @brief get_shape_color and assign unique id to unique color
     * @param id
     * @return color in string
     *
    virtual const std::string get_shape_color(int id) const = 0;*/

    /**
     * @brief ~TetrisInterface
     */
    virtual ~TetrisInterface() = default;

  private:

    /**
     * @brief notify new value to observer
     */
    virtual void notify() = 0;

    /**
     * @brief places the piece definitively on the board, sets the score and,
     * if necessary, asks for a level increment, moves on to the next shape.
     * @param the value of the player's drop case
     * @default value considering that the player did not make a drop
     */
    virtual void setShapeOnBoard(int drop_value = 0) = 0;

    /**
     * @brief set_score
     * @param score
     */
    virtual void set_score(int score) = 0;

    /**
     * @brief increments to next level
     */
    virtual void next_level() = 0;

    /**
     * @brief passes the next brick to the current brick
     */
    virtual void next_shape() = 0;

    /**
     * @brief calculate_score
     * @param l is the number of lines performed at the
     * @param d number of slots (in height)
     * @param n is the current level
     * @return final score calculed
     */
    virtual int calculate_score(int l, int d, int n) = 0;

};

}
#endif // TETRISINTERFACE_H
