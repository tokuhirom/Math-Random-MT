/*
 * Math::Random::MT
 * Copyright 2001 Abhijit Menon-Sen <ams@wiw.org>
 */

#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"
#include "ppport.h"

#include "mt.h"

typedef struct mt * Math__Random__MT;

void * I32ArrayPtr ( int n ) {
    SV * sv = sv_2mortal( NEWSV( 0, n*sizeof(I32) ) );
    return SvPVX(sv);
}

MODULE = Math::Random::MT   PACKAGE = Math::Random::MT  PREFIX = mt_
PROTOTYPES: DISABLE

Math::Random::MT
mt_setup(seed)
    I32     seed
    CODE:
        RETVAL = mt_setup(seed);
    OUTPUT:
        RETVAL

Math::Random::MT
mt_setup_array( array, ... )
    CODE:
        I32 * array = I32ArrayPtr( items );
        U32 ix_array = 0;
        while (items--) {
            array[ix_array] = (I32 *)SvIV(ST(ix_array));
            ix_array++;
        }
        RETVAL = mt_setup_array( array, ix_array );
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
