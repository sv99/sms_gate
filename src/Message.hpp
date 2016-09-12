//
// Created by Volkov on 09.09.16.
//

#ifndef SMS_GATE_MESSAGE_H
#define SMS_GATE_MESSAGE_H

#include <string>

#include "PhoneBook.hpp"

class Message {
public:
  int m_id{0};
  Number m_from{};
  Number m_to{};
  std::string m_text{""};

  std::string to_string();
};

#endif //SMS_GATE_MESSAGE_H
