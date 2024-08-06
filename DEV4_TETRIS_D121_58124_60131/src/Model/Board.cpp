#include "Board.h"

using namespace std;
using namespace model;
using namespace shape;

namespace model {
    Board::Board(){
        this->board_row = 20;
        this->board_col = 10;
        initialize();
    }

    Board::Board(int row, int col) {
        this->board_row = row;
        this->board_col = col;
        initialize();
    }


    bool Board::is_cell_empty(Position& pos){
        return board[pos.get_x()][pos.get_y()] == 0;
    }

    bool Board::is_out_of_board(Position& pos) {
        return pos.get_x() < 0 || pos.get_x() > board_row-1 || pos.get_y() < 0 || pos.get_y() > board_col-1;
    }

    void Board::set_shape_on_board(const Shape& curr_shape) {
        const std::vector<Position>& positions = curr_shape.get_cell_status();
        for (int i = 0; i < positions.size(); ++i) {
            int row = curr_shape.get_offset().get_x() + positions.at(i).get_x();
            int col = curr_shape.get_offset().get_y() + positions.at(i).get_y();
            board[row][col] = curr_shape.get_id();
        }
    }

    const int &Board::get_board_col() const
    {
        return this->board_col;
    }

    const int &Board::get_board_row() const
    {
        return this->board_row;
    }
    const vector<vector<int>>& Board::get_board() const {
        return this->board;
    }

    int Board::clear_all_row() {
        int completed = 0;
        int row = board_row - 1;
        while (row >= 1) {
            if (is_row_full(row)) {
                completed++;
                move_line(row);
            } else {
                row--;
            }
        }
        return completed;
    }

    /**
    * =======================================
    *           PRIVATE METHODS
    * =======================================
    */
    void Board::move_line(int line) {
        while(line > 1) {
            for (int col = 0; col < board_col; ++col) {
                board[line][col] = board[line - 1][col];
                board[line - 1][col] = 0;
            }
            line--;
        }
    }

    bool Board::is_row_full(int row) {
        for (int col = 0; col < board_col; ++col) {
            if(board[row][col] == 0) {
                return false;
            }
        }
        return true;
    }

    void Board::initialize() {
        for (int row = 0; row < board_row; ++row) {
            vector<int> tmp;
            for (int col = 0; col < board_col; ++col) {
                tmp.push_back(0);
            }
            board.push_back(tmp);
        }
    }
}

