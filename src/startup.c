#include <stdint.h>
#include <stdlib.h>
#include "settings.h"
#include <raylib.h>
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
    camera.position = (Vector3) {25.0f, 25.0f, 25.0f};
    camera.target = (Vector3) {0.0f, 0.0f, 0.0f};
    camera.up = (Vector3) {0.0f, 1.0f, 0.0f};
    camera.fovy = 70.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Model characterModel = LoadModel("assets/Tanks/tnk_tank_p.glb");
    Vector3 tank_pos = {0.0f, 0.0f, 0.0f};

    Color bg_color = BLUE;

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(bg_color);
        BeginMode3D(camera);

        //DrawModel(characterModel, (Vector3){0.0f,1.0f,0.0f}, 1.0f, RED);
        DrawGrid(15, 3.0f);

        EndMode3D();
        DrawFPS(10,10);
        EndDrawing();
    }

    return 0;
}