#include <bits/stdc++.h>
#include "../include/shell.h"
#include "../include/command.h"

using namespace std;

string Shell::menuChoice() {
  printf("Enter command or type exit\n");
  string ln;
  getline(cin, ln);
  return ln;
}

void Shell::run() {
  string mc = menuChoice();
  if (!strcasecmp(mc.c_str(), "exit"))  return;
  
  istringstream is(mc);
  Command().execute(is, path);
  run();
}
