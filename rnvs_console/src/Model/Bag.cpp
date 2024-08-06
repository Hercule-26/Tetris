#include "Bag.h"
#include "Shapes/Shapes.h"
#include <algorithm> //std::shuffle
#include <random>    //std::default_random_engine et std::random_device

#include "Shapes/Shape.h"   // rnvs : ajout

using namespace std;
using namespace model;
using namespace shape;

namespace model
{
Bag::Bag()
{
    cpt = 0;
    for (int i = 1; i <= 7; i++) shapes.push_back(createShape(i));
    reorder();
}
const Shape & Bag::get_shape()
{
    if (cpt == 7)
    {
        reorder();
        cpt = 0;
    }
    cpt++;
    return shapes.at(cpt - 1);

}

/**
* =======================================
*           PRIVATE METHODS
* =======================================
*/
void Bag::reorder()
{
    // rnvs : les variables suivantes pourraient être statiques
    random_device rd;
    default_random_engine rng(rd());

    shuffle(shapes.begin(), shapes.end(), rng);
};
}
