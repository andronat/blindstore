#ifndef __cblindstore__Keychain__
#define __cblindstore__Keychain__

#include <iostream>
#include <gmpxx.h>

class Keychain {
private:
    mpz_class *sk;
    mpz_class *pk;

public:
    Keychain();
    mpz_class* get_public_key();
    void set_public_key(mpz_class *pk);
    mpz_class* get_secret_key();
    void set_secret_key(mpz_class *sk);
};

#endif
