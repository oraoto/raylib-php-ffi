<?php

include __DIR__ . "/../../RayLib.php";

// Initialization
RayLib::init(); //

$screenWidth = 800;
$screenHeight = 450;

RayLib::InitWindow($screenWidth, $screenHeight, "raylib [core] example - basic window");

RayLib::SetTargetFPS(60);  // Set target frames-per-second

// Main game loop
while (!RayLib::WindowShouldClose())
{
    // Draw
    RayLib::BeginDrawing();
    RayLib::ClearBackground(RayLib::$WHITE);
    RayLib::DrawText("Congrats! You created your first window!", 190, 200, 20, RayLib::$LIGHTGRAY);
    RayLib::EndDrawing();
}
// De-Initialization
RayLib::CloseWindow();
