#ifndef LEVEL_H
#define LEVEL_H
#include <chrono>
#include <map>
namespace model {
/**
 * @brief The Level class represent difficulty of the game, the higher the level, the faster the speed of play
 */
class Level {

    /**
     * @brief level_number : the current level
     */
    int level_number;

    /**
     * @brief  _timetoLevel : each level number is assigned to a duration
     */
    std::map<int,std::chrono::duration<double>> _timetoLevel;

public :

    /**
     * @brief set the level for players starting with a certain level
     * @param level
     */
    Level(int level = 1);

    /**
     * @brief get_level current
     * @return
     */
    const int& get_level() const;

    /**
     * @brief next_level
     */
    void next_level();

    /**
     * @brief get current time in duration
     * @return
     */
    const std::chrono::duration<double> &get_time() const;

    /**
     * @brief get_time_in_seconde
     * @return duration convert into double (1,0.83,0.76,...)
     */
    const double get_time_in_seconde() const;

private :

    /**
     * @brief each level number is assigned to a duration
     * The duration start with 1 secondes. (60/60)
     */
    void initialize();
};



}
#endif // LEVEL_H
