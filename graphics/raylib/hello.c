#include "raylib.h"

int main() {
  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  SetTraceLogLevel(LOG_NONE);
  InitWindow(0, 0, "Test");

  Camera camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;

  SetCameraMode(camera, CAMERA_FREE);

  SetTargetFPS(60);

  Vector3 cubePosition = {0.0f, 0.0f, 0.0f};
  Vector3 cubeSize = {2.0f, 2.0f, 2.0f};
  Vector2 cubeScreenPosition = {0.0f, 0.0f};

  Ray ray = {0};
  RayCollision collision = {0};

  while (!WindowShouldClose()) {
    UpdateCamera(&camera);
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
      if (!collision.hit) {
        ray = GetMouseRay(GetMousePosition(), camera);

        collision = GetRayCollisionBox(ray,
          (BoundingBox){
            (Vector3){
              cubePosition.x - cubeSize.x / 2,
              cubePosition.y - cubeSize.y / 2,
              cubePosition.z - cubeSize.z / 2
            },
            (Vector3){
              cubePosition.x + cubeSize.x / 2,
              cubePosition.y + cubeSize.y / 2,
              cubePosition.z + cubeSize.z / 2
            }
          });
      } else
        collision.hit = false;
    }

    cubeScreenPosition = GetWorldToScreen((Vector3){cubePosition.x, cubePosition.y + 2.5f, cubePosition.z}, camera);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginMode3D(camera);

    DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
    DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);

    DrawGrid(100, 1.0f);

    EndMode3D();
    DrawText("Label", (int)cubeScreenPosition.x - MeasureText("Label", 20) / 2, (int)cubeScreenPosition.y, 20, BLACK);
    if (collision.hit) {
      DrawText("BOX SELECTED", 10, 10, 30, GREEN);
    }
    DrawFPS(10, 10);
    EndDrawing();
  }

  CloseWindow();
}
