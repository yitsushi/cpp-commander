/*
 * Original code by Balazs Nadasdi (http://github.com/Yitsushi/)
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any
 * damages arising from the use of this software.
 * Permission is granted to anyone to use this software for any
 * purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must
 * not claim that you wrote the original software. If you use this
 * software in a product, an acknowledgment in the product documentation
 * would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and
 * must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 */

#include "Argument.hpp"
#include <string>
#include <iostream>
#include <algorithm>

namespace Commander {
  Argument::Argument(const std::string key, const std::string value) : m_key(key), m_value(value)
  {}

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

  int Argument::IntValue()
  {
    return std::atoi(m_value.c_str());
  }

  long Argument::LongValue()
  {
    return std::atol(m_value.c_str());
  }

  bool Argument::BoolValue()
  {
    std::string v = m_value;
    std::transform(v.begin(), v.end(), v.begin(), ::tolower);
    if (v == "true" || v == "yes" || v == "y" || v == "enabled") return true;

    if (std::atoi(v.c_str()) > 0) return true;

    return false;
  }

  std::list<std::string> Argument::ListValue(const char delimiter)
  {
    size_t last_pos = 0, pos = 0;
    std::list<std::string> value_list;

    while ((pos = m_value.find(delimiter, last_pos)) != std::string::npos) {
      value_list.push_back(m_value.substr(last_pos, pos-last_pos));
      last_pos = pos + 1;
    }
    value_list.push_back(m_value.substr(last_pos));

    return value_list;
  }

  std::list<int> Argument::IntListValue(const char delimiter)
  {
    std::list<int> value_list;
    std::list<std::string> svalue_list = ListValue(delimiter);

    for (std::string s : svalue_list) {
      value_list.push_back(std::atoi(s.c_str()));
    }

    return value_list;
  }

  std::list<long> Argument::LongListValue(const char delimiter)
  {
    std::list<long> value_list;
    std::list<std::string> svalue_list = ListValue(delimiter);

    for (std::string s : svalue_list) {
      value_list.push_back(std::atol(s.c_str()));
    }

    return value_list;
  }
}
