#include "CommandDescriptor.hpp"

#include <string>
#include "Command.hpp"

namespace Commander {
  CommandDescriptor::CommandDescriptor(std::string name, Command* handler)
    : m_name(name), m_handler(handler) {}

  std::string CommandDescriptor::Name()
  { return m_name; }

  Command* CommandDescriptor::Handler()
  { return m_handler; }
}
