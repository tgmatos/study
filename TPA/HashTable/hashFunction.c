#include "hashFunction.h"

//h(k) = k mod N
long long hashFunction(long long input, long long tam)
{
    return input % tam;
}

//h2(k) = 1 + ( k mod (N-1) )
long long secondHashFunction(long long input, long long tam)
{
    return (input % (tam - 1)) + 1;
}

//rh(i,k) = ( i + h2(k) ) mod N
long long thirdHashFunction(long long tam, long long i, long long secondHash)
{
    return (i + secondHash) % tam;
}