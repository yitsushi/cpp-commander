#include <iostream>
#include "CommandRegistry.hpp"

#include "ArgumentRegistry.hpp"
#include "CommandDescriptor.hpp"

namespace Commander {
  CommandRegistry::CommandRegistry(int argc, const char *argv[]) {
    m_appName = argv[0];
    m_arguments = new ArgumentRegistry(argc, argv);
  }

  void CommandRegistry::Register(NewCommandFunc callable)
  {
    CommandDescriptor* desc = callable(m_appName);
    m_commands[desc->Name()] = desc;
  }

  void CommandRegistry::Execute()
  {
    if (!m_arguments->HasCommand()) {
      std::cout << "No command specified" << std::endl;
      return;
    }

    if (m_commands.find(m_arguments->Command()) == m_commands.end()) {
      std::cout << "Command not found" << std::endl;
      return;
    }

    std::cout << "# Execute command:" << std::endl;
    m_commands[m_arguments->Command()]->Handler()->Execute(m_arguments);
  }

  void CommandRegistry::Dump()
  {
    std::cout << "# Available commands:" << std::endl;

    for (auto& c : m_commands) {
      std::cout << "  - " << c.first << std::endl;
    }

    std::cout << "# Call details: (K = Key, V = Value)" << std::endl;

    m_arguments->Dump();
  }
}
