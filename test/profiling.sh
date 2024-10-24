#!/bin/bash

# Function to create a directory with the specified number of files of a given size
create_directory() {
    local dir_name=$1
    local file_count=$2
    local file_size=$3

    mkdir -p "$dir_name"
    cd "$dir_name" || exit

    for ((i = 1; i <= file_count; i++)); do
        dd if=/dev/zero of=file${i}.bin bs=$file_size count=1 &>/dev/null
    done

    cd ..
}

# Function to create directories recursively until a total of 10000 files are created
create_recursive_directories() {
    local base_dir=$1
    local current_count=$2
    local remaining_count=$((10 - current_count))

    if [ "$remaining_count" -le 0 ]; then
        return
    fi

    local sub_dir_name="subdir_$((current_count / 10))"
    create_directory "$base_dir/$sub_dir_name" 10 1M

    create_recursive_directories "$base_dir/$sub_dir_name" "$((current_count + 10))"
}

# Create directories and files using shell functions
create_directory "dir_1GB" 2 1M
create_directory "dir_10MB" 5 10M
create_directory "dir_recursive" 5 10M
create_recursive_directories "dir_recursive" 5

# create_large_files
# create_medium_files
cd ..    
# create_recursive_files


echo "Script completed."
