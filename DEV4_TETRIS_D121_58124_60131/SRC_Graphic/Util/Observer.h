#ifndef OBSERVER_H
#define OBSERVER_H

namespace util {
/**
* @brief The Observer class represents an object that observes changes in observable objects.
*
* This class provides an interface for objects that wish to observe changes in observable objects.
*/
struct Observer {

    /**
    * @brief Virtual destructor for Observer class.
    *
    * Ensures proper destruction of derived classes.
    */
    virtual ~Observer() = default;

    /**
    * @brief Update function called by observable objects to notify changes.
    *
    * This function is called by observable objects to notify the observer of changes.
    * Subclasses of Observer should implement this method to define specific actions to take when notified.
    */
    virtual void update() = 0;
};

}

#endif
