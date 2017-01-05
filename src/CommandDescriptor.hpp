#ifndef _Commander_CommandDescriptor_hpp_
#define _Commander_CommandDescriptor_hpp_

#include <string>
#include "Command.hpp"

namespace Commander {
  class CommandDescriptor
  {
  public:
    CommandDescriptor(std::string name, Command* handler);

    std::string Name();
    Command* Handler();

  private:
    std::string m_name;
    Command* m_handler;
  };
}

typedef Commander::CommandDescriptor* (*NewCommandFunc)(const std::string);
#endif
