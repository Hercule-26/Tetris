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

const Shape& Game::get_curr_shape() const {
    return this->curr_shape;
}
const Shape& Game::get_next_shape() const {
    return next_s;
}

const double Game::get_tick() const {
    return this->level.get_time_in_seconde();
}

int Game::calculate_score(int l, int d, int n) {
    switch(l) {
        case 4 : return (1200 * l + d) * n;
        case 3 : return (300 * l + d) * n;
        case 2 : return (100 * l + d) * n;
        default : return (40 * l + d) * n;
    }
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
    uniform_int_distribution<int> distCol(-3, board.get_board_col()-6);
    int maximumShapes = (board.get_board_col()+board.get_board_row())/4;
    for(int i = 0; i < maximumShapes; i++){
    curr_shape.move(0,distCol(rd));
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

/**
 *
 * Name            FG  BG
 * Red             31  41
 * Green           32  42
 * Yellow          33  43
 * Blue            34  44
 * Magenta         35  45
 * Cyan            36  46
 * White           37  47
 *
string const Game::get_shape_color(int id) const {
        switch(id) {
        case 1 : return "\033[31mO\033[0m";
            break;
        case 2 : return "\033[32mO\033[0m";
            break;
        case 3 : return "\033[33mO\033[0m";
            break;
        case 4 : return "\033[34mO\033[0m";
            break;
        case 5 : return "\033[35mO\033[0m";
            break;
        case 6 : return "\033[36mO\033[0m";
            break;
        default: return "\033[37mO\033[0m";
        }
    }
**/
}

