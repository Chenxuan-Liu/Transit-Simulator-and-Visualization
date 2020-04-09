/**
 * @file visualization_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef VISUALIZATION_SIMULATOR_H_
#define VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>

#include "web_code/web/web_interface.h"
#include "src/config_manager.h"
#include "src/bus_factory.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
<<<<<<< HEAD
 public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        void Pause();
        void Update();

 private:
=======
    public:
        VisualizationSimulator(WebInterface*, ConfigManager*, std::ostream*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        bool Update();
        bool CanUpdate();
        void TogglePause();
    private:
        void ExecuteUpdate();
>>>>>>> support-code
        WebInterface* webInterface_;
        ConfigManager* configManager_;

        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;

        std::vector<Route *> prototypeRoutes_;
        std::vector<Bus *> busses_;

        int busId = 1000;
<<<<<<< HEAD
        bool pausestate = false;
=======
        bool paused_;
        std::ostream* out_;
>>>>>>> support-code
};

#endif  // VISUALIZATION_SIMULATOR_H_
