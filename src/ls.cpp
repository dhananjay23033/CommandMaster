#include <bits/stdc++.h>
#include "ls.h"

using namespace std;

std::string escapeRegexSpecialChars(const std::string& input) {
    std::string output;
    for (char c : input) {
        if (c == '\\' || c == '.' || c == '*' || c == '+' || c == '?' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}' || c == '^' || c == '$' || c == '|') {
            output += '\\'; // Escape special characters with backslash
        }
        output += c;
    }
    return output;
}

std::string wildcardToRegex(const std::string& wildcardPattern) {
    std::string regexPattern;
    bool escaped = false;

    for (char c : wildcardPattern) {
        if (c == '*' && !escaped) {
            regexPattern += ".*"; // Match zero or more characters
        } else if (c == '?' && !escaped) {
            regexPattern += '.';  // Match any single character
        } else if (c == '\\' && !escaped) {
            escaped = true;      // Set the escape flag for the next character
        } else {
            regexPattern += escapeRegexSpecialChars(std::string(1, c));
            escaped = false;      // Reset the escape flag
        }
    }

    // Modify the regex to make ? non-greedy
    size_t pos = 0;
    while ((pos = regexPattern.find("\\?", pos)) != std::string::npos) {
        regexPattern.replace(pos, 2, ".?");
        pos += 2;
    }
    
    return regexPattern;
}

void LS::execute(istream &is, filesystem::path path) {
  bool hasL = false, hasR = false, potPathSet = false, wildcard = false;
  string arg, potPath, wildcardPattern;
  while (is >> arg) {
    if (arg == "-l") hasL = true;
    else if (arg == "-R") hasR = true;
    else if (arg == "--version") {
      version();
      return;
    } else if (arg == "--help") {
      help();
      return;
    } else if (arg[0] == '*' || arg[0] == '?') {
      wildcard = true;
      wildcardPattern = arg;
    } else if (!potPathSet) {
      potPath = arg;
      potPathSet = true;
    } else {
      cerr << "Invalid Option\n";
      return;
    }
  }
  
  try {
    if (filesystem::path(potPath).is_absolute()) path = potPath;
    if (hasR) {
      executeR(hasL, path);
    } else if (wildcard) {
        auto regexPattern = wildcardToRegex(wildcardPattern);
        for (const auto& entry : filesystem::directory_iterator(path)) {
          auto filename = entry.path().filename().string();
          // cout<<escapedPattern<<" "<<filename<<endl;
          if (std::regex_search(filename, std::regex(regexPattern))) {
            print(hasL, entry.path());
          }
        }
    } else {
      for (const auto& entry : filesystem::directory_iterator(path)) {
            print(hasL, entry.path());  
      }
    }
  } catch (exception &e) {
    cerr << e.what() ;
  }
  
  cout << '\n';
}

void LS::print(bool hasL, filesystem::path path) {
  cout << path.filename() << ' ';
  // if (hasL) cout << format("{}\n", filesystem::last_write_time(path));
}

void LS::executeR(bool hasL, filesystem::path path) {
  for (const auto& entry : filesystem::recursive_directory_iterator(path)) print(hasL, entry.path());        
}

void LS::help() {
  cout << "Usage: ls [OPTION]... [FILE]...\n"
       << "List information about the files in the current directory.\n"
       << "-l\t\tDetailed list\n"
       << "-R\t\tList recursively\n"
       << "--version\tDisplay version information\n"
       << "--help\t\tDisplay help message\n\n";
}

