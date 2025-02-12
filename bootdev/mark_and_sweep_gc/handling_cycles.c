/** Handling Cycles: 
 * 
 * I've built a simple reference counting garbage collector. It can
 * handle: 
 *      ▫️ Simple types, like INTEGER and FLOAT
 *      ▫️ Dynamically allocated types like STRING
 *      ▫️ Static Container types like VECTOR3
 *      ▫️ Dynamic Container types like ARRAY
 * 
 * However there's one little problem with my implementation. Take 
 * a look at the code below in main
 * 
 * I create a first array and shove the second array inside of it.
 * Everything here works as expected. The trouble arises when I 
 * introduce a cycle: for example, first contains second but second
 * also contains first... 
 * 
 * In the case below both refcounts are stuck at one after being 
 * decremented because when first has its refcount decremented it 
 * already had 2. So it only drops to 1, which doesn't trigger a free
 * of the second array. 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "snekobject.h"

int main(int argc, char const *argv[])
{
    snek_object_t *first = new_snek_array(1);
    snek_object_t *second = new_snek_array(1);
    // refcounts: first = 1, second = 1
    snek_array_set(first, 0, second);
    // refcounts: first = 1, second = 2
    snek_array_set(second, 0, first);
    // refcounts: first = 2, second = 2
    refcount_dec(first);
    // refcounts: first = 1, second = 2
    refcount_dec(second);
    // refcounts: first = 1, second = 1
    // all free, BUT NOT REALLY

    // The above won't compile and we get a segfault since we are left
    // with references to memory that doesn't exist.
    
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
    // Something I learned from Teej, instead of writing 'free(obj) so
    // much, I can only put the special 'frees' in the switch and
    // just free the obj at the end after we break out of the switch.
    // since at the end of every option I'm freeing obj
    switch (obj->kind)
    {
    case INTEGER:
    case FLOAT:
        break;
    case STRING:
        free(obj->data.v_string);
        break;
    case VECTOR3:
        // I started by just freeing everything, but as per the instructions
        // which make perfect sense, I need to refcount_dec not free. The
        // free will happen automatically if I hit zero
        refcount_dec(obj->data.v_vector3.x);
        refcount_dec(obj->data.v_vector3.y);
        refcount_dec(obj->data.v_vector3.z);
        break;
    case ARRAY:
        for (size_t i = 0; i < obj->data.v_array.size; i++)
        {
            refcount_dec(obj->data.v_array.elements[i]);
        }
        free(obj->data.v_array.elements);
        break;
    default:
        return;
    }
    // that's what this was here for. Now I get it.
    free(obj);
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

// snek_array-set update to increment refcount on object set. If there was
// already an element at that index, decrement its refcount as it was
// replaced
bool snek_array_set(snek_object_t *snek_obj, size_t index, snek_object_t *value)
{
    if (snek_obj == NULL ||
        value == NULL ||
        snek_obj->kind != ARRAY ||
        index >= snek_obj->data.v_array.size)
    {
        return false;
    }
    refcount_inc(value);
    if (snek_obj->data.v_array.elements[index])
    {
        refcount_dec(snek_obj->data.v_array.elements[index]);
    }
    snek_obj->data.v_array.elements[index] = value;
    return true;
}

snek_object_t *snek_array_get(snek_object_t *snek_obj, size_t index)
{
    if (snek_obj == NULL ||
        snek_obj->kind != ARRAY ||
        index >= snek_obj->data.v_array.size)
    {
        return NULL;
    }
    return snek_obj->data.v_array.elements[index];
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
