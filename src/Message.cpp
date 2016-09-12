//
// Created by Volkov on 09.09.16.
//

#include "Message.hpp"

std::string Message::to_string() {
  return "id: " + std::to_string (m_id) + ", from: " + m_from.to_string () + ", to: " + m_to.to_string ();
};
