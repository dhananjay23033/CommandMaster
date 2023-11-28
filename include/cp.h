#ifndef CP_H
#define CP_H

#include "command.h"

using namespace std;

class CP : public Command {
  void help();
public:
  void execute(istream&, filesystem::path&);
};

#endif
