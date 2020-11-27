#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main()
{
    THash* hash = hash_create(20);

    hash_add(hash, hash_create_obj(5));
    hash_add(hash, hash_create_obj(25));
    hash_add(hash, hash_create_obj(45));

    hash_print(hash);

    hash_free(hash);

    return 0;
}
