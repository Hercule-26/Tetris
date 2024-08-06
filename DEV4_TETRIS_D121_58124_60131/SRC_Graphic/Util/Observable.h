#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include "Observer.h"
namespace util {
/**
     * @brief The Observable class represents an object that can be observed by multiple observers.
     *
     * This class provides an interface for objects that wish to be observed by other objects.
     * It allows observers to register themselves to receive notifications when the state of the observable object changes.
     */
struct Observable {

    /**
    * @brief Register an observer to receive notifications from this observable object.
    *
    * @param obs A pointer to the observer object to register.
    */
    virtual void Register(Observer* obs) = 0;

    /**
    * @brief Unregister an observer from receiving notifications from this observable object.
    *
    * @param obs A pointer to the observer object to unregister.
    */
    virtual void Unregister(Observer* obs) = 0;

    /**
    * @brief Notify all registered observers that the state of the observable object has changed.
    *
    * This function is called to notify all registered observers that the state of the observable object has changed.
    * Observers are typically notified through their respective update() methods.
    */
    virtual void notify() = 0;
};
}

#endif
