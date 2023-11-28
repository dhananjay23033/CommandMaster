#ifndef MV_H
#define MV_H

#include "command.h"

using namespace std;

class MV : public Command {
  void help();
public:
  void execute(istream&, filesystem::path&);
};

#endif
