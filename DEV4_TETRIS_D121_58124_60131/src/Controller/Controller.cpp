#include "../Controller/Controller.h"
#include <iostream>
#include <stdexcept>
namespace controller {

using namespace std;
using namespace model;
using namespace view;


Controller::Controller(TetrisInterface& game, View& view) : game(game), view(view) {
    game.Register(&view);
}

void Controller::start() {
/* Pour la partie graphique !
    auto start_time = std::chrono::steady_clock::now(); // Stock le temps initial
    while (true) {
        auto current_time = std::chrono::steady_clock::now(); // Enregistrer le temps actuel
        auto time_past = std::chrono::duration_cast<std::chrono::seconds>(current_time - start_time).count();
        // Vérifier si deux secondes se sont écoulées depuis le dernier enregistrement du temps
        if (time_past >= this->game.get_tick()) {

            std::cout << "Temps actuel : " <<  this->game.get_tick() << std::endl;
            std::cout << "Niveau actuel : " <<  this->game.get_level() << std::endl;
            this->game.move_shape_down();
            start_time = current_time;
        }
    }
*/
    std::string input = "";
    while(!game.is_game_over()) {
        cout << "Entrez une commande \n(s: down, q: left, d: right | f: drop | e: rotate rigth | a: rotate left)" << endl;
        getline(cin, input);
        try {
            if(input == "s") game.move_shape_down();
            else if(input == "q") game.move_shape_l_r(Direction::LEFT);
            else if(input == "d") game.move_shape_l_r(Direction::RIGHT);
            else if(input == "a") game.rotate_shape(Rotation::ROTATE_LEFT);
            else if(input == "e") game.rotate_shape(Rotation::ROTATE_RIGHT);
            else if(input == "f") game.drop_shape();
            else cout << "Aucune commande correspond !!" << endl;
        } catch(const std::invalid_argument& e) {
            cout << "Commande invalide : " << e.what() << std::endl;
        }
    }
    view.gameIsFinish();

}
}
