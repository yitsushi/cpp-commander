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
