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

// class IObserver;

/**
 * @brief The Observable class
 *
 * This class derived Buss class.
 */
class IObservable {
    std::vector<IObserver*> observer_;
 public:
    void NotifyObservers(BusData *info);
    void ClearObservers();
    void RegisterObserver(IObserver *observer);
};


#endif  // SRC_IOBSERVABLE_H_
