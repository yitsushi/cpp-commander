#ifndef _commander_ArgumentRegistry_hpp_
#define _commander_ArgumentRegistry_hpp_

#include <list>
#include "Argument.hpp"

namespace Commander {
  class ArgumentRegistry
  {
  public:
    ArgumentRegistry(int argc, const char *argv[]);

    void Dump();

    Argument* FindByKey(std::string);

    bool HasCommand();
    std::string Command();

    bool HasSubCommand();
    std::string SubCommand();

  private:
    std::list<Argument*> m_arguments;
    std::string m_command;
    std::string m_subcommand;
  };
}

#endif

