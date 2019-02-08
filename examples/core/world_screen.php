<?php

include __DIR__ . "/../../RayLib.php";

// Initialization
RayLib::init();

$screenWidth = 800;
$screenHeight = 450;

RayLib::InitWindow($screenWidth, $screenHeight, "raylib [core] example -  camera free");

$camera = RayLib::Camera();
$camera->position = RayLib::Vector3(10.0, 10.0, 10.0);
$camera->target = RayLib::Vector3(0, 0, 0);
$camera->up = RayLib::Vector3(0, 1, 0);
$camera->fovy = 45.0;
$camera->type = RayLib::CAMERA_PERSPECTIVE;

$cubePosition = RayLib::Vector3(0, 0, 0);
$cubeScreenPosition;

RayLib::SetCameraMode($camera, RayLib::CAMERA_FREE);

raylib::SetTargetFPS(60);

// Main game loop
while (!RayLib::WindowShouldClose())
{
    // Update
    RayLib::UpdateCamera(FFI::addr($camera));

    $cubeScreenPosition = RayLib::GetWorldToScreen(RayLib::Vector3($cubePosition->x, $cubePosition->y + 2.5, $cubePosition->z), $camera);

    // Draw
    RayLib::BeginDrawing();
    RayLib::ClearBackground(RayLib::$RAYWHITE);

    RayLib::BeginMode3D($camera);
    RayLib::DrawCube($cubePosition, 2.0, 2.0, 2.0, RayLib::$RED);
    RayLib::DrawCubeWires($cubePosition, 2.0, 2.0, 2.0, RayLib::$MAROON);
    RayLib::DrawGrid(10, 1.0);
    RayLib::EndMode3D();


    RayLib::DrawText("Enemy: 100 / 100", $cubeScreenPosition->x - RayLib::MeasureText("Enemy: 100 / 100", 20) / 2, $cubeScreenPosition->y, 20, RayLib::$BLACK);
    RayLib::DrawText("Text is always on top of the cube", ($screenWidth - RayLib::MeasureText("Text is always on top of the cube", 20)) / 2, 25, 20, RayLib::$GRAY);

    RayLib::EndDrawing();
}
// De-Initialization
RayLib::CloseWindow();
