#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdint>
#include <experimental/filesystem>

#include <stdlib.h>

#include "../include/streak.hh"

namespace fs = std::experimental::filesystem;
const std::string DELIM = "ಡ", _("_");
std::hash<std::string> str_hash;

// Recursively traverse all directories starting from root_path
int enumerate(std::string root_path, std::string out_path) {
    std::cout << "Iterating through " << root_path << std::endl;
    std::cout << "Writing {path, size, hash(file_name)} to "
              << out_path
              << std::endl;

    // File containing the system's files, sizes and hash of file name.
    std::ofstream out_file(out_path);

    for(auto& dirent: fs::recursive_directory_iterator(root_path)) {
        // Consider only regular files.
        if (fs::is_regular_file(dirent)) {
            fs::path path = dirent.path();
            out_file << path.string()
                     << DELIM
                     << fs::file_size(dirent)
                     << DELIM
                     << str_hash(path.filename().string())
                     << std::endl;
        }
    }

    out_file.close();
    return 0;
}

// Utility function.
std::vector<std::string> split(std::string str, std::string delim) {
    std::vector<std::string> tokens;

    char* cstr = strdup(str.c_str());
    const char* cdelim = delim.c_str();

    char* token = strtok(cstr, cdelim);

    while(token) {
        tokens.push_back(std::string(token));
        token = strtok(NULL, cdelim);
    }

    return tokens;
}

// For all the paths in dataset_path, calculate streaks
// and write to files in map_base_dir
int make_maps(std::string dataset_path, std::string map_base_dir) {
    std::cout << "Reading from " << dataset_path << std::endl;
    std::cout << "Generating map in " << map_base_dir << std::endl;

    std::ifstream dataset(dataset_path);
    std::ofstream out_file;

    std::string line, path, size_sc, name_sc;
    uint64_t size, name;

    std::vector<std::string> values;

    while (getline(dataset, line)) {
        values = split(line, DELIM);
    
        path = values[0];
        size = stoull(values[1]);
        name = stoull(values[2]);

        size_sc = std::to_string(streak(size));
        name_sc = std::to_string(streak(name));

        out_file = std::ofstream(map_base_dir + size_sc + _ + name_sc, std::ios_base::app);
        out_file << path << std::endl;
        out_file.close();
    }
    dataset.close();
    return 0;
}

int query(std::string file_path_str, std::string maps_dir) {
    fs::path file_path(file_path_str);

    uint64_t size = fs::file_size(file_path);

    std::string name_str = file_path.filename().string();
    uint64_t name = str_hash(name_str);

    std::string size_sc = std::to_string(streak(size));
    std::string name_sc = std::to_string(streak(name));

    std::string line;
    std::ifstream result_file(maps_dir + size_sc + _ + name_sc);

    std::cout << "File Size: " << size
              << std::endl
              << "File Name: " << name_str
              << std::endl
              << "Name Hash: " << name
              << std::endl << std::endl
              << "Size Streak: " << size_sc
              << std::endl
              << "Name Streak: " << name_sc
              << std::endl << std::endl
              << "Similar Files:"
              << std::endl;

    while (getline(result_file, line)) {
        std::cout << line << std::endl;
    }

    result_file.close();
    return 0;
}