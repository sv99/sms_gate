//
// Created by Volkov on 09.09.16.
//

#ifndef SMS_GATE_PHONEBOOK_H
#define SMS_GATE_PHONEBOOK_H

#include <string>
#include <vector>

class Number {
 public:
  int m_id{0};
  std::string m_number{""};

  std::string to_string();
};

class Record {
 public:
  int m_id{0};
  std::string m_FirstName{};
  std::string m_SecondName{};
  std::vector<Number> numbers{};

  std::string to_string();
};

class PhoneBook {
 public:
  std::vector<Record> records{};
};

#endif //SMS_GATE_PHONEBOOK_H
