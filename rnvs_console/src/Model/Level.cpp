#include "Level.h"

using namespace std;


namespace model {

Level::Level(int level) : level_number(level) {
    initialize();
}

void Level::next_level() {
    if(level_number < 20) level_number++;
}

const int& Level::get_level() const {
    return level_number;
}

const chrono::duration<double> &Level::get_time() const{
    return _timetoLevel.at(level_number);
}

const double Level::get_time_in_seconde() const {
    return get_time().count();
}


/**
 * =======================================
 *           PRIVATE METHODS
 * =======================================
 */

void Level::initialize() {
    double number = 60;
    _timetoLevel[1] = chrono::duration<double>(number/60);
    number = number-7;
    _timetoLevel[2] = chrono::duration<double>(number/60);
    for(int i = 3; i <= 20; i++) {
        if(i < 7){
            number = number-4;
            _timetoLevel[i] = chrono::duration<double>(number/60);
        } else if(i < 12){
           number = number-5;
            _timetoLevel[i] = chrono::duration<double>(number/60);
        } else {
            number--;
            _timetoLevel[i] = chrono::duration<double>(number/60);
        }
    }
}
}
