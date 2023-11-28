#include <bits/stdc++.h>
#include "ls.h"

using namespace std;

void LS::execute(istream &is, filesystem::path &path) {
  bool hasL = false, hasR = false;
  string arg;
  while (is >> arg) {
    if (arg == "-l") hasL = true;
    else if (arg == "-R") hasR = true;
    else if (arg == "--version") {
      version();
      return;
    } else if (arg == "--help") {
      help();
      return;
    } else {
      cerr << "Invalid Option\n";
      return;
    }
  }
  
  if (hasR) {
    executeR(hasL, path);
  } else {
    for (const auto& entry : filesystem::directory_iterator(path)) print(hasL, entry.path());  
  }
  
  cout << '\n';
}

void LS::print(bool hasL, filesystem::path path) {
  cout << path.filename() << ' ';
  if (hasL) cout << format("{}\n", filesystem::last_write_time(path));
}

void LS::executeR(bool hasL, filesystem::path path) {
  for (const auto& entry : filesystem::recursive_directory_iterator(path)) print(hasL, entry.path());        
}

void LS::help() { printf("List information about the files in the current directory.\n-l\tDetailed list\n-R\tList recursively\n\n"); }
