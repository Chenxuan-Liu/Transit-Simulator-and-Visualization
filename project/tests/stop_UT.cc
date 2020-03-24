/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <gtest/gtest.h>

#include <iostream>
#include <string>
#include <list>
#include <string>

//#include "../src/passenger_loader.h"
//#include "../src/passenger_unloader.h"
#include "../src/stop.h"
#include "../src/bus.h"
#include "../src/passenger.h"
#include "../src/route.h"
#include "../src/passenger_generator.h"
#include "../src/random_passenger_generator.h"
//#include "../src/stop.h"

using namespace std;

class Route;

/******************************************************
* TEST FEATURE SetUp
*******************************************************/
class StopTests : public ::testing::Test {
protected:
    Stop *stop = new Stop(1,44.972392, -93.243774), *stop1, *stop2;
    Stop ** stops1, **stops2;
    std::list<double> dist;
    double * distance;
};

TEST_F(StopTests,Constructor){
    EXPECT_EQ(stop -> GetId(),1);
    EXPECT_EQ(stop -> GetLongitude(),44.972392);
    EXPECT_EQ(stop -> GetLatitude(),-93.243774);
}



TEST_F(StopTests, GetId){
    EXPECT_EQ(stop -> GetId(), 1);
}


TEST_F(StopTests, GetLongtitude){
    EXPECT_EQ(stop -> GetLongitude(), 44.972392);
}

TEST_F(StopTests, GetLatitude){
    EXPECT_EQ(stop -> GetLatitude(), -93.243774);
}
