#define BOOST_TEST_DYN_LINK

#ifdef STAND_ALONE
#define BOOST_TEST_MODULE Argument test
#endif

#include <boost/test/unit_test.hpp>
#include <string>
#include <list>
#include <sstream>
#include <Commander/Argument.hpp>

BOOST_AUTO_TEST_CASE(KeyOnlyArgument)
{
  Commander::Argument* arg;
  std::string key = "verbose";
  std::string value = "";

  arg = new Commander::Argument(key, value);

  BOOST_CHECK_EQUAL(arg->OnlyKey(), true);
  BOOST_CHECK_EQUAL(arg->OnlyValue(), false);
  BOOST_CHECK_EQUAL(arg->Key(), key);
}

BOOST_AUTO_TEST_CASE(ValueOnlyArgument)
{
  Commander::Argument* arg;
  std::string key = "";
  std::string value = "single-value";

  arg = new Commander::Argument(key, value);

  BOOST_CHECK_EQUAL(arg->OnlyKey(), false);
  BOOST_CHECK_EQUAL(arg->OnlyValue(), true);
  BOOST_CHECK_EQUAL(arg->Value(), value);
}

BOOST_AUTO_TEST_CASE(KeyValueArgument)
{
  Commander::Argument* arg;
  std::string key = "target";
  std::string value = "remote";

  arg = new Commander::Argument(key, value);

  BOOST_CHECK_EQUAL(arg->OnlyKey(), false);
  BOOST_CHECK_EQUAL(arg->OnlyValue(), false);
  BOOST_CHECK_EQUAL(arg->Key(), key);
  BOOST_CHECK_EQUAL(arg->Value(), value);
}

BOOST_AUTO_TEST_CASE(IntValueArgument)
{
  Commander::Argument* arg;
  int excepted_value = 1234;

  std::string key = "id";
  std::string value = std::to_string(excepted_value);

  arg = new Commander::Argument(key, value);

  BOOST_CHECK_EQUAL(arg->OnlyKey(), false);
  BOOST_CHECK_EQUAL(arg->OnlyValue(), false);
  BOOST_CHECK_EQUAL(arg->Key(), key);
  BOOST_CHECK_EQUAL(arg->Value(), value);
  BOOST_CHECK_EQUAL(arg->IntValue(), excepted_value);
}

BOOST_AUTO_TEST_CASE(BoolValueArgument)
{
  Commander::Argument* arg;

  std::string key = "want";

  std::list< std::pair<std::string, bool> > test_values = {
    {"y", true}, {"Y", true}, {"yes", true},
    {"true", true}, {"enabled", true},
    {"1", true}, {"2", true},

    {"something", false}, {"", false},
    {"no", false}, {"0", false}, {"-1", false}
  };

  for (auto k : test_values) {
    arg = new Commander::Argument(key, k.first);
    BOOST_CHECK_EQUAL(arg->BoolValue(), k.second);
  }
}

BOOST_AUTO_TEST_CASE(LongValueArgument)
{
  Commander::Argument* arg;
  long excepted_value = 123443242321;

  std::string key = "id";
  std::string value = std::to_string(excepted_value);

  arg = new Commander::Argument(key, value);

  BOOST_CHECK_EQUAL(arg->OnlyKey(), false);
  BOOST_CHECK_EQUAL(arg->OnlyValue(), false);
  BOOST_CHECK_EQUAL(arg->Key(), key);
  BOOST_CHECK_EQUAL(arg->Value(), value);
  BOOST_CHECK_EQUAL(arg->LongValue(), excepted_value);
}

BOOST_AUTO_TEST_CASE(ListValueArgument)
{
  Commander::Argument* arg;
  std::list<std::string> excepted_value = {"abc", "def", "ghj"};
  char delimiter = ',';

  std::string key = "id";
  std::string value;

  std::stringstream ss;
  for (std::string s : excepted_value) {
    ss << s << delimiter;
  }
  value = ss.str();
  // value.pop_back(); <-- only c++11
  value = value.substr(0, value.length()-1);

  arg = new Commander::Argument(key, value);

  BOOST_CHECK_EQUAL(arg->OnlyKey(), false);
  BOOST_CHECK_EQUAL(arg->OnlyValue(), false);
  BOOST_CHECK_EQUAL(arg->Key(), key);
  BOOST_CHECK_EQUAL(arg->Value(), value);
  std::list<std::string> values = arg->ListValue(delimiter);
  BOOST_CHECK_EQUAL_COLLECTIONS(
      values.begin(), values.end(),
      excepted_value.begin(), excepted_value.end()
  );
}

BOOST_AUTO_TEST_CASE(IntListValueArgument)
{
  Commander::Argument* arg;
  std::list<int> excepted_value = {1, 2, 9, -3};
  char delimiter = ',';

  std::string key = "id";
  std::string value;

  std::stringstream ss;
  for (int s : excepted_value) {
    ss << s << delimiter;
  }
  value = ss.str();
  value = value.substr(0, value.length()-1);

  arg = new Commander::Argument(key, value);

  BOOST_CHECK_EQUAL(arg->OnlyKey(), false);
  BOOST_CHECK_EQUAL(arg->OnlyValue(), false);
  BOOST_CHECK_EQUAL(arg->Key(), key);
  BOOST_CHECK_EQUAL(arg->Value(), value);
  std::list<int> values = arg->IntListValue(delimiter);
  BOOST_CHECK_EQUAL_COLLECTIONS(
      values.begin(), values.end(),
      excepted_value.begin(), excepted_value.end()
  );
}

BOOST_AUTO_TEST_CASE(LongListValueArgument)
{
  Commander::Argument* arg;
  std::list<long> excepted_value = {
    123443242321,
    123443242326,
    -123443242329
  };
  char delimiter = ',';

  std::string key = "id";
  std::string value;

  std::stringstream ss;
  for (long s : excepted_value) {
    ss << s << delimiter;
  }
  value = ss.str();
  value = value.substr(0, value.length()-1);

  arg = new Commander::Argument(key, value);

  BOOST_CHECK_EQUAL(arg->OnlyKey(), false);
  BOOST_CHECK_EQUAL(arg->OnlyValue(), false);
  BOOST_CHECK_EQUAL(arg->Key(), key);
  BOOST_CHECK_EQUAL(arg->Value(), value);
  std::list<long> values = arg->LongListValue(delimiter);
  BOOST_CHECK_EQUAL_COLLECTIONS(
      values.begin(), values.end(),
      excepted_value.begin(), excepted_value.end()
  );
}
