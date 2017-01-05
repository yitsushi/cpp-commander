#ifndef _MyCommand_hpp_
#define _MyCommand_hpp_

#include <string>
#include "../../src/Command.hpp"
#include "../../src/CommandDescriptor.hpp"
#include "../../src/ArgumentRegistry.hpp"


namespace Commands {
  class MyCommand : public Commander::Command {
    void Execute(Commander::ArgumentRegistry* args);
  };

  Commander::CommandDescriptor* NewMyCommand(const std::string appName);
}

#endif
