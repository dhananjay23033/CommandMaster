#ifndef RM_H
#define RM_H

#include "command.h"

using namespace std;

class RM : public Command {
  void help();
public:
  void removeFile(bool hasV, const filesystem::path& targetPath);
  void execute(istream&, filesystem::path&);
};

#endif
