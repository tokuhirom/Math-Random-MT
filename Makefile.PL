use ExtUtils::MakeMaker;

WriteMakefile(
    NAME          => 'Math::Random::MT',
    OBJECT        => 'MT.o _mt.o',
    VERSION_FROM  => 'MT.pm',
    ABSTRACT_FROM => 'MT.pm',
);
