use strict;

use Test;
use vars qw($loaded);
use Benchmark qw(timediff timestr);

BEGIN { plan tests => 4 }
END   { print "not ok 1\n" unless $loaded }

use Math::Random::MT;
ok($loaded = 1);
ok(my $gen = Math::Random::MT->new(5489));
ok(0.814723691903055, $gen->rand());
ok(0.135477004107088, $gen->rand());
