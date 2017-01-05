#include "../src/ArgumentRegistry.hpp"

int main(int argc, const char *argv[])
{

  Commander::ArgumentRegistry* arguments;
  arguments = new Commander::ArgumentRegistry(argc, argv);

  arguments->Dump();

  return 0;
}
