#ifndef _commander_Argument_hpp_
#define _commander_Argument_hpp_

#include <string>

namespace Commander {
  class Argument
  {
  public:
    Argument(const std::string key, const std::string value);
    ~Argument();

    bool OnlyValue();
    bool OnlyKey();
    std::string Key();
    std::string Value();

    void Print();

  private:
    std::string m_key;
    std::string m_value;
  };
}

#endif

