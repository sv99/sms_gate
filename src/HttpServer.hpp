//
// Created by Volkov on 09.09.16.
//

#ifndef SMS_GATE_HTTPSERVER_H
#define SMS_GATE_HTTPSERVER_H

#include "mongoose.h"

class GateController;

class HttpServer {
 public:
  GateController *m_GateController;
  struct mg_mgr mgr;
  struct mg_connection *c;

  HttpServer (GateController *m_GateController);

  void start ();
  void stop ();
};

#endif //SMS_GATE_HTTPSERVER_H
