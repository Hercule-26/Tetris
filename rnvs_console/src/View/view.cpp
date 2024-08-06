#include "View.h"
#include <iostream>

#include "../Model/TetrisInterface.h"   // rnvs : ajout
#include "../Model/Shapes/Position.h"   // rnvs : ajout
#include "../Model/Shapes/Shape.h"      // rnvs : ajout

using namespace std;
using namespace model;


namespace view
{


View::View(const TetrisInterface & game) : game{game} {}

void View::update()
{
    print_stat(game.get_score(), game.get_level());
    print_next_shape(game.get_next_shape());
    print_board(game.get_board(), game.get_curr_shape());
}

void View::gameIsFinish()
{
    cout << "Le jeux est fini : vous avez perdu HAHAHA" << endl;
}


/**
 * =======================================
 *           PRIVATE METHODS
 * =======================================
 */

void View::print_stat(const int & score, const int & level)
{
    cout << "Level : " << level << " | Score : " << score << endl;
}

void View::print_next_shape(const shape::Shape & shape)
{
    cout << "Next shape : " << endl;
    for (int row = 0; row < 4; ++row)
    {
        cout << "   ";
        for (int col = 3; col < 7; ++col)
        {
            shape::Position pos(row, col);
            if (pos == shape)
            {
                cout << shape.get_id() << " ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void View::print_board(const vector<vector<int>> & board,
                       const shape::Shape & curr_shape)
{
    int col = board[0].size();
    int row = board.size();
    cout << " ";
    for (int nb = 0; nb <= col; ++nb)
    {
        cout << "--";
    }
    cout << endl;
    for (int rowIndex = 0; rowIndex < row; rowIndex++)
    {
        cout << "|  ";
        for (int j = 0; j < col; j++)
        {
            shape::Position pos(rowIndex, j);
            if (curr_shape == pos)
            {
                cout << curr_shape.get_id() << " ";
            }
            else
            {
                board[rowIndex][j] != 0 ? cout << board[rowIndex][j] << " " : cout <<
                                               ". ";
            }
            if (j > 0 && j % (col - 1) == 0) cout << " |" << endl;
        }
    }
    cout << " ";
    for (int nb = 0; nb <= col; ++nb)
    {
        cout << "--";
    }
    cout << endl;
}


}
