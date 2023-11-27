#include <bits/stdc++.h>
#include "command.h"
#include "ls.h"

using namespace std;

void Command::execute(istream &is, filesystem::path path) {
  string cmd;
  is >> cmd;
  if (cmd == "ls") LS().execute(is, path);
  else cerr << "Command not found\n";
}
