#include <stdint.h>
#include <stdlib.h>
#include "settings.h"
#include <raylib.h>

int init_game() {
    struct window_parameters wparam;
    wparam.width = 1200;
    wparam.height = 700;
    wparam.window_state = 0;

    InitWindow(wparam.width, wparam.height, "tanCs");
    if (wparam.window_state == 1) ToggleBorderlessWindowed();
    SetTargetFPS(144);
    // Define the camera to look into our 3d world
    Camera camera = { 0 };
    camera.position = (Vector3){ 0.0f, 10.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    Texture2D texture = LoadTexture("C_Logo.png");

    while(!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);


        DrawGrid(15, 1.0f);

        EndMode3D();

        EndDrawing();
    }

    return 0;
}