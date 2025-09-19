#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{
    public:
        A();
};

class B : public Base
{
    public:
        B();
};

class C : public Base
{
    public:
        C();
};

Base* generate();
void    identify( Base* p );
void    ident6ify( Base& p );