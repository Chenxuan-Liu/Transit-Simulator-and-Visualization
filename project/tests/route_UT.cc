#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"
#include "../src/passenger.h"
#include "../src/stop.h"
#include "../src/route.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class RouteTests : public ::testing::Test {
protected:
  Route *route;
  Passenger *passenger;  
  Stop * stop, **stops;
  RandomPassengerGenerator *generator;
  double  ps[1];
  virtual void SetUp(){
    passenger = new Passenger();
    stop = new Stop(1,10.0,20.0);
    stops = new Stop*[1];
    stops[0] =  stop;
    ps[0] = 10.0;
    std::list<double> prob;
    std::list<Stop*> stop2;
    generator = new RandomPassengerGenerator(prob, stop2);
  }

  virtual void TearDown(){
    delete route;
    route = NULL;
  }
};

TEST_F(RouteTests, Constructor){
      SetUp();
      route = new Route("Como Ave", stops, ps, 1, generator);
      EXPECT_EQ(route -> GetName(), "Como Ave");
      //EXPECT_EQ(stop -> GetId(), route -> GetDestinationStop() -> GetId());
      TearDown();
};


TEST_F(RouteTests,IsAtEnd){
      SetUp();
      route =  new Route("Como Ave", stops, ps,1,generator);
      EXPECT_EQ(route -> IsAtEnd(),false);
      TearDown();
  };

  TEST_F(RouteTests, GetDestinationStop){
      SetUp();
      route = new Route("Como Ave", stops, ps, 1, generator);
      Stop *_stop = route -> GetDestinationStop();
      EXPECT_EQ(_stop -> GetId(), 1);
      TearDown();
  };

  TEST_F(RouteTests, GetTotalRouteDistance){
      SetUp();
      route = new Route("Como Ave", stops, ps, 1, generator);  
      EXPECT_EQ(route -> GetTotalRouteDistance(), 0);
      TearDown();
  };

  TEST_F(RouteTests, GetNextStopDistance){
      SetUp();
      route = new Route("Como Ave", stops, ps, 1, generator);
      EXPECT_EQ(route -> GetNextStopDistance(), 0);
      TearDown();
  };
  
  TEST_F(RouteTests, GetName){
      SetUp();
      route = new Route("Como Ave", stops, ps, 1, generator);
      EXPECT_EQ(route -> GetName(), "Como Ave");
      TearDown();
  };

  TEST_F(RouteTests, GetStops){
      SetUp();
      route = new Route("Como Ave", stops, ps, 1, generator);
      std::list<Stop *> _stops = route -> GetStops();
      EXPECT_EQ(_stops.front() -> GetId(), 1);
      TearDown();
  };
 
