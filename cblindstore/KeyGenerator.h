#ifndef __cblindstore__KeyGenerator__
#define __cblindstore__KeyGenerator__

#include <gmpxx.h>
#include "Keychain.h"

class KeyGenerator {
private:
    mpz_class etha;
    mpz_class gamma;
    
    mpz_class* generate_secret_key(mpz_class &etha);
    mpz_class* generate_public_key(mpz_class &gamma, mpz_class *sk);

public:
    KeyGenerator(int m, int lamda);
    
    bool generate_key_pair(Keychain &kc);
};

#endif
