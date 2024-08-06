#include "KeyBoardInput.h"
#include <iostream>
#include <limits> // pour std::numeric_limits

namespace controller {

using namespace std;

int inputNumber(int min, int max, string message) {
    string input = "";
    int inputNumber = 0;
    bool ok = false;
    while (!ok) {
        cout << message << " (entre " << min << " et " << max << ") : ";
        getline(cin, input);
        try {
            inputNumber = stoi(input); // std::stoi vérifie aussi si l'entrée est un nombre, sinon il renvoie une exception
        } catch (const invalid_argument& e) {
            cout << "Erreur: l'entree doit etre un nombre : " << e.what() << endl;
        }
        if (max >= inputNumber && min <= inputNumber) {
            ok = true;
        }
    }
    return inputNumber;
}

std::string choiceDefaultBoard(string msg) {
    string input = "";
    while(true){
        cout << "\n" << msg;
        getline(cin, input);
        if(input == "y" || input == "n") {
            break;
        }else {
            cout << "\nVeuillez entrer 'y' ou 'n'.";
        }
        cout << endl;
    }
    cout << " " << endl;

    return input;
}


}
