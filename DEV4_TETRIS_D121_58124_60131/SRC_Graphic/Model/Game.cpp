#include "Game.h"
#include <random>

using namespace model;
using namespace shape;
using namespace std;
using namespace util;

namespace model {

Game::Game(int lvl, int row, int col) : score(0), bag(), board({row, col}), level(lvl), counteCompletedLine(0) {
    curr_shape = bag.get_shape();
    next_s = bag.get_shape();
    curr_shape.move(0, (col/2)-1);
    next_s.move(0, (col/2)-1);
}

const int& Game::get_score() const {
    return this->score;
}

const int& Game::get_level() const {
    return this->level.get_level();
}

const vector<vector<int>>& Game::get_board() const {
    return this->board.get_board();
}

const int Game::get_board_col() const{
    return board.get_board_col();
}

const int Game::get_board_row() const{
    return board.get_board_row();
}

const Shape& Game::get_curr_shape() const {
    return this->curr_shape;
}
const Shape& Game::get_next_shape() const {
    return next_s;
}

const double Game::get_tick() const {
    return this->level.get_time_in_seconde();
}


int Game::calculate_score(int linesCleared, int dropDistance, int level) {
    int baseScore;
    switch(linesCleared) {
    case 4: baseScore = 1200; break;
    case 3: baseScore = 300; break;
    case 2: baseScore = 100; break;
    default: baseScore = 40; break;
    }
    return (baseScore * linesCleared + dropDistance) * level;
}

void Game::move_shape_l_r(Direction2D dir) {
    if(is_movable(dir)) {
        curr_shape.move(dir);
    }
    move_shape_down();
    notify();
}

bool Game::move_shape_down() {
    if(is_movable(Direction::DOWN)) {
        curr_shape.move(Direction::DOWN);
        notify();
        return true;
    } else {
        setShapeOnBoard();
        return false;
    }
}

bool Game::rotation_is_possible() {
    vector<Position> positions = curr_shape.get_cell_status();
    for(Position & pos : positions) {
        Position pos_tmp = pos + curr_shape.get_offset();
        if(board.is_out_of_board(pos_tmp) || !board.is_cell_empty(pos_tmp)) {
            return false;
        }
    }
    return true;
}

bool Game::is_game_over() {
    for (const Position & pos : curr_shape.get_cell_status()) {
        Position pos_tmp = pos + curr_shape.get_offset();
        if(!board.is_cell_empty(pos_tmp)) return true;
    }
    for (int col = 0; col < board.get_board_col(); ++col) {
        Position pos(0, col);
        if(!board.is_cell_empty(pos)) return true;
    }
    return false;
}

void Game::generateRandomBoard(){
    random_device rd;
    mt19937 gen(rd());
    int colOffset = board.get_board_col() / 4;
    int colRange = board.get_board_col() / 2;
    uniform_int_distribution<int> distCol(colOffset, colOffset + colRange);
    int maximumShapes = (board.get_board_col() + board.get_board_row()) / 5;

    for (int i = 0; i <= maximumShapes; i++) {
        curr_shape = bag.get_shape();
        int colPos = distCol(gen);
        curr_shape.move(0, colPos);
        drop_shape();
    }
    set_score(-1);
}

void Game::rotate_shape(Rotation dir) {
    curr_shape.rotate(dir);
    if(!rotation_is_possible()) {
        switch(dir) {
            case Rotation::ROTATE_LEFT : curr_shape.rotate(Rotation::ROTATE_RIGHT);
            break;
            case Rotation::ROTATE_RIGHT : curr_shape.rotate(Rotation::ROTATE_LEFT);
            break;
        }
    }
    move_shape_down();
    notify();
}

void Game::drop_shape() {
    int drop = 0;
    while(is_movable(Direction::DOWN)) {
        curr_shape.move(Direction::DOWN);
        drop++;
    }
    setShapeOnBoard(drop);
}

bool Game::is_movable(Direction2D dir) {
    const vector<Position>& pos = curr_shape.get_cell_status();
    for (unsigned i = 0; i < pos.size(); ++i) {
        Position tmp_pos = curr_shape.get_offset() + pos.at(i);
        tmp_pos = tmp_pos + dir;
        if(board.is_out_of_board(tmp_pos) || !board.is_cell_empty(tmp_pos)) return false;
    }
    return true;
}




/**
 * =======================================
 *           PRIVATE METHODS
 * =======================================
 */

void Game::setShapeOnBoard(int drop_value){
    board.set_shape_on_board(curr_shape);
    int l = board.clear_all_row();
    int tmp_score = calculate_score(l, drop_value, level.get_level());
    counteCompletedLine += l;
    if(counteCompletedLine >= 10){
        level.next_level();
        counteCompletedLine = 0;  }
    set_score(tmp_score);
    next_shape();
    notify();
}

void Game::set_score(int score) {
    if(score < 0){
        this->score = 0;
    } else {
        this->score += score;
    }

}

void Game::next_level() {
    level.next_level();
}

void Game::next_shape() {
    curr_shape = next_s;
    next_s = bag.get_shape();
    next_s.move(0, (board.get_board_col()/2)-1);
}


/**
 * =====================================
 *      DESIGN PATTERN OBSERVER
 * =====================================
 */
void Game::Register(Observer* obs) {
    observers.insert(obs);
    notify();
}

void Game::Unregister(Observer* obs) {
    observers.erase(obs);
}

void Game::notify() {
    for(Observer* obs : observers) obs->update();
}


}

