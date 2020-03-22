/**
 * @file route.h
 *
 * @Copyright 2019 3081 Staff, All rights reserved.
 */

<<<<<<< HEAD
#ifndef ROUTE_H_
#define ROUTE_H_
=======
#ifndef SRC_ROUTE_H_
#define SRC_ROUTE_H_
>>>>>>> support-code

#include <list>
#include <iostream>
#include <string>

#include "./data_structs.h"

#include "./passenger_generator.h"
#include "./stop.h"

class PassengerGenerator;

class Route {
 public:
  Route(std::string name, Stop ** stops, double * distances, int num_stops,
        PassengerGenerator *);
  Route * Clone();
  void Update();
  void Report(std::ostream&);
  bool IsAtEnd() const;
<<<<<<< HEAD

  Stop *  PrevStop();  //  Returns stop before destination stop
  void NextStop();  //  Change destination_stop_ to next stop
=======
  
  Stop *  PrevStop(); // Returns stop before destination stop
  void NextStop();  // Change destination_stop_ to next stop
>>>>>>> support-code
  Stop * GetDestinationStop() const;    // Get pointer to next stop
  double GetTotalRouteDistance() const;
  double GetNextStopDistance() const;

  // Vis Getters
  std::string GetName() const { return name_; }
  std::list<Stop *> GetStops() const { return stops_; }
  void UpdateRouteData();
  RouteData GetRouteData() const;
<<<<<<< HEAD

 private:
  int GenerateNewPassengers();       //  generates passengers on its route
=======
 private:
  int GenerateNewPassengers();       // generates passengers on its route
>>>>>>> support-code
  PassengerGenerator * generator_;
  std::list<Stop *> stops_;
  std::list<double> distances_between_;  // length = num_stops_ - 1
  std::string name_;
  int num_stops_;
  int destination_stop_index_;  // always starts at zero, no init needed
  Stop * destination_stop_;
  // double trip_time_; // derived data - total distance travelled on route
<<<<<<< HEAD
  RouteData route_data_;
};
#endif  // ROUTE_H_
=======

  RouteData route_data_;

};
#endif  // SRC_ROUTE_H_
>>>>>>> support-code

