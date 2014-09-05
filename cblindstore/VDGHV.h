#ifndef __cblindstore__VDGHV__
#define __cblindstore__VDGHV__

#include <iostream>
#include <gmpxx.h>
#include "Keychain.h"

class VDGHV {
private:
    mpz_class gamma;
    mpz_class rho;
    
    Keychain *kc;
    
public:
    VDGHV(int m, int lamda);
    void encrypt(int message, mpz_class *pk);
    void decrypt();
};

#endif
