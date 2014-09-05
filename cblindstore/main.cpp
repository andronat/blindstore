#include <iostream>
#include "KeyGenerator.h"



int main(int argc, const char * argv[]) {
    // Setup our keychain
    Keychain kc;
    
    // Number of records
    int m = 10000000;
    
    // Security parameter λ
    int lamda = 60;

    KeyGenerator kg(m, lamda);
    
    if (kg.generate_key_pair(kc)) {
        std::cout << "Generated a key pair" << "\n";
    }
    
    return 0;
}

