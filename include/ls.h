#ifndef LS_H
#define LS_H

#include <bits/stdc++.h>
#include "command.h"

using namespace std;

class LS : public Command {
public:
  void execute(istream&, filesystem::path), executeR(bool, filesystem::path), print(bool, filesystem::path);
};

#endif
