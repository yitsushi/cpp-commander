#include <iostream>
#include <string>
#include <Commander/ArgumentRegistry.hpp>
#include <Commander/CommandDescriptor.hpp>
#include "DynamicCommand.hpp"

namespace Commands {
  void DynamicCommand::Execute(Commander::ArgumentRegistry* args)
  {
    if (args->FindByKey("verbose") != nullptr) {
      std::cout << "Verbose mode is active..." << std::endl;
    }
    std::cout << "Dynamic command executed." << std::endl;
  }

  Commander::CommandDescriptor* NewDynamicCommand(const std::string appName)
  {
    Commander::CommandDescriptor* desc;

    desc = new Commander::CommandDescriptor("DynamicCommand", new DynamicCommand());

    return desc;
  }
}

extern "C" {
  Commander::CommandDescriptor* call_NewDynamicCommand(const std::string appName)
  {
    return Commands::NewDynamicCommand(appName);
  }
}
