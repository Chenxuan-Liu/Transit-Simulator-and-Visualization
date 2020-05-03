/**
 * @file IObservable.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_IOBSERVABLE_H_
#define SRC_IOBSERVABLE_H_

#include <string>
#include <list>
#include <vector>
#include <iterator>  // for iterators
#include <iostream>


#include "src/data_structs.h"
#include "src/IObserver.h"

// using namespace std;
template <typename T>


// class IObserver;

/**
 * @brief The Observable class
 *
 * This class derived Bus and Stop class. 
 */
class IObservable {
    std::vector<IObserver<T>*> observer_;
 public:
    void NotifyObservers(T info);
    void ClearObservers();
    void RegisterObserver(IObserver<T> *observer);
};



/**
* @brief NotifyObservers
* Notifies observers with current template type
* @param T Information
* @return void
*/
template <typename T>
void IObservable<T>::NotifyObservers(T info) {
    for (typename std::vector<IObserver<T>*> :: iterator iter
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
template <typename T>
void IObservable<T>::ClearObservers() {
  observer_.clear();
}


template <typename T>
/**
* @brief RegisterObserver
* Adds an observer to the observer_ vector
* @param Observer
* @return void
*/
void IObservable<T>::RegisterObserver(IObserver<T> *observer) {
  /* uses observer_ variable */
  observer_.push_back(observer);
}


#endif  // SRC_IOBSERVABLE_H_
