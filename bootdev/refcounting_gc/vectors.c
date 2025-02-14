/** Vectors:
 *
 * So no I've arrived at the first container type! What makes vector3
 * not like the other types is that it holds other snek objects. That
 * means it 'references' them. They are contained in its x,y, and z 
 * fields.
 * 
 * When I create a vector and place objects in those fields, I need to 
 * increment teh refcount of each of those objects! Otherwise I might
 * accidently free its content and be left with a vector holding 
 * garbage memory. 
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "snekobject.h"

int main(int argc, char const *argv[])
{
    printf("\nCOMPILATION SUCCESS!!!\n\n");

    return 0;
}

void refcount_dec(snek_object_t *obj)
{
    // handle NULL gracefully
    if (obj == NULL)
    {
        return;
    }
    // decrement the refcount
    obj->refcount--;
    // if refcount reaches 0 call refcount_free on object
    if (obj->refcount == 0)
    {
        refcount_free(obj);
    }
}

void refcount_free(snek_object_t *obj)
{
    // if obj is an INTEGER or FLOAT, free the object itself
    // since it holds the actual value. I don't need to worry about
    // the data inside the object since its stored directly in the
    // object not on the heap.
    switch (obj->kind)
    {
    case INTEGER:
    case FLOAT:
        free(obj);
        break;
    case STRING:
        free(obj->data.v_string);
        free(obj);
        break;
    case VECTOR3:
        // I started by just freeing everything, but as per the instructions
        // which make perfect sense, I need to refcount_dec not free. The
        // free will happen automatically if I hit zero
        refcount_dec(obj->data.v_vector3.x);
        refcount_dec(obj->data.v_vector3.y);
        refcount_dec(obj->data.v_vector3.z);
        break;
    default:
        return;
    }
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

// Updating function to refcount_inc each of its 3 objects.
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
    refcount_inc(x);
    refcount_inc(y);
    refcount_inc(z);

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
