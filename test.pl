use strict;

use Test;
use vars qw($loaded);
use Benchmark qw(timediff timestr);

BEGIN { plan tests => 4 }
END   { print "not ok 1\n" unless $loaded }

use Math::Random::MT;
ok($loaded = 1);
ok(my $gen = Math::Random::MT->new(4357));
ok(0.667576477630064, $gen->rand());
ok(0.369083872530609, $gen->rand());
