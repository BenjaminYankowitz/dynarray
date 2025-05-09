#include "../dynarray.h"
#include "macroassert.h"

int main()
{
    int *v = dynarray_create(int);
    
    assert_eq(dynarray_length(v), 0);
    assert_lte(dynarray_length(v), dynarray_capacity(v));

    for (int i = 0; i < 10; i++) {
        dynarray_push(v, i);
        dynarray_push_rval(v, 100 - i);
        assert_lte(dynarray_length(v), dynarray_capacity(v));
    }

    for (int i = 0; i < dynarray_length(v); i++) {
        int value;
        assert_eq(dynarray_get(v,i,value), true);
        assert_eq(value, v[i]);
        printf("v[%d] -> %d\n", i, v[i]);
    }
    
    assert_eq(dynarray_length(v), 20);
    assert_lte(dynarray_length(v), dynarray_capacity(v));

    dynarray_destroy(v);
}
