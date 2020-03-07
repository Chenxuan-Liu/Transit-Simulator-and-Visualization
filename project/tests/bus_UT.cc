/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

#include "../src/passenger_loader.h"
#include "../src/passenger_unloader.h"
#include "../src/bus.h"
#include "../src/route.h"
#include "../src/stop.h"
#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"

using namespace std;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class BusTests : public ::testing::Test {
protected:

    Route * route;
    Bus * bus;
    Stop * stop, **stops;
    RandomPassengerGenerator *generator;
    double  ps[1];
    Passenger * passenger;

    void SetUp( ) { 
        // code here will execute just before the test ensues 
	    passenger = new Passenger();
        stop = new Stop(1,10.0,20.0);
        stops = new Stop*[1];
        stops[0] =  stop;
        ps[0] = 20.0;
        std::list<double> prob;
        std::list<Stop*> stop2;
        generator = new RandomPassengerGenerator(prob, stop2);
    }

    virtual void TearDown(){
        delete route;
        delete stop;
        delete [] stops;
        delete passenger;
        delete bus;
        bus = NULL;
        stop = NULL;
        stops = NULL;
        passenger = NULL;
        route = NULL;
    }

};

TEST_F(BusTests, Constructor){
    SetUp();
    route = new Route("Como Ave", stops, ps, 1, generator);
    bus = new Bus("MN transit", route, route, 60, 1);
    EXPECT_EQ(bus -> IsTripComplete(), false);
    TearDown();
}

TEST_F(BusTests, LoadPassenger){
    SetUp();
    Passenger *passenger =  new Passenger();
    route = new Route("Como Ave", stops, ps, 1, generator);
    bus = new Bus("MN transit", route, route, 60, 1);
    EXPECT_EQ(bus -> LoadPassenger(passenger),true);
    TearDown();
}

TEST_F(BusTests, Move){
    SetUp();
    route = new Route("Como Ave", stops, ps, 1, generator);
    bus = new Bus("MN transit", route, route, 60, 1);
    EXPECT_EQ(bus -> Move(),true);
    EXPECT_EQ(bus -> Move(), false);
    TearDown();
}

TEST_F(BusTests, GetName){
    SetUp();
    route = new Route("Como Ave", stops, ps, 1, generator);
    bus = new Bus("MN transit", route, route, 60, 1);
    EXPECT_EQ(bus -> GetName(),"MN transit");
    TearDown();
}

TEST_F(BusTests, GetNextStop){
    SetUp();
    route = new Route("Como Ave", stops, ps, 1, generator);
    bus = new Bus("MN transit", route, route, 60, 1);
    Stop * _stop = bus -> GetNextStop();
    EXPECT_EQ(_stop -> GetId(), stop -> GetId());
    TearDown();
}

TEST_F(BusTests, GetCapacity){
    SetUp();
    route = new Route("Como Ave", stops, ps, 1, generator);
    bus = new Bus("MN transit", route, route, 60, 1);
    EXPECT_EQ(bus -> GetCapacity(), 60);
    TearDown();
}


