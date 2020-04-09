#include <iostream>

#include "config_manager.h"
#include "visualization_simulator.h"

#include "my_web_server_session_state.h"
#include "my_web_server_command.h"
#include "my_web_server_session.h"
#include "my_web_server.h"
#include <iostream>
#include <fstream>
using std::fstream;
#include <cstring>
using std::strerror;
#include <cerrno>

//#define _USE_MATH_DEFINES
//#include <cmath>
//#include <libwebsockets.h> 


int main(int argc, char**argv) {
	std::cout << "Usage: ./build/bin/ExampleServer 8081 <fname>" << std::endl;

	if (argc > 1) {
		int port = std::atoi(argv[1]);
		std::streambuf* buffer;
		std::ofstream of;
		if (argc > 2) {
			std::string filename = argv[2];
			of.open(filename.c_str(), fstream::out);
			buffer = of.rdbuf();
			std::cout << "got here" << std::endl;
			
		} else {
			std::cout << "got here instead" << std::endl;
			buffer = std::cout.rdbuf();
		}
		std::ostream out(buffer);
		out << "Writing" << std::endl;

		MyWebServerSessionState state;

        MyWebServer* myWS = new MyWebServer();
        ConfigManager* cm = new ConfigManager();
        
        cm->ReadConfig("config.txt");
        std::cout << "Using default config file: config.txt" << std::endl;

        VisualizationSimulator* mySim = new VisualizationSimulator(myWS, cm, &out);

		state.commands["getRoutes"] = new GetRoutesCommand(myWS);
		state.commands["getBusses"] = new GetBussesCommand(myWS);
        state.commands["start"] = new StartCommand(mySim);
        state.commands["update"] = new UpdateCommand(mySim);
        state.commands["initRoutes"] = new InitRoutesCommand(cm);
		state.commands["pause"] = new PauseCommand(mySim);

		WebServerWithState<MyWebServerSession, MyWebServerSessionState> server(state, port);
		while (true) {
			server.service();
		}
	}

	return 0;
}


