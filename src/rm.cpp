#include <bits/stdc++.h>
#include "rm.h"

using namespace std;

void RM::execute(istream &is, filesystem::path &path) {
  string target;
  is >> target;
  filesystem::path targetPath = path / target;
  if (!filesystem::exists(targetPath)) {
    cerr << "Target does not exist\n";
    return;
  }
  
  try {
    filesystem::remove(targetPath);
    cout << "Removed " << targetPath << '\n';
  } catch (const filesystem::filesystem_error& e) {
    cerr << "Failed to remove file: " << e.what() << '\n';
  }
}

void RM::help() { printf("Usage: rm [OPTION]... [FILE]...\nRemove (unlink) the FILE(s).\n\n"); }
