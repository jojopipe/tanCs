#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <raylib.h>


uint8_t map_load_from_file(map_t* m, const char* filepath) {
	FILE *file = fopen(filepath, "r");
    uint32_t file_size;
    char *data;
	if (file == NULL) return 0;
    fseek(file, 0L, SEEK_END);
    file_size = ftell(file);
    rewind(file);
    data = malloc(file_size);
    fread(data, 1, file_size, file);
    fclose(file);
	uint32_t dim;
	for (dim = 0; dim < file_size; ++dim) {
		if (data[dim] == '\n')
			break;
	}
	
	char* end;
	m->x = strtol(data, &end, 10);
	m->y = strtol(end + 1, &end, 10);
	m->data = (uint8_t*) calloc(sizeof(uint8_t), m->x * m->y);	
	printf("Loaded Map of Size: %d, %d\n", m->x, m->y);
	uint32_t index = 0;
	do {
		m->data[index++] = strtol(end + 1, &end, 10);
	} while (end < data + file_size && index < m->x * m->y);

	return 1;
}

void map_render(map_t* m) {
	for (uint32_t y = 0; y < m->y; ++y) {
		for (uint32_t x = 0; x < m->x; ++x) {
			switch (m->data[x + y * m->x]) {
				case 1:
					DrawCube((Vector3) {y * 5 + 2.5f - (((float)m->y * 5) / 2), 0 + 2.5f, x * 5 + 2.5f - (((float)m->x * 5) / 2)}, 5.f, 5.f, 5.f, BROWN);
					break;
				case 2:
					DrawCube((Vector3) {y * 5 + 2.5f - (((float)m->y * 5) / 2), 0 + 2.5f, x * 5 + 2.5f - (((float)m->x * 5) / 2)}, 5.f, 5.f, 5.f, RED);
					break;
				case 3:
					DrawCube((Vector3) {y * 5 + 2.5f - (((float)m->y * 5) / 2), 0 + 2.5f, x * 5 + 2.5f - (((float)m->x * 5) / 2)}, 5.f, 5.f, 5.f, BLACK);
					break;

				default:
				;
			}

		}
	}
}

void map_print(map_t* m) {
	char* c = "█";
	char buff[128];
	size_t in = 0;
	for (uint32_t y = 0; y < m->y; ++y) {
		for (uint32_t x = 0; x < m->x; ++x) {
			switch (m->data[x + y * m->x]) {
				case 1:
					sprintf(buff, "\033[38;2;%hhu;%hhu;%hhum%s\033[0m", 100, 70, 0, c);
					printf("%s", buff);
					printf("%s", buff);
					break;
				case 2:
					sprintf(buff, "\033[38;2;%hhu;%hhu;%hhum%s\033[0m", 255, 0, 0, c);
					printf("%s", buff);
					printf("%s", buff);
					break;
				case 3:
					sprintf(buff, "\033[38;2;%hhu;%hhu;%hhum%s\033[0m", 0, 0, 0, c);
					printf("%s", buff);
					printf("%s", buff);
					break;
				default:
					sprintf(buff, "\033[38;2;%hhu;%hhu;%hhum%s\033[0m", 255, 255, 255, c);
					printf("%s", buff);
					printf("%s", buff);
					break;

			}
			++in;
		}
		printf("\n");
	}
}

