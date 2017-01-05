#ifndef _commander_CommandRegistry_hpp_
#define _commander_CommandRegistry_hpp_

#include <map>
#include <string>
#include "ArgumentRegistry.hpp"
#include "CommandDescriptor.hpp"

namespace Commander {
  class CommandRegistry
  {
  public:
    CommandRegistry(int argc, const char *argv[]);
    void Register(NewCommandFunc callable);
    void Execute();
    void Dump();

  private:
    ArgumentRegistry* m_arguments;
    std::map<std::string, CommandDescriptor*> m_commands;

    std::string m_appName;
  };
}

#endif
