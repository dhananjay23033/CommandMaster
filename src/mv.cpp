#include <bits/stdc++.h>
#include "mv.h"

using namespace std;

void MV::execute(istream &is, filesystem::path &path) {
  string source, destination;
  is >> source >> destination;
  filesystem::path srcPath = path / source;
  filesystem::path destPath = path / destination;
  if (!filesystem::exists(srcPath)) {
    cerr << "Source file does not exist\n";
    return;
  }
  
  if (filesystem::exists(destPath) && filesystem::is_directory(destPath)) {
    destPath /= srcPath.filename();
  }

  try {
    filesystem::rename(srcPath, destPath);
    cout << "Moved " << srcPath << " to " << destPath << '\n';
  } catch (const filesystem::filesystem_error& e) {
    cerr << "Failed to move file: " << e.what() << '\n';
  }
}

void MV::help() { printf("Usage: mv [OPTION]... SOURCE DEST\nMove SOURCE to DEST\n\n"); }
