#include <bits/stdc++.h>
#include "mv.h"

using namespace std;

void MV::execute(istream &is, filesystem::path &path) {
  string arg, srcDestPair[2];
  bool hasV = false;
  int isd = 0;
  for (; is >> arg;) {
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
  if (!filesystem::exists(srcPath)) {
    cerr << "Source file does not exist\n";
    return;
  }

  if (filesystem::exists(destPath) && filesystem::is_directory(destPath)) {
    destPath /= srcPath.filename();
  }

  // Create a vector to store future objects
    std::vector<std::future<void>> futures;

  // Launch a task asynchronously for moving the file
  futures.emplace_back(std::async(std::launch::async, &MV::moveFile, this, hasV, srcPath, destPath));
  
  // Wait for the task to complete
  for (auto& future : futures) {
      future.get();
  }
}

void MV::moveFile(bool hasV, const filesystem::path& srcPath, const filesystem::path& destPath) {
    try {
        filesystem::rename(srcPath, destPath);

        if (hasV) {
            std::cout << srcPath << "\n->\n" << destPath << '\n';
        }
    } catch (const filesystem::filesystem_error& e) {
        std::cerr << "Failed to move file: " << e.what() << '\n';
    }
}

void MV::help() {
  cout << "Usage: mv [OPTION]... SOURCE DEST\n"
       << "Move SOURCE to DEST (default current directory)\n\n"
       << "Options:\n"
       << "--version\tDisplay version information\n"
       << "--help\t\tDisplay this help message\n"
       << "-v\t\tExplain what is being done during the move operation (verbose mode)\n\n";
}

