#include <bits/stdc++.h>
#include "cd.h"

using namespace std;

void CD::execute(istream &is, filesystem::path &path) {
  string arg, target;
  bool hasV = false, targetSet = false;
  while (is >> arg) {
    if (arg == "-v" || arg == "--verbose") hasV = true;
    else if (arg == "--version") {
      version();
      return;
    } else if (arg == "--help") {
      help();
      return;
    } else if (!targetSet) {
      target = arg;
      targetSet = true;
    } else {
      cerr << "Invalid Option\n";
      return;
    }
  }
  
  if (target == ".." or target == "~" or target == "") {
    path = (target == ".." ? path.parent_path() : filesystem::path(getenv("HOME")));
    if (hasV) cout << "Switched to\n" << path << '\n';
    return;
  }
  
  filesystem::path absPath = filesystem::path(target);
  filesystem::path newPath = (absPath.is_absolute() ? absPath : path / target);
  if (!filesystem::exists(newPath) or !filesystem::is_directory(newPath)) {
    cerr << "Failed to switch to directory\n";
    return;
  }
  
  if (hasV) cout << "Switched from\n" << path << "\nto\n" << newPath << '\n';
  path = newPath;
}

void CD::help() {
  printf("cd: cd [dir]\nChange the shell working directory.\n\n");
  printf("Options:\n");
  printf("  -v, --verbose   Print verbose output.\n");
  printf("  --version       Print version information.\n");
  printf("  --help          Display this help message and exit.\n");
}
