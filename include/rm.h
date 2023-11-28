#ifndef RM_H
#define RM_H

#include "command.h"

using namespace std;

class RM : public Command {
  void help();
public:
  void execute(istream&, filesystem::path&);
};

#endif
