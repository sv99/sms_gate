//
// Created by Volkov on 09.09.16.
//

#ifndef SMS_GATE_INPUTWORKER_H
#define SMS_GATE_INPUTWORKER_H

#include "Message.hpp"
//#include "GateController.hpp"

class GateController;

class InputWorker {
 public:
  GateController* m_GateController;

  InputWorker (GateController *m_GateController);
  void start();
  void stop();
  int receive(Message &message);
};

#endif //SMS_GATE_INPUTWORKER_H
