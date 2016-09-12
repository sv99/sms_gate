//
// Created by Volkov on 09.09.16.
//

#include <iostream>

#include "HttpServer.hpp"

HttpServer::HttpServer (GateController *m_GateController) : m_GateController (m_GateController)
{}

void HttpServer::start ()
{
  std::cout << "HttpServer::start" << std::endl;
  //TODO - start real HTTP server
}

void HttpServer::stop ()
{
  std::cout << "HttpServer::stop" << std::endl;
  //TODO - stop HTTP server
}
