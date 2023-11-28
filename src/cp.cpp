#include <bits/stdc++.h>
#include "cp.h"

using namespace std;

void CP::execute(istream &is, filesystem::path &path) {
  string source, destination;
  is >> source >> destination;
  filesystem::path srcPath = path / source;
  filesystem::path destPath = path / destination;
  if (!filesystem::exists(srcPath) or !filesystem::is_regular_file(srcPath)) {
    cerr << "Source file does not exist or is not a regular file\n";
    return;
  }

  if (filesystem::exists(destPath) and filesystem::is_directory(destPath)) {
    destPath /= srcPath.filename();
  }

  try {
    filesystem::copy_file(srcPath, destPath);
    cout << "Copied " << srcPath << " to " << destPath << '\n';
  } catch (const filesystem::filesystem_error& e) {
    cerr << "Failed to copy file: " << e.what() << '\n';
  }
}

void CP::help() { printf("Usage: cp [OPTION]... SOURCE DEST\nCopy SOURCE to DEST\n\n"); }
