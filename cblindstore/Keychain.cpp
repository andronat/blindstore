#include "Keychain.h"

Keychain::Keychain() {
}

mpz_class* Keychain::get_secret_key() {
    return this->sk;
}

void Keychain::set_secret_key(mpz_class *sk) {
    this->sk = sk;
}

mpz_class* Keychain::get_public_key() {
    return this->pk;
}

void Keychain::set_public_key(mpz_class *pk) {
    this->pk = pk;
}
