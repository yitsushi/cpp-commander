#include <iostream>
#include <string>
#include "MyCommand.hpp"
#include "../../src/ArgumentRegistry.hpp"
#include "../../src/CommandDescriptor.hpp"

namespace Commands {
  void MyCommand::Execute(Commander::ArgumentRegistry* args)
  {
    std::cout << "My Command is executed..." << std::endl;

    if (args->FindByKey("verbose") != nullptr) {
      std::cout << "Verbose mode is active..." << std::endl;
    }
  }

  Commander::CommandDescriptor* NewMyCommand(const std::string appName)
  {
    Commander::CommandDescriptor* desc;

    desc = new Commander::CommandDescriptor("MyCommand", new MyCommand());

    return desc;
  }
}
