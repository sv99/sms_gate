//
// Created by Volkov on 09.09.16.
//

#include <iostream>

#include "InputWorker.hpp"
#include "GateController.hpp"

InputWorker::InputWorker (GateController *m_GateController) : m_GateController (m_GateController)
{}

void InputWorker::start ()
{
  std::cout << "InputWorker::start" << std::endl;
  //TODO - shedule periodical check input SMS
}

void InputWorker::stop ()
{
  std::cout << "InputWorker::stop" << std::endl;
  //TODO - stop sheduler
}

int InputWorker::receive (Message &message)
{
  std::cout << "InputWorker::receive " << message.to_string () << std::endl;
  return m_GateController->receiveSMS (message);
}
