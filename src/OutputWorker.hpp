//
// Created by Volkov on 09.09.16.
//

#ifndef SMS_GATE_OUTPUTWORKER_H
#define SMS_GATE_OUTPUTWORKER_H

#include "Message.hpp"

class GateController;

class OutputWorker {
 public:
  GateController* m_GateController;

  OutputWorker (GateController *m_GateController);
  int send(Message &mesasage);
};

#endif //SMS_GATE_OUTPUTWORKER_H
