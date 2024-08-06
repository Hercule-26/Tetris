#ifndef KEYBOARDINPUT_H
#define KEYBOARDINPUT_H
#include <string>
namespace controller {

/**
 * @brief Convert string input into integer
 * @param message , minimum value, maximum value
 * @return integer
 */
int inputNumber(int min, int max, std::string message);

/**
 * @brief choiceDefaultBoard yes or not
 * @param msg
 * @return a string of "y" for yes, "n" for no
 */
std::string choiceDefaultBoard(std::string msg);
}
#endif // KEYBOARDINPUT_H
