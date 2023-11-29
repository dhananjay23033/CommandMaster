#include <bits/stdc++.h>
#include "rm.h"

using namespace std;

void RM::execute(istream &is, filesystem::path &path) {
  string arg;
  bool hasV = false, targetSet = false;
  filesystem::path targetPath;
  for (; is >> arg;) {
    if (arg == "-v") hasV = true;
    else if (arg == "--version") {
      version();
      return;
    } else if (arg == "--help") {
      help();
      return;
    } else if (!targetSet) {
      targetPath = path / arg;
      targetSet = true;
    } else {
      cerr << "Invalid Option\n";
      return;
    }
  }

  if (!filesystem::exists(targetPath)) {
    cerr << "Target does not exist\n";
    return;
  }

  try {
    filesystem::remove(targetPath);
    if (hasV) cout << targetPath << "\nRemoved\n";
  } catch (const filesystem::filesystem_error& e) {
    cerr << "Failed to remove file: " << e.what() << '\n';
  }
}

void RM::help() {
  cout << "Usage: rm [OPTION]... [FILE]...\n"
       << "Remove (unlink) the FILE(s).\n\n"
       << "Options:\n"
       << "--version\tDisplay version information\n"
       << "--help\t\tDisplay this help message\n"
       << "-v\t\tExplain what is being done during the removal operation (verbose mode)\n\n";
}
