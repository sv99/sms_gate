//
// Created by Volkov on 09.09.16.
//

#include <iostream>

#include "OutputWorker.hpp"

OutputWorker::OutputWorker (GateController *m_GateController) : m_GateController (m_GateController)
{}

int OutputWorker::send (Message &message)
{
  std::cout << "OutputWorker::send " << message.to_string () << std::endl;
  //TODO - prepare message and write to the outgoing folder for smsd
  return 0;
}
