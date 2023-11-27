#ifndef COMMAND_H
#define COMMAND_H

#include <bits/stdc++.h>

using namespace std;

class Command {
protected:
  void version();
public:
  void execute(istream&, filesystem::path);
};

#endif
