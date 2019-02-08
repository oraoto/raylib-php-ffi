<?php

include __DIR__ . "/../../RayLib.php";

// Initialization
RayLib::init();

$screenWidth = 800;
$screenHeight = 450;

RayLib::InitWindow($screenWidth, $screenHeight, "raylib [core] example - mouse input");

$ballPosition = RayLib::Vector2(-100.0, 100.0);
$ballColor = RayLib::$DARKBLUE;

RayLib::SetTargetFPS(60);

// Main game loop
while (!RayLib::WindowShouldClose())
{
    // Update
    $ballPosition = RayLib::GetMousePosition();

    if (RayLib::IsMouseButtonPressed(RayLib::MOUSE_LEFT_BUTTON)) {
        $ballColor = RayLib::$MAROON;
    } elseif (RayLib::IsMouseButtonPressed(RayLib::MOUSE_MIDDLE_BUTTON)) {
        $ballColor = RayLib::$LIME;
    } elseif (RayLib::IsMouseButtonPressed(RayLib::MOUSE_RIGHT_BUTTON)) {
        $ballColor = RayLib::$DARKBLUE;
    }

    // Draw
    RayLib::BeginDrawing();
    RayLib::ClearBackground(RayLib::$RAYWHITE);
    RayLib::DrawCircleV($ballPosition, 40, $ballColor);
    RayLib::DrawText("move ball with mouse and click mouse button to change color", 10, 10, 20, RayLib::$DARKGRAY);
    RayLib::EndDrawing();
}
// De-Initialization
RayLib::CloseWindow();
