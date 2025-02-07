#ifndef __TANK
#define __TANK

#include <stdint.h>
#include <stdint.h>
#include <raylib.h>
#include <raymath.h>


typedef struct tank {
	Vector3 pos;
	float speed;
	int32_t rot;
	uint32_t hp;
	uint32_t bullets_max;
	uint32_t bullets_rem;
	float bullet_speed;
	Model model; 

} tank_t;

void tank_create(tank_t* t, Vector3 pos, float speed, int32_t rotation, uint32_t hp, \
		uint32_t bullet_max, uint32_t bullet_speed, const char* model_path);

void tank_create_default(tank_t* t);
uint8_t tank_rotate(tank_t* t, int32_t dest);
void tank_move(tank_t* t, int32_t dir);
void tank_draw(tank_t* t);
void tank_shot(tank_t* t, Vector2 dir);
#endif

