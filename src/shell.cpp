#include <bits/stdc++.h>
#include "../include/shell.h"
#include "../include/read.h"

using namespace std;

string Shell::menuChoice() {
  printf("Enter command or type exit\n");
  return read<string>();
}

void Shell::run() {
  string mc = menuChoice();
  if (!strcasecmp(mc.c_str(), "exit"))  return;
  
  cerr << "FUSBJ DA\n";//TODO
  run();
}
