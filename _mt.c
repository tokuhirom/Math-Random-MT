/*
 * $Id: _mt.c,v 1.00 2002/02/08 19:22:46 ams Exp $
 * Copyright (C) 1997, 1999 Makoto Matsumoto and Takuji Nishimura.
 * Copyright 2001 Abhijit Menon-Sen <ams@wiw.org>
 */

#include "mt.h"

/* This code is based on mt19937ar.c, written by Takuji Nishimura and
   Makoto Matsumoto (20020126). Further details are available at
   <URL:http://www.math.keio.ac.jp/matumoto/emt.html>.

   REFERENCE
   M. Matsumoto and T. Nishimura,
   "Mersenne Twister: A 623-Dimensionally Equidistributed Uniform
   Pseudo-Random Number Generator",
   ACM Transactions on Modeling and Computer Simulation,
   Vol. 8, No. 1, January 1998, pp 3--30. */

struct mt *mt_setup(unsigned long int seed)
{
    int i;
    struct mt *self = malloc(sizeof(struct mt));
    unsigned long *mt;

    if (self) {
        mt = self->mt;
        mt[0] = seed & 0xffffffff;
        for (i = 1; i < N; i++)
            mt[i] = 1812433253 * (mt[i-1]^(mt[i-1]>>30)) + i;
        self->mti = N;
    }

    return self;
}

void mt_free(struct mt *self)
{
    free(self);
}

/* Returns a pseudorandom number which is uniformly distributed in [0,1) */
double mt_genrand(struct mt *self)
{
    int kk;
    unsigned long int y;
    static unsigned long int mag01[2] = {0x0, 0x9908b0df};
    static const unsigned long int UP_MASK = 0x80000000, LOW_MASK = 0x7fffffff;

    if (self->mti >= N) {
        for (kk = 0; kk < N-M; kk++) {
            y = (self->mt[kk] & UP_MASK) | (self->mt[kk+1] & LOW_MASK);
            self->mt[kk] = self->mt[kk+M] ^ (y >> 1) ^ mag01[y & 1];
        }

        for (; kk < N-1; kk++) {
            y = (self->mt[kk] & UP_MASK) | (self->mt[kk+1] & LOW_MASK);
            self->mt[kk] = self->mt[kk+(M-N)] ^ (y >> 1) ^ mag01[y & 1];
        }

        y = (self->mt[N-1] & UP_MASK) | (self->mt[0] & LOW_MASK);
        self->mt[N-1] = self->mt[M-1] ^ (y >> 1) ^ mag01[y & 1];

        self->mti = 0;
    }
  
    y  = self->mt[self->mti++];
    y ^= y >> 11;
    y ^= y <<  7 & 0x9d2c5680;
    y ^= y << 15 & 0xefc60000;
    y ^= y >> 18;

    return y*(1.0/4294967296.0);
}
