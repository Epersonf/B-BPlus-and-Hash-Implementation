#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main()
{
    THash* hash_1 = hash_create(10);

    hash_add(hash_1, hash_create_obj(10));
    hash_add(hash_1, hash_create_obj(20));
    hash_add(hash_1, hash_create_obj(30));
    hash_add(hash_1, hash_create_obj(40));
    hash_add(hash_1, hash_create_obj(50));
    hash_add(hash_1, hash_create_obj(60));
    hash_add(hash_1, hash_create_obj(70));
    hash_add(hash_1, hash_create_obj(80));
    hash_add(hash_1, hash_create_obj(90));
    hash_add(hash_1, hash_create_obj(95));
    hash_add(hash_1, hash_create_obj(105));


    hash_print(hash_1);

    hash_free(hash_1);
    return 0;
}
