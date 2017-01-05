#ifndef _Commander_Command_hpp_
#define _Commander_Command_hpp_

#include "ArgumentRegistry.hpp"

namespace Commander {
  class Command
  {
  public:
    virtual void Execute(ArgumentRegistry* args) = 0;
  };
}

#endif
