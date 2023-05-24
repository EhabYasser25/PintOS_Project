#include <stdint.h>

#define FRACTION_BITS 14


real
fixed(int num)
{
    real new_real = (real)num << FRACTION_BITS;
    return new_real;
}

int
round(real num)
{
    if (num >= 0) {
        return (num + (1 << (FRACTION_BITS - 1))) >> FRACTION_BITS;
    } else {
        return (num - (1 << (FRACTION_BITS - 1))) >> FRACTION_BITS;
    }
}

real
trunc(real num)
{
    return num >> FRACTION_BITS;
}

real 
add(real a, real b) 
{
    return a + b;
}

real 
addN(real a, int b) 
{
    return a + (b << FRACTION_BITS);
}

real 
sub(real a, real b)
{
    return a - b;
}

real 
subN(real a, int b)
{
    return a - (b << FRACTION_BITS);
}

real 
mul(real a, real b)
{
    return (a * b) >> FRACTION_BITS;
}

real 
mulN(real a, int b)
{
    return a * b;
}

real 
div(real a, real b)
{
    return (a << FRACTION_BITS) / b;
}

real 
divN(real a, int b)
{
    return a / b;
}
