#ifndef GAME_H
#define GAME_H
#include "TetrisInterface.h"
#include <set>
#include "Bag.h"
#include "Level.h"
#include "Board.h"
namespace model {
/**
 * @brief The Game class logic for Tetris game
 */
class Game : public TetrisInterface {

    /**
     * @brief observers : game is observed by view
     */
    std::set<util::Observer*> observers;

    /**
     * @brief score : current score
     */
    int score;

    /**
     * @brief curr_shape : the shape currently playing
     */
    shape::Shape curr_shape;

    /**
     * @brief next_s : the next shape to be played
     */
    shape::Shape next_s;

    /**
     * @brief bag : class bag contain 7 bricks
     */
    Bag bag;

    /**
     * @brief board : class board 2D arrow
     */
    Board board;

    /**
     * @brief level : class level current level (speed) of the game
     */
    Level level;

    /**
     * @brief counteCompletedLine : count all lines have been completed in game for incremente level
     */
    unsigned counteCompletedLine;

public:

    /**
     * @brief Constructs a new Game object with the specified parameters.
     * @param row Number of rows in the game board.
     * @param col Number of columns in the game board.
     * @param lvl Initial level of the game.
     */
    Game(int lvl, int row = 20, int col = 10);

    /**
     * ==========================================================
     *  ALL DOCUMENTATION IS WRITE IN INTERFACE : TetrisInterface
     * ==========================================================
     */

    const int& get_score() const override;

    const int& get_level() const override;

    const double get_tick() const override;

    const std::vector<std::vector<int>>& get_board() const override;

    const shape::Shape& get_curr_shape() const override;

    const shape::Shape& get_next_shape() const override;

    void set_score(int score) override;

    int calculate_score(int l, int d, int n) override;

    bool move_shape_down() override;

    void move_shape_l_r(Direction2D dir) override;

    void rotate_shape(Rotation dir) override;

    void drop_shape() override;

    void next_level() override;

    void next_shape() override;

    void Register(util::Observer* obs) override;

    void Unregister(util::Observer* obs) override;

    bool is_game_over() override;

    // std::string const get_shape_color(int shape_id) const override;

    void generateRandomBoard();

    void setShapeOnBoard(int drop_value = 0) override;

private:

    void notify() override;

    bool is_movable(Direction2D dir);

    bool rotation_is_possible();

};

}
#endif // GAME_H
