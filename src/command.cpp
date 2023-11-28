#include <bits/stdc++.h>
#include "command.h"
#include "ls.h"
#include "cd.h"
#include "cp.h"
#include "mv.h"

using namespace std;

void Command::execute(istream &is, filesystem::path &path) {
  string cmd;
  is >> cmd;
  if (cmd == "ls") LS().execute(is, path);
  else if (cmd == "cd") CD().execute(is, path);
  else if (cmd == "cp") CP().execute(is, path);
  else if (cmd == "mv") MV().execute(is, path); //TODO
  else cerr << "Command not found\n";
}

void Command::version() {
  printf("(🐚️) 1.0\nCopyright (C) 2023 Free Software Foundation, Inc.\nLicense GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\nWritten by Mayank Gusain and Dhananjay Sharma.\n\n");
}
