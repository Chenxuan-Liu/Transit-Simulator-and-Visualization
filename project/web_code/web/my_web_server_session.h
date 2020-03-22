
#ifndef MY_WEB_SERVER_SESSION_H
#define MY_WEB_SERVER_SESSION_H

<<<<<<< HEAD
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wshadow"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wfloat-equal"
#pragma GCC diagnostic ignored "-Wsuggest-override"
#pragma GCC diagnostic ignored "-Woverloaded-virtual"

#include "WebServer.h"
#include "my_web_server_session_state.h"

#pragma GCC diagnostic pop
=======
#include "WebServer.h"
#include "my_web_server_session_state.h"

>>>>>>> support-code

class MyWebServerSession : public JSONSession {
    public:
        MyWebServerSession(MyWebServerSessionState s) : state(s) {}
        ~MyWebServerSession() {}

        void receiveJSON(picojson::value& val) override;
        void update() override {}

    private:
        MyWebServerSessionState state;
};


#endif // MY_WEB_SERVER_SESSION_H
