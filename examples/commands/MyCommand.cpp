#include <iostream>
#include <string>
#include <list>
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

    if (args->FindByKey("ids") != nullptr) {
      std::list<int> ids = args->FindByKey("ids")->IntListValue(',');
      std::cout << "Provided ID list:" << std::endl;
      for (int id : ids) {
        std::cout << " - " << id << std::endl;
      }
    }
  }

  Commander::CommandDescriptor* NewMyCommand(const std::string appName)
  {
    Commander::CommandDescriptor* desc;

    desc = new Commander::CommandDescriptor("MyCommand", new MyCommand());

    return desc;
  }
}
