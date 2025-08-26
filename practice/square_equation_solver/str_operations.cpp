#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "str_operations.hpp"

int endswith(const char *s1, const char *s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    size_t n1 = strlen( s1 );
    size_t n2 = strlen( s2 );
    
    if (strlen(s2) >= strlen(s1)) return 0;

    return ( n2 == 0 ) || ( !( n1 < n2 ) && memcmp( s1 + n1 - n2, s2, n2 ) == 0 );
}