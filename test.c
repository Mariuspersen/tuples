#include <stdio.h>

#define TUPLE_IMPLEMENTATION
#include "tuples.h"

int main(void) {
    Tuple* test = tuples_create(3,tuple_create((char)'C'),tuple_create(10),tuple_create(3.14));
    for (size_t i = 0; i < 3; i++)
    {
        printf(TP_Fmt(test[i]),TP_Arg(test[i]));
        printf("\n");
    }
    
    
    tuple_delete(test);

    return 0;
}