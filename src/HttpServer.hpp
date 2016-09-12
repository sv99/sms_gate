//
// Created by Volkov on 09.09.16.
//

#ifndef SMS_GATE_HTTPSERVER_H
#define SMS_GATE_HTTPSERVER_H

class GateController;

class HttpServer {
 public:
  GateController *m_GateController;
  HttpServer (GateController *m_GateController);

  void start ();
  void stop ();
};

#endif //SMS_GATE_HTTPSERVER_H
