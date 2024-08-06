#include "Shape.h"
#include "../Direction.h"
#include <stdexcept>
namespace model::shape {
Shape::Shape() : rotation_state{0} { offset = Position(0, 0); }


const int &Shape::get_id() const {return id;}

void Shape::rotate(model::Rotation rotation) {
    switch(rotation) {
        case model::ROTATE_LEFT : rotation_state == 0 ? rotation_state = 3 : rotation_state--;
            break;
        case model::ROTATE_RIGHT : rotation_state == 3 ? rotation_state = 0 : rotation_state++;
            break;
    }
}

void Shape::move(Direction2D d) {
    offset = offset + d;
}

void Shape::move(int row, int column) {
    offset = offset + Position(row, column);
}

const Position& Shape::get_offset() const {
    return offset;
}

const std::vector<Position>& Shape::get_cell_status() const {return cell_status.at(rotation_state);}

void Shape::set_cell_status(std::map<int, std::vector<shape::Position>> cell_status) {
    this->cell_status = cell_status;
}
void Shape::set_id(int id) {
    if(id < 0 || 7 < id){
        throw std::invalid_argument("ID of piece is inside intervall [0;7]");
    }
    this->id = id;
}

bool operator==(const Shape& s, const Position& pos) {
    const std::vector<Position>& cell_status = s.get_cell_status();
    for(const Position& block_pos : cell_status) {
        if((s.get_offset() + block_pos) == pos) {
            return true;
        }
    }
    return false;
}
bool operator==(const Position& pos, const Shape& s) {
    return s == pos;
}

}
