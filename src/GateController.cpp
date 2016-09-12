//
// Created by Volkov on 09.09.16.
//

#include <iostream>

#include "GateController.hpp"

GateController::GateController ()
    : m_HttpServer (this), m_InputWorker (this), m_OutputWorker (this)
{}

void GateController::start ()
{
  m_InputWorker.start();
  m_HttpServer.start();
}

void GateController::stop ()
{
  m_HttpServer.stop();
  m_InputWorker.stop();
}

int GateController::sendSMS (Message &message)
{
  std::cout << "GateController::sendSMS: " << message.to_string () << std::endl;
  m_OutputWorker.send (message);
  //TODO - prepare message and write to the outgoing folder for smsd
  return 0;
}

int GateController::receiveSMS (Message &message)
{
  std::cout << "GateController::receiveSMS" << message.to_string () << std::endl;
  //TODO - prepare message and write to the outgoing folder for smsd
  return 0;
}