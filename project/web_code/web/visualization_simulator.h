/**
 * @file visualization_simulator.h
 *
 * @copyright 2019 3081 Staff, All rights reserved.
 */
#ifndef WEB_CODE_WEB_VISUALIZATION_SIMULATOR_H_
#define WEB_CODE_WEB_VISUALIZATION_SIMULATOR_H_

#include <vector>
#include <list>
#include <string>
#include <sstream>

#include "web_code/web/web_interface.h"
#include "src/config_manager.h"
#include "src/bus_factory.h"
#include "src/IObservable.h"
#include "src/file_writer_manager.h"
#include "src/decorator.h"

class Route;
class Bus;
class Stop;
class BusDepot;


class VisualizationSimulator {
 public:
        VisualizationSimulator(WebInterface*, ConfigManager*, std::ostream*);
        ~VisualizationSimulator();

        void Start(const std::vector<int>&, const int&);
        bool Update();
        bool CanUpdate();
        void TogglePause();
        void ClearListeners();
        void ClearListenersStop();
        void AddListeners(std::string*, IObserver<BusData*>*);
        void AddListenerStop(std::string*, IObserver<Stop*>*);

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
        std::ostream* out_;
        std::string bus_stats_file_name = "BusData.csv";
};

#endif  // WEB_CODE_WEB_VISUALIZATION_SIMULATOR_H_
