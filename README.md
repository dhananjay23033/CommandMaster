# 🚀 Custom Linux Shell in C++ 🖥️

Welcome to the **Custom Linux Shell** project! This C++ implementation mimics the functionality of popular Linux shell commands like `cd`, `mv`, `rm`, `ls`, and `cp` — complete with additional options, profiling, and multi-threading to optimize performance. This README will walk you through the project structure, setup, and usage. 🎯

## 🎯 Features

- **Implemented Commands:**
  - `cd`: Change directories.
  - `mv`: Move or rename files.
  - `rm`: Remove files or directories.
  - `ls`: List directory contents.
  - `cp`: Copy files or directories.
  
- **Options Supported:**
  - **-r**: Recursive for `rm` and `cp` 📂
  - **--help**: Displays help for each command ❓
  - **-f**: Force deletion in `rm` 🚨
  - **-i**: Interactive mode in `mv` and `rm` ⚠️

- **Profiling:**
  - Uses a bash script to create test file structures for profiling:
    - **100 files of 1GB each** 🗃️
    - **10,000 files of 10MB each** 📂
    - **Recursive directory structure with 10MB files** 🔄

- **Multi-threading:** 🚦
  - Recursive tasks like `cp -r` and `rm -r` intelligently spawn threads based on system cores for optimal performance.

- **Performance Comparison:** ⚡
  - Profiling data is captured for both single-threaded and multi-threaded versions of the shell.

## 📁 Repository Structure

```
├── src/                      # C++ source files
│   ├── command_base.cpp       # Base class for commands
│   ├── cd_command.cpp         # Implementation of 'cd'
│   ├── mv_command.cpp         # Implementation of 'mv'
│   ├── rm_command.cpp         # Implementation of 'rm'
│   ├── ls_command.cpp         # Implementation of 'ls'
│   ├── cp_command.cpp         # Implementation of 'cp'
│   └── main.cpp               # Entry point for the shell
├── bash_scripts/              # Profiling scripts
│   ├── create_files.sh        # Script to create file structures
│   ├── profile_single.sh      # Script to profile single-threaded shell
│   └── profile_multi.sh       # Script to profile multi-threaded shell
├── Makefile                   # Build and compile the project
└── README.md                  # Project documentation (this file)
```

## 🛠️ How to Build

To compile and run this project, follow these steps:

1. **Clone the repository:**

   ```bash
   git clone https://github.com/username/repo.git
   cd repo
   ```

2. **Build the binaries:**

   - **For debugging:**

     ```bash
     make debug
     ```

   - **For optimized execution:**

     ```bash
     make release
     ```

3. **Run the shell:**

   ```bash
   ./custom_shell
   ```

## 🔧 Commands and Options

Here’s how you can use each command within the shell:

| Command      | Description                                                                                             |
|--------------|---------------------------------------------------------------------------------------------------------|
| **cd**       | Changes the current working directory.                                                                   |
| **mv**       | Moves or renames files and directories. Usage: `mv source target [-i]`.                                  |
| **rm**       | Removes files or directories. Usage: `rm file [-r] [-f]`.                                                |
| **ls**       | Lists the contents of a directory.                                                                       |
| **cp**       | Copies files or directories. Usage: `cp source target [-r]`.                                             |

### Additional Options

- **-r**: Recursive (used in `rm` and `cp`).
- **--help**: Displays detailed usage information for any command.
- **-f**: Force removal (used in `rm`).
- **-i**: Interactive mode to confirm before each action (used in `rm` and `mv`).

## 🧪 Profiling

Profiling allows you to measure the performance of the implemented commands under different file structures.

1. **Create test directories and files:**

   ```bash
   bash bash_scripts/create_files.sh
   ```

2. **Run the profiler (single-threaded):**

   ```bash
   bash bash_scripts/profile_single.sh
   ```

3. **Run the profiler (multi-threaded):**

   ```bash
   bash bash_scripts/profile_multi.sh
   ```

4. **Compare Results:** 
   The profiler will display the execution time for each scenario, helping you analyze performance improvements due to multi-threading.

## ⚙️ Multi-Threading Implementation

The number of threads is automatically chosen based on:
- The number of cores available on your system.
- The workload for recursive operations (`cp -r`, `rm -r`).

## 📊 Profiling Results

After profiling, compare the results from the single-threaded and multi-threaded versions to see the performance gains due to parallel processing.

---

### 🛠️ Contributions

Feel free to open a pull request if you'd like to improve the shell, add new features, or enhance performance!

---

**Happy Coding!** ✨

--- 