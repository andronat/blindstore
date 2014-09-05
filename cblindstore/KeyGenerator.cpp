#include <iostream>
#include <gmpxx.h>
#include <math.h>
#include "Keychain.h"
#include "KeyGenerator.h"
#include "Utils.h"


mpz_class* KeyGenerator::generate_public_key(mpz_class &gamma, mpz_class *sk) {
    mpz_class* q0 = new mpz_class();
    mpz_class range;
    
    // chooses q0 from (2Z + 1) intersection [1,2^gamma/sk) and sets pk = q0 * sk.
    mpz_ui_pow_ui(range.get_mpz_t(), 2, gamma.get_ui());
    range = range / *sk;
    
    random_z_number(q0, 1, range - 1);
    
    if (mpz_even_p(q0->get_mpz_t())) {
        (*q0)--;
    }
    
    *q0 = (*q0) * (*sk);

    return q0;
}

mpz_class* KeyGenerator::generate_secret_key(mpz_class &etha) {
    mpz_class* sk = new mpz_class();
    mpz_class range;
    
    // Chooses a random odd etha-bit integer p from (2Z + 1) intersection (2^(etha-1), 2^etha) as the secret key sk.
    // To get a range we need to find an integer between (2^(etha-1), 2^etha) => 2^(etha-1) + (0, 2^(etha-1))
    mpz_ui_pow_ui(range.get_mpz_t(), 2, etha.get_ui() - 1L); // Unfortunatly this: mpz_class two = 2; mpz_class a = two ^ etha; is not working
    
    // + 1 and - 1 because the lower limit is excluded
    random_z_number(sk, range + 1, range - 1);
    
    if (mpz_even_p(sk->get_mpz_t())) {
        (*sk)--;
    }
    
    return sk;
}

KeyGenerator::KeyGenerator(int m, int lamda) {
    // Bits required for query
    int logm = (int)log2(m) + 1;
    std::cout << "Number of bits required for " << m << " records: " << logm << "\n";
    
    this->etha = (lamda + 3) * ceil(logm);
    this->gamma = 5 * (lamda + 3) * ceil(logm) / 2;
    
    std::cout << "For KeyGen(λ=" << lamda << ")" << ":= ρ = " << lamda <<  ", η = " << this->etha << ", γ = " << this->gamma << "\n";
}

bool KeyGenerator::generate_key_pair(Keychain &kc) {
    kc.set_secret_key(this->generate_secret_key(this->etha));
    kc.set_public_key(this->generate_public_key(this->gamma, kc.get_secret_key()));
    
    std::cout << "Sercert Key size (bytes): " << mpz_sizeinbase(kc.get_secret_key()->get_mpz_t(),2)/8 << "\n";
    std::cout << "Public Key size (bytes): " << mpz_sizeinbase(kc.get_public_key()->get_mpz_t(),2)/8 << "\n";

    return true;
}
