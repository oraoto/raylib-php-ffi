<?php

include __DIR__ . "/../../RayLib.php";

// Initialization
RayLib::init();

$screenWidth = 800;
$screenHeight = 450;

RayLib::InitWindow($screenWidth, $screenHeight, "raylib [models] example -  heightmap loading and drawing");

$camera = RayLib::Camera();
$camera->position = RayLib::Vector3(18.0, 16.0, 18.0);
$camera->target = RayLib::Vector3(0, 0, 0);
$camera->up = RayLib::Vector3(0, 1, 0);
$camera->fovy = 45.0;
$camera->type = RayLib::CAMERA_PERSPECTIVE;

$image = RayLib::LoadImage(__DIR__ . "/resources/heightmap.png");

// TODO: FFI doesn't support returning array
$texture = RayLib::LoadTextureFromImage($image);

$mesh = RayLib::GenMeshHeightmap($image, RayLib::Vector3(16, 8, 16));
$model = RayLib::LoadModelFromMesh($mesh);

$model->material->maps[RayLib::MAP_DIFFUSE]->texture = texture;
$mapPosition = RayLib::Vector3(-8, 0, -8);

RayLib::UnloadImage($image);

RayLib::SetCameraMode($camera, RayLib::CAMERA_ORBITAL);

raylib::SetTargetFPS(60);

// Main game loop
while (!RayLib::WindowShouldClose())
{
    // Update
    RayLib::UpdateCamera(FFI::addr($camera));

    // Draw
    RayLib::BeginDrawing();
    RayLib::ClearBackground(RayLib::$RAYWHITE);

    RayLib::BeginMode3D($camera);
    RayLib::DrawModel($model, $mapPosition, 1.0, RayLib::$RED);
    RayLib::DrawGrid(20, 1.0);
    RayLib::EndMode3D();

    RayLib::DrawTexture(texture, $screenWidth - $texture->width - 20, 20, RayLib::$WHITE);
    RayLib::DrawRectangleLines($screenWidth - $texture->width - 20, 20, $texture->width, $texture->height, RayLib::$GREEN);

    DrawFPS(10, 10);
    RayLib::EndDrawing();
}
// De-Initialization
RayLib::CloseWindow();
