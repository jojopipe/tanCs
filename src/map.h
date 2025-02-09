#ifndef __TANCS_MAP
#define __TANCS_MAP

#include <stdint.h>

#define BLOCK_AIR 				0
#define BLOCK_WOOD 				1
#define BLOCK_DESTRUCTABLE 		2
#define BLOCK_HOLE				3


typedef struct map {
	uint32_t x;
	uint32_t y;
	uint8_t* data;
} map_t;


uint8_t map_load_from_file(map_t* m, const char* filepath);
void map_render(map_t* m);
void map_print(map_t* m);


#endif
