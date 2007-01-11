/*
 * $Id: mt.h,v 1.00 2002/02/08 19:22:46 ams Exp $
 * Copyright 2001 Abhijit Menon-Sen <ams@wiw.org>
 */

#include <stdlib.h>

#if defined(__linux__) || defined(__WIN32__)
#include <stdint.h>
#elif defined(__osf__)
#include <inttypes.h>
#else
#include <sys/types.h>
#endif

#ifndef _MATH_MT_H_
#define _MATH_MT_H_

/* Period parameters */
enum { N = 624, M = 397 };

struct mt {
    uint32_t mt[N];
    int mti;
};

struct mt *mt_setup(uint32_t seed);
struct mt *mt_setup_array(uint32_t *array, int n);
void mt_free(struct mt *self);
double mt_genrand(struct mt *self);

#endif
