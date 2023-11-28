#include <bits/stdc++.h>
#include "cd.h"

using namespace std;

void CD::execute(istream &is, filesystem::path &path) {
  string target;
  is >> target;
  if (target == ".." or target == "~") {
    path = (target == ".." ? path.parent_path() : filesystem::path(getenv("HOME")));
    cout << "Switched to\n" << path << '\n';
    return;
  }
  
  filesystem::path newPath = path / target;
  if (!filesystem::exists(newPath) or !filesystem::is_directory(newPath)) {
    cerr << "Failed to switch to directory\n";
    return;
  }
  
  cout << "Switched from\n" << path << "\nto\n" << newPath << '\n';
  path = newPath;
}

void CD::help() { printf("cd: cd [dir]\nChange the shell working directory.\nChange the current directory to DIR.\n\n"); }
