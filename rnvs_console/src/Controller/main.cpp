#include <iostream>
#include "../Model/Game.h"
#include "../View/View.h"
#include "../Controller/Controller.h"
#include "../Controller/KeyBoardInput.h"
#include <string>

using namespace std;
using namespace controller;
using namespace model;
using namespace view;


int main() {
     // ---------------- TETRIS ------------------ //
    try {
    std::string choix = choiceDefaultBoard("Choisir le tableau par defaut ? [y/n] : ");
    if(choix == "y") {
        int level = inputNumber(1, 20, "Entrer le niveau du jeux");
        Game TetrisGame(level);
        if(choiceDefaultBoard("Tableau generee aleatoirement ? [y/n] :") == "y") {
            TetrisGame.generateRandomBoard();
        }
        View TetrisView(TetrisGame);

        Controller controller(TetrisGame, TetrisView);

        controller.start();
    } else {
        cout << "=== Choisissez la taille du tableau ===" << endl;
        int heigth = inputNumber(10, 50, "Entrer la longueur du tableau : ");
        int width = inputNumber(10, 100, "Entrer la largeur du tableau : ");
        int level = inputNumber(1, 20, "Entrer le niveau du jeux");
        Game TetrisGame(level, heigth, width);
        if(choiceDefaultBoard("Tableau generee aleatoirement ? [y/n] :") == "y"){
            TetrisGame.generateRandomBoard();
        }
        View TetrisView(TetrisGame);

        Controller controller(TetrisGame, TetrisView);

        controller.start();
    }

    } catch(const invalid_argument &e){
        cout << e.what() << endl;
    } catch(...){
        cout << "Erreur non invalid_argument" << endl;
    }
    return 0;

}
