/*
 * $Id: mt.h,v 1.00 2002/02/08 19:22:46 ams Exp $
 * Copyright 2001 Abhijit Menon-Sen <ams@wiw.org>
 */

#include <stdlib.h>

#ifndef _MATH_MT_H_
#define _MATH_MT_H_

/* Period parameters */
enum { N = 624, M = 397 };

struct mt {
    unsigned long int mt[N];
    int mti;
};

struct mt *mt_setup(unsigned long int seed);
void mt_free(struct mt *self);
double mt_genrand(struct mt *self);

#endif
