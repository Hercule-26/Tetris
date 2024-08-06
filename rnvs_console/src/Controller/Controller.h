#ifndef CONTROLLER_H
#define CONTROLLER_H
// #include "../Model/TetrisInterface.h"    // rnvs : comm
// #include "../View/View.h"                // rnvs : comm

namespace model     // rnvs : ajout
{
class TetrisInterface;  // rnvs : ajout
}

namespace view  // rnvs : ajout
{
class View; // rnvs : ajout
}

namespace controller
{

/**
 * @brief The Controller class
 */
class Controller
{
    /**
     * @brief game
     */
    model::TetrisInterface & game;
    /**
     * @brief view
     */
    view::View & view;
  public :
    /**
     * @brief Controller
     * @param game
     * @param view
     */
    Controller(model::TetrisInterface & game, view::View & view);
    /**
     * @brief start the game and contain keyboard logic
     */
    void start();
};

}

#endif
