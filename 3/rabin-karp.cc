#include <iostream>
#include <cstdint>

// type being used to represent number
typedef uint64_t int_type;

using namespace std;

int main(int argc, char const *argv[]) {
    hash<string> str_hash;
    cout << "Input: " << argv[1] << endl << "Hash: " << str_hash(argv[1]) << endl;
    return 0;
}