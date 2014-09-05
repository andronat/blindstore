#include <iostream>
#include "Utils.h"

void random_z_number(mpz_class *result, const mpz_class &start_value, const mpz_class &uper_bound) {
    // DISCLAIMER: GMP seams to be unsafe for random genering numbers! <http://stackoverflow.com/questions/9791761/using-gmp-for-cryptography-how-to-get-random-numbers>
    // DISCLAIMER 2: using a low-resolution current time is usually a poor choice for a random number generator seed <https://gmplib.org/manual/Random-State-Seeding.html>
    gmp_randclass random_generator(gmp_randinit_default);
    random_generator.seed(time(NULL));

    *result = start_value + random_generator.get_z_range(uper_bound);
}
