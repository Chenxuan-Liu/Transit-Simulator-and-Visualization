
#ifndef VISUALIZATION_SIMULATOR_H_
#define VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>

#include "web_interface.h"
#include "config_manager.h"

class Route;
class Bus;
class Stop;

class VisualizationSimulator {
    public:
        VisualizationSimulator(WebInterface*, ConfigManager*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        bool Update();
        bool CanUpdate();
        void TogglePause();
    private:
        void ExecuteUpdate();
        WebInterface* webInterface_;
        ConfigManager* configManager_;
       
        std::vector<int> busStartTimings_;
        std::vector<int> timeSinceLastBus_;
        int numTimeSteps_;
        int simulationTimeElapsed_;

        std::vector<Route *> prototypeRoutes_;
        std::vector<Bus *> busses_;

        int busId = 1000;
        bool paused_;
};

#endif // VISUALIZATION_SIMULATOR_H_
