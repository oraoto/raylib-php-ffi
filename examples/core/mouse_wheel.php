<?php

include __DIR__ . "/../../RayLib.php";

// Initialization
RayLib::init();

$screenWidth = 800;
$screenHeight = 450;

RayLib::InitWindow($screenWidth, $screenHeight, "raylib [core] example - mouse wheel");

$boxPositionY = $screenHeight / 2 - 40;
$scrollSpeed = 4;

RayLib::SetTargetFPS(60);

// Main game loop
while (!RayLib::WindowShouldClose())
{
    // Update
    $boxPositionY -= RayLib::GetMouseWheelMove() * $scrollSpeed;

    // Draw
    RayLib::BeginDrawing();
    RayLib::ClearBackground(RayLib::$RAYWHITE);
    RayLib::DrawRectangle($screenWidth / 2 - 40, $boxPositionY, 80, 80, RayLib::$MAROON);

    RayLib::DrawText("Use mouse wheel to move the cube up and down!", 10, 10, 20, RayLib::$GRAY);
    RayLib::DrawText(RayLib::TextFormat("Box position Y: %03i", $boxPositionY), 10, 40, 20, RayLib::$LIGHTGRAY);
    RayLib::EndDrawing();
}
// De-Initialization
RayLib::CloseWindow();
