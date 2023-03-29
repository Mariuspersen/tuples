#ifndef TUPLES_H_
#define TUPLES_H_

#include <stdarg.h>
#include <stdlib.h>

#ifndef TUPLE
#define TUPLE
#endif // SBDEF

typedef enum {
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_CHAR,
} DataType;

typedef union {
    int as_int;
    float as_float;
    double as_double;
    char as_char;
} Data;

typedef struct {
    DataType type;
    Data data;
} Tuple;

Tuple tuple_create_char(char val);
Tuple tuple_create_float(float val);
Tuple tuple_create_double(double val);
Tuple tuple_create_int(int val);

#define tuple_create(val) _Generic((val), \
    char: tuple_create_char, \
    float: tuple_create_float, \
    double: tuple_create_double, \
    int: tuple_create_int \
)(val)

#define TP_Arg(tp)  (tp).data
#define TP_Fmt(tp)  (tp).type == TYPE_INT ? "%d" :      \
                    (tp).type == TYPE_FLOAT ? "%f" :    \
                    (tp).type == TYPE_DOUBLE ? "%lf" :  \
                    (tp).type == TYPE_CHAR ? "%c" :     \
                    "%d(?)"

Tuple* tuples_create(size_t tuple_count,...);
void tuple_delete(Tuple* tp);

#endif
#ifdef TUPLE_IMPLEMENTATION

TUPLE Tuple tuple_create_int(int val) {
    Tuple tp = { .type=TYPE_INT, .data.as_int=val};
    return tp;
}
TUPLE Tuple tuple_create_float(float val) {
    Tuple tp = { .type=TYPE_FLOAT, .data.as_float=val};
    return tp;
}
TUPLE Tuple tuple_create_double(double val) {
    Tuple tp = { .type=TYPE_DOUBLE, .data.as_float=val};
    return tp;
}
TUPLE Tuple tuple_create_char(char val) {
    Tuple tp = { .type=TYPE_CHAR, .data.as_char=val};
    return tp;
}

TUPLE Tuple* tuples_create(size_t tuple_count,...) {
    va_list arg;
    Tuple* tuple = (Tuple*)malloc(tuple_count*sizeof(Tuple));

    va_start(arg,tuple_count);
    for (size_t i = 0; i < tuple_count; i++)
    {
        Tuple temp = va_arg(arg,Tuple);
        tuple[i] = temp;
    }
    va_end(arg);
    return tuple;
}

void tuple_delete(Tuple* tp) {
    free(tp);
}

#endif