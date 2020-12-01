typedef struct object {
    int key;
    int amt;
} TObject;

TObject* hash_create_obj(int key) {
    TObject* object = malloc(sizeof(TObject));
    object->key = key;
    object->amt = 0;
    return object;
}

typedef struct hash_struct {
    int amount;
    TObject** obj_list;
} THash;

THash* hash_create(int amount) {
    THash* toReturn = malloc(sizeof(THash));
    toReturn->amount = amount;
    if (amount % 2 == 0) toReturn->amount++;
    toReturn->obj_list = calloc(sizeof(TObject*), toReturn->amount);
    return toReturn;
}

int getIndexLinear(THash* hash_obj, int key, int offset) {
    return ((key % hash_obj->amount) + offset) % hash_obj->amount;
}

int getIndexQuadratic(THash* hash_obj, int key, int offset) {
    return ((key % hash_obj->amount) + offset * offset) % hash_obj->amount;
}

int hashFunction_aux(THash* hash_obj, int key, int offset, int add) {
    int index = getIndexQuadratic(hash_obj, key, offset);

    if (offset == hash_obj->amount) return -1;

    if (add) {
        if (hash_obj->obj_list[index] != NULL) {
            if (hash_obj->obj_list[index]->key == key) return -1;
            return hashFunction_aux(hash_obj, key, offset + 1, add);
        }
    } else {
        if (hash_obj->obj_list[index] != NULL) {
            if (hash_obj->obj_list[index]->key != key)
                return hashFunction_aux(hash_obj, key, offset + 1, add);
        } else if (hash_obj->obj_list[index] == NULL)
                return hashFunction_aux(hash_obj, key, offset + 1, add);
    }

    return index;
}

int hashFunction(THash* hash_obj, int key, int add) {
    return hashFunction_aux(hash_obj, key, 0, add);
}

void hash_add(THash* hash_obj, TObject* obj) {
    int index = hashFunction(hash_obj, obj->key, 1);
    if (index == -1) return;
    hash_obj->obj_list[index] = obj;
}

void hash_del(THash* hash_obj, int key) {
    int index = hashFunction(hash_obj, key, 0);
    if (index == -1) return;
    hash_obj->obj_list[index] = NULL;
}

TObject* hash_get(THash* hash_obj, int key) {
    int index = hashFunction(hash_obj, key, 0);
    if (index == -1) return NULL;
    return hash_obj->obj_list[index];
}

void hash_print(THash* hash_obj) {
    for (int i = 0; i < hash_obj->amount; i++) {
        if (hash_obj->obj_list[i] == NULL) {
            printf("-> NULL\n");
            continue;
        }
        printf("-> %d\n", hash_obj->obj_list[i]->key);
    }
}

void hash_free(THash* hash_obj) {
    for (int i = 0; i < hash_obj->amount; i++) {
        if (hash_obj->obj_list[i] == NULL) continue;
        free(hash_obj->obj_list[i]);
    }
    free(hash_obj->obj_list);
    free(hash_obj);
}
