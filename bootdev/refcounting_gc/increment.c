/**Increment
 *
 * Here I need to be able to increment the reference count of a
 * SnekObject any time a new reference to it is created
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "snekobject.h"

int main(int argc, char const *argv[])
{
    printf("\nTest - test_int_has_refcount\n");
    snek_object_t *obj = new_snek_integer(10);
    printf("\tRefcount should be 1 on creation and it is: %d\n", obj->refcount);
    refcount_inc(obj);
    printf("\tRefcount should be incremented to 2 and it is: %d\n", obj->refcount);

    free(obj);

    return 0;
}

void refcount_inc(snek_object_t *obj)
{
    if (obj == NULL)
    {
        return;
    }
    obj->refcount++;
}

snek_object_t *_new_snek_object()
{
    // allocate a snek_object_t *obj on heap - initialize memory to null
    // which means use calloc then confirm allocation
    snek_object_t *obj = calloc(1, sizeof(snek_object_t *));
    if (obj == NULL)
    {
        return NULL;
    }

    obj->refcount = 1;
    return obj;
}

snek_object_t *new_snek_array(size_t size)
{
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    snek_object_t **elements = calloc(size, sizeof(snek_object_t *));
    if (elements == NULL)
    {
        free(obj);
        return NULL;
    }

    obj->kind = ARRAY;
    obj->data.v_array = (snek_array_t){.size = size, .elements = elements};

    return obj;
}

snek_object_t *new_snek_vector3(
    snek_object_t *x,
    snek_object_t *y,
    snek_object_t *z)
{
    if (x == NULL || y == NULL || z == NULL)
    {
        return NULL;
    }

    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = VECTOR3;
    obj->data.v_vector3 = (snek_vector_t){.x = x, .y = y, .z = z};
    return obj;
}

snek_object_t *new_snek_integer(int value)
{
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = INTEGER;
    obj->data.v_int = value;
    return obj;
}

snek_object_t *new_snek_float(float value)
{
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    obj->kind = FLOAT;
    obj->data.v_float = value;
    return obj;
}

snek_object_t *new_snek_string(char *value)
{
    snek_object_t *obj = _new_snek_object();
    if (obj == NULL)
    {
        return NULL;
    }

    int len = strlen(value);
    // I guess we didn't do sizeof since len is already a size_t? But no its
    // not. len is an int. Not sure why we are mallocing this way. First time
    // I see malloc without a sizeof. I guess since chars are 1 byte,
    // theres no need to do size of char as opposed to size of int
    // or size of float or size of pointer which are all different
    // number of bytes. 🤔
    char *dst = malloc(len + 1);
    if (dst == NULL)
    {
        free(obj);
        return NULL;
    }

    strcpy(dst, value);

    obj->kind = STRING;
    obj->data.v_string = dst;
    return obj;
}
