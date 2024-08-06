#ifndef BOARD_H
#define BOARD_H
// #include "./Shapes/Position.h"   // rnvs : comm
// #include "./Shapes/Shape.h"      // rnvs : comm
#include <vector>

namespace model
{

// rnvs : ajout
namespace shape // rnvs : ajout
{
class Position; // rnvs : ajout
class Shape; // rnvs : ajout
} // rnvs : ajout

/**
 * @brief The Board class represents a game board.
 *
 */
class Board
{

    /**
     * @brief board : board 2D arrow of table
     */
    std::vector<std::vector<int>> board;

    /**
     * @brief board_row : row of arroow
     */
    int board_row;

    /**
     * @brief board_col : cof of arrow
     */
    int board_col;

  public:

    /**
    * @brief Constructs a new Board object with default size (20x10).
    */
    Board();

    /**
    * @brief Constructs a new Board object with custom size.
    *
    * @param row The number of rows in the board.
    * @param col The number of columns in the board.
    * @throw std::invalid_argument If row < 10 or col < 5.
    */
    Board(int row, int col);

    /**
    * @brief Clears all full rows from the board and moves the lines above down.
    *
    * @return The number of rows cleared.
    */
    int clear_all_row();

    /**
    * @brief Checks if the given cell on the board is empty.
    *
    * @param pos The position of the cell to check.
    * @return True if the cell is empty, false otherwise.
    */
    bool is_cell_empty(shape::Position & pos);
    /**
    * @brief Checks if the given position is out of the board's bounds.
    *
    * @param pos The position to check.
    * @return True if the position is out of bounds, false otherwise.
    */
    bool is_out_of_board(shape::Position & pos);
    /**
    * @brief Sets the given shape on the board.
    *
    * @param curr_shape The shape to set on the board.
    */
    void set_shape_on_board(const model::shape::Shape & curr_shape);
    /**
    * @brief Gets the number of rows in the board.
    *
    * @return The number of rows.
    */
    const int & get_board_row() const;
    /**
    * @brief Gets the number of columns in the board.
    *
    * @return The number of columns.
    */
    const int & get_board_col() const;
    /**
    * @brief Gets the current state of the board.
    *
    * @return A reference to the 2D vector representing the board.
    */
    const std::vector<std::vector<int>> & get_board() const;

  private:

    /**
    * @brief Moves the given line down by one row.
    *
    * @param line The line to move down.
    */
    void move_line(int row);
    /**
    * @brief Checks if the given row is full.
    *
    * @param row The row to check.
    * @return True if the row is full, false otherwise.
    */

    bool is_row_full(int row);
    /**
    * @brief Initializes the board with empty cells.
    */
    void initialize();

};

}
#endif // BOARD_H
