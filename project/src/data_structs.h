<<<<<<< HEAD
/**
 * @file data_struct.h
 *
 * @copyright 2020 Chenxuan Liu, All rights reserved.
 */
=======

>>>>>>> support-code
#ifndef DATA_STRUCTS_H_
#define DATA_STRUCTS_H_

#include <string>
#include <vector>


struct Position {
    Position() : x(0), y(0) {}
    float x;
    float y;
};

struct BusData {
    BusData() : id(""), position(Position()), num_passengers(0), capacity(0) {}
    std::string id;
    Position position;
    int num_passengers;
    int capacity;
};

struct StopData {
    StopData() : id(""), position(Position()), num_people(0) {}
    std::string id;
    Position position;
    int num_people;
};

struct RouteData {
    RouteData() : id(""), stops(std::vector<StopData>(0)) {}
    std::string id;
    std::vector<StopData> stops;
};
<<<<<<< HEAD
#endif  // DATA_STRUCTS_H_
=======

#endif // DATA_STRUCTS_H_
>>>>>>> support-code
