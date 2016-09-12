//
// Created by Volkov on 09.09.16.
//

#ifndef SMS_GATE_GATECONTROLLER_H
#define SMS_GATE_GATECONTROLLER_H

#import "HttpServer.hpp"
#import "InputWorker.hpp"
#import "OutputWorker.hpp"

class GateController {
 public:
  HttpServer m_HttpServer;
  InputWorker m_InputWorker;
  OutputWorker m_OutputWorker;

  GateController ();
  void start ();
  void stop ();
  int sendSMS (Message &message);
  int receiveSMS (Message &message);
};

#endif //SMS_GATE_GATECONTROLLER_H
