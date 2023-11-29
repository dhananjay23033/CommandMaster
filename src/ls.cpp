#include <bits/stdc++.h>
#include "ls.h"

using namespace std;

void LS::execute(istream &is, filesystem::path path) {
  bool hasL = false, hasR = false, potPathSet = false;
  string arg, potPath;
  while (is >> arg) {
    if (arg == "-l") hasL = true;
    else if (arg == "-R") hasR = true;
    else if (arg == "--version") {
      version();
      return;
    } else if (arg == "--help") {
      help();
      return;
    } else if (!potPathSet) {
      potPath = arg;
      potPathSet = true;
    } else {
      cerr << "Invalid Option\n";
      return;
    }
  }
  
  if (filesystem::path(potPath).is_absolute()) path = potPath;
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

void LS::help() {
  cout << "Usage: ls [OPTION]... [FILE]...\n"
       << "List information about the files in the current directory.\n"
       << "-l\t\tDetailed list\n"
       << "-R\t\tList recursively\n"
       << "--version\tDisplay version information\n"
       << "--help\t\tDisplay help message\n\n";
}

