/**
 * @file local_simulator.cc
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#include "src/r_local_simulator.h"

#include <vector>
#include <list>

#include "src/bus.h"
#include "src/stop.h"
#include "src/route.h"
#include "src/rtest_passenger_generator.h"

bool rLocalSimulator::Start() {
  simulation_time_elapsed_ = 0;  // init, but also allows restart

  // int num_round_trips = 10;
  int num_round_trips = 1;
  for (int i = 0; i < num_round_trips; i++) {
    time_since_last_bus_generation_.push_back(0);
  }

  Stop ** CC_EB_stops = new Stop *[8];
  Stop ** CC_WB_stops = new Stop *[9];
  Stop ** CC_SO_stops = new Stop *[8];
  Stop ** CC_SI_stops = new Stop *[8];
  std::list<Stop *> CC_EB_stops_list;  
  std::list<Stop *> CC_WB_stops_list;
  std::list<Stop *> CC_SO_stops_list; 
  std::list<Stop *> CC_SI_stops_list; 
  
  //Staticly defined objects get destroyed at end of Start()!
  //Must be dynamic...
  
  // CC Eastbound stops
  Stop * stop_CC_EB_1 = new Stop(0, 44.972392, -93.243774);  // West bank station
  Stop * stop_CC_EB_2 = new Stop(1, 44.973580, -93.235071);  // student union station
  Stop * stop_CC_EB_3 = new Stop(2, 44.975392, -93.226632);  // Oak St & Washington Ave
  Stop * stop_CC_EB_4 = new Stop(3, 44.975837, -93.222174);  // before transit
  Stop * stop_CC_EB_5 = new Stop(4, 44.980753, -93.180669);  // tway
  Stop * stop_CC_EB_6 = new Stop(5, 44.983375, -93.178810);  // Fairgrounds
  Stop * stop_CC_EB_7 = new Stop(6, 44.984540, -93.181692);  // Buford & Gartner
  Stop * stop_CC_EB_8 = new Stop(7, 44.984630, -93.186352);  // SPSC
  
  // CC Westbound stops
  Stop * stop_CC_WB_1 = new Stop(8, 44.984630, -93.186352);  // SPSC
  Stop * stop_CC_WB_2 = new Stop(9, 44.984482, -93.181657);  // Buford & Gartner
  Stop * stop_CC_WB_3 = new Stop(10, 44.983703, -93.178846);  // Fairgrounds
  Stop * stop_CC_WB_4 = new Stop(11, 44.980663, -93.180808);  // Tway
  Stop * stop_CC_WB_5 = new Stop(12, 44.976397, -93.221801);  // before transit
  Stop * stop_CC_WB_6 = new Stop(13, 44.978058, -93.229176); // Ridder
  Stop * stop_CC_WB_7 = new Stop(14, 44.978366, -93.236038);  // Jones-Eddy
  Stop * stop_CC_WB_8 = new Stop(15, 44.974549, -93.236927);  // Bruininks
  Stop * stop_CC_WB_9 = new Stop(16, 44.972638, -93.243591);  // Blegen

  // CC SightSeeing out stops
  Stop * stop_CC_SO_1 = new Stop(17, 44.975566, -93.237288);
  Stop * stop_CC_SO_2 = new Stop(18, 44.978449, -93.235285);
  Stop * stop_CC_SO_3 = new Stop(19, 44.979309, -93.234753);
  Stop * stop_CC_SO_4 = new Stop(20, 44.983655, -93.231351);
  Stop * stop_CC_SO_5 = new Stop(21, 44.987630, -93.230301);
  Stop * stop_CC_SO_6 = new Stop(22, 44.987765, -93.227190);
  Stop * stop_CC_SO_7 = new Stop(23, 44.987839, -93.221717);

  // CC SightSeeing out stops
  Stop * stop_CC_SI_1 = new Stop(24, 44.987942, -93.221911);
  Stop * stop_CC_SI_2 = new Stop(25, 44.987884, -93.226841);
  Stop * stop_CC_SI_3 = new Stop(26, 44.987549, -93.230477);
  Stop * stop_CC_SI_4 = new Stop(27, 44.983970, -93.231322);
  Stop * stop_CC_SI_5 = new Stop(28, 44.979378, -93.234907);
  Stop * stop_CC_SI_6 = new Stop(29, 44.978211, -93.236059);
  Stop * stop_CC_SI_7 = new Stop(30, 44.975566, -93.237288);

  CC_EB_stops_list.push_back(stop_CC_EB_1);
  CC_EB_stops[0] = stop_CC_EB_1;
  CC_EB_stops_list.push_back(stop_CC_EB_2);
  CC_EB_stops[1] = stop_CC_EB_2;
  CC_EB_stops_list.push_back(stop_CC_EB_3);
  CC_EB_stops[2] = stop_CC_EB_3;
  CC_EB_stops_list.push_back(stop_CC_EB_4);
  CC_EB_stops[3] = stop_CC_EB_4;
  CC_EB_stops_list.push_back(stop_CC_EB_5);
  CC_EB_stops[4] = stop_CC_EB_5;
  CC_EB_stops_list.push_back(stop_CC_EB_6);
  CC_EB_stops[5] = stop_CC_EB_6;
  CC_EB_stops_list.push_back(stop_CC_EB_7);
  CC_EB_stops[6] = stop_CC_EB_7;
  CC_EB_stops_list.push_back(stop_CC_EB_8);
  CC_EB_stops[7] = stop_CC_EB_8;
  
  CC_WB_stops_list.push_back(stop_CC_WB_1);
  CC_WB_stops[0] = stop_CC_WB_1;
  CC_WB_stops_list.push_back(stop_CC_WB_2);
  CC_WB_stops[1] = stop_CC_WB_2;
  CC_WB_stops_list.push_back(stop_CC_WB_3);
  CC_WB_stops[2] = stop_CC_WB_3;
  CC_WB_stops_list.push_back(stop_CC_WB_4);
  CC_WB_stops[3] = stop_CC_WB_4;
  CC_WB_stops_list.push_back(stop_CC_WB_5);
  CC_WB_stops[4] = stop_CC_WB_5;
  CC_WB_stops_list.push_back(stop_CC_WB_6);
  CC_WB_stops[5] = stop_CC_WB_6;
  CC_WB_stops_list.push_back(stop_CC_WB_7);
  CC_WB_stops[6] = stop_CC_WB_7;
  CC_WB_stops_list.push_back(stop_CC_WB_8);
  CC_WB_stops[7] = stop_CC_WB_8;
  CC_WB_stops_list.push_back(stop_CC_WB_9);
  CC_WB_stops[8] = stop_CC_WB_9;

  CC_SI_stops_list.push_back(stop_CC_SI_1);
  CC_SI_stops[0] = stop_CC_SI_1;
  CC_SI_stops_list.push_back(stop_CC_SI_2);
  CC_SI_stops[1] = stop_CC_SI_2;
  CC_SI_stops_list.push_back(stop_CC_SI_3);
  CC_SI_stops[2] = stop_CC_SI_3;
  CC_SI_stops_list.push_back(stop_CC_SI_4);
  CC_SI_stops[3] = stop_CC_SI_4;
  CC_SI_stops_list.push_back(stop_CC_SI_5);
  CC_SI_stops[4] = stop_CC_SI_5;
  CC_SI_stops_list.push_back(stop_CC_SI_6);
  CC_SI_stops[5] = stop_CC_SI_6;
  CC_SI_stops_list.push_back(stop_CC_SI_7);
  CC_SI_stops[6] = stop_CC_SI_7;

  CC_SO_stops_list.push_back(stop_CC_SO_1);
  CC_SO_stops[0] = stop_CC_SO_1;
  CC_SO_stops_list.push_back(stop_CC_SO_2);
  CC_SO_stops[1] = stop_CC_SO_2;
  CC_SO_stops_list.push_back(stop_CC_SO_3);
  CC_SO_stops[2] = stop_CC_SO_3;
  CC_SO_stops_list.push_back(stop_CC_SO_4);
  CC_SO_stops[3] = stop_CC_SO_4;
  CC_SO_stops_list.push_back(stop_CC_SO_5);
  CC_SO_stops[4] = stop_CC_SO_5;
  CC_SO_stops_list.push_back(stop_CC_SO_6);
  CC_SO_stops[5] = stop_CC_SO_6;
  CC_SO_stops_list.push_back(stop_CC_SO_7);
  CC_SO_stops[6] = stop_CC_SO_7;
 
  double * CC_EB_distances = new double[7];
  double * CC_WB_distances = new double[8];
  double * CC_SO_distances = new double[7];
  double * CC_SI_distances = new double[7];

  CC_EB_distances[0] = 4;
  CC_EB_distances[1] = 4;
  CC_EB_distances[2] = 2;
  CC_EB_distances[3] = 19;
  CC_EB_distances[4] = 1;
  CC_EB_distances[5] = 1;
  CC_EB_distances[6] = 2;
  
  CC_WB_distances[0] = 2;
  CC_WB_distances[1] = 1;
  CC_WB_distances[2] = 2;
  CC_WB_distances[3] = 19;
  CC_WB_distances[4] = 3;
  CC_WB_distances[5] = 3;
  CC_WB_distances[6] = 2;
  CC_WB_distances[7] = 3;
  
  
  std::list<double> CC_EB_probs;  //realistic .15, .3, .025, .05, .05, 0
  CC_EB_probs.push_back(.15); //WB
  CC_EB_probs.push_back(.3); //CMU
  CC_EB_probs.push_back(.025); //O&W
  CC_EB_probs.push_back(.05); //Pre-transit
  CC_EB_probs.push_back(.05); //post-transit
  CC_EB_probs.push_back(.01); //State fair
  CC_EB_probs.push_back(.01); //Buford
  CC_EB_probs.push_back(0); //SPSC - MUST BE 0
  //TODO: is this always true? If so, we may want to reduce the length of probs to_char_type
  //        remove possibility of generating passengers with nowhere to go
  
  std::list<double> CC_WB_probs; //realistic .35, .05, .01, .01, .2, 0
  CC_WB_probs.push_back(.35); //SPSC
  CC_WB_probs.push_back(.05); //Buford
  CC_WB_probs.push_back(.01); //State fair  
  CC_WB_probs.push_back(.01); //post-transit
  CC_WB_probs.push_back(.025); //pre-transit
  CC_WB_probs.push_back(.05); //Ridder
  CC_WB_probs.push_back(.1); //Jones-Eddy
  CC_WB_probs.push_back(.3); //Bruininks
  CC_WB_probs.push_back(0); //Blegen


  std::list<double> CC_SO_probs;
   CC_SO_probs.push_back(.40);
   CC_SO_probs.push_back(.30);
   CC_SO_probs.push_back(.20);
   CC_SO_probs.push_back(.10);
   CC_SO_probs.push_back(.30);
   CC_SO_probs.push_back(.05);
   CC_SO_probs.push_back(.20);

  std::list<double> CC_SI_probs;
  CC_SI_probs.push_back(.20);
  CC_SI_probs.push_back(.05);
  CC_SI_probs.push_back(.30);
  CC_SI_probs.push_back(.15);
  CC_SI_probs.push_back(.20);
  CC_SI_probs.push_back(.30);
  CC_SI_probs.push_back(.40);
  
  //Staticly defined objects get destroyed at end of Start()!
  //Must be dynamic...
  //RandomPassengerGenerator CC_EB_generator(CC_EB_probs, CC_EB_stops_list);
  //RandomPassengerGenerator CC_WB_generator(CC_WB_probs, CC_WB_stops_list);
  
 RtestPassengerGenerator * CC_EB_generator = new RtestPassengerGenerator (CC_EB_probs, CC_EB_stops_list);
 RtestPassengerGenerator * CC_WB_generator = new RtestPassengerGenerator (CC_WB_probs, CC_WB_stops_list);
 RtestPassengerGenerator * CC_SI_generator = new RtestPassengerGenerator (CC_SI_probs, CC_SI_stops_list);
 RtestPassengerGenerator * CC_SO_generator = new RtestPassengerGenerator (CC_SO_probs, CC_SO_stops_list);
  
  //Test to ensure generators are working
  //Helpful for debugging
  //CC_EB_generator.GeneratePassengers();
  //CC_WB_generator.GeneratePassengers();
  
  //Again, MUST be dynamic...
  //Route CC_EB("Campus Connector - Eastbound", CC_EB_stops, CC_EB_distances, 8, &CC_EB_generator);
  //Route CC_WB("Campus Connector - Westbound", CC_WB_stops, CC_WB_distances, 9, &CC_WB_generator);
  
  Route * CC_EB = new Route("Campus Connector - Eastbound", CC_EB_stops, CC_EB_distances, 8, CC_EB_generator);
  Route * CC_WB = new Route("Campus Connector - Westbound", CC_WB_stops, CC_WB_distances, 9, CC_WB_generator);
  
  prototype_routes_.push_back(CC_EB);
  prototype_routes_.push_back(CC_WB);

  prototype_routes_[0]->Report(std::cout);
  prototype_routes_[1]->Report(std::cout);

  bus_counters_.push_back(10000);

  //This will eventually be replaced by configuration/command line argument
  bus_start_timings_.push_back(10); 
  
  // Do we want a bus on start? Or let the update handle this?
  // active_buses_.push_back(new Bus(std::to_string(bus_counters_[0]),
  //   prototype_routes[0].Clone(), prototype_routes[1].Clone(), 60, 1));
  // bus_counters_[0]++;

  return true;
}

bool rLocalSimulator::Update() {
  // increase time
  simulation_time_elapsed_++;
  std::cout << "~~~~~~~~~~~~~ The time is now " << simulation_time_elapsed_;
  std::cout << " ~~~~~~~~~~~~~" << std::endl;
  
  // various route-indexed list iterators
  std::vector<int>::iterator bus_gen_timing_iter = bus_start_timings_.begin();
  std::vector<int>::iterator bus_counter_iter = bus_counters_.begin();
  std::vector<Route *>::iterator prototype_route_iter =
                                                     prototype_routes_.begin();

  // increase each time since last bus
  // various iterators parallel the time_since_last iterator
  for (std::vector<int>::iterator it = time_since_last_bus_generation_.begin();
      it != time_since_last_bus_generation_.end();
      it++, bus_gen_timing_iter++, bus_counter_iter++) {
    (*it)++;
    
    // if time since last [index] == bus gen timing[index]
    if (0 >= (*bus_gen_timing_iter)) {
      // create a new bus! routes are:
      // prototype_routes_[index * 2] & prototype_routes_[index * 2 + 1]
      Route * outbound = (*prototype_route_iter);
      prototype_route_iter++;
      Route * inbound = (*prototype_route_iter);
      prototype_route_iter++;
      
      active_buses_.push_back(new Bus(std::to_string((*bus_counter_iter)),
                                  outbound->Clone(), inbound->Clone(), 60, 1));
      (*bus_counter_iter)++;
      (*bus_gen_timing_iter) = 10;
    } else {
      prototype_route_iter++;
      prototype_route_iter++;
      (*bus_gen_timing_iter)--;
    }
  }

  // for each bus
  for (std::list<Bus *>::iterator bus_iter = active_buses_.begin();
      bus_iter != active_buses_.end(); bus_iter++) {
    // update bus
    (*bus_iter)->Update();
    // bus report
    (*bus_iter)->Report(std::cout);
    
    //REQUIRES USE OF IsTripComplete, which was not required
    //Buses which are "done" will just keep having Update() called
    //  Students MAY need to deal with this, not sure yet...
    // remove bus if trip is complete
    //if ((*bus_iter)->IsTripComplete()) {
    //  bus_iter = active_buses_.erase(bus_iter);
    //  bus_iter--;
    //}
  }
  
  // for each stop
  for (std::vector<Route *>::iterator route_iter = prototype_routes_.begin();
      route_iter != prototype_routes_.end(); route_iter++) {
    // update stop
    (*route_iter)->Update();
    (*route_iter)->Report(std::cout);
  }
  
  return true;
}