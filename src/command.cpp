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

void Command::version() {
  printf("(🐚️) 1.0\nCopyright (C) 2023 Free Software Foundation, Inc.\nLicense GPLv3+: GNU GPL version 3 or later <https://gnu.org/licenses/gpl.html>.\nThis is free software: you are free to change and redistribute it.\nThere is NO WARRANTY, to the extent permitted by law.\nWritten by Mayank Gusain and Dhananjay Sharma.\n");
}
