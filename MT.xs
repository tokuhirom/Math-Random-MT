/*
 * $Id: MT.xs,v 1.00 2002/02/08 19:22:46 ams Exp $
 * Copyright 2001 Abhijit Menon-Sen <ams@wiw.org>
 */

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "ppport.h"

#include "mt.h"

typedef struct mt * Math__Random__MT;

MODULE = Math::Random::MT   PACKAGE = Math::Random::MT  PREFIX = mt_
PROTOTYPES: DISABLE

Math::Random::MT
mt_setup(seed)
    I32     seed
    CODE:
        RETVAL = mt_setup(seed);
    OUTPUT:
        RETVAL

void
mt_DESTROY(self)
    Math::Random::MT self
    CODE:
        mt_free(self);

double
mt_genrand(self)
    Math::Random::MT self
    CODE:
        RETVAL = mt_genrand(self);
    OUTPUT:
        RETVAL
