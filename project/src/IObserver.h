/**
 * @file IObserver.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */

#ifndef SRC_IOBSERVER_H_
#define SRC_IOBSERVER_H_

#include <string>
#include <list>
#include <vector>
#include <iterator>  // for iterators
#include <iostream>
#include "src/data_structs.h"


class IObserver {
 public:
    virtual void UpdateObserver(BusData * info) = 0;
};

#endif  // SRC_IOBSERVER_H_
