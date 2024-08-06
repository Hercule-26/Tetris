#include "Position.h"

namespace model::shape {

Position::Position(int x, int y) : pos(std::make_pair(x, y)) {}

const int &Position::get_x() const {return pos.first;}

const int &Position::get_y() const {return pos.second;}

model::shape::Position operator+(const Position& pos, const Direction2D& dir) {
    return {pos.get_x() + dir.first, pos.get_y() + dir.second};
}
model::shape::Position operator+(const Direction2D& dir, const Position& pos) {
    return pos + dir;
}
model::shape::Position operator+(const Position& pos1, const Position& pos2) {
    return {pos1.get_x() + pos2.get_x(), pos1.get_y() + pos2.get_y()};
}
bool operator==(const Position& pos1, const Position& pos2) {
    return (pos1.get_x() == pos2.get_x()) && (pos1.get_y() == pos2.get_y());
}
}
