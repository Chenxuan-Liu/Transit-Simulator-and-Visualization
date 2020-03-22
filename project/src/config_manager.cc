<<<<<<< HEAD
/**
 * @file config_manager.cc
 *
 * @copyright 2020 Chenxuan Liu, All rights reserved.
 */
#include "./config_manager.h"
=======

#include "config_manager.h"

#include "route.h"
#include "stop.h"
#include "random_passenger_generator.h"
>>>>>>> support-code

#include <sstream>
#include <fstream>
#include <list>
#include <algorithm>
<<<<<<< HEAD

#include "./route.h"
#include "./stop.h"
#include "./random_passenger_generator.h"


//  #include <functional>


ConfigManager::ConfigManager() : routes(std::vector<Route *>()) {
=======
//#include <functional>


ConfigManager::ConfigManager() : routes(std::vector<Route *>()) {

>>>>>>> support-code
}

ConfigManager::~ConfigManager() {
    for (int i = 0; i < static_cast<int>(routes.size()); i++) {
        routes[i] = nullptr;
    }
    routes.clear();
}

void ConfigManager::ReadConfig(const std::string filename) {
<<<<<<< HEAD
    std::ifstream configFile("config/" + filename);

    //  std::hash<std::string> stringHash;
=======

    std::ifstream configFile("config/" + filename);

    //std::hash<std::string> stringHash;
>>>>>>> support-code

    std::list<Stop *> stops = std::list<Stop *>();
    std::list<double> distances = std::list<double>();
    double oldLat = 0;
    double oldLon = 0;
    std::list<double> currProbabilities = std::list<double>();
    std::string currGeneralName = "";
    std::string currRouteName = "";

    std::vector<std::string> stopNames = std::vector<std::string>();
    int stopId = 10;

    std::string line;
    while (std::getline(configFile, line)) {
<<<<<<< HEAD
=======
        
>>>>>>> support-code
        std::istringstream stringStream(line);
        std::string chunk;

        if (!std::getline(stringStream, chunk, ',')) { continue; }
<<<<<<< HEAD

        if (chunk == "ROUTE_GENERAL") {
            currGeneralName = "";
            std::getline(stringStream, currGeneralName);
        } else if (chunk == "ROUTE") {
            // If we are coming to a route besides our first one, save all our
            // data and init variables for next route
            if (stops.size() > 0) {
=======
        
        if (chunk == "ROUTE_GENERAL") {
            
            currGeneralName = "";
            std::getline(stringStream, currGeneralName);
        
        } else if (chunk == "ROUTE") {

            // If we are coming to a route besides our first one, save all our
            // data and init variables for next route
            if (stops.size() > 0) {

>>>>>>> support-code
                // Convert our variables into the necessary raw memory
                int numStops = static_cast<int>(stops.size());
                Stop ** rawStops = new Stop *[numStops];
                int it = 0;
                for (auto* s : stops) {
                    rawStops[it] = s;
                    it++;
                }
<<<<<<< HEAD

                int numDists = static_cast<int>(distances.size());
                double * rawDists = new double[numDists];
=======
                
                int numDists = static_cast<int>(distances.size());
                double * rawDists = new double [numDists];
>>>>>>> support-code
                it = 0;
                for (const auto& d : distances) {
                    rawDists[it] = d;
                    it++;
                }
<<<<<<< HEAD

=======
                
>>>>>>> support-code
                routes.push_back(
                        new Route(
                            currGeneralName + " " + currRouteName,
                            rawStops,
                            rawDists,
                            static_cast<int>(stops.size()),
<<<<<<< HEAD
                            new RandomPassengerGenerator(
                            currProbabilities, stops)));
=======
                            new RandomPassengerGenerator(currProbabilities, stops)
                        )
                    );
>>>>>>> support-code

                stops.clear();
                distances.clear();
                currProbabilities.clear();
<<<<<<< HEAD
            }
            oldLat = 0;   //  Refresh our old values on a new route
            oldLon = 0;

            std::getline(stringStream, currRouteName);
            currRouteName.erase(std::remove(currRouteName.begin(),
            currRouteName.end(), ' '), currRouteName.end());

        } else if (chunk == "STOP") {
            // Grab our comma seperated values
            std::string stopName;
            std::getline(stringStream, stopName, ',');
            stopName.erase(std::remove(stopName.begin(),
            stopName.end(), ' '), stopName.end());

            // Check if the stop already exists
            std::vector<std::string>::iterator it
            = std::find(stopNames.begin(), stopNames.end(),
            stopName);
            if (it != stopNames.end()) {
                // We have already seen this stop
                int index = std::distance(stopNames.begin(), it);

                std::list<Stop *>::iterator iter = stops.begin();
                std::advance(iter, index);

=======

            }
            oldLat = 0; // Refresh our old values on a new route
            oldLon = 0;

            std::getline(stringStream, currRouteName);
            currRouteName.erase(std::remove(currRouteName.begin(), currRouteName.end(), ' '), currRouteName.end());

        } else if (chunk == "STOP") {

            // Grab our comma seperated values
            std::string stopName;
            std::getline(stringStream, stopName, ',');
            stopName.erase(std::remove(stopName.begin(), stopName.end(), ' '), stopName.end());
            
            // Check if the stop already exists
            std::vector<std::string>::iterator it = std::find(stopNames.begin(), stopNames.end(), stopName);
            if (it != stopNames.end()) {
                
                // We have already seen this stop
                int index = std::distance(stopNames.begin(), it);
                
                std::list<Stop *>::iterator iter = stops.begin();
                std::advance(iter, index);
                
>>>>>>> support-code
                stops.push_back(*iter);
                continue;
            }

            // If we have not seen this stop, set it up
            int id = stopId;
            stopId++;

            std::string latString;
            std::getline(stringStream, latString, ',');
            double latitude = std::stod(latString);

            std::string lonString;
            std::getline(stringStream, lonString, ',');
            double longitude = std::stod(lonString);

            stops.push_back(new Stop(id, latitude, longitude));

            // Need to turn these lat and long into real-world distances
<<<<<<< HEAD
            // This means moving 1 speed in a time click moves 1 mile.
            // That's a bit far, so I multiply *
            // 2 so that a speed of 1 moves 1/2 mile
            latitude *= 69 * 2;
            longitude *= 55 * 2;

            // Grabbing last element from list is hard, so cache position
            // instead
            if (stops.size() > 1) {
                double dist = sqrt((latitude-oldLat)*
                (latitude-oldLat) + (longitude-oldLon)*(longitude-oldLon));
                distances.push_back(dist);
            }
            oldLat = latitude;
            oldLon = longitude;

=======
            // This means moving 1 speed in a time click moves 1 mile. That's a bit far, so I multiply * 2 so that a speed of 1 moves 1/2 mile
            latitude *= 69 * 2;
            longitude *= 55 * 2;
            
            // Grabbing last element from list is hard, so cache position
            // instead
            if (stops.size() > 1) {
                double dist = sqrt((latitude-oldLat)*(latitude-oldLat) + (longitude-oldLon)*(longitude-oldLon));
                distances.push_back(dist);
            }    
            oldLat = latitude;
            oldLon = longitude;
            
>>>>>>> support-code
            std::string probString;
            std::getline(stringStream, probString);
            double probability = std::stod(probString);

            currProbabilities.push_back(probability);
        }
    }
<<<<<<< HEAD

    // Generatre our last route
    if (stops.size() > 0) {
=======
    
    // Generatre our last route
    if (stops.size() > 0) {
        
>>>>>>> support-code
        // Convert our variables into the necessary raw memory
        int numStops = static_cast<int>(stops.size());
        Stop ** rawStops = new Stop *[numStops];
        int it = 0;
        for (auto* s : stops) {
            rawStops[it] = s;
            it++;
        }
<<<<<<< HEAD

        int numDists = static_cast<int>(distances.size());
        double * rawDists = new double[numDists];
=======
            
        int numDists = static_cast<int>(distances.size());
        double * rawDists = new double [numDists];
>>>>>>> support-code
        it = 0;
        for (const auto& d : distances) {
            rawDists[it] = d;
            it++;
        }
<<<<<<< HEAD

=======
            
>>>>>>> support-code
        routes.push_back(
                new Route(
                    currGeneralName + " " + currRouteName,
                    rawStops,
                    rawDists,
                    static_cast<int>(stops.size()),
<<<<<<< HEAD
                    new RandomPassengerGenerator(currProbabilities, stops)));
=======
                    new RandomPassengerGenerator(currProbabilities, stops)
                )
            );
>>>>>>> support-code
    }

    currProbabilities.clear();
    stops.clear();
    distances.clear();
<<<<<<< HEAD
=======

>>>>>>> support-code
}
