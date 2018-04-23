// use enumerator.cc to create dataset of files, their size and hash

#include <iostream>

#include "../include/enumerator.hh"
#include "../include/streak.hh"

std::string usage("usage:\n\
$ ./main.out [--enumerate ROOT_PATH DATASET_PATH]\n\
             [--make_maps DATASET_PATH MAPS_DIR] (make sure MAPS_DIR end with a '/')\n\
             [--query FILE_PATH MAPS_DIR] (make sure MAPS_DIR end with a '/')");

int main(int argc, char const *argv[]) {
    if (argc == 4) {
        std::string action(argv[1]);

        if (action == "--query") {
            std::string file_path(argv[2]), maps_dir(argv[3]);
            return query(file_path, maps_dir);
        } else if (action == "--enumerate") {
            std::string root_path(argv[2]), dataset_path(argv[3]);
            return enumerate(root_path, dataset_path);
        } else if (action == "--make_maps") {
            std::string dataset_path(argv[2]), maps_dir(argv[3]);
            return make_maps(dataset_path, maps_dir);
        }
    }
    std::cout << usage << std::endl;
    return 0;
}