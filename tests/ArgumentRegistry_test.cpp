#define BOOST_TEST_MODULE ArgumentRegistry test
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <Commander/Argument.hpp>
#include <Commander/ArgumentRegistry.hpp>

BOOST_AUTO_TEST_CASE(UnknownArgument)
{
  const char* argv[] = { "./myprogram", "--verbose", "--remote=localhost" };
  int argc = 3;

  Commander::ArgumentRegistry* registry = new Commander::ArgumentRegistry(argc, argv);
  Commander::Argument* arg;

  BOOST_CHECK(!registry->HasCommand());
  BOOST_CHECK(!registry->HasSubCommand());

  arg = registry->FindByKey("random");
  BOOST_CHECK(!arg);
}

BOOST_AUTO_TEST_CASE(DashDash)
{
  const char* argv[] = { "./myprogram", "--verbose", "--remote=localhost" };
  int argc = 3;

  Commander::ArgumentRegistry* registry = new Commander::ArgumentRegistry(argc, argv);
  Commander::Argument* arg;

  BOOST_CHECK(!registry->HasCommand());
  BOOST_CHECK(!registry->HasSubCommand());

  arg = registry->FindByKey("verbose");
  BOOST_CHECK(arg);
  BOOST_CHECK(arg->OnlyKey());

  arg = registry->FindByKey("remote");
  BOOST_CHECK(arg);
  BOOST_CHECK(!arg->OnlyKey());
  BOOST_CHECK_EQUAL(arg->Value(), "localhost");
}

BOOST_AUTO_TEST_CASE(SingleDash)
{
  const char* argv[] = { "./myprogram", "-v", "-r=localhost" };
  int argc = 3;

  Commander::ArgumentRegistry* registry = new Commander::ArgumentRegistry(argc, argv);
  Commander::Argument* arg;

  BOOST_CHECK(!registry->HasCommand());
  BOOST_CHECK(!registry->HasSubCommand());

  arg = registry->FindByKey("v");
  BOOST_CHECK(arg);
  BOOST_CHECK(arg->OnlyKey());

  arg = registry->FindByKey("r");
  BOOST_CHECK(arg);
  BOOST_CHECK(!arg->OnlyKey());
  BOOST_CHECK_EQUAL(arg->Value(), "localhost");
}

BOOST_AUTO_TEST_CASE(MixedDashes)
{
  const char* argv[] = { "./myprogram", "-v", "--remote=localhost" };
  int argc = 3;

  Commander::ArgumentRegistry* registry = new Commander::ArgumentRegistry(argc, argv);
  Commander::Argument* arg;

  BOOST_CHECK(!registry->HasCommand());
  BOOST_CHECK(!registry->HasSubCommand());

  arg = registry->FindByKey("v");
  BOOST_CHECK(arg);
  BOOST_CHECK(arg->OnlyKey());

  arg = registry->FindByKey("remote");
  BOOST_CHECK(arg);
  BOOST_CHECK(!arg->OnlyKey());
  BOOST_CHECK_EQUAL(arg->Value(), "localhost");
}

BOOST_AUTO_TEST_CASE(HasCommand)
{
  const char* argv[] = { "./myprogram", "MyCommand", "-v", "--remote=localhost" };
  int argc = 4;

  Commander::ArgumentRegistry* registry = new Commander::ArgumentRegistry(argc, argv);
  Commander::Argument* arg;

  BOOST_CHECK(registry->HasCommand());
  BOOST_CHECK_EQUAL(registry->Command(), "MyCommand");
  BOOST_CHECK(!registry->HasSubCommand());

  arg = registry->FindByKey("v");
  BOOST_CHECK(arg);
  BOOST_CHECK(arg->OnlyKey());

  arg = registry->FindByKey("remote");
  BOOST_CHECK(arg);
  BOOST_CHECK(!arg->OnlyKey());
  BOOST_CHECK_EQUAL(arg->Value(), "localhost");
}

BOOST_AUTO_TEST_CASE(HasSubCommand)
{
  const char* argv[] = { "./myprogram", "MyCommand", "Copy", "-v", "--remote=localhost" };
  int argc = 5;

  Commander::ArgumentRegistry* registry = new Commander::ArgumentRegistry(argc, argv);
  Commander::Argument* arg;

  BOOST_CHECK(registry->HasCommand());
  BOOST_CHECK_EQUAL(registry->Command(), "MyCommand");
  BOOST_CHECK(registry->HasSubCommand());
  BOOST_CHECK_EQUAL(registry->SubCommand(), "Copy");

  arg = registry->FindByKey("v");
  BOOST_CHECK(arg);
  BOOST_CHECK(arg->OnlyKey());

  arg = registry->FindByKey("remote");
  BOOST_CHECK(arg);
  BOOST_CHECK(!arg->OnlyKey());
  BOOST_CHECK_EQUAL(arg->Value(), "localhost");
}
