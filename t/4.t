use strict;

use Test;
use vars qw($loaded);
use Benchmark qw(timediff timestr);

BEGIN { plan tests => 3 }
END   { print "not ok 1\n" unless $loaded }

# Check that the results are the same with the function-call interface
# as with the OO interface

use Math::Random::MT qw(srand rand);
ok($loaded = 1);
srand(5489);
ok(0.814723691903055, rand());
ok(0.135477004107088, rand());
