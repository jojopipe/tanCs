#ifndef TANCS_GAMEOBJECT_H
#define TANCS_GAMEOBJECT_H
#include <raylib.h>

typedef struct gameobject gameobject_t;
typedef struct transform transform_t;

struct transform {
    Vector3 position;
    Vector3 rotation;
    Vector3 size;
};

struct gameobject {
    transform_t transform;
    char *name;

};

#endif //TANCS_GAMEOBJECT_H
