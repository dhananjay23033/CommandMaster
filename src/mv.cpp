#include <bits/stdc++.h>
#include "mv.h"

using namespace std;

void MV::execute(istream &is, filesystem::path &path) {
 string arg, srcDestPair[2];
 bool hasV = false;
 int isd = 0;
 for (; is >> arg;) {
   if (arg == "-v") hasV = true;
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

 filesystem::path srcPath = path / srcDestPair[0];
 filesystem::path destPath = path / srcDestPair[1];

 if (!filesystem::exists(srcPath)) {
   cerr << "Source file does not exist\n";
   return;
 }

 if (filesystem::exists(destPath) && filesystem::is_directory(destPath)) {
   destPath /= srcPath.filename();
 }

 try {
   filesystem::rename(srcPath, destPath);
   if (hasV) cout << srcPath << "\n->\n" << destPath << '\n';
 } catch (const filesystem::filesystem_error& e) {
   cerr << "Failed to move file: " << e.what() << '\n';
 }
}

void MV::help() { printf("Usage: mv [OPTION]... SOURCE DEST\nMove SOURCE to DEST (default current directory)\n\n"); }
