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
#ifndef _commander_ArgumentRegistry_hpp_
#define _commander_ArgumentRegistry_hpp_

#include <list>
#include "Argument.hpp"

namespace Commander {
  class ArgumentRegistry
  {
  public:
    ArgumentRegistry(int argc, const char *argv[]);

    void Dump();

    Argument* FindByKey(std::string);

    bool HasCommand();
    std::string Command();

    bool HasSubCommand();
    std::string SubCommand();

  private:
    std::list<Argument*> m_arguments;
    std::string m_command;
    std::string m_subcommand;
  };
}

#endif

