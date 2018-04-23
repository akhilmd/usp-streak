# usp-streak
UNIX System Programming Hackathon Assignment 

## Building:
```
$ git clone https://github.com/akhilmd/usp-streak.git
$ cd usp-streak
$ make
```

## Usage:
```
$ ./main.out [--enumerate ROOT_PATH DATASET_PATH]
             [--make_maps DATASET_PATH MAPS_DIR] (make sure MAPS_DIR end with a '/')
             [--query FILE_PATH MAPS_DIR] (make sure MAPS_DIR end with a '/')
```

## Running Tests:
`$ make test`

#### Example Test Run:
```
Compiling...
mkdir -p obj
g++ -g -std=c++14 -o obj/enumerator.o -c src/enumerator.cc
mkdir -p obj
g++ -g -std=c++14 -o obj/streak.o -c src/streak.cc
mkdir -p bin
g++ -g -std=c++14 -o bin/main.out src/main.cc obj/enumerator.o obj/streak.o -lstdc++fs

Creating tests directory...

Help:
$ ./bin/main.out
usage:
$ ./main.out [--enumerate ROOT_PATH DATASET_PATH]
             [--make_maps DATASET_PATH MAPS_DIR] (make sure MAPS_DIR end with a '/')
             [--query FILE_PATH MAPS_DIR] (make sure MAPS_DIR end with a '/')

Generate Streak Files:
$ ./bin/main.out --enumerate ./test_dir/ ./tests/files.data
Iterating through ./test_dir/
Writing {path, size, hash(file_name)} to ./tests/files.data

$ ./bin/main.out --make_maps ./tests/files.data ./tests/maps/
Reading from ./tests/files.data
Generating map in ./tests/maps/

Example Query:
$ ./bin/main.out --query ./test_dir/f1 ./tests/maps/
File Size: 755
File Name: f1
Name Hash: 6152274446545244381

Size Streak: 2
Name Streak: 2

Similar Files:
./test_dir/d1/f2
./test_dir/f1

Removing tests directory...

```
