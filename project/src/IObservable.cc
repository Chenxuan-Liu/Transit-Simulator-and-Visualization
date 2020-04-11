/**
 * @file IObservable.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#include <string>
#include <list>
#include <vector>
#include <iterator>  // for iterators
#include <iostream>

#include "src/IObservable.h"
// #include "src/bus.h"

// class IObserver;
// using namespace std;

/**
* @brief NotifyObservers
* Notifies observers with current bus data
* @param BusData Information
* @return void
*/

void IObservable::NotifyObservers(BusData *info) {
    for (std::vector<IObserver*> :: iterator iter
    = observer_.begin(); iter != observer_.end(); ++iter) {
      if (*iter != 0) {
        (*iter) -> UpdateObserver(info);
      }
    }
}


/**
* @brief ClearObservers
* Removes all observers from observer_ vector
* @param none
* @return void
*/
void IObservable::ClearObservers() {
  observer_.clear();
}



/**
* @brief RegisterObserver
* Adds an observer to the observer_ vector
* @param Observer
* @return void
*/
void IObservable::RegisterObserver(IObserver *observer) {
  /* uses observer_ variable */
  observer_.push_back(observer);
}
