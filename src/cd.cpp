#include <bits/stdc++.h>
#include "cd.h"

using namespace std;

void CD::execute(istream &is, filesystem::path &path) {
  string target;
  is >> target;
  filesystem::path newPath = path / target;
  if (filesystem::exists(newPath) && filesystem::is_directory(newPath)) {
    cout << "Switched from\n" << path << "\nto\n" << newPath << '\n';
    path = newPath;
  } else {
    cerr << "Failed to switch to directory\n";
  }
}

void CD::help() { printf("cd: cd [dir]\nChange the shell working directory.\nChange the current directory to DIR.\n\n"); }
