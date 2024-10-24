#ifndef MV_H
#define MV_H

#include "command.h"

using namespace std;

class MV : public Command {
  void help();
public:
  void moveFile(bool hasV, const filesystem::path& srcPath, const filesystem::path& destPath);
  void execute(istream&, filesystem::path&);
};

#endif
