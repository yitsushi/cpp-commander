#include "ArgumentRegistry.hpp"
#include "Argument.hpp"
#include <iostream>

namespace Commander {
  ArgumentRegistry::ArgumentRegistry(int argc, const char *argv[])
  {
    for (int i = 1; i < argc; i++) {
      std::string key, value;

      if (strncmp(argv[i], "-", 1) == 0) {
        int shift = 1;

        if (strncmp(argv[i], "--", 2) == 0) shift = 2;
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

  void ArgumentRegistry::Dump()
  {
    if (HasCommand()) {
      std::cout << "Command: " << Command() << std::endl;
    }
    if (HasSubCommand()) {
      std::cout << "Subcommand: " << SubCommand() << std::endl;
    }

    for (Argument* arg : m_arguments) {
      arg->Print();
    }
  }
}
