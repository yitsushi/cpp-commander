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
#include "ArgumentRegistry.hpp"
#include "Argument.hpp"
#include <iostream>
#include <cstring>

namespace Commander {
  ArgumentRegistry::ArgumentRegistry(int argc, const char *argv[])
  {
    for (int i = 1; i < argc; i++) {
      std::string key, value;

      if (std::strncmp(argv[i], "-", 1) == 0) {
        int shift = 1;

        if (std::strncmp(argv[i], "--", 2) == 0) shift = 2;
        key = std::string(argv[i] + shift);

        int separator_index = key.find("=");
        if (separator_index != std::string::npos) {
          value = key.substr(separator_index + 1);
          key = key.substr(0, separator_index);
        }
      } else {
        if (m_arguments.empty()) {
          if (m_command.empty()) {
            m_command = std::string(argv[i]);
            continue;
          }
          if (!m_command.empty() && m_subcommand.empty()) {
            m_subcommand = std::string(argv[i]);
            continue;
          }
        }
        value = std::string(argv[i]);
      }

      Argument* new_arg = new Argument(key, value);
      m_arguments.push_back(new_arg);
    }
  }

  Argument* ArgumentRegistry::FindByKey(std::string key)
  {
    for (Argument* arg : m_arguments) {
      if (arg->Key() == key) return arg;
    }
    return nullptr;
  }

  bool ArgumentRegistry::HasCommand() { return !m_command.empty(); }
  std::string ArgumentRegistry::Command() { return m_command; }

  bool ArgumentRegistry::HasSubCommand() { return !m_subcommand.empty(); }
  std::string ArgumentRegistry::SubCommand() { return m_subcommand; }
}
