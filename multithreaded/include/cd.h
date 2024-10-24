#ifndef CD_H
#define CD_H

#include "command.h"

using namespace std;

class CD : public Command {
  void help();
public:
  void execute(istream&, filesystem::path&);
};

#endif
