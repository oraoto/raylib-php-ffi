<?php

include __DIR__ . "/../../RayLib.php";

// Initialization
RayLib::init();

$screenWidth = 800;
$screenHeight = 450;

RayLib::InitWindow($screenWidth, $screenHeight, "raylib [core] example - keyboard input");

$ballPosition = RayLib::Vector2($screenWidth / 2, $screenHeight / 2);

RayLib::SetTargetFPS(60);

// Main game loop
while (!RayLib::WindowShouldClose())
{
    // Update
    if (RayLib::IsKeyDown(RayLib::KEY_RIGHT)) $ballPosition->x += 2.0;
    if (RayLib::IsKeyDown(RayLib::KEY_LEFT))  $ballPosition->x -= 2.0;
    if (RayLib::IsKeyDown(RayLib::KEY_UP))    $ballPosition->y -= 2.0;
    if (RayLib::IsKeyDown(RayLib::KEY_DOWN))  $ballPosition->y += 2.0;

    // Draw
    RayLib::BeginDrawing();
    RayLib::ClearBackground(RayLib::$RAYWHITE);
    RayLib::DrawText("move the ball with arrow keys", 10, 10, 20, RayLib::$DARKGRAY);
    RayLib::DrawFPS(40, 40);
    RayLib::DrawCircleV($ballPosition, 50, RayLib::$MAROON);
    RayLib::EndDrawing();
}
// De-Initialization
RayLib::CloseWindow();
