#ifndef _MyCommand_hpp_
#define _MyCommand_hpp_

#include <string>
#include <Commander/Command.hpp>
#include <Commander/CommandDescriptor.hpp>
#include <Commander/ArgumentRegistry.hpp>


namespace Commands {
  class MyCommand : public Commander::Command {
    void Execute(Commander::ArgumentRegistry* args);
  };

  Commander::CommandDescriptor* NewMyCommand(const std::string appName);
}

#endif
