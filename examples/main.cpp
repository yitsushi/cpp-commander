#include <Commander/CommandRegistry.hpp>

#include "commands/MyCommand.hpp"

int main(int argc, const char *argv[])
{

  Commander::CommandRegistry* registry = new Commander::CommandRegistry(argc, argv);

  registry->Register(&(Commands::NewMyCommand));

  registry->Execute();

  return 0;
}
