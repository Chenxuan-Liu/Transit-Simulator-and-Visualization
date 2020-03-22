/**
 * @file passenger.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
<<<<<<< HEAD
#ifndef PASSENGER_H_
#define PASSENGER_H_
=======
#ifndef SRC_PASSENGER_H_
#define SRC_PASSENGER_H_
>>>>>>> support-code

#include <iostream>
#include <string>

class Passenger {  // : public Reporter {
 public:
  explicit Passenger(int = -1, std::string = "Nobody");
  void Update();
  void GetOnBus();
  int GetTotalWait() const;
  bool IsOnBus() const;
  int GetDestination() const;
  void Report(std::ostream&) const;
 private:
  std::string name_;
  int destination_stop_id_;
  int wait_at_stop_;
  int time_on_bus_;
  int id_;
  static int count_;  // global count, used to set ID for new instances
};
<<<<<<< HEAD
#endif  // PASSENGER_H_
=======
#endif  // SRC_PASSENGER_H_
>>>>>>> support-code
