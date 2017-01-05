#include "Argument.hpp"
#include <string>
#include <iostream>

namespace Commander {
  Argument::Argument(const std::string key, const std::string value) : m_key(key), m_value(value)
  {}

  Argument::~Argument()
  {
    std::cout << "freeee meeee...." << std::endl;
  }

  bool Argument::OnlyValue()
  {
    return m_key.empty();
  }

  bool Argument::OnlyKey()
  {
    return m_value.empty();
  }

  std::string Argument::Key()
  {
    return m_key;
  }

  std::string Argument::Value()
  {
    return m_value;
  }

  void Argument::Print()
  {
    if (OnlyKey()) {
      std::cout << "  [K ] " << Key() << std::endl;
    } else if (OnlyValue()) {
      std::cout << "  [ V] " << Value() << std::endl;
    } else {
      std::cout << "  [KV] " << Key() << " -> " << Value() << std::endl;
    }
  }
}
