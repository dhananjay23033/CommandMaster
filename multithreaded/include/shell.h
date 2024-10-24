#ifndef SHELL_H
#define SHELL_H

using namespace std;

class Shell {
  filesystem::path path = filesystem::current_path();
  string menuChoice();
public:
  void run();
};

#endif
