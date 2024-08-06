#ifndef VIEW_H
#define VIEW_H
#include "../Util/Observer.h"
#include "../Model/Shapes/Shape.h"
#include "../Model/TetrisInterface.h"

namespace view {
/**
* @brief The View class represents the graphical user interface for the Tetris game.
*
* This class provides functionality to display the Tetris game board, current and next shapes,
* score, and level to the user.
*/
class View : public util::Observer {

    /**
     * @brief game
     */
    const model::TetrisInterface& game;

    /**
     * @brief print_next_shape to be played
     * @param shape
     */
    void print_next_shape(const model::shape::Shape& shape);

    /**
     * @brief print_board and all shapes set
     * @param board
     * @param curr_shape
     */
    void print_board(const std::vector<std::vector<int>>& board, const model::shape::Shape& curr_shape);

    /**
     * @brief print_stat of the score, level
     * @param score
     * @param level
     */
    void print_stat(const int& score, const int& level);

public:

    /**
     * @brief View
     * @param game Reference to the TetrisInterface object representing the game.
     */
    View(const model::TetrisInterface& game);

    /**
    * @brief Update function called when the observable object notifies changes.
    */
    void update() override;

    /**
    * @brief Function called when the game is finished.
    */
    void gameIsFinish();
};

}
#endif
