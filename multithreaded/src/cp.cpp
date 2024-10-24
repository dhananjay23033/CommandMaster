#include <bits/stdc++.h>
#include "cp.h"

using namespace std;

void CP::execute(istream &is, filesystem::path &path) {
  string arg, srcDestPair[2];
  bool hasV = false;
  for (int isd = 0; is >> arg;) {
    if (arg == "-v" || arg == "--verbose") hasV = true;
    else if (arg == "--version") {
      version();
      return;
    } else if (arg == "--help") {
      help();
      return;
    } else if (isd < 2) srcDestPair[isd++] = arg;
    else {
      cerr << "Invalid Option\n";
      return;
    }
  }
  
  auto absSrc = filesystem::path(srcDestPair[0]), absDest = filesystem::path(srcDestPair[1]);
  filesystem::path srcPath = (absSrc.is_absolute() ? absSrc : path / srcDestPair[0]);
  filesystem::path destPath = (absDest.is_absolute() ? absDest : path / srcDestPair[1]);
  if (!filesystem::exists(srcPath) or !filesystem::is_regular_file(srcPath)) {
    cerr << "Source file does not exist or is not a regular file\n";
    return;
  }

  if (filesystem::exists(destPath) and filesystem::is_directory(destPath)) {
    destPath /= srcPath.filename();
  }

  try {
    filesystem::copy_file(srcPath, destPath);
    if (hasV) cout << srcPath << "\n->\n" << destPath << '\n';
  } catch (const filesystem::filesystem_error& e) {
    cerr << "Failed to copy file: " << e.what() << '\n';
  }
}

void CP::help() {
  cout << "Usage: cp [OPTION]... SOURCE DEST\n"
       << "Copy SOURCE to DEST (default current directory)\n\n"
       << "Options:\n"
       << "--version\tDisplay version information\n"
       << "--help\t\tDisplay this help message\n"
       << "-v, --verbose\tExplain what is being done during the copy operation\n\n";
}

