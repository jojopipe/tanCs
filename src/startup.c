#include <stdint.h>
#include "settings.h"
#include <raylib.h>
#include "tank.h"
#include "map.h"


#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif


int init_game() {
    struct window_parameters wparam;
    wparam.width = 1200;
    wparam.height = 700;
    wparam.window_state = 0;

    InitWindow(wparam.width, wparam.height, "tanCs");
    if (wparam.window_state == 1) ToggleBorderlessWindowed();
    SetTargetFPS(144);
    Camera camera = { 0 };
    camera.position = (Vector3) {45.0f, 35.0f, 0.f};
    camera.target = (Vector3) {0.0f, 0.0f, 0.0f};
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    camera.fovy = 65.f;
    camera.projection = CAMERA_ORTHOGRAPHIC;

    Model characterModel = LoadModel("tnk_tank_p.glb");
    Vector3 tank_pos = {0.0f, 0.0f, 0.0f};

    Color bg_color = RAYWHITE;
	Vector3 pos = {0, 1, 0};
	float deltaTime = 1;
	float r_angle = -90;
	float r_speed = 2.5;
	tank_t tank;

	tank_create_default(&tank);
	map_t map;
	map_load_from_file(&map, "map1.map");
	map_print(&map);	

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(bg_color);
        BeginMode3D(camera);
		
//        DrawModel(characterModel, pos, 0.2f, RED);
//		DrawModelEx(characterModel, pos, (Vector3) {0, 1, 0}, r_angle, (Vector3) {0.2, 0.2, 0.2}, (Color){255, 0, 0, 70});
		map_render(&map);
        DrawGrid(20, 5.0f);
		tank_draw(&tank);
//DrawCube((Vector3) {-25 * 5, 1, -25 * 5})
			
		if (IsKeyDown(KEY_W) && IsKeyDown(KEY_D))
			tank_move(&tank, 225);
		else if (IsKeyDown(KEY_A) && IsKeyDown(KEY_S))
			tank_move(&tank, 45);
		else if (IsKeyDown(KEY_S) && IsKeyDown(KEY_D))
			tank_move(&tank, 135);
		else if (IsKeyDown(KEY_A) && IsKeyDown(KEY_W))
			tank_move(&tank, 315);


		else if (IsKeyDown(KEY_W))
			tank_move(&tank, 270);
		else if (IsKeyDown(KEY_S))
			tank_move(&tank, 90);
		else if (IsKeyDown(KEY_A))
			tank_move(&tank, 0);
		else if (IsKeyDown(KEY_D))
			tank_move(&tank, 180);

        EndMode3D();
        DrawFPS(10, 10);
        EndDrawing();
    }

    return 0;
}
