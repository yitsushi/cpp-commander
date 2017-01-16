#define BOOST_TEST_DYN_LINK

#ifdef STAND_ALONE
#define BOOST_TEST_MODULE ArgumentRegistry test
#endif

#include <boost/test/unit_test.hpp>
#include <string>
#include <list>
#include <sstream>
#include <Commander/Argument.hpp>
#include <Commander/ArgumentRegistry.hpp>
#include <Commander/Command.hpp>
#include <Commander/CommandDescriptor.hpp>
#include <Commander/CommandRegistry.hpp>

bool testcommand_called = false;

class MyTestCommand : public Commander::Command
{
  void Execute(Commander::ArgumentRegistry* args);
};

void MyTestCommand::Execute(Commander::ArgumentRegistry* args)
{
  BOOST_CHECK_MESSAGE(args->FindByKey("verbose"), "verbose flag does not exist");
  testcommand_called = true;
}

Commander::CommandDescriptor* NewMyTestCommand(const std::string appName)
{
  BOOST_CHECK_EQUAL(appName, "./myprogram");
  Commander::CommandDescriptor* desc;

  desc = new Commander::CommandDescriptor("MyTestCommand", new MyTestCommand());

  return desc;
}

BOOST_AUTO_TEST_CASE(MyTestCommandCall)
{
  const char* argv[] = { "./myprogram", "MyTestCommand", "--verbose", "--remote=localhost" };
  int argc = 4;

  testcommand_called = false;
  Commander::CommandRegistry* registry = new Commander::CommandRegistry(argc, argv);

  registry->Register(&(NewMyTestCommand));

  registry->Execute();
  BOOST_CHECK_MESSAGE(testcommand_called, "MyTestCommand::Execute was not called");
}

BOOST_AUTO_TEST_CASE(ExecuteWithoutCommand)
{
  const char* argv[] = { "./myprogram", "--verbose", "--remote=localhost" };
  int argc = 3;

  testcommand_called = false;
  Commander::CommandRegistry* registry = new Commander::CommandRegistry(argc, argv);

  registry->Register(&(NewMyTestCommand));

  registry->Execute();
  BOOST_CHECK_MESSAGE(!testcommand_called, "MyTestCommand::Execute was called, sadly");
}

BOOST_AUTO_TEST_CASE(ExecuteWithInvalidCommand)
{
  const char* argv[] = { "./myprogram", "NoCommand", "--verbose", "--remote=localhost" };
  int argc = 4;

  testcommand_called = false;
  Commander::CommandRegistry* registry = new Commander::CommandRegistry(argc, argv);

  registry->Register(&(NewMyTestCommand));

  registry->Execute();
  BOOST_CHECK_MESSAGE(!testcommand_called, "MyTestCommand::Execute was called, sadly");
}
