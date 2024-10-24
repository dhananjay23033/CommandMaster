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

  // Create a vector to store future objects
  std::vector<std::future<void>> futures;

  // Launch a task asynchronously for removing the file
  futures.emplace_back(std::async(std::launch::async, &RM::removeFile, this, hasV, targetPath));

  // Wait for the task to complete
  for (auto& future : futures) {
      future.get();
  }

}

void RM::removeFile(bool hasV, const filesystem::path& targetPath) {
    try {
        filesystem::remove(targetPath);

        if (hasV) {
            std::cout << targetPath << "\nRemoved\n";
        }
    } catch (const filesystem::filesystem_error& e) {
        std::cerr << "Failed to remove file: " << e.what() << '\n';
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
