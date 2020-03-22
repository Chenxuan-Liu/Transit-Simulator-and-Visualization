<<<<<<< HEAD
/**
 * @file config_manager.h
 *
 * @copyright 2020 Chenxaun Liu, All rights reserved.
 */
=======

>>>>>>> support-code
#ifndef CONFIG_MANAGER_H_
#define CONFIG_MANAGER_H_

#include <vector>
#include <string>


class Route;

<<<<<<< HEAD
class ConfigManager {
 public:
=======
class ConfigManager { 

    public:
>>>>>>> support-code
        ConfigManager();
        ~ConfigManager();

        void ReadConfig(const std::string filename);

<<<<<<< HEAD
        std::vector<Route *> GetRoutes() const { return routes; }

 private:
        std::vector<Route *> routes;
};

#endif  // CONFIG_MANAGER_H_
=======
        std::vector<Route *> GetRoutes() const { return routes; };

    private:
        std::vector<Route *> routes;

};

#endif // CONFIG_MANAGER_H_
>>>>>>> support-code
