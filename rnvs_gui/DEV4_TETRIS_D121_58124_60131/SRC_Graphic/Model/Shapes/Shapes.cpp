#include "Shape.h"
#include <stdexcept>

namespace model::shape {


struct ShapeO : public Shape {
    ShapeO() {
        std::map<int, std::vector<shape::Position>> cells;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 0)};
        cells[1] = cells[0];
        cells[2] = cells[0];
        cells[3] = cells[0];
        set_id(1);
        set_cell_status(cells);
    }
};

struct ShapeT : public Shape {
    ShapeT() {
        std::map<int, std::vector<shape::Position>> cells;
        cells[0] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(1, 2)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(1, 0)};
        set_id(2);
        set_cell_status(cells);
    }
};

struct ShapeI : public Shape {
    ShapeI() {
        std::map<int, std::vector<shape::Position>> cells;
        cells[0] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        cells[1] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        cells[2] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        cells[3] = {Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3)};
        set_id(3);
        set_cell_status(cells);
    }
};

struct ShapeJ : public Shape {
    ShapeJ() {
        std::map<int, std::vector<shape::Position>> cells;
        cells[0] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(2, 1)};
        cells[1] = {Position(2, 3), Position(2, 2), Position(2, 1), Position(1, 1)};
        cells[2] = {Position(3, 1), Position(2, 1), Position(1, 1), Position(1, 2)};
        cells[3] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        set_id(4);
        set_cell_status(cells);
    }
};

struct ShapeL : public Shape {
    ShapeL() {
        std::map<int, std::vector<shape::Position>> cells;
        cells[0] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2)};
        cells[1] = {Position(1, 3), Position(1, 2), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(3, 2), Position(2, 2), Position(1, 2), Position(1, 1)};
        cells[3] = {Position(1, 2), Position(2, 2), Position(2, 1), Position(2, 0)};
        set_id(5);
        set_cell_status(cells);
    }
};

struct ShapeZ : public Shape {
    ShapeZ() {
        std::map<int, std::vector<shape::Position>> cells;
        cells[0] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 2), Position(1, 2), Position(1, 1), Position(2, 1)};
        cells[2] = cells[0];
        cells[3] = cells[1];
        set_id(6);
        set_cell_status(cells);
    }
};
struct ShapeS : public Shape {
    ShapeS() {
        std::map<int, std::vector<shape::Position>> cells;
        cells[0] = {Position(1, 0), Position(1, 1), Position(0, 1), Position(0, 2)};
        cells[1] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        cells[2] = cells[0];
        cells[3] = cells[1];
        set_id(7);
        set_cell_status(cells);
    }
};

const Shape createShape(int id) {
    if(id < 1 || id > 7){
        throw std::invalid_argument("Les identifiants des shapes sont compris entre 1 et 7");
    }
    switch(id) {
        case 1 :
            return shape::ShapeO();
            break;
        case 2 :
            return shape::ShapeT();
                break;
        case 3 :
            return shape::ShapeI();
                break;
        case 4 :
            return shape::ShapeJ();
            break;
        case 5 :
            return shape::ShapeL();
                break;
        case 6 :
            return shape::ShapeZ();
            break;
        default :
            return shape::ShapeS();
            break;
    }
}
}
