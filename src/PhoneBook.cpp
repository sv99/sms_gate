//
// Created by Volkov on 09.09.16.
//

#include "PhoneBook.hpp"

std::string Number::to_string ()
{
  return "id: " + std::to_string (m_id) + ", Number: " + m_number;
}

std::string Record::to_string ()
{
  return "id: " + std::to_string (m_id) + ", FirstName: " + m_FirstName + ", SecondName: " + m_SecondName;
}