/*
 * Original code by Balazs Nadasdi (http://github.com/Yitsushi/)
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any
 * damages arising from the use of this software.
 * Permission is granted to anyone to use this software for any
 * purpose, including commercial applications, and to alter it and
 * redistribute it freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must
 * not claim that you wrote the original software. If you use this
 * software in a product, an acknowledgment in the product documentation
 * would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such, and
 * must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source
 * distribution.
 */
#ifndef _commander_Argument_hpp_
#define _commander_Argument_hpp_

#include <string>
#include <list>

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

    // Helper functions
    int IntValue();
    long LongValue();
    bool BoolValue();
    std::list<std::string> ListValue(const char delimiter);
    std::list<int> IntListValue(const char delimiter);
    std::list<long> LongListValue(const char delimiter);

  private:
    std::string m_key;
    std::string m_value;
  };
}

#endif

