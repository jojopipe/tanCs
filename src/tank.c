#include "tank.h" #include <raymath.h>
#include <raylib.h>
#include <math.h>


#define TANK_SCALE (Vector3) {0.2, 0.2, 0.2}
#define TANK_ROT_AXIS (Vector3) {0, 1, 0}

void tank_create(tank_t* t, Vector3 pos, float speed, int rotation, uint32_t hp, \
		uint32_t bullet_max, uint32_t bullet_speed, const char* model_path);


void tank_create_default(tank_t* t) {
	t->hp = 1;
	t->speed = 0.1f;
	t->pos = (Vector3) {0, 1, 0};
	t->bullets_max = 5;
	t->bullets_rem = 5;
	t->bullet_speed = 0.5f;
	t->model = LoadModel("default_tank.glb");
}

int32_t angleDiff(int32_t a, int32_t b) {
    return ((((a - b) % 360) + 540) % 360) - 180;
}

// returns 1 while rotating and 0 when done
uint8_t tank_rotate(tank_t* t, int32_t dest) {
	float diff = angleDiff(t->rot, dest);
    
    if (fabsf(diff) < 0.1f) {
        t->rot = dest;
        return 0;
    }

    float rotation_speed = 2.0f;
    if (fabsf(diff) < 10.0f) rotation_speed *= 0.5f;
    
    t->rot += (diff > 0) ? -rotation_speed : rotation_speed;
    t->rot = fmodf(t->rot, 360.0f);
    return 1;
}

void tank_move(tank_t* t, int32_t dir) {
	if (tank_rotate(t, dir)) return;
    float radians = t->rot * DEG2RAD;
    t->pos.z += cosf(radians) * t->speed;
    t->pos.x += sinf(radians) * t->speed;

}

void tank_draw(tank_t* t) {
	DrawModelEx(t->model, t->pos, TANK_ROT_AXIS, (TANK_ROT_AXIS, t->rot) , TANK_SCALE, (Color) {255, 0, 0, 70});
}

void tank_shoot(tank_t* t, Vector2 dir) {

}

