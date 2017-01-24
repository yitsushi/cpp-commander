#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <iostream>
#include <list>
#include <dlfcn.h>

#include <Commander/CommandRegistry.hpp>

#include "commands/MyCommand.hpp"

std::list<void *> dl_list;

void loadDynamicCommands(Commander::CommandRegistry* registry, const char* dir)
{
  DIR *dp;
  struct dirent *dirp;
  struct stat filestat;
  std::string filepath;
  std::string prefix = "command_";

  dp = opendir(dir);
  if (dp != NULL) {
    while ((dirp = readdir( dp ))) {
      filepath = std::string(dir) + "/" + dirp->d_name;

      if (stat( filepath.c_str(), &filestat ))  continue;
      if (S_ISDIR( filestat.st_mode ))          continue;

      if (filepath.substr(filepath.rfind('/') + 1, prefix.size()) != prefix) {
        continue;
      }

      // Determine the name of our new command
      int pad = filepath.rfind('/') + prefix.size() + 1;
      std::string command_name = filepath.substr(pad, filepath.rfind('.') - pad);

      void *hndl = dlopen(filepath.c_str(), RTLD_NOW);
      if(hndl == NULL) continue;

      dl_list.insert(dl_list.end(), hndl);

      std::string maker_name = "call_New" + command_name;

      NewCommandFunc maker = (NewCommandFunc) dlsym(hndl, maker_name.c_str());
      const char *dlsym_error = dlerror();

      registry->Register(maker);
    }
  }
}

void closeDynamicCommands()
{
  for(auto itr = dl_list.begin(); itr != dl_list.end(); ++itr){
    dlclose(*itr);
  }
}

int main(int argc, const char *argv[])
{
  Commander::CommandRegistry* registry = new Commander::CommandRegistry(argc, argv);

  registry->Register(&(Commands::NewMyCommand));

  loadDynamicCommands(registry, "bin/dynamic_commands");

  // Register dynamic commands

  registry->Execute();

  // Close all dynamic links
  closeDynamicCommands();

  return 0;
}
